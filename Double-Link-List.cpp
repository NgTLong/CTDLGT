#include<bits/stdc++.h>
using namespace std;
struct node {//Bieu dien node
    int info;
    struct node *next;
    struct node *prev;
}*start;
class double_llist {//Bieu dien lop
    public:
        void create_list(int value);//Tao node
        void add_begin(int value);//Them node vao dau
        void add_after(int value, int position);//Them node truoc pos
        void delete_element(int value);//Loai node
        void search_element(int value);//Tim node
        void display_dlist();//Hien thi danh sach
        void count();//Dem node
        void reverse();//Dao nguoc
        double_llist(){//Constructor
            start = NULL;  
        }
};
void double_llist::create_list(int value){//Khoi tao danh sach LK kep
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL){
        temp->prev = NULL;
        start = temp;
    }
    else {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
void double_llist::add_begin(int value){//Them node vao dau node
    if (start == NULL){
        cout<<"Danh sach rong."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Node da duoc them vao dau"<<endl;
}
void double_llist::add_after(int value, int pos){//Them node sau vi tri pos
    if (start == NULL){
        cout<<"Lan dau tao danh sach."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++) {//Chuyen den vi tri pos
        q = q->next;
        if (q == NULL) {
            cout<<"So node nho hon ";
            cout<<pos<<" phan tu."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL) {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else  {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Node da duoc chen"<<endl;
}
void double_llist::delete_element(int value){//Loai node kho danh sach
    struct node *tmp, *q;
     /*Loai node o dau*/
    if (start->info == value){
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Node dau tien da loai bo"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL) { //Di chuyen den node truoc  
        if (q->next->info == value){//Neu node truoc co gia tri value
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Node da loai bo"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->info == value){//Neu value la node cuoi cung 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Node cuoi cung bi loai bo"<<endl;
        return;
    }
    cout<<"Node  "<<value<<" khong ton tai"<<endl;
}
void double_llist::display_dlist(){//Hien thi danh sach
    struct node *q;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    q = start;
    cout<<"Noi dung danh sach lien ket kep :"<<endl;
    while (q != NULL){
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
void double_llist::count(){//Dem so node 	
    struct node *q = start;
    int cnt = 0;
    while (q != NULL){
        q = q->next;
        cnt++;
    }
    cout<<"So node: "<<cnt<<endl;
}
void double_llist::reverse(){//Dao nguoc danh sach
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"Danh sach da dao nguoc"<<endl; 
}
int main(){
    int choice, element, position;
    double_llist dl;
    while (1){
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Cac thao tac tren DSLK Kep"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Tao Node"<<endl;
        cout<<"2.Them node vao dau"<<endl;
        cout<<"3.Them node vao truoc"<<endl;
        cout<<"4.Loai bo node"<<endl;
        cout<<"5.Hien thi danh sach"<<endl;
        cout<<"6.Dem so node"<<endl;
        cout<<"7.Dao nguoc danh sach"<<endl;
        cout<<"8.Thoat"<<endl;
        cout<<"Lua chon chuc nang : ";
        cin>>choice;
        switch ( choice ){
            case 1:
                 cout<<"Nhap gia tri: ";cin>>element;
                 dl.create_list(element);
                 cout<<endl;
                 break;
            case 2:
                 cout<<"Nhap gia tri: ";cin>>element;
                 dl.add_begin(element);
                 cout<<endl;
                 break;
            case 3:
                 cout<<"Nhap gia tri: ";cin>>element;
                 cout<<"Chen sau vi tri: ";cin>>position;
                 dl.add_after(element, position);
                 cout<<endl;
                 break;
            case 4:
                 if (start == NULL){                      
                    cout<<"Danh sach rong"<<endl;   
                    break;
                 }
                 cout<<"Noi dung node can loai: ";cin>>element;
                 dl.delete_element(element);
                 cout<<endl;
                 break;
            case 5:
                 dl.display_dlist();
                 cout<<endl;
                 break;
            case 6:
                 dl.count();
                 break;    
            case 7:
                 if (start == NULL){
                    cout<<"Danh sach rong"<<endl;
                    break;
                 }
                 dl.reverse();cout<<endl;
                 break;
            case 8:
                 exit(1);
            default:
                    cout<<"Sai lua chon"<<endl;
                    break;
        }
    }
    return 0;
}
