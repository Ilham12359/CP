#include <bits/stdc++.h>
using namespace std;

// #define ll long long;

typedef long long ll;
#define endl '\n';
#define MOD 1e9+7;
#define run freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bismillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
  bismillah
  // run

  ll n,m;cin>>n>>m;
  ll sumA=0, sumB=0;
  vector<ll> a,b;
  while(n--){
    ll x;cin>>x;
    a.push_back(x);
    sumA+=x;
  }
  while(m--){
    ll x;cin>>x;
    b.push_back(x);
    sumB+=x;
  }

  sort(b.begin(),b.end());

  ll ans=0;
  ll sumAstart=sumA;

  // cout<<sumA<<endl;

  while(b.size()*sumA<=a.size()*sumB && b.size()>1){
    ll tmp=b.back();
    b.pop_back();
    a.push_back(tmp);
    sumA+=tmp;
    sumB-=tmp;
    while(b.back()==tmp&&b.size()>1){
      sumA+=tmp;
      sumB-=tmp;
      b.pop_back();
      a.push_back(tmp);
    }
  }

  // cout<<sumA<<" "<<b.size()<<endl;

  if(b.size()*sumA>a.size()*sumB){
    cout<<sumA-sumAstart;
  }else cout<<-1;

  return 0;


}


// N M
// A1 A2 … AN
// B1 B2 … BM