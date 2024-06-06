#include <iostream>
using namespace std;

typedef struct node *address;
struct node{
    address prev;
    int data;
    address next;
};

address first,last=NULL;

address alokasi (int datanya){
    address hasil=new node;
    hasil->data= datanya;
    hasil->next= hasil->prev=NULL;
    return hasil;
}

void InsertFirst(address baru){
    if (first == NULL){
        first = last = baru;
    }else{
        baru->next=first;
        first->prev=baru;
        first=baru;
    }
}

void insertLast (address baru){
    if (last == NULL){
        first = last = baru;
    }else{
        last->next=baru;
        baru->prev=last;
        last=baru;
    }
}

void deleteFirst(){
    if(first==NULL){
        cout<<"Daftar buku kosong"<<endl;
        return;
    }
    first = first->next;
    delete first->prev;
    first->prev=NULL;
}

void deleteLast(){
    if (first==NULL){
        cout<<"Daftar buku kosong"<<endl;
        return;
    }
    last= last->prev;
    delete last->next;
    last->next==NULL;
}

void cetak(){
    address p=first;
    while (p!=NULL){
        cout<<"ID Buku:"<<p->data<<endl;
        p=p->next;
    }
}

int main(){
    InsertFirst(alokasi(10));
    InsertFirst(alokasi(30));
    InsertFirst(alokasi(50));
    InsertFirst(alokasi(19));
    InsertFirst(alokasi(90));
    InsertFirst(alokasi(27));
    InsertFirst(alokasi(11));
    cetak();

    cout<<"\nDaftar buku setelah penghapusan:"<<endl;
    cetak();
    return 0;
}
