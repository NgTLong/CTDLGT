#include<bits/stdc++.h>
using namespace std;

void xuly(int a[], int n){
	int i, R[n];
	stack<int> st;
	for(i=n-1;i>=0;i--){
		while(!st.empty() && st.top() <= a[i]) st.pop();
		if(st.empty()) R[i] = -1;
		else R[i] = st.top();
		st.push(a[i]);
	}
	for(i=0;i<n;i++) cout<<R[i]<<" ";
	cout<<endl;
}
main(){
	int t,n,a[100005],i;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++) cin>>a[i];
		xuly(a,n);
	}
}
