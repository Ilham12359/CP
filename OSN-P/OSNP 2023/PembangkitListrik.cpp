#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define MOD 1e9+7;
#define run freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bismillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

class DSU{
  private:
   vector<ll> dsu;
  public:
   DSU(ll n){
    dsu.resize(n+1);
    iota(dsu.begin(),dsu.end(),0);
   }

   ll find(ll x){
    if(dsu[x]==x)return x;
    else return dsu[x]=find(dsu[x]);
   }

   void add(ll a,ll b){
    ll ka=find(a);
    ll kb=find(b);
    dsu[ka]=kb;
   }
};


int main(){
  bismillah
  // run
  
  ll n,m,k;cin>>n>>m>>k;
  vector<ll> diff,cost,sortDiff;
  for(ll i=0;i<n;i++){
    ll x;cin>>x;
    diff.push_back(x);
  }
  for(ll i=0;i<m;i++){
    ll x;cin>>x;
    cost.push_back(x);
  }

  DSU dsu(n);

  for(ll i=0;i<k;i++){
    ll a,b;
    cin>>a>>b;
    dsu.add(a,b);
  }

  map<ll,ll> mp;

  for(int i=1;i<=n;i++){
    mp[dsu.find(i)]=LLONG_MAX;
  }

  for(ll i=1;i<=n;i++){
    mp[dsu.find(i)]=min(mp[dsu.find(i)],diff[i-1]);
  }

  for(auto x:mp){
    sortDiff.push_back(x.second);
  }

  sort(sortDiff.begin(),sortDiff.end(),greater<ll>());
  sort(cost.begin(),cost.end());
  
  ll ans=0;


  for(ll i=0;i<min(sortDiff.size(),cost.size());i++){
    ans+=(cost[i]*sortDiff[i]);
  }

  if(sortDiff.size()>cost.size()){
    ans=-1;
  }

  cout<<ans<<endl;
  return 0;
}

