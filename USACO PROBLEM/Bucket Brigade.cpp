#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define endl '\n';
#define MOD 1e9+7;
#define run freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bismillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
  bismillah
  // run
  freopen("buckets.in","r",stdin);freopen("buckets.out","w",stdout);

  vector<string> grid(10);

  int bb,kb,bl,kl,br,kr;

  for(int i=0;i<10;i++){
    string s;cin>>s;
    grid.push_back(s);
    for(int j=0;j<10;j++)
      if(s[j]=='B'){
        bb=i;kb=j;
      }else if(s[j]=='L'){
        bl=i;kl=j;
      }else if(s[j]=='R'){
        br=i;kr=j;
      }
  }

  int ans=abs(bl-bb)+abs(kl-kb);
  if(bl==bb&&bl==br){
    if(kr>min(kl,kb)&&kr<max(kl,kb))ans+=2;
  }
  else if(kl==kb&&kl==kr){
    if(br>min(bl,bb)&&br<max(bl,bb))ans+=2;
  }
  cout<<ans-1<<endl;

  
}