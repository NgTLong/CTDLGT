#include<iostream>
using namespace std;
struct node { //Bieu dien Node
    int info;
    struct node *next;
}*start;
class single_linked_list { //Bieu dien lop
    public:
        node* create_node(int);//Tao mot node
        void insert_begin(); //Them node vao dau
        void insert_pos(); //Them node vao vi tri cho truoc
        void insert_last(); //Them node vao cuoi
        void delete_pos(); //Loai node tai vi tri cho truoc
        void sort(); //Sap xep node
        void search(); //Tim kiem node
        void update(); //Cap nhat thong tin node
        void reverse(); //Dao nguoc danh sach
        void display(); //Hien thi danh sach
        single_linked_list(){//Constructor
            start = NULL;
        }
};
node *single_linked_list::create_node(int value){
    struct node *temp; //Khai bao hai con tro *temp
    temp = new(struct node); //Cap phat bo nho cho temp
    if (temp == NULL){ //Neu khong gian nho day
        cout<<"Khong du bo nho de cao phat"<<endl;
        return NULL;
    }
    else {
        temp->info = value;//Thiet lap thanh phan thong tin
        temp->next = NULL; //Thiet lap thanh phan lien ket    
        return temp;//Tra lai ket qua
    }
}
void single_linked_list::insert_begin(){ //Chen node vao dau
    int value;
    cout<<"Nhap gia tri node:"; cin>>value;
    struct node *temp, *p;
    temp = create_node(value);//Tao node can them
    if (start == NULL){//Neu danh sach rong
        start = temp;
        start->next = NULL;          
    } 
    else {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Hoan thanh them node vao dau"<<endl;
}
 
/*
 * Inserting Node at last
 */
void single_linked_list::insert_last(){//Them node vao cuoi
    int value;
    cout<<"Nhap gia tri cho node: ";cin>>value;
    struct node *temp, *s;
    temp = create_node(value);//Tao node moi
    if(start==NULL){
    	start =temp;
    	start ->next =NULL;
   		return;
	}	
    s = start;
    while (s->next != NULL){ //Di chuyen den node cuoi cung         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp; //Thiet lap lien ket cho node
    cout<<"Hoan thanh them node vao cuoi"<<endl;  
}
void single_linked_list::insert_pos(){//Them node vao vi tri cho truoc
    int value, pos, counter = 0; 
    cout<<"Nhap gia tri node:";cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);//Tao node
    cout<<"Vi tri node can them: ";cin>>pos;
    int i; s = start; 
    while (s != NULL){
        s = s->next; counter++;
    }
    if (pos == 1){ //Neu vi tri dau tien
        if (start == NULL){//Neu danh sach rong
            start = temp;
            start->next = NULL;
        }
        else {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter){
        s = start;
        for (i = 1; i < pos; i++){//Di chuyen den vi tri pos
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;//Thiet lap lien ket cho node
        temp->next = s;
    }
    else {
        cout<<"Vuot qua gioi han danh sach"<<endl;
    }
}
void single_linked_list::sort(){//Sap xep cac node
    struct node *ptr, *s;
    int value;
    if (start == NULL){//Neu danh sach rong
        cout<<"Khong phai lam gi"<<endl;
        return;
    }
    ptr = start;//ptr tro den dau danh sach
    while (ptr != NULL){ //Bat dau sap xep
        for (s = ptr->next;s !=NULL;s = s->next){
            if (ptr->info > s->info){
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}
void single_linked_list::delete_pos(){//Loai phan tu o vi tri cho truoc
    int pos, i, counter = 0;
    if (start == NULL){ //Neu danh sach rong
        cout<<"Khong the thuc hien"<<endl;
        return;
    }
    cout<<"Vi tri can loai bo:";cin>>pos;
    struct node *s, *ptr;
    s = start; //s tro den dau danh sach
    if (pos == 1){ //Neu la node dau tien
        start = s->next;
    }
    else {
        while (s != NULL) {//Dem so  node cua danh sach
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter){ //Neu vi tri trong danh sach
            s = start;
            for (i = 1;i < pos;i++){ //Chuyen den Pos
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next; //Thiet lap lien ket cho node
        }
        else {
            cout<<"Vi tri ngoai danh sach"<<endl;
        }
        delete s;
        cout<<"Node da bi loai bo"<<endl;
    }
}
void single_linked_list::update(){//Sua doi thong tin node
    int value, pos, i;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    cout<<"Vi tri node can sua doi:";cin>>pos;
    cout<<"Gia tri moi cua node:";cin>>value;
    struct node *s, *ptr;
    s = start; //s tro den node dau tien
    if (pos == 1){//Neu la node dau tien
        start->info = value; //Cap nhat node
    }
    else {
        for (i = 0;i < pos - 1;i++){//Chyen den node pos
            if (s == NULL){//Neu node rong
                cout<<"Vi tri "<<pos<<" khong hop le";
                return;
            }
            s = s->next;
        }
        s->info = value;  //Cap nhat thong tin node
    }
    cout<<"Sua doi thanh cong"<<endl;
} 
void single_linked_list::search(){//Tim kiem node
    int value, pos = 0;
    bool flag = false;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    cout<<"Gia tri can tim:";cin>>value;
    struct node *s; s = start;//s tro den dau danh sach
    while (s != NULL){ pos++;
        if (s->info == value){//Neu s->infor la value
            flag = true;
            cout<<"Gia tri "<<value<<" tai vi tri "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Gia tri "<<value<<" khong ton tai trong danh sach"<<endl;  
}
void single_linked_list::reverse(){//Dao nguoc danh sach
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL) {//Neu danh sach rong
        cout<<"Danh sach rong"<<endl;
        return;
    }
    if (start->next == NULL){//Neu chi co mot node
        return;
    }  
    ptr1 = start; //ptr1 tro den node dau tien
    ptr2 = ptr1->next;//ptr2 tro den node ke tiep
    ptr3 = ptr2->next;//ptr3 tro den node ke tiep ptr2
    ptr1->next = NULL;//Ngat lien ket ptr1
    ptr2->next = ptr1;//Thiet lap lien ket cho ptr2
    while (ptr3 != NULL){//Lap neu ptr3 khong rong
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
void single_linked_list::display(){//Hien thi danh sach
    struct node *temp;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    temp = start;
    cout<<"Noi dung danh sach: "<<endl;
    while (temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
main(){//Chuon trinh chinh
    int choice;
    single_linked_list X;//X la doi tuong DSLKD 
	start = NULL;
    while (1){
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Thao tac tren danh sach lien ket don"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Them node vao dau danh sach"<<endl;
        cout<<"2.Them node vao cuoi danh sach"<<endl;
        cout<<"3.Them node vao node hien tai"<<endl;
        cout<<"4.Sap xep cac node cua danh sach"<<endl;
        cout<<"5.Loai node o vi tri xac dinh"<<endl;
        cout<<"6.Sua doi noi dung node"<<endl;
        cout<<"7.Tim kiem node theo gia tri"<<endl;
        cout<<"8.Hien thi no dung danh sach"<<endl;
        cout<<"9.Dao nguoc danh sach "<<endl;
        cout<<"10.Thoat "<<endl;
        cout<<"Lua cho chuc nang: "; cin>>choice;
        switch(choice){
            case 1:
                 cout<<"Chen node vao dau: "<<endl;
                 X.insert_begin();cout<<endl;
                 break;
            case 2:
                 cout<<"Chen node vao cuoi: "<<endl;
                 X.insert_last();cout<<endl;
                 break;
            case 3:
                 cout<<"Chen node tai vi tri xac dinh:"<<endl;
                 X.insert_pos();cout<<endl;
                 break;
            case 4:
                 cout<<"Sap xep danh sach: "<<endl;
                 X.sort();cout<<endl;
                 break;
            case 5:
                 cout<<"Loai bo node tai vi tri: "<<endl;
                 X.delete_pos();
                 break;
            case 6:
                 cout<<"Sua doi gia tri node:"<<endl;  
                 X.update();cout<<endl;
                 break;
            case 7:
                 cout<<"Tim kiem node: "<<endl;
                 X.search();cout<<endl;
                 break;
            case 8:
                 cout<<"Danh sach duoc hien thi:"<<endl;
                 X.display();cout<<endl;
                 break;
            case 9:
                 cout<<"Dao nguoc danh sach"<<endl;
                 X.reverse();cout<<endl;
                 break;
            case 10:
                 cout<<"Thoat..."<<endl;
                 exit(1);
                 break;  
            default:
                 cout<<"Lua chon sai"<<endl;
        }
    }
}
