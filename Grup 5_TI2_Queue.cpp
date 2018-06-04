#include<iostream>
#include<conio.h>
using namespace std;

/* Mendeklarasikan variabel yang dibutuhkan */
int data[5];            // Membuat array untuk membatasi jumlah nilai yang dimasukkan pada queue
const int MAX = 4;        // menentukan batasan nilai pada queue
int depan = 0;            // pada bagian depan dideklarasikan 0 terlebih dahulu
int top = -1;            // pada bagian top dideklarasikan -1 terlebih dahulu
int count;

//Mendeklarasikan node dan pointer - pointer yang dibutuhkan
struct node{
    int data;
    node* next;
};
node *n, *temp, *pre;
node *head = NULL;
node *tail = NULL;

/* ================================================ QUEUE DENGAN ARRAY ==============================*/
// fungsi untuk menambahkan nilai pada queue
void enqueue(int n){
    if(top == MAX){                    // memeriksa apakah bagian top sudah memenuhi nilai max
        cout << "\nQueue penuh!\n";    // jika sudah maka akan muncul queue sudah penuh
    }
    else{
        top++;                        // jika tidak terjadi increment pada top sehingga menambah nilai pada queue
        data[top] = n;                // menambahkan nilai di bagian bagian belakang pada queue
        cout << "Data sudah terupdate" << endl;
    }
}

// Fungsi untuk menghapus nilai pada queue
void dequeue(){
    if(top == -1){                            // Memeriksa apakah top masih di index -1
        cout << "\nQueue tidak ada!\n";        // jika iya maka queue masih kosong
    }
    else{
        cout << "\nData yang dikeluarkan adalah " << data[0]; // memberitahukan nilai yang dikeluarkan
        for(int i = 0; i<5; i++){
            data[i] = data[i+1];               
        }
        top--;                                        // top terjadi dicrement pada indexnya karna ada nilai yang keluar
        cout << "\nData sudah terupdate\n" << endl;
    }
}

// Fungsi melihat nilai pada queue
void queuelihat(){
    int i =  top;        // mendeklarasikan variabel baru dan diletakkan bersama dengan top
    if(top == -1){                            // Memeriksa apakah top masih di index -1
        cout << "\nQueue tidak ada!\n";
    }
    else{
        cout << "\nData yang ada pada Queue adalah \n";
        cout << "tail->";
        while(i >= 0){
            cout << data[i] << "->";        // varibel queue berpindah dan menampilkan nilainya pada queue
            i--;                            // Terjadi dicrement pada i karna dibaca dari depan
        }
        cout << "head";
    }
}

/* ================================================== QUEUE DENGAN LINKED LIST ======================== */
// mendeklarasikan node untuk menambah node baru
void nodebaru(int data){
    n = new node;
    n->data = data;
    n->next = NULL;   
}

// Fungsi menambah nilai pada queue
void nodetambahlist(int data){
    if(head == NULL){                // Jika head == NULL ( data masih Kosong )
        nodebaru(data);                // maka node baru mengisi queue
        head = n;                    // nodebaru menjadi head pada queue
        tail = head;                // dan nodebaru juga menjadi tail
    }
    else{
        nodebaru(data);                // jika tidak maka node baru ditambahkan pada queue
        tail->next = n;                // Tail berpindah ke nilai baru
        tail = n;                    // tail terletak di nodebaru
    }
    cout << "Data sudah terupdate" << endl;
}

// Menghapus nilai pada queue
void nodehapuslist(){
    if (head == NULL){                                    // Jika head = NULL ( data masih kosong )
        cout << "\nBelum ada data yang dimasukkan\n";    // Maka tidak ada nilai yang bisa dihapuskan
    }
    else{
        temp = head;                                            // Jika tidak maka temp terletak di head
        cout << "Data yang dikeluarkan adalah " << temp->data;    // memberitahukan data yang dhikeluarkan dengan menampilkan temp ->data
        head = head->next;                                        // head pindah ke nilai selanjutnya
        temp->next = NULL;                                        // temp selanjutnya bernilai NULL
        delete temp;                                            // Menghapus tempnya
    }
}

// Fungsi menampilkan nilai pada queue
void nodelihatist(){
    if (head == NULL){                                            // Jika head = NULL ( data masih kosong )
        cout << "\nBelum ada data yang dimasukkan\n";            // Tidak ada yang bisa ditampilkan
    }
    else{
        temp = head;                                            // Jika ada nilai pada queue, temp diletakkan di Head
        cout << "\nData yang ada adalah = " << endl;
        cout << "head<-";
        while (temp!=NULL){
            cout << temp->data << "<-";                            // temp menghubungkan ke data dan menampilkannya
            temp = temp->next;                                    // temp pindah ke nilai selanjutnya sampai tail
        }
        cout << "Tail" << endl;
    }   
}

// Mendeklarasikan fungsi
void queuearray();
void queuelist();
void menu();

// Memanggil fungsi menu sebagai membaca pertama saat program pertama kali di running
int main(){
    menu();
}

// Fungsi untuk pilihan pada menu queue menggunakan array
void queuearray(){
    char ulang,pilihan;
    int data;
    do{
        system("cls");
        cout << "========  Program Queue Array  ========\n";
        cout<<"\nMenu : \n"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Cetak data"<<endl;
        cout<<"4. Kembali ke menu"<<endl;
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                cout << "\nMasukkan data = "; cin >> data;
                enqueue(data);
                break;
            case '2' :
                dequeue();
                break;
              case '3' :
                queuelihat();
                break;
            case '4' :
                menu();
                break;                  
              default :
                cout<<"\nPilih ulang"<<endl;
              }
             
          cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
    }   
    while(ulang=='y' || ulang=='Y');
}


// Fungsi untuk pilihan pada menu queue menggunakan linked list
void queuelist(){
    char ulang,pilihan;
    int data;
    do{
        system("cls");
        cout << "=====  Program Queue Linked List  =====\n";
        cout<<"\nMenu : \n"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Cetak data"<<endl;
        cout<<"4. Kembali ke menu"<<endl;
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                cout << "\nMasukkan data = "; cin >> data;
                nodetambahlist(data);
                break;
            case '2' :
                nodehapuslist();
                break;
              case '3' :
                nodelihatist();
                break;
            case '4' :
                menu();
                break;
            default :
                cout<<"\nPilih ulang"<<endl;
              }
             
          cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
    }   
    while(ulang=='y' || ulang=='Y');
}

// Fungsi untuk pilihan mau menggunakan queue dengan cara array atau linked list
// dan fungsi ini yang pertama kali di baca program
void menu(){
    char ulang, pilihan;
    int data;
    do{
        ulang = 'n';
        system("cls");
        cout << "Grup 5 = Huda Izzatul Haq                   0110217069"<< endl;
        cout << "         Fatkhurrahmana Jundi Binauf        0110217071"<< endl;
        cout << "         Muhammad Fazri                     0110217030"<< endl;
        cout << "======================================================================"<<endl;
        cout << "========  Menu Program Queue  =========\n";
        cout<<"\nPilih cara : \n";
        cout<<"1. Queue  array\n";
        cout<<"2. Queue linked list\n";
        cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
       
        switch(pilihan){
            case '1' :
                queuearray();
                break;
            case '2' :
                queuelist();
                break;           
              default :
                cout<<"\nInput salah\n";
                getch();
                   ulang = 'y';
        }
    }
    while(ulang == 'y');
}


