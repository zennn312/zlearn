#include <iostream>

using namespace std;

struct lagu{
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

lagu daftarlagu[100];
int jmlhlagu = 0;

void bubblesort(lagu array[], int n){
    for(int a = 0; a < n-1; a++){
        for(int b = 0; b < n-a-1; b++){
            if(array[b].judul > array[b+1].judul){
                swap(array[b], array[b+1]);
            }
        }
    }
}

void tampillagu(lagu array[], int n){
    cout << "Playlist Lagu" << endl;
    cout << "===================" << endl;
    for(int a = 0; a < n; a++){
        cout << a+1 << ". " << array[a].judul << " - " << array[a].penyanyi << endl;
    } cout << endl;
}

void carilagu(lagu array[], int n, string judul){
    bool search = false;
    for(int a = 0; a < n; a++){
        if(array[a].judul == judul){
            cout << "Lagu ditemukan!" << endl;
            cout << "Judul    : " << array[a].judul << endl;
            cout << "Penyanyi : " << array[a].penyanyi << endl;
            cout << "Genre    : " << array[a].genre << endl;
            cout << "Tahun    : " << array[a].tahun << endl;
            search = true;
            break;
        } 
    } if(!search) {
        cout << "Lagu tidak ditemukan!" << endl;
    }
}

void editlagu(lagu array[], int n, string judul){
    for(int a = 0; a < n; a++){
        if(array[a].judul == judul){
            cout << "Masukkan judul baru    : ";
            getline(cin, array[a].judul);
            cout << "Masukkan penyanyi baru : ";
            getline(cin, array[a].penyanyi);
            cout << "Masukkan genre baru    : ";
            getline(cin, array[a].genre);
            cout << "Masukkan tahun baru    : ";
            cin >> array[a].tahun; cin.ignore();
            cout << "Lagu berhasil diperbarui!" << endl;
            return;
        }
    } cout << "Lagu tidak ditemukan!" << endl;
}

void simpanfile() {
    FILE *outFile = fopen("list_lagu.dat", "wb");
    if (outFile != NULL) {
        fwrite(&jmlhlagu, sizeof(jmlhlagu), 1, outFile);
        fwrite(daftarlagu, sizeof(lagu), jmlhlagu, outFile);
        fclose(outFile);
        cout << "File berhasil ditambah!" << endl;
    } else {
        cout << "Gagal membuka file!" << endl;
    }
}

void muatfile() {
    FILE *inFile = fopen("list_lagu.dat", "rb");
    if (inFile != NULL) {
        fread(&jmlhlagu, sizeof(jmlhlagu), 1, inFile);
        fread(daftarlagu, sizeof(lagu), jmlhlagu, inFile);
        fclose(inFile);
        cout << "File berhasil dimuat!" << endl;
    } else {
        cout << "File tidak ditemukan!" << endl;
    }
}

int main(){

    int n = 0;
    lagu daftarlagu[100];
    int menu;
    string kembali;

    muatfile();
    
    
    do {
        cout << "Playlist Lagu" << endl;
        cout << "==============" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Edit Lagu" << endl;
        cout << "3. Tampilkan Lagu" << endl;
        cout << "4. Cari Lagu" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;
        cin.ignore();
        
        switch (menu){

            case 1 :
                cout << "========================" << endl;
                cout << "Masukkan jumlah lagu : ";
                cin >> n;
                cin.ignore();
                cout << "========================" << endl;
                for(int a = 0; a < n; a++){
                    cout << "Masukkan judul lagu  : ";
                    getline(cin,daftarlagu[a].judul);
                    cout << "Masukkan penyanyi    : ";
                    getline(cin,daftarlagu[a].penyanyi);
                    cout << "Masukkan genre lagu  : ";
                    getline(cin,daftarlagu[a].genre);
                    cout << "Masukkan tahun rilis : ";
                    cin >> daftarlagu[a].tahun;
                    cin.ignore();
                    cout << endl;
                }
                simpanfile();
                
            break;

            case 2 : {
                string judul;
                // cin.ignore();
                cout << "Masukkan lagu yang ingin diedit : ";
                getline(cin, judul);
                editlagu(daftarlagu, n, judul);
                simpanfile();
            
            break;}
                
            case 3 : {
                bubblesort(daftarlagu,n);
                tampillagu(daftarlagu,n);
            }
            break;
                
            case 4 : {
                cout << "========================" << endl;
                string judul;
                cout << "Masukkan judul lagu : ";
                getline(cin,judul);
                carilagu(daftarlagu,n,judul);
                cout << "========================" << endl;

            break;}
            
            case 5 : 
                cout << "==================="<< endl;
                cout << "Keluar dari program" << endl;
                cout << "==================="<< endl;
            break;
            
            default:
                cout << "Pilihan tidak valid" << endl;
            break;
        } 
        if(menu != 5) {
            do{
                cout << "Kembali ke menu (y/n): "; cin >> kembali;
                cin.ignore();
                cout << "========================" << endl;
                    if(kembali != "y" && kembali != "n"){
                        cout << "Input salah, silahkan ulangi!" << endl;                   
                    }
                } while (kembali != "y" && kembali != "n");      
            }
    } while (menu !=5 && kembali == "y");

    return 0;
}