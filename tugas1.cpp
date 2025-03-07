#include <iostream>
#include <string>
using namespace std;

struct lagu{
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

void bubblesort(lagu array[], int n){
    for(int a = 0; a < n-1; a++){
        for(int b = 0; b < n-a-1; b++){
            if(array[b].judul > array[b+1].judul){
                swap(array[b], array[b+1]);
            }
        }
    }
}

void printarray(lagu array[], int n){
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

int main(){

    int n;
    lagu daftarlagu[5];
    int menu;
    string kembali;

    
    do {
        cout << "Playlist Lagu" << endl;
        cout << "==============" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Cari Lagu" << endl;
        cout << "3. Keluar" << endl;
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
                bubblesort(daftarlagu,n);
                printarray(daftarlagu,n);
            break;
                
            case 2 : {
                cout << "========================" << endl;
                string judul;
                cout << "Masukkan judul lagu : ";
                getline(cin,judul);
                carilagu(daftarlagu,n,judul);
                cout << "========================" << endl;

            break;}
            
            case 3 : 
                cout << "==================="<< endl;
                cout << "Keluar dari program" << endl;
                cout << "==================="<< endl;
            break;
            
            default:
                cout << "Pilihan tidak valid" << endl;
            break;
        } 
        if(menu != 3) {
            do{
                cout << "Kembali ke menu (y/n): "; cin >> kembali;
                cin.ignore();
                cout << "========================" << endl;
                    if(kembali != "y" && kembali != "n"){
                        cout << "Input salah, silahkan ulangi!" << endl;                   
                    }
                } while (kembali != "y" && kembali != "n");      
            }
    } while (menu !=3 && kembali == "y");

    return 0;
}