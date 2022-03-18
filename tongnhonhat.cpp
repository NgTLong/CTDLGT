#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,val;
	cin>>t;
	while(t--){
		vector<int>a;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>val;
			if(val!=0) a.push_back(val);
		}
		sort(a.begin(),a.end());
		long long x=0,y=0;
		for(int i=0;i<a.size();i++){
			if(i%2==0) x=10*x+a[i];
			else y=10*y+a[i];
		}
		cout<<x+y<<'\n';
	}
	return 0;
}
