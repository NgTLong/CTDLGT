#include<iostream>
using namespace std;

int l[100001];
int doitien(int a[], int x){
    for (int i = 0; i <= x; i++) l[i] = 0;
    for (int i = 0; i < 10; i++) l[a[i]] = 1;
	for (int i = 1; i <= x; i++){
		for (int j = 0; j < 10; j++)
	        if (i >= a[j]){
                if ((l[i] > l[i-a[j]] + 1 && l[i-a[j]] != 0) || (l[i] == 0 && l[i-a[j]] != 0)){ 
                    l[i] = l[i-a[j]] + 1;
                }
	        }	
	}
	return l[x];	    
}

int main(){
	short t;
	cin>>t;
	while(t--){
		int x;
	    cin >> x;
	    int a[] = {1,2,5,10,20,50,100,200,500,1000};
	    cout << doitien(a, x)<<endl;
	}	
	return 0;
}
