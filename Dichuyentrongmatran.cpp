#include<bits/stdc++.h>
using namespace std;

int A[1001][1001], C[1001][1001],N,M;

void xuly(){
	int i,j,x;
	memset(C,-1,sizeof(C));
	queue<pair<int,int> > Q;
	Q.push({1,1});
	C[1][1] = 0;
	while(!Q.empty()){
		pair<int,int> t= Q.front();
		i = t.first;
		j = t.second;
		x = A[i][j];
		Q.pop();
		if(C[i][j+x] == -1){
			Q.push({i,j+x});
			C[i][j+x] = C[i][j] + 1;
		}
		if(C[i+x][j] == -1){
			Q.push({i+x,j});
			C[i+x][j] = C[i][j] + 1;
		}
		if(C[N][M]!=-1) break;
	}
	cout<<C[N][M]<<endl;
}
main(){
	int t,i,j;
	cin>>t;
	while(t--){
		cin>>N>>M;
		memset(A,0,sizeof(A));
		for(i=1;i<=N;i++){
			for(j=1;j<=M;j++){
				cin>>A[i][j];
			}
		}
		xuly();
	}
}
