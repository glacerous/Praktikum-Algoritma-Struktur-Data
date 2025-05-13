#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct barang {
    string nama, kode;
    int harga, stok;
    barang* next;
};

barang* head = nullptr;

void menu();
void inputdata();
void tampildata();
void hapusdata();
void tampilkantermurah();
void tampilkantermahal();

int main() {
    int pilih;
    char lanjut;
    do {
        menu();
        cin >> pilih;
        switch (pilih) {
            case 1:
                inputdata();
                break;
            case 2:
                tampildata();
                break;
            case 3:
                hapusdata();
                break;
            case 0:
                cout << "keluar dari program\n";
                exit(0);
            default:
                cout << "pilihan tidak valid \n";
        }
        cout << "kembali ke menu? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}

void menu() {
    cout << "\n===== SISTEM MANAJEMEN STOK GUDANG =====\n"
         << "1. Input stok barang\n"
         << "2. Lihat daftar stok\n"
         << "3. Hapus barang dari stok\n"
         << "0. Keluar\n"
         << "=========================================\n"
         << "Masukkan pilihan: ";
}

void inputdata() {
    int n;
    cout << "Jumlah barang yang akan ditambahkan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        barang* baru = new barang;
        cout << "\nbarang ke-" << i+1 << endl;
        cout << "Nama barang : "; getline(cin, baru->nama);
        cout << "Kode barang : "; getline(cin, baru->kode);
        cout << "Harga       : "; cin >> baru->harga;
        cout << "Jumlah stok : "; cin >> baru->stok;
        cin.ignore();
        baru->next = nullptr;

        if (!head) {
            head = baru;
        } else {
            barang* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = baru;
        }
    }
}

void tampildata() {
    if (!head) {
        cout << "Data kosong\n";
        return;
    }

    int pilihan;
    cout << "1. Urut termurah\n2. Urut termahal\nPilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        tampilkantermurah();
    } else if (pilihan == 2) {
        tampilkantermahal();
    } else {
        cout << "Pilihan tidak valid\n";
    }
}

void tampilkantermurah() {
    int count = 0;
    barang* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    barang** arr = new barang*[count];
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    // bubble sort dari termurah 
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->harga > arr[j + 1]->harga) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << left << setw(10) << "Kode" << setw(20) << "Nama barang" << setw(10) << "Harga" << setw(10) << "Stok" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << arr[i]->kode << setw(20) << arr[i]->nama << setw(10) << arr[i]->harga << setw(10) << arr[i]->stok << endl;
    }
    delete[] arr;
}

void tampilkantermahal() {
    int count = 0;
    barang* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    barang** arr = new barang*[count];
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    // Bubble sort dari termahal 
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->harga < arr[j + 1]->harga) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << left << setw(10) << "Kode" << setw(20) << "Nama barang" << setw(10) << "Harga" << setw(10) << "Stok" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << arr[i]->kode << setw(20) << arr[i]->nama << setw(10) << arr[i]->harga << setw(10) << arr[i]->stok << endl;
    }

    delete[] arr;
}



void hapusdata() {
    if (!head) {
        cout << "Data kosong!!!!!\n";
        return;
    }

    string nama;
    cout << "Masukkan nama barang yang ingin dihapus: ";
    cin.ignore();
    getline(cin, nama);

    barang* temp = head; // mulai dri barang pertama
    barang* prev = nullptr; // awal null karena blm maju
    while (temp) { // selama temp bkn null
        if (temp->nama == nama) { // dan jika nama dri barang saat ini sama dengan yg ingin dihapus
            if (!prev) { // penanganan khusus klo yg diapus barang pertama (head)
                head = temp->next; 
            } else {
                prev->next = temp->next; // barang sblmnya (prev) skrng lgsng loncat ke barang sesudah temp
            }
            delete temp;
            cout << "barang berhasil dihapus\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "barang tidak ditemukan\n";
}
