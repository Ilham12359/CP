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

  ll n,k,x;cin>>n>>k>>x;
  vector<ll> pos,val;
  for(ll i=0;i<n;i++){
    ll x;cin>>x;
    pos.push_back(x);
  }
  for(ll i=0;i<n;i++){
    ll x;cin>>x;
    val.push_back(x);
  }

  auto it=lower_bound(pos.begin(),pos.end(),x);
  vector<ll> pos1,pos2,val1,val2;

  ll idx=distance(pos.begin(),it);
  if(pos[idx]>x)idx--;
  // cout<<idx<<endl;

  for(ll i=0;i<=idx;i++){
    pos1.push_back(pos[i]);
    val1.push_back(val[i]);
  }

  for(ll i=idx+1;i<pos.size();i++){
    pos2.push_back(pos[i]);
    val2.push_back(val[i]);
  }

  vector<ll> left,right;
  vector<ll> lval(1,0),rval(1,0);

  for(ll i=pos1.size()-1;i>=0;i--){
    left.push_back(x-pos1[i]);
    lval.push_back(lval.back()+val1[i]);
  }


  for(ll i=0;i<pos2.size();i++){
    right.push_back(pos2[i]-x);
    rval.push_back(rval.back()+val2[i]);
  }

  ll ans=0;
  // cout<<left.size()<<endl;
  // cout<<right.size()<<endl;
  // for(auto i:lval)cout<<i<<" ";
  // cout<<endl;
  // for(auto i:right)cout<<i<<" ";
  // cout<<endl;

  // right to left
  for(ll i=0;i<right.size();i++){
    ll tpos=k;
    ll tval=rval[i+1];
    tpos-=right[i];
    if(tpos<0){
      break;
    }
    ans=max(ans,tval);
    tpos-=right[i];
    if(tpos<0 || left.size()==0){
      continue;
    }
    auto it=lower_bound(left.begin(),left.end(),tpos);
    ll tidx=distance(left.begin(),it);
    if(tpos<left[tidx])tidx--;
    if(tidx<0)continue;
    tval+=lval[tidx+1];
    ans=max(ans,tval);
  }

  // for(auto i:lval)cout<<i<<" ";
  // cout<<endl;
  // for(auto i:rval)cout<<i<<" ";
  // cout<<endl;

  // left to right
  for(ll i=0;i<left.size();i++){
    ll tpos=k;
    ll tval=lval[i+1];
    tpos-=left[i];
    if(tpos<0){
      break;
    }
    ans=max(ans,tval);
    tpos-=left[i];
    if(tpos<0 || right.size()==0){
      continue;
    }
    auto it=lower_bound(right.begin(),right.end(),tpos);
    ll tidx=distance(right.begin(),it);
    if(tpos<right[tidx])tidx--;
    if(tidx<0)continue;
    tval+=rval[tidx+1];
    ans=max(ans,tval);
  }
  
  // cout<<"hello";
  cout<<ans;
  return 0;
}


// N K X 
// A1 A2 … AN 
// B1 B2 … BN