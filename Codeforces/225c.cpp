#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

void solve() {
  ll n,m;
  cin>>n>>m;
  
  ll l,r;
  cin>>l>>r;

  vector<string> grid(n);
  vector<vector<ll>> pref(n+1,vector<ll>(m+1,0));

  for(auto &e:grid)
    cin>>e;

  for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++)
      pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(grid[i-1][j-1]=='.');

  vector<vector<ll>> dp(m+1,vector<ll>(2,INT_MAX));
  dp[0][0]=0;
  dp[0][1]=0;

  for(ll i=1;i<=m;i++){
      for(ll len=l;len<=r;len++){
        if(i-len<0)
          break;
        ll total=n*len;
        ll c1=0,c0=0;

        c1=pref[n][i]-pref[n][i-len];
        c0=total-c1;

        dp[i][1]=min(dp[i][1],dp[i-len][0]+c0);
        dp[i][0]=min(dp[i][0],dp[i-len][1]+c1);
      }
  }

  cout<<min(dp[m][0],dp[m][1])<<endl;
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
