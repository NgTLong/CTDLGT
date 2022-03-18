#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		string s;
		cin>>k>>s;
		int d[300]={0};
		int max=0;
		for(int i=0;i<s.size();i++){
			d[s[i]]++;
			if(max<d[s[i]]) max = d[s[i]];
		}
		if((max-1)*(k-1) > s.size()-max) cout<<-1;
		else cout<<1;
		cout<<endl;
	}
	return 0;
}
