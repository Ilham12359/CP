#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

vector<ll> fen;
vector<ll> vt;

void update(ll pos,ll val){
  ll idx=pos;
  for(;idx<(int)fen.size();idx+=idx&(-idx))
    fen[idx]+=val;
}

ll que(ll pos){
  ll sum=0;
  ll idx=pos;

  for(;idx>0;idx-=idx&(-idx))
    sum+=fen[idx];
  return sum;
}

void solve() {
  ll n,k;
  cin>>n>>k;
  vt.resize(n+1,0);
  
  
  ll ans=0;  
  vector<ll> pref(n+1,0);  
  map<ll,ll> mcom;
  set<ll> scom;
  scom.insert(0);
  
  for(ll i=1;i<=n;i++){
    ll val;
    cin>>val;
    // if(val>=k)
    //   ans++;
    pref[i]=pref[i-1]+val;
    vt[i]=(pref[i]-k*i);
    scom.insert(pref[i]-k*i);
  }   

  // // cordinate compression
  ll cur=1;
  for(auto &e:scom)
    mcom[e]=cur++;

  for(auto &e:vt)
    e=mcom[e];

  fen.resize(cur+1,0);

  for(ll i=0;i<=n;i++){
    ll val=vt[i];
    // cout<<val<<" ";
    ans+=que(val);
    update(val,1);
  }
  // cout<<endl;

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

// pr-pl>=k*(r-l)
// pr-pl>=kr-kl
// pr-kr>=pl-kl
