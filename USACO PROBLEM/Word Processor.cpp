#include <bits/stdc++.h>
using namespace std;
#define ll long long;
// #define endl '\n';
#define MOD 1e9+7;
#define run freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bismillah ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
  bismillah
  // run
  freopen("word.in","r",stdin);freopen("word.out","w",stdout);

  int n,m;cin>>n>>m;
  int sum=0;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    sum+=s.length();
    if(sum<=m){
      if(i)cout<<" ";
      cout<<s;
    }else{
      cout<<endl;
      cout<<s;
      sum=s.length();
    }
  }
  
}