#include <iostream>
using namespace std;

void menu();
void inputdata();
void tampildata();
void bubblesort();
void quicksort(int low, int high);
void sequentialsearch();

struct kendaraan{
    string plat;
    string jenis;
    string merk;
    string model;
    string nama_pemilik;
    int tahun_produksi;
}; 
    kendaraan datakendaraan[100];
    int jumlahkendaraan = 0;

int main() {
    int pilihan;
    do {
        menu();
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan){
            case 1:
                inputdata();
                break;
            case 2:
                tampildata();
                break;
            case 3:
                bubblesort();
                break;
            case 4:
                quicksort(0,jumlahkendaraan -1);
                break;
            case 5:
                sequentialsearch();
                break;
            case 6:
                cout << "keluar dari program" << endl;
                break;
            default:
                cout << "pilihan tidak valid" << endl;
        }
    } while (pilihan != 6);
    return 0;
}

void menu(){
    cout << "\n============================\n";
    cout << "        MENU PILIHAN        \n";
    cout << "============================\n";
    cout << "1. Input Data Kendaraan\n";
    cout << "2. Tampilkan Seluruh Data Kendaraan\n";
    cout << "3. Urutkan Data Kendaraan (Bubble Sort)\n";
    cout << "4. Urutkan Data Kendaraan (Quick Sort)\n";
    cout << "5. Cari Data Kendaraaan (Sequential Search)\n";
    cout << "6. Keluar\n";
    cout << "============================\n";    

}

void inputdata() {
    int tambah = 0;
    cout << "masukkan jumlah kendaraan yang ingin diinput: ";
    cin >> tambah;
    cin.ignore(); 

    if (tambah <= 0) {
        cout << "jumlah harus lebih dari 0" << endl;
        return;
    }

    if (jumlahkendaraan + tambah > 100) {
        cout << "jumlah max 100" << endl;
        return;
    }
    
    for (int i = jumlahkendaraan; i < jumlahkendaraan + tambah; i++) {
        cout << "\ndata kendaraan ke-" << (i + 1) << ":" << endl;
        
        cout << "plat kendaraan: ";
        getline(cin, datakendaraan[i].plat);

        cout << "jenis kendaraan: ";
        getline(cin, datakendaraan[i].jenis);

        cout << "merk kendaraan: ";
        getline(cin, datakendaraan[i].merk);

        cout << "model kendaraan: ";
        getline(cin, datakendaraan[i].model);

        cout << "Nama pemilik: ";
        getline(cin, datakendaraan[i].nama_pemilik);

        cout << "tahun produksi: ";
        cin >> datakendaraan[i].tahun_produksi;
        cin.ignore();
    }
    
    jumlahkendaraan += tambah;
}
void tampildata(){
    if (jumlahkendaraan == 0){
        cout << "data kosong\n";
        return;
    }
    cout << "\n list kendaraan\n";
    for (int i = 0; i < jumlahkendaraan; i++){
        cout << "\nkendaraan ke-" << (i + 1) << ":" << endl;
        cout << "Plat Kendaraan    : " << datakendaraan[i].plat << endl;
        cout << "Jenis Kendaraan   : " << datakendaraan[i].jenis << endl;
        cout << "Merk Kendaraan    : " << datakendaraan[i].merk << endl;
        cout << "Model Kendaraan   : " << datakendaraan[i].model << endl;
        cout << "Nama Pemilik      : " << datakendaraan[i].nama_pemilik << endl;
        cout << "Tahun Produksi    : " << datakendaraan[i].tahun_produksi << endl;
        cout << "------------------------------------" << endl;
    }
}

void bubblesort(){
    if (jumlahkendaraan == 0){
        cout << "data kosong" << endl;
        return;
    }
    for (int i = 0; i < jumlahkendaraan -1; i++){
        for (int j = 0; j < jumlahkendaraan - i - 1; j++){
            if (datakendaraan[j].tahun_produksi > datakendaraan[j+1].tahun_produksi){
                swap(datakendaraan[j], datakendaraan[j + 1]);
            }
        }
    } cout << "data telah diiurutkan bedasarkan tahun produksi";
}

void quicksort(int low,int high){
    if (jumlahkendaraan == 0){
        cout << "data kosong" << endl;
        return;
    }

    int awal = low, akhir = high;
    int pivot = datakendaraan[(low + high/2)].tahun_produksi;

    do {
        while (datakendaraan[low].tahun_produksi < pivot) low++;
        while (datakendaraan[high].tahun_produksi > pivot) high--;

        if (low <= high){
            swap(datakendaraan[low], datakendaraan[high]);
            low ++;
            high --;
        }
    } while (low <= high);

    if (awal < akhir) quicksort (awal,high);
    if (low < akhir) quicksort (low, akhir);

    cout << "data telah diiurutkan bedasarkan tahun produksi";
}

void sequentialsearch(){
    string cari;
    bool found = false;
    int i = 0;

    if (jumlahkendaraan == 0){
        cout << "data kosong " << endl;
        return;
    }

    cin.ignore();
    cout << "masukkan nama pemilik yang ingin dicari: "; 
    getline(cin, cari);

    while ((i < jumlahkendaraan) && !found){
        if (datakendaraan[i].nama_pemilik == cari){
            found = true;
        } else {
            i++;
        }
    }
    for (int i = 0; i < jumlahkendaraan; i++) {
        if (found){
        cout << "nama pemilik ditemukan:\n";
        cout << "\nkendaraan ke-" << (i + 1) << ":" << endl;
        cout << "Plat Kendaraan    : " << datakendaraan[i].plat << endl;
        cout << "Jenis Kendaraan   : " << datakendaraan[i].jenis << endl;
        cout << "Merk Kendaraan    : " << datakendaraan[i].merk << endl;
        cout << "Model Kendaraan   : " << datakendaraan[i].model << endl;
        cout << "Nama Pemilik      : " << datakendaraan[i].nama_pemilik << endl;
        cout << "Tahun Produksi    : " << datakendaraan[i].tahun_produksi << endl;
        cout << "------------------------------------" << endl;
    }
    }   
    if (found == false){
        cout << "nama pemilik dengan nama " << cari << " tidak ditemukan" ;
    }
}
