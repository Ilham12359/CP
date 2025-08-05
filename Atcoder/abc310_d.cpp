#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll n,t,m;
vector<vector<bool>> valid;
vector<vector<ll>> teams;
ll cnt=0;

void dfs(ll pos){
  // cout<<pos<<endl;
  if(pos==n+1){
    if((int)teams.size()==t)
      cnt++;
    return;
  }

  for(ll i=0;i<(int)teams.size();i++){
    ll cek=1;
    for(auto &e:teams[i]){
      if(!valid[e][pos])
        cek=0;
    }
      if(cek){
        teams[i].push_back(pos);
        dfs(pos+1);
        teams[i].pop_back();
      }
  }

  if((int)teams.size()<t){
    teams.push_back({pos});
    dfs(pos+1);
    teams.pop_back();
  }
  return;
}

void solve() {  

  cin>>n>>t>>m;
  valid.resize(n+1,vector<bool>(n+1,1));
  for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    valid[a][b]=0;
    valid[b][a]=0;
  }

  dfs(1);
   cout<<cnt<<endl;
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
