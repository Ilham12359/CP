#include <bits/stdc++.h>
using namespace std;

#define ll long long 

struct dt{
  ll l;
  ll r;
};

bool cmp(dt a,dt b){
  return min(a.l,a.r)<min(b.l,b.r);
}

void update(ll idx,ll val,vector<ll> &cost,vector<ll> &fen){
  ll diff=val-cost[idx];
  cost[idx]=val;
  for(;idx<(int)cost.size();idx+=idx&(-idx))
    fen[idx]+=diff;
}

ll que(ll idx,vector<ll> &fen){
  ll sum=0;
  for(;idx>0;idx-=idx&(-idx))
    sum+=fen[idx];
  return sum;
}

void solve(){
  ll n,c;
  cin>>n>>c;

  vector<dt> vt(n+1);
  for(ll i=1;i<=n;i++){
    ll val;
    cin>>val;
    vt[i]={i+val,(n+1-i)+val};
  }

  sort(vt.begin(),vt.end(),cmp);
  
  vector<ll> cost(n+1,0);
  vector<ll> fen(n+1,0);

  for(ll i=1;i<=n;i++){
    update(i,min(vt[i].l,vt[i].r),cost,fen);
  }

  ll ans=0;

  // for each i, we try to fix that it start from left
  for(ll i=1;i<=n;i++){
    ll sum=c-vt[i].l;
    if(sum<0)
      continue;
    update(i,0,cost,fen);
    ll lo=1,hi=n;
    ll len=0;

    while(lo<=hi){
      ll mid=lo+(hi-lo)/2;
      if(que(mid,fen)<=sum){
        len=mid;
        lo=mid+1;
      }else hi=mid-1;
    }

    if(len<i)
      len++;
    ans=max(ans,len);
    update(i,min(vt[i].l,vt[i].r),cost,fen);
  }

  // for(auto &e:cost)
  //   cout<<e<<" ";
  // cout<<endl;

  cout<<ans<<endl;

}

int main(){
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(NULL);cin.tie(0);

  ll t=1;
  cin>>t;

  while(t--)
    solve();
}
