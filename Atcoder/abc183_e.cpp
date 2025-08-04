#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll mod=1e9+7;

void solve() {
  ll n,m;
  cin>>n>>m;

  vector<string> grid(n);
  for(auto &e:grid)
    cin>>e;

  vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
  vector<vector<ll>> pref1(n+1,vector<ll>(m+1,0));
  vector<vector<ll>> pref2(n+1,vector<ll>(m+1,0));
  vector<vector<ll>> pref3(n+1,vector<ll>(m+1,0));


  dp[1][1]=1;
  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++){

      if(grid[i-1][j-1]!='.')
        continue;
      dp[i][j]+=pref1[i-1][j]+pref2[i][j-1]+pref3[i-1][j-1];
      dp[i][j]%=mod;

      pref1[i][j]+=pref1[i-1][j]+dp[i][j];
      pref2[i][j]+=pref2[i][j-1]+dp[i][j];
      pref3[i][j]+=pref3[i-1][j-1]+dp[i][j];

      pref1[i][j]%=mod;
      pref2[i][j]%=mod;
      pref3[i][j]%=mod;
    }

  // for(ll i=1;i<=n;i++){
  //   for(ll j=1;j<=m;j++)
  //     cout<<dp[i][j]<<" ";
  //   cout<<endl;
  // }

  ll ans=dp[n][m];

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
