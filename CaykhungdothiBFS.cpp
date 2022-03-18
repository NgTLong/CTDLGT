#include<bits/stdc++.h>
using namespace std;
vector<int> List[1005];
bool chuaxet[1005];
int n,m,u,v;
vector<pair<int,int> > ck;
void BFS(int u){
	queue<int>q;
	q.push(u);
	chuaxet[u] = false;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<List[x].size();i++){
		    int y = List[x][i];
		    if(chuaxet[y]){
		    	ck.push_back({x,y});
		    	q.push(y);
		    	chuaxet[y] = false;
			}
	}
	}
}
main(){
	int t,i,x,y;
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
		BFS(u);
		if(ck.size() != n-1) cout<<-1<<endl;
		else{
			for(i=0;i<ck.size();i++){
				cout<< ck[i].first << " " << ck[i].second << endl;
			}
		}
	}
}
