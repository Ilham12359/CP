#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll mod=1e9+7;

void solve() {
  ll n;
  cin>>n;

  vector<ll> a(n),b(n),c(n);
  for(auto &e:a)
    cin>>e;
  for(auto &e:b)
    cin>>e;
  for(auto &e:c)
    cin>>e;

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  vector<ll> prefB(n,0);
  for(ll i=0;i<n;i++){
    auto it=upper_bound(c.begin(),c.end(),b[i])-c.begin();
    ll cnt=n-it;
    prefB[i]=cnt;
  }

  for(ll i=n-2;i>=0;i--)
    prefB[i]+=prefB[i+1];

  ll ans=0;
  for(ll i=0;i<n;i++){
    ll pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
    if(pos==n)
      continue;
    ans+=prefB[pos];
  }

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
