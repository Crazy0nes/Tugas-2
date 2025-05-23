#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node* next;
    Node* prev;
};

struct Node* buatnode(string data){
    // Node* newNode = new Node{data, NULL, NULL};
    Node* newNode = (Node*)malloc(sizeof(data));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev= NULL;
    return newNode;
}

void sisipnodedepan(Node** head, string data){

    Node* newNode = buatnode(data);
    newNode->next = *head;
    if(*head != NULL){

        (*head)->prev = newNode;

    }
    *head = newNode;
}

void sisipnodebelakang(Node** head, string data){

    Node* newNode = buatnode(data);
    if(*head == NULL){

        *head = newNode;
        return;

    }
    Node* bantu = *head;
    while(bantu->next != NULL){
        bantu = bantu->next;
    }
    bantu->next = newNode;
    newNode->prev = bantu;

}

Node* searching(Node* head, string key){

    Node* bantu = head;
    while(bantu != NULL){
        if(bantu->data == key){
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL;

}
void printdaridepan(Node* head){

    if(head == NULL){
        cout << "Node nya ga ada!" << endl;
    }
    Node* bantu = head;
    while(bantu != NULL){
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}


void hapusnodetengah(Node** head, string key){
    if(*head == NULL){
        cout << "List Kosong" << endl;
        return;
    }

    Node* bantu = *head;
    while(bantu != NULL && bantu->data != key){
        bantu = bantu ->next;
    }

    if(bantu == NULL){
        cout << "Node ga ketemu!" << endl;
        return;
    }
    
    if(bantu->prev != NULL){
        bantu->prev->next = bantu->next;
    }else{
        *head = bantu->next;
    }
    if(bantu->next != NULL){

        bantu->next->prev = bantu->prev;

    }
    free(bantu);

}


int main(){
    Node* head = NULL;
    bool retry = true;
    string judul;
    while(retry == true){
cout << "=== MENU MANAJEMEN DAFTAR BUKU ===" << endl;
cout << "1. Tambah Buku Di Depan" << endl;
cout << "2. Tambah Buku Di Belakang" << endl;
cout << "3. Hapus Buku berdasarkan Judul" << endl;
cout << "4. Tampilkan Daftar Buku" << endl;
cout << "5. Keluar" << endl;
cout << endl << endl;
cout << "Pilih Menu: ";
int pilihan;
cin >> pilihan;
if(pilihan < 1 || pilihan > 5){
    cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
    retry = true;
    continue;
}
switch (pilihan)
{
case 1:
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, judul);
    sisipnodedepan(&head, judul);
    cout << "Buku berhasil ditambahkan di depan" << endl;
    break; 

case 2:
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, judul);
    sisipnodebelakang(&head, judul);
    cout << "Buku berhasil ditambahkan di belakang" << endl;
    break; 

case 3:
    cout << "Masukkan Judul Buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, judul);
    hapusnodetengah(&head, judul);
    cout << "Buku berhasil dihapus" << endl;
    break; 

case 4:
    /* code */
    break; 

case 5:
    retry = false;
    cout << "Terima Kasih" << endl;
    break;

default:
    break;
}


} 

}