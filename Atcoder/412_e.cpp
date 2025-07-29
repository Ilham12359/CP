#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll l,r;
ll idx(ll n){return n-l;}

void solve(){
    cin>>l>>r;

    vector<ll> dp(r-l+1,0);
    vector<ll> vt(1e7+5,0);
    ll ans=(l>1);


    for(ll i=2;i<=1e7;i++)
        if(i>r)
            break;
        else if(!vt[i]){
            for(ll j=i*i;j<=1e7;j+=i)
                vt[j]=1;
            
            ll start=l+((i-(l%i))%i);
            while(start<=r){
                dp[idx(start)]=1;
                start+=i;
            }

            ll cur=i;
            ll cnt=0;
            while(cur<=r){
                if(cur==l)
                    ans--;
                if(cur>=l)
                    cnt++;
                if(cur<=LLONG_MAX/i)
                    cur*=i;
                else break;
            }

            ans+=cnt;
        }

    for(ll i=0;i<r-l+1;i++)
        if(!dp[i])
            ans++;

    if(l>1e7&&dp[0]==0)
        ans--;

    
    cout<<ans<<endl;
}

// solusi-> dari l...r, cari banyaknya bilangan yang merupakan perpangkatan dari satu bilangan prima
                                                                                                  
int main(){

        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(NULL);cin.tie(0);

    ll t=1;
    // cin>>t;

    while(t--)
        solve();
}

// range=10e14-10e7...10e14
// check all prime 1...1e7 where have effect in range
