// Thuat toan Merge Sort
#include<bits/stdc++.h> 
using namespace std;
// hop nhat hai doan duoc sap 
void merge(int A[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; //so luong phan tu doan 1
    int n2 =  r - m; //so luong phan tu doan 2  
    //tao mang phu L[] va R[]
    int L[n1], R[n2];   
    //luu cac phan tu A[l], A[l+1]..A[m] vao L[]
    for (i = 0; i < n1; i++)     
        L[i] = A[l + i]; 
    //luu cac phan tu A[m+1], A[m+1]..A[r] vao R[]
    for (j = 0; j < n2; j++) 
        R[j] = A[m + 1+ j];   
    //Hop nhat vao doan A[l]...A[r]
    i = 0; // thiet lap vi tri cua L[] 
    j = 0; // thiet lap vi tri cua R[] 
    k = l; // xuat phat tu k=l 
    while (i < n1 && j < n2) { //lap neu dieu nay dung
        if (L[i] <= R[j]) {	//neu L[i]<=L[j]	
            A[k] = L[i];i++; //lay A[k] = L[i] va tang i
        } 
        else   { 
            A[k] = R[j]; j++; //lay A[k] = R[j] va tang j
        } 
        k++; //tang k
    }   
    //lay not cac phan tu con lai trong L[] hoac R[]
    while (i < n1) { //lap neu i<n1
        A[k] = L[i]; i++; k++; //lay A[k] = L[i] va tang i va k
    } 
    while (j < n2) { //lap neu j<n2
        A[k] = R[j]; j++; k++; //lay A[k] = R[j] va tang j va k
    } 
} 
  
// Thu tuc sap xep hoa nhap
void mergeSort(int A[], int l, int r) { 
    if (l < r)  { 
        int m = l+(r-l)/2; //lay m la phan tu o giua          
        mergeSort(A, l, m); //tri nua thu nhat
        mergeSort(A, m+1, r); //tri nua thu 2  
        merge(A, l, m, r); //hoa nhap hai nua
    } 
} 
// dua ra ket qua
void Result(int A[], int n) {     
    for (int i=0; i < n; i++) 
        cout<<A[i]<<" "; 
    cout<<endl; 
} 
// Test solution
int main() { 
	int *A, n, T; cin>>T;
	while(T--){
		cin>>n; A = new int[n];
		for(int i=0; i<n; i++) cin>>A[i];
		mergeSort(A,0,n-1); Result(A,n);
		delete A;
	}
} 
