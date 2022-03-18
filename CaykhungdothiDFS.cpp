#include<bits/stdc++.h>
using namespace std;
bool chuaxet[1005];
vector<int> List[1005];
vector<pair<int,int> > ck;

void DFS(int u){
	chuaxet[u] = false;
	for(int i=0;i<List[u].size();i++){
		int v = List[u][i];
		if(chuaxet[v]){
			ck.push_back({u,v});
			DFS(v);
		}
	}
}

main(){
	int t,n,m,u,x,y,i;
	cin>>t;
	while(t--){
		memset(chuaxet,true,sizeof(chuaxet));
		for(i=0;i<1005;i++) List[i].clear();
		ck.clear();
		cin>>n>>m>>u;
		for(i=1;i<=m;i++){
			cin>>x>>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		DFS(u);
		if(ck.size() != n-1) cout << -1 << endl;
		else{
			for(i=0;i<ck.size();i++){
			cout<<ck[i].first<<" "<<ck[i].second<<endl;
		}		
		}
	}
}
