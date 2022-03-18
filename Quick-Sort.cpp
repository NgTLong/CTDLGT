//thuat toan quick sort
#include <bits/stdc++.h>
using namespace std;     
//thu tuc phan mang thanh hai doan [nho hon][privot][lon hon]
int partition (int A[], int low, int high)  {  
    int pivot = A[high]; // khoa phan chia o vi tri high  
    int i = (low - 1); // vi tri phan tu nho hon  
    for (int j = low; j <= high - 1; j++) {  //duyet trong khoang [low, high-1]
        // If current element is smaller than the pivot  
        if (A[j] < pivot){ //neu phan tu hien tai nho hon khoa 
            i++; //tang chi so phan tu nho hon 
            swap(A[i], A[j]);//doi noi dung A[i] va A[j]
        }  
    }  
    swap(A[i + 1], A[high]);//doi noi dung A[i+] va A[high]  
    return (i + 1);//day la vi tri cua khoa  
}  
void quickSort(int A[], int low, int high) {  
    if (low < high) {  //neu can duoi be hon can tren
        int pi = partition(A, low, high); //chi mang thanh hai doan
        quickSort(A, low, pi - 1);  //quick sort nua thu nhat
        quickSort(A, pi + 1, high); //quick sort nua thu hai 
    }  
}    
// dua ra ket qua
void Result(int A[], int n)  {      
    for (int i = 0; i < n; i++)  
        cout << A[i] << " ";  
    cout << endl;  
}  
// Test solution 
int main()  {  
    int *A, n, T;  cin>>T;
    while(T--) {
    	cin>>n; A = new int[n];
    	for(int i=0; i<n; i++) cin>>A[i];
    	quickSort(A, 0, n-1);
    	Result(A,n); delete A;
	}
}  
