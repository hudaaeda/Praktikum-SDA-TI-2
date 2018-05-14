#include <iostream>
using namespace std;
void hapus_tengah(int posisi);

struct node 
{
	int urut;
	node *next;
};


node *curr, *prev;

node *kepala = NULL;
	node *posisi;
	int option = 0;
	
void nambah_awal() 
{
	node *baru;
	baru = new node;
	cout << "Masukkan data = ";
	cin >> baru->urut;
	baru->next = NULL;
	
	if (kepala == NULL)
	{
		kepala=baru;
		kepala->next = NULL;
	}
	else
	{
		baru->next = kepala;
		kepala = baru;
	}
	
}

void nambah_tengah()
{
  node *baru, *bantu;
  int posisi;
  if(kepala != NULL)
  {
    cout<<"diposisikan data ke  : ";
    cin>>posisi;
    baru =new node;
   bantu=kepala;

    for(int i=1;i<posisi-1;i++) {
      if(bantu->next != NULL)
        bantu=bantu->next;
      else
        break;
    }
  cout << "Masukkan nilainya    : ";
  cin >> baru->urut;
  baru->next=bantu->next;
  bantu->next=baru;
  }
  else
  {
    cout<<"Data masih kosong";

  }
}

void nambah_akhir()
{
	node *temp1, *temp2;
	temp1 = new node;
	cout << "Masuk ke urut = ";
	cin >> temp1 -> urut;
	temp1 -> next = NULL;
	
	if (kepala == NULL)
	{
		kepala = temp1;
		posisi = kepala;
	}
	else
	{
		temp2 = kepala;
		while (temp1 != NULL)
		{
			temp2 = temp2->next;
		}
		temp2 -> next = NULL;
	}
}

void hapus_awal()
{
	node *temp;
	temp = kepala;
	kepala = kepala -> next;
	delete temp;
}

void hapus_tengah(int posisi)
{
	node *curr,*pre;
	curr = kepala;
	
	for (int i=1;i<posisi;i++)
	{
		pre = curr;
		curr = curr -> next;
	}
	pre -> next = curr -> next;
	delete curr;
}

void hapus_akhir()
{
	node *temp1,*temp2;
	if ( kepala == NULL) 
	{
		cout << "Data kosong " << endl;
	}
	else 
	{
		temp1 = kepala;
		if (temp1 -> next == NULL)
		{
			delete temp1;
			kepala = NULL;
		}
		else
		{
			while (temp1 -> next !=NULL)
			{
				temp2 = temp1;
				temp1 = temp1 -> next;
			}
			delete temp1;
			temp2 -> next = NULL;
		}
	}
}


void tampilkan_semua()
{
  node *temp;
  temp = kepala;
  cout << endl;
cout << "DATA [";
  if (temp == NULL)
    cout << "data kosong " << endl;
  else
  {
    while (temp != NULL)
    {  
     cout << "" << temp->urut << ",";

     if (temp == posisi)
        cout << "     <== posisi node";
     temp = temp->next;
    }
    cout << "] "<< endl;
  }

}


int main()
{
	
	cout << " ======================== PROGRAM LINKED LIST ================"<< endl;
	int posisi;
	kepala = NULL;
	do
	{
		cout << endl;
		cout << " ========  Menu =========== "<< endl;
		cout << "0. Keluar program "<< endl;
		cout << "1. Tambah di bagian awal "<< endl;
		cout << "2. Tambah di bagian tengah "<< endl;
		cout << "3. Tambah di bagian akhir "<< endl;
		cout << "4. Tampilkan semua "<< endl;
		cout << "5. Hapus di bagian awal "<< endl;
		cout << "6. Hapus di bagian Tengah "<< endl;
		cout << "7. Hapus di bagian akhir "<<endl;
		
		cout << endl;
		cout << "Pilihan = ";
		cin >> option;
		
		switch (option)
		{
			case 1 :
				nambah_awal();
				break;
			case 2 :
				nambah_tengah();
				break;
			case 3 :
				nambah_akhir();
				break;
			case 4 :
				tampilkan_semua();
				break;
			case 5 :
				hapus_awal();
				break;
			case 6 :
				cout << "posisi ke berapa : ";
				cin >> posisi;
				hapus_tengah(posisi);
				break;
			case 7 :
				hapus_akhir();
				break;
		}
	}
	while (option != 0);
}
