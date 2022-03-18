#include<bits/stdc++.h>
using namespace std;

int M = 123456789;
long long powerMod(int n,long long k){
	if (k==0) return 1;
	long long x = powerMod(n,k/2);
	if(k%2==0) return x*x%M;
	return n*(x*x%M)%M;
}
main(){
	int t;
	cin>>t;
	long long n;
	while(t--){
		cin>>n;
		cout<<powerMod(2,n-1)<<endl;
	}
}
