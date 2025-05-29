#include <iostream>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    Buku* prev;
    Buku* next;
};

Buku* head = nullptr;
Buku* tail = nullptr;

Buku* buatNode(string judul, string penulis) {
    Buku* baru = new Buku;
    baru->judul = judul;
    baru->penulis = penulis;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}

void Sisipnodedepan(string judul, string penulis) {
    Buku* baru = buatNode(judul, penulis);
    if (!head) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void Sisipnodebelakang(string judul, string penulis) {
    Buku* baru = buatNode(judul, penulis);
    if (!tail) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void printdaridepan() {
    if (!head) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    Buku* temp = head;
    while (temp) {
        cout << "=> Judul: " << temp->judul << " || Penulis: " << temp->penulis << endl;
        temp = temp->next;
    }
}

void hapusnodetengah(string judul) {
    if (!head) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    Buku* temp = head;
    while (temp && temp->judul != judul) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Buku tidak ditemukan.\n";
        return;
    }

    if (temp == head && temp == tail) {
        head = tail = nullptr;
    } else if (temp == head) {
        head = head->next;
        if (head) head->prev = nullptr;
    } else if (temp == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
}



int main(){
    Buku* head = nullptr;
    Buku* tail = nullptr;
    bool retry = true;
    string judul,penulis;
    while(retry == true){
        system("cls");
cout << "=== MENU MANAJEMEN DAFTAR BUKU ===" << endl;
cout << "1. Tambah Buku Di Depan" << endl;
cout << "2. Tambah Buku Di Belakang" << endl;
cout << "3. Hapus Buku berdasarkan Judul" << endl;
cout << "4. Tampilkan Daftar Buku" << endl;
cout << "5. Keluar" << endl;
cout << "Pilih Menu: ";
int pilihan;
cin >> pilihan;
if(pilihan < 1 || pilihan > 5){
    cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
    system("pause");
    retry = true;
    continue;
}
switch (pilihan)
{
case 1:
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, judul);
    cout << "Masukkan Penulis Buku: ";
    getline(cin, penulis);
    Sisipnodedepan(judul, penulis);
    cout << "Buku berhasil ditambahkan di depan" << endl;
    retry = true;
    system("pause");
    break; 

case 2:
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, judul);
    cout << "Masukkan Penulis Buku: ";
    getline(cin, penulis);
    Sisipnodebelakang(judul, penulis);
    cout << "Buku berhasil ditambahkan di belakang" << endl;
    retry = true;
    system("pause");
    break; 

case 3:
    cout << "Masukkan Judul Buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, judul);
    hapusnodetengah(judul);
    cout << "Buku berhasil dihapus" << endl;
    retry = true;
    system("pause");
    break; 

case 4:
cout << endl;
    cout << "Daftar Buku: " << endl;
    printdaridepan();
    retry = true;
    system("pause");
    break; 

case 5:
    retry = false;
    cout << "Terima Kasih" << endl;
    system("pause");
    break;

default:
    break;
}


} 

}