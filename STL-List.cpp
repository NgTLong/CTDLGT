#include <bits/stdc++.h>
using namespace std;
int main()
{
    int myints[] = {5, 6, 3, 2, 7};
    list<int> l, l1 (myints, myints + sizeof(myints) / sizeof(int));
    list<int>::iterator it;
    int choice, item;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"DANH SACH LIEN KET STL"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Them node vao dau"<<endl;
        cout<<"2.Them node vao cuoi"<<endl;
        cout<<"3.Loai node o dau"<<endl;
        cout<<"4.Loai node o cuoi"<<endl;
        cout<<"5.Phan tu dau DSLK"<<endl;
        cout<<"6.Phan tu cuoi DSLK"<<endl;
        cout<<"7.Kich co cua DSLK"<<endl;
        cout<<"8.Thay doi kich co DSLK"<<endl;
        cout<<"9.Loai node co gia tri value"<<endl;
        cout<<"10.Loai node trung nhau"<<endl;
        cout<<"11.Dao nguoc DSLK"<<endl;
        cout<<"12.Sap xep DSLK"<<endl;
        cout<<"13.Hop nhat Sorted DSLK"<<endl;
        cout<<"14.Duyet DSLK"<<endl;
        cout<<"15.Thoat"<<endl;
        cout<<"Dua vao lua chon: ";
        cin>>choice;
        switch(choice) {
        case 1:
            cout<<"Nhap gia tri node:: "; cin>>item;
            l.push_front(item); break;
        case 2:
            cout<<"Nhap gia tri node: "; cin>>item;
            l.push_back(item); break;
        case 3:
            item = l.front();//lay node dau tien
            l.pop_front();//laoi node dau tien
	    	cout<<"Node "<<item<<" bi loai"<<endl;
            break;
        case 4:
            item = l.back();//lay node cuoi cung
            l.pop_back();//loai node cuoi cung
	    	cout<<"Node "<<item<<" bi loai"<<endl;
            break;
        case 5:
	    	cout<<"Phan tu dau DSLK: ";
	    	cout<<l.front()<<endl; break;
        case 6:
            cout<<"Phan tu cuoi DSLK: ";
            cout<<l.back()<<endl; break;
        case 7:
            cout<<"Kich thuoc DSLK: "<<l.size()<<endl;
            break;
        case 8:
            cout<<"Dua vao so luong node: ";cin>>item;
            if (item <= l.size())
                l.resize(item);
            else
                l.resize(item, 0);
            break;
        case 9:
            cout<<"Phan tu can loai:"; cin>>item;
            l.remove(item); break;
        case 10:
            l.unique();//loai cac node giong nhau
            cout<<"Cac node giong nhau bi loai"<<endl;
            break;
        case 11:
            l.reverse();
            cout<<"Danh sach duoc dao nguoc"<<endl;
            break;
        case 12:
            l.sort();cout<<"DSLK da sap"<<endl;
            break;
        case 13:
            l1.sort();//sap L1
            l.sort();//sap L
            l.merge(l1);//hop nhat L va L1
            cout<<"Hai danh sach da hoa nhap"<<endl;
            break;
        case 14:
            cout<<"Duyet danh sach:  ";
            for (it = l.begin(); it != l.end(); it++)
                cout<<*it<<"  ";
            cout<<endl;
            break;
		case 15:
            exit(1);  break;
        default:
            cout<<"lua chon sai"<<endl;break;
        }
    }
    return 0;
}
