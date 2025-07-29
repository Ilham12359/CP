#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> numbers;

void solve() {
    ll n;
    cin>>n;
    
    vector<ll> vt(n);
    ll sum=0;
    for(auto &e:vt){
        cin>>e;
        sum+=e;
    }

    sort(vt.begin(),vt.end());
    for(ll i=0;i<n;i++){
        ll len=n-i;
        if(sum>=numbers[len]){
            cout<<i<<endl;
            return;
        }
        sum-=vt[i];
    }   
}

void precompute(){
    ll n=1e7+5;
    vector<ll> dp(n+1,0);
    
    dp[1]=1;
    for(ll i=2;i*i<=n;i++)
        if(dp[i])
            continue;
        else{
            for(ll j=i*i;j<=n;j+=i)
                dp[j]=1;
        }
    
    ll cnt=0;
    numbers.push_back(0);
    for(ll i=2;i<=n;i++)
        if(!dp[i])
            numbers.push_back(numbers.back()+i);
}

int main() {
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(NULL);
  cin.tie(0);

  ll t = 1;
  cin>>t;

  precompute();

  while (t--) 
    solve();
}
