#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long Max=0;
		int n;
		cin>>n;
		long long a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++){
			Max += a[i]*i;
			Max%=mod;
		}
		cout<<Max<<'\n';
	}
	return 0;
}
