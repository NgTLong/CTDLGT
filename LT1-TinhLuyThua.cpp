#include<bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
long long powerMod(int a,long b){
	if (a==0 && b==0) return 0;
	if(b==0) return 1;
	long long x = powerMod(a,b/2);
	if(b%2==0) return x*x%M;
	return a*(x*x%M)%M;
}
main(){
	int t,a;
	long b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<powerMod(a,b)<<endl;
	}
}
