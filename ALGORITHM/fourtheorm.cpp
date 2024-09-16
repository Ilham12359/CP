#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   
	long long x;          
	cin>>x;
	ll num=x;
	ll a=sqrt(x);
	for(ll sa=a;sa>=max(a-100,(ll)0);sa--){
		ll b=sqrt(x-(sa*sa));
		for(ll sb=b;sb>=max(b-100,(ll)0);sb--){
			ll c=sqrt(x-(sa*sa)-(sb*sb));
			for(ll sc=c;sc>=max(c-100,(ll)0);sc--){
				ll d=sqrt(x-(sa*sa)-(sb*sb)-(sc*sc));
				for(ll sd=d;sd>=max(d-100,(ll)0);sd--){
				ll tmp=(sa*sa)+(sb*sb)+(sc*sc)+(sd*sd);
				if(tmp==num){
					cout<<sa<<" "<<sb<<" "<<sc<<" "<<sd<<endl;
				}
				}
			}
		}
	}
    return 0;
}
                                                      