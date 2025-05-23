#include <iostream>
using namespace std;

struct buku
{
    string judul;
    string penulis;
    buku *next;
    buku *prev;
};

buku *buatNode(string judul, string penulis)
{
    buku *bukuBaru = new buku;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->next = NULL;
    bukuBaru->prev = NULL;
    return bukuBaru;
}

void tambahDepan(buku **head, buku **tail, string judul, string penulis)
{
    buku *bukuBaru = buatNode(judul, penulis);

    bukuBaru->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = bukuBaru;
    }
    else
    {
        *tail = bukuBaru;
    }

    *head = bukuBaru;
}

void tambahBelakang(buku **head, buku **tail, string judul, string penulis)
{
    buku *bukuBaru = buatNode(judul, penulis);

    bukuBaru->prev = *tail;
    if (*tail != NULL)
    {
        (*tail)->next = bukuBaru;
    }
    else
    {
        *head = bukuBaru;
    }

    *tail = bukuBaru;
}

void tampil(buku *head)
{
    if (head == NULL)
    {
        cout << "Daftar buku masih kosong\n";
        return;
    }
    buku *bantu = head;
    cout << "========= DAFTAR BUKU =========\n";

    while (bantu != NULL)
    {
        cout << "Judul   : " << bantu->judul << endl;
        cout << "Penulis : " << bantu->penulis << endl;
        cout << "==============================\n";
        bantu = bantu->next;
    }
}

void hapus(buku **head, buku **tail, string jdlcari)
{
    if (*head == NULL)
    {
        cout << "Daftar buku masih kosong\n";
        cout << "==============================\n";
        return;
    }
    buku *bantu = *head;
    while (bantu != NULL && bantu->judul != jdlcari)
    {
        bantu = bantu->next;
    }
    if (bantu == NULL)
    {
        cout << "Buku dengan judul " << jdlcari << " tidak ditemukan\n";
        cout << "==============================\n";
        return;
    }

    if (bantu->prev != NULL)
    {
        bantu->prev->next = bantu->next;
    }
    else
    {
        *head = bantu->next;
    }

    if (bantu->next != NULL)
    {
        bantu->next->prev = bantu->prev;
    }
    else
    {
        *tail = bantu->prev;
    }

    delete bantu;
    cout << "Buku dengan judul " << jdlcari << " barhasil dihapus\n";
    cout << "==============================\n";
}

int main()
{

    buku *head = NULL;
    buku *tail = NULL;
    int pilih;
    string judul, penulis;

    do
    {
        cout << "\n============ MENU ===========\n";
        cout << "1. Tambah Buku di Depan\n";
        cout << "2. Tambah Buku di Belakang\n";
        cout << "3. Hapus Buku berdasarkan Judul\n";
        cout << "4. Tampilkan Daftar Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilih;
        cin.ignore();
        cout << "=============================\n";

        switch (pilih)
        {
        case 1:
            cout << "Masukkan Judul Buku   : ";
            getline(cin, judul);
            cout << "Masukkan Penulis Buku : ";
            getline(cin, penulis);
            tambahDepan(&head, &tail, judul, penulis);
            cout << "Buku berhasil ditambahkan di depan!\n";
            cout << "=============================\n";
            break;

        case 2:
            cout << "Masukkan Judul Buku   : ";
            getline(cin, judul);
            cout << "Masukkan Penulis Buku : ";
            getline(cin, penulis);
            tambahBelakang(&head, &tail, judul, penulis);
            cout << "Buku berhasil ditambahkan di belakang!\n";
            cout << "=============================\n";
            break;

        case 3:
            cout << "Masukkan Judul Buku yang ingin dihapus: ";
            getline(cin, judul);
            hapus(&head, &tail, judul);
            break;

        case 4:
            tampil(head);
            cout << endl;
            break;

        case 5:
            break;

        default:
            cout << "Pilihan tidak valid. Silakan coba lagi!\n";
            cout << "=============================\n";
            break;
        }

    } while (pilih != 5);

    return 0;
}