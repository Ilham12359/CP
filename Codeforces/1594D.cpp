#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

ll cek1;

void dfs(ll cur,ll &cnt1,ll &cnt0,vector<vector<pll>> &edge,vector<ll> &state){
    if(!cek1)
        return;
    // cout<<cur<<":"<<state[cur]<<endl;
    for(auto &e:edge[cur]){
        ll nx=e.first;
        ll tmp=state[cur]^e.second;
        if(state[nx]==-1){
            state[nx]=tmp;
            if(tmp)
                cnt1++;
            else cnt0++;
            dfs(nx,cnt1,cnt0,edge,state);
        }else if(state[nx]!=tmp){
            cek1=0;
            return;
        }
    }
}

void solve() {
    ll n,m,ans=0;
    cin>>n>>m;

    cek1=1;
    
    vector<vector<pll>> edge(n+1);
    vector<ll> state(n+1,-1);

    for(ll i=0;i<m;i++){
        ll a,b,cek=0;
        string s;
        cin>>a>>b>>s;

        if(s[0]=='i')
            cek=1;
        edge[a].push_back({b,cek});
        edge[b].push_back({a,cek});
    }


    for(ll i=1;i<=n;i++)
        if(state[i]<0){
            ll c1=0,c0=0;
            state[i]=1;
            c1++;
            dfs(i,c1,c0,edge,state);
            ans+=max(c1,c0);
            if(!cek1)
                break;
        }

    if(cek1)
        cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main() {
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(NULL);
  cin.tie(0);

  ll t = 1;
  cin>>t;
    
  while (t--) 
    solve();
}
