#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n,m,k,tar;
vector<vector<ll>> grid;
vector<unordered_map<ll,int,custom_hash>> mp;
ll ans=0;

ll db[]={0,1};
ll dk[]={1,0};

void dfs1(ll cb,ll ck,ll val,ll step){
  if(step==tar){
    ll tval=k^val;
    ans+=mp[ck][tval];
    return;
  }
  val^=grid[cb][ck];

  for(ll i=0;i<2;i++){
    ll nb=cb+db[i];
    ll nk=ck+dk[i];

    if(nb>=0&&nk>=0&&nb<n&&nk<m)
      dfs1(nb,nk,val,step+1);
  }
}

void dfs2(ll cb,ll ck,ll val,ll step){
  val^=grid[cb][ck];
  if(step==tar){
    mp[ck][val]++;
    return;
  }

  for(ll i=0;i<2;i++){
    ll nb=cb-db[i];
    ll nk=ck-dk[i];

    if(nb>=0&&nk>=0&&nb<n&&nk<m)
      dfs2(nb,nk,val,step+1);
  }
}

void solve() {
  cin>>n>>m>>k;

  grid.resize(n,vector<ll>(m,0));
  mp.resize(m);

  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++)
      cin>>grid[i][j];

  ll tmp=0;
  tar=n+m-2;
  if(tar&1)
    tmp=-1;
  tar/=2;


  dfs2(n-1,m-1,0,0);
  dfs1(0,0,0,tmp);

  cout<<ans<<endl;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(NULL);
  cin.tie(0);

  ll t = 1;
  // cin>>t;

  while (t--) {
    solve();
  }
}
