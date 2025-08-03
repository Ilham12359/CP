#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll, ll>
#define endl '\n'

ll mod=998244353;
ll n,q;
vector<ll> vt;
vector<ll> seg;
ll left(ll idx){return 2*idx+1;}
ll right(ll idx){return 2*idx+2;}

ll que(ll l,ll r,ll idx=0,ll lo=0,ll hi=n-1){
  if(hi<l||lo>r)
    return 0;

  if(lo>=l&&hi<=r)
    return seg[idx];

  ll mid=lo+(hi-lo)/2;
  return que(l,r,left(idx),lo,mid)+que(l,r,right(idx),mid+1,hi);
}

ll update(ll pos,ll idx=0,ll lo=0,ll hi=n-1){
  if(lo==hi){
    return seg[idx]=vt[lo];
  }
  ll mid=lo+(hi-lo)/2;
  if(pos<=mid)
    update(pos,left(idx),lo,mid);
  else update(pos,right(idx),mid+1,hi);

  return seg[idx]=seg[left(idx)]+seg[right(idx)];
}

void solve() {
  cin>>n>>q;

  vt.resize(n,0);
  vector<ll> in(n);
  seg.resize(4*n,0);
  for(auto &e:in)
    cin>>e;

  vector<ll> ans(q);
  vector<vector<pll>> mp(n+1);
  for(ll i=0;i<q;i++){
    ll l,r;
    cin>>l>>r;
    --l;--r;
    mp[r].push_back({l,i});
  }

  vector<ll> last(n+1,-1);
  for(ll i=0;i<n;i++){
    ll cur=in[i];
    if(last[cur]!=-1){
      vt[last[cur]]--;
      update(last[cur]);
    }
    last[cur]=i;
    vt[i]++;
    update(i);

    for(auto &e:mp[i]){
      ll l=e.first,idx=e.second;
      ans[idx]=que(l,i);
    }
  }

  for(auto &e:ans)
    cout<<e<<endl;
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
