//Duong di cua con chuot trong me cung
//D:xuong duoi;L:dich trai;R:dich phai; U:len tren
#include <bits/stdc++.h> 
#define MAX 10
using namespace std; 
int N;//kich co me cung
int maze[MAX][MAX];//bieu dien me cung
bool sol[MAX][MAX];//trang thai cac o trong me cung
string S="";//ket qua 1 duong di
int dem; //so luong duong di
void Init(void)   {
	cin>>N; //nhap kich co me cung	
	dem =0; //so luong duong di
	for(int i=0; i<N;i++) {	//thiet lap me cung
		for(int j=0; j<N; j++) {		
			cin>>maze[i][j];//nhap gia tri cac o cua me cung
			sol[i][j] = false;//thiet lap trang thai cac o chua den
		}
	}
}
// kiem tra mot o co den duoc hay khong
bool isSafe(int x, int y) { 
	if(x>=0 && x<N && y>=0 && y<N && !sol[x][y] && maze[x][y]) 
		return true;  //neu den duoc
    return false; //neu khongden duoc
}   
// Dua ra tat ca cac duong di bang DFS(0,0)
void DFS(int x, int y) { 
    if (x == N - 1 && y == N - 1) {         
        cout<<S<<" ";  dem++;
    }       
    sol[x][y] = true; //ghi nhan o (i,j) da den
	if (isSafe(x + 1, y)) { //neu phep D duoc chap thuan        
		S = S+"D"; //cong them vao path ki tu D
        DFS(x + 1, y);//goi de qui bat dau tai o (i+1,j) 
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui		
    }       
    if (isSafe(x, y - 1)) { //neu phep L duoc chap thuan
        S = S+"L"; //them vao path ki tu L
        DFS(x, y - 1); //goi de qui bat dau tai o (i,j-1)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui                   
    }   
    if (isSafe(x, y + 1))  {//neu phep R duoc chap thuan 
        S = S+"R";; //them vao path ki tu R
        DFS(x, y + 1); //goi de qui bat dau tai o (i,j+1)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui		
    }     
    if (isSafe(x - 1, y)) { //neu phep U duoc chap thuan
        S = S+"U";; //them vao path ki tu U
        DFS(x - 1, y); //goi de qui bat dau tai o (i-1,j)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui               
    } 
    sol[x][y] = false; //hoan tra lai sol[x][y]
}   

// Test solution 
int main() { 
    int T, N; cin>>T; 
    while(T--){ 
    	Init();DFS(0,0);
    	if(dem==0) cout<<"-1";
    	cout<<endl;
	}	
} 

