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

  int n,m,k;cin>>n>>m>>k;
  set<int> st;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    st.insert(x);
  }

  int high=m+k;
  int ans=0;
  while(st.upper_bound(high)!=st.end()){
    ans++;
    int tmp=*st.upper_bound(high);
    st.erase(tmp);
    high=tmp+k;
  }

  cout<<ans;

  return 0;
}


// N M K
// A1 A2 … AN