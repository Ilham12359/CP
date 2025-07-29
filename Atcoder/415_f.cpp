#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dt{
    ll val;
    char prefVal;
    ll prefLen;
    char suffVal;
    ll suffLen;
};

ll n,q;
vector<dt> seg;
string s;

ll left(ll idx){return 2*idx+1;}
ll right(ll idx){return 2*idx+2;}

void merge(dt &cur, dt &left, dt &right,ll &lo,ll &mid,ll &hi){
   // merge default
    cur.val=max(left.val,right .val);
    cur.prefLen=left.prefLen;
    cur.suffLen=right .suffLen;
    cur.prefVal=left.prefVal;
    cur.suffVal=right .suffVal;


    // special case
    // suff1==pref2
    if(left.suffVal==right .prefVal){
        cur.val=max(cur.val,left.suffLen+right .prefLen);

        // aaaa aabbb
        if(left.prefLen==(mid-lo+1))
            cur.prefLen=left.prefLen+right .prefLen;
        // bbaa aaaa
        if(right .prefLen==(hi-(mid+1)+1))
            cur.suffLen=left.suffLen+right .prefLen;
    }
}

void build(ll idx=0,ll lo=0,ll hi=n-1){
    if(lo==hi){
        seg[idx].val=1;
        seg[idx].suffLen=1;
        seg[idx].prefLen=1;
        seg[idx].prefVal=s[lo];
        seg[idx].suffVal=s[lo];
        return;
    }

    ll mid=lo+(hi-lo)/2;
    build(left(idx),lo,mid);
    build(right(idx),mid+1,hi);

    merge(seg[idx],seg[left(idx)],seg[right(idx)],lo,mid,hi);
}

dt que(ll l,ll r,ll idx=0,ll lo=0,ll hi=n-1){
    if(lo>r||hi<l)
        return {0,'0',0,'0',0};
    if(l<=lo&&hi<=r)
        return seg[idx];
    ll mid=lo+(hi-lo)/2;
    dt tleft=que(l,r,left(idx),lo,mid);
    dt tright=que(l,r,right(idx),mid+1,hi);

    if(tleft.val==0)
        return tright;
    if(tright.val==0)
        return tleft;

    dt cur;
    merge(cur,tleft,tright,lo,mid,hi);
    return cur;
}

void update(ll pos,ll idx=0,ll lo=0,ll hi=n-1){
    if(lo==hi){
        seg[idx].prefVal=s[pos];
        seg[idx].suffVal=s[pos];
        return;
    }
    ll mid=lo+(hi-lo)/2;

    if(pos<=mid)
        update(pos,left(idx),lo,mid);
    else update(pos,right(idx),mid+1,hi);

    merge(seg[idx],seg[left(idx)],seg[right(idx)],lo,mid,hi);
}

void solve() {
    cin>>n>>q>>s;

    seg.resize(4*n);
    build();

    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll pos;char c;
            cin>>pos>>c;
            s[pos-1]=c;
            update(pos-1);
        }else{
            ll l,r;
            cin>>l>>r;
            cout<<que(l-1,r-1).val<<endl;
        }
    }
}

int main() {

//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(NULL);
  cin.tie(0);

  ll t = 1;
//   cin >> t;

  while (t--) 
    solve();
}
