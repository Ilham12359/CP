#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define endl '\n';
#define MOD 1e9+7;
#define run freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bismillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
  bismillah
  run
  // freopen("promote.in","r",stdin);freopen("promote.out","w",stdout);

  vector<int> vt;
  for(int i=0;i<7;i++)
  {
    int x;cin>>x;
    vt.push_back(x);
  }

  sort(vt.begin(),vt.end());

  cout<<vt[0]<<" "<<vt[1]<<" "<<vt[6]-(vt[0]+vt[1])<<endl;

  
}
