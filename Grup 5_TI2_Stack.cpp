#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

// Mendeklarasikan terlebih dahulu variabel yang dibutuhkan
int data[10];            // mendeklarasikan jumlah nilai yang bisa dimasukkan dengan array
const int MAX = 9;        // Menentukan batas nilai yang dimasukkan
int top = -1;            // mendeklarasikan -1 untuk mengawali bahwa stack masih kosong
int count = -1;           

// Mendeklarasikan node dan pointer - pointer yang dibutuhkan
struct node{
    int data;
    node* next;
};
node *n, *temp;
node *head = NULL;
node *tail = NULL;

/* =================================================== MENGGUNAKAN ARRAY ===========================================*/
// mendeklarasikan kondisi jika stack sudah penuh
bool isFullA(){
    if(top == MAX){
        return true;
    }
    else{
        return false;
    }
}

// mendeklarasikan kondisi jika stack masih kosong
bool isEmptyA(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

// fungsi untuk menambah nilai pada stack
void pusharray(int n){
    if(isFullA()){                        // mengecek apakah stack penuh?
        cout << "\nStack penuh\n";
    }
    else{
        top++;                            // Menambah nilai di stack jika tidak penuh
        data[top] = n;
    }
}

// fungsi mengeluarkan nilai pada stack
void poparray(){
    if(isEmptyA()){                            // Menegecek  apakah stack masih kosong?
        cout << "\nData masih kosong\n";
    }
    else{
        cout << "\nbagian yang dikeluarkan adalah " << data[top] << " pada bagian data[" << top << "]\n";    // Mengeluarkan nilai pada stack
    }
}

// fungsi membaca nilai yang ada pada stack
void readarray(){
    int i = top;
    if(isEmptyA()){                                // mengecek apakah stack masih kosong?
        cout << "\n Data masih kosong \n";
    }
    else{
        cout << "\nData stack  = \n";
        while(i >= 0){                                                   
            cout << setw(2) << data[i] << "\n" << setw(3) << "|\n";                // menampilan nilai pada stack dengan membaca dari atas
            i--;
        }
        cout << "head\n";
    }
}

// fungsi menghapus semua nilai pada array
void cleararray(){
    top = -1;                // mengganti top menjadi -1 sehingga dianggap tidak ada nilai pada stack
}

/* ===================================================================== MENGGUNAKAN LINKED LIST ================================ */
// Fungsi untuk memeriksa stack kosong
bool isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

// memeriksa stack sudah penuh
bool isFull(){
    if(count == MAX){
        return true;
    }
    else{
        return false;
    }
}


// Fungsi menambahkan nilai pada stack
void push(int data){
    if(isFull()){                    // memanggil fungsi pengecekkan stack sudah penuh atau belum
        cout << "Stack penuh";
    }
    else{
        if(head == NULL){                // jika head = null maka data pertama yang dimasukkan menjadi head / nilai awal yang masuk
            n = new node;
            n->data = data;
            n->next = NULL;
            head = n;
            tail = head;
        }
        else{
            n = new node;            // jika sudah ada angka maka nilai berada di atas angka terakhir masuk / nilai yang paling atas pada stack
            n->data = data;
            tail->next = n;
            tail = n;
            n->next = NULL;
        }
    }
}

// fungsi menghapus
void pop(){
    if(isEmpty()){                                        // memanggil fungsi pengecekkan stack masih kosong
        cout << "\nBelum ada data yang dimasukkan\n";
    }
    else{
        cout << "\nData yang dikeluarkan adalah =\n";       
        cout << tail->data;                                // nilai yang paling atas pada stack di hapus dengan memindahkan pointer tail
    }
}

// Fungsi menghapus semua nilai pada stack
void clear(){                                           
    if(head == NULL){                                        // jika head = null belum ada yang dimasukkan
        cout <<"\nBelum ada data yang dimasukkan\n";
    }
    head = NULL;                                            // mengubah / menjadikan head = NULL sehingga memotong semua pointer dan menghapus semua hubungan
    cout << "\nData sudah dihapus\n";                        // nilai pada stack
}

// Fungsi menampilkan nilai stack
void read(){
    if(isEmpty()){                                            // Memanggil fungsi pengecekkan apakah stack kosong?
        cout << "\nBelum ada data yang dimasukkan\n";
    }
    else{
        temp = head;                                                // menjadikan letak temp di head terlebih dahulu
        cout << "\nData yang ada pada stack adalah = " << endl;
        while (temp!=NULL){                                            // memberikan kondisi jika temp selanjutnya tidak sama dengan null
            cout << temp->data << "->";                                // maka temp menghubung ke nilai selanjutnya dan menampilkan nilainya
            temp = temp->next;                                        // memindahkan temp ke nilai selanjutnya
            }
        cout << "Top" << endl;
    }
}

// mendeklarasikan fungsi
void menu();
void stackarray();
void stacklist();

int main(){
    menu();
}

// Fungsi untuk pilihan pada menu stack mengguanakan array
void stackarray(){
    char ulang,pilihan;
    int data;
    do{
        system("cls");
        cout << "----  Program Stack Array  ----\n";
        cout<<"\nMenu : \n"<<endl;
        cout<<"1. Push "<<endl;
        cout<<"2. Pop "<<endl;
        cout<<"3. Clear "<<endl;
        cout<<"4. Read "<<endl;
        cout<<"5. kembali ke menu"<<endl;
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                cout << "\nMasukkan data = "; cin >> data;
                pusharray(data);
                break;
            case '2' :
                poparray();
                break;
              case '3' :
                cleararray();
                break;
              case '4' :
                readarray();
            case '5' :
                menu();
                break;              
              default :
                cout<<"\nPilih ulang"<<endl;
              }
             
          cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
    }   
    while(ulang=='y' || ulang=='Y');
}

// Fungsi untuk pilihan pada stack menggunakan linked list
void stacklist(){
    char ulang,pilihan;
    int data;
    do{
        system("cls");
        cout << "----  Program Stack Linked List  ----\n";
        cout<<"\nMenu : \n"<<endl;
        cout<<"1. Push "<<endl;
        cout<<"2. Pop "<<endl;
        cout<<"3. Delete "<<endl;
        cout<<"4. Read "<<endl;
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                cout << "\nMasukkan data = "; cin >> data;
                push(data);
                break;
            case '2' :
                pop();
                break;
              case '3' :
                clear();
                break;
              case '4' :
                read();
                break;
            default :
                cout<<"\nPilih ulang"<<endl;
              }
             
          cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
    }   
    while(ulang=='y' || ulang=='Y');
}

// Fungsi menu pertama kali yang muncul pada porgram
// fungsi untuk user memilih stack menggunakan array atau linked list
void menu(){
    char ulang, pilihan;
    int data;
    do{
        system("cls");
        cout << "Grup 5 = Huda Izzatul Haq                   0110217069"<< endl;
        cout << "         Fatkhurrahmana Jundi Binauf        0110217071"<< endl;
        cout << "         Muhammad Fazri                     0110217030"<< endl;
        cout << "======================================================================"<<endl;
        cout << "---- Menu Program Stack  -----\n";
        cout<<"\nPilih cara yang akan digunakan : \n";
        cout<<"1. Stack dengan array\n";
        cout<<"2. Stack dengan linked list\n";
        cout<<"3. Keluar program\n";
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                stackarray();
                break;
            case '2' :
                stacklist();
                break;
            case '3' :
                ulang = 'Y';
                break;               
              default :
                cout<<"\nInput salah\n";
              }
             
          if(pilihan != '1' && pilihan != '2' && pilihan != '3'){
              ulang = 'Y';
            cout << "Tekan sembarang tombol untuk memuat ulang";
              getch();
        }
        else{
            ulang = 'y';
        }
    }
    while(ulang !='y');
}
