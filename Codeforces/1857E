#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

void solve() {
  ll n;
  cin>>n;

  vector<ll> vt(n+1,0),pref(n+1,0),suff(n+2,0);

  map<ll,ll> mp;

  for(ll i=1;i<=n;i++)
    cin>>vt[i];
  vector<ll> ans=vt;

  sort(vt.begin(),vt.end());
  for(ll i=1;i<=n;i++)
    pref[i]=pref[i-1]+vt[i];

  for(ll i=n;i>0;i--)
    suff[i]=suff[i+1]+vt[i];

  for(ll i=1;i<=n;i++){
    ll ans=0;
    ll cur=vt[i];
    ans+=i*(cur)-pref[i]+i;
    ans+=suff[i]-(n-i+1)*(cur)+(n-i+1);
 
    mp[cur]=ans-1;
  }

  for(ll i=1;i<=n;i++)
    cout<<mp[ans[i]]<<" ";

  cout<<endl;
)


}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(NULL);
  cin.tie(0);

  ll t = 1;
  cin>>t;
    
  while (t--) 
    solve();
}
