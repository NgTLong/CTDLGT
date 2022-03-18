#include<bits/stdc++.h>
using namespace std;
int n,m;
bool chuaxet[1005];
vector<int> List[1005];

void induongdi(){
	stack<int> st;
	st.push(v);
	while(st.top()!=u){
		int t=st.top();
		st.push(truoc[t]);
	}
	while(!st.empty()){
		int t=st.top();
		st.pop();
		cout<<t<<" ";
	}
	cout<<endl;
}

main(){
	int t,u,x,y,i;
	cin>>t;
	while(t--){
		memset(chuaxet,true,sizeof(chuaxet));
		for(i=0;i<1005;i++) List[i].clear();
		cin>>n>>m>>u;
		for(i=1;i<=m;i++){
			cin>>x>>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		induongdi();
	}
}
