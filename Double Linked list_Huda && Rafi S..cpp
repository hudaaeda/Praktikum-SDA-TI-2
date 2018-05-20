#include<iostream>
using namespace std;

struct node{
	int data;
	node* prev;
	node* next;
};
node *n, *temp, *pre;
node *head = NULL;
node *tail = NULL;

void nodepertama(int data){
	n = new node;
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
}

void nodedepan(int data){
	temp = head;
	nodepertama(data);
	n->next = head;
	head = n;
	temp->prev = n;
	
}

void nodebelakang(int data){
	temp = head;
	nodepertama(data);
	tail->next = n;
	n->prev = temp;
	tail = n;
}

void nodetengah(int urut, int data){
	if(urut == 1){
		cout << "\nProgram akan dialihkan ke tambah node didepan\n";
		nodedepan(data);
	}
	else if(head->next == NULL){
		cout << "\nProgram akan dialihkan ke tambah node dibelakang\n";
		nodebelakang(data);
	}
	else {
		temp = head;
		nodepertama(data);
		for (int i = 1; i<urut; i++){
			pre = temp;
			temp = temp->next;
		}
		pre->next = n;
		n->prev = pre;
		n->next = temp;
		temp->prev = n;
	}
}



void nodebaru(int data){
	char pilihan;
	int urut;
	
	if(head == NULL){
		nodepertama(data);
		head = n;
		tail = n;
	}
	
	else{	
		cout << "\ndiletakkan di?\n";
		cout << "1. Depan\n";
		cout << "2. Tengah\n";
		cout << "3. Belakang\n";
		cout << "\nPilihan = "; cin >> pilihan;
		
		switch(pilihan){
    		case '1' :
				nodedepan(data);
            	break;
    		case '2' :
    	        cout << "\nUrutan keberapa? "; 
    	        cin >> urut;
    	        nodetengah(urut,data);
        	    break;
      		case '3' :
				nodebelakang(data);
        	    break;         	
      		default :
            	cout<<"\nPilihan salah\n"<<endl;
      	}
	}
	cout << "Data sudah tersimpan\n";
}

void nodehapusdepan(){
	temp = head->next;
	temp->prev = NULL;
	head->next = NULL;
	head = temp;
}



void nodehapusbelakang(){
	temp = tail->prev;
	temp->next = NULL;
	tail->prev = NULL;
	tail = temp;
}


void nodehapus(){
	char pilihan;
	int urut;
	temp = head;
	
	if (head == NULL){
		cout << "\nBelum ada data yang dimasukkan\n";
	}
	else{	
		cout << "\nhapus di bagian?\n";
		cout << "1. Depan\n";
		cout << "2. Belakang\n";
		cout << "3. Semua\n";
		cout << "\nPilihan = "; cin >> pilihan;
			
		switch(pilihan){
    		case '1' :
				nodehapusdepan();
            	break;
      		case '2' :
				nodehapusbelakang();
        	    break; 
      		case '3' :
				head = NULL;
        	    break;				       	
      		default :
            	cout<<"\nPilihan salah"<<endl;
      	}
      	cout << "Data sudah tersimpan\n";
	}	
}

void nodeubahtengah(int urut,int data){
	temp = head;
	
	
	for (int i = 1; i<urut; i++){
		temp = temp->next;
	}
	temp->data = data;
}

void nodeubah(int data){
	char pilihan;
	int urut;
	temp = head;
	
	if(head == NULL){
		cout << "\nBelum ada data yang dimasukkan\n";
	}
	else{
		cout << "Masukkan data : "; cin >> data;
		
		cout << "\nMau ubah yang mana?\n";
		cout << "1. Depan\n";
		cout << "2. Tengah\n";
		cout << "3. Belakang\n";
		cout << "\nPilihan = "; cin >> pilihan;
			
		switch(pilihan){
    		case '1' :
				head->data = data;
            	break;
    		case '2' :
    	        cout << "\nMau ubah data keberapa? ";
    	        cin >> urut;
    	        nodeubahtengah(urut,data);
        	    break;
      		case '3' :
				tail->data = data;
        	    break;         	
      		default :
            	cout<<"\nPilihan salah"<<endl;
      	}
      	cout << "Data sudah tersimpan\n";
	}
}

void nodetampilsemua(){
	cout << "\nData yang ada adalah = " << endl;
	cout << "NULL<-";
	while (temp!=NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void nodetampiltengah(int n){
	int i = 1;
	while (temp->next != NULL && i<n){
		temp = temp->next;
		i++;
	}
	if (temp->next = NULL){
		cout << "\nData yang anda cari bukan data tengah";
	}
	else {
		cout << "\nData yang ada adalah = ";
		cout << temp->data;
	}
}

void nodetampil(){
	char pilihan;
	int n;
	temp = head;
	if (head == NULL){
		cout << "\nBelum ada data yang dimasukkan\n";
	}
	else {
		cout << "\nMau liat yang mana?\n";
		cout << "1. Depan\n";
		cout << "2. Tampilkan semua \n";
		cout << "\nPilihan = "; cin >> pilihan;
		
		switch(pilihan){
    		case '1' :
      			cout << "\nData yang ada adalah = " << endl;
				cout << head->data;
            	break;
      		case '2' :
        	    nodetampilsemua();
            	break;          	
      		default :
            	cout<<"\nPilihan salah"<<endl;
      	}		
	}
}

int main(){
	char ulang,pilihan;
	int data;
	do{
		system("cls");
		cout << "===== Program Double Linked List =====\n";
		cout<<"\nMenu : "<<endl;
		cout<<"1. Input data"<<endl;
		cout<<"2. Hapus data"<<endl;
    	cout<<"3. Ubah Data"<<endl;
    	cout<<"4. Cetak Data"<<endl; 
    	cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
    	
    	switch(pilihan){
    		case '1' :
            	cout<<"\nMasukkan data : ";
            	cin>>data;
            	nodebaru(data);
            	break;
    		case '2' :
    	        nodehapus();
        	    break;
      		case '3' :
				nodeubah(data);
        	    break;
      		case '4' :
        		nodetampil();
            	break;          	
      		default :
            	cout<<"\nPilih ulang"<<endl;
      		}
      		
      	cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
	}	
	while(ulang=='y' || ulang=='Y');
}
