#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
biar paham 
author : saysansay 
ref : jagokoding.com
crud without database 

iostream : adalah standard librari input/output stream object
conio.h : standard library header compiler MSDOS 
fsstream : standard input / output file stream
string.h : standard string library 

to do list
Penggunaan Struct
Sorting Algoritma


*/
typedef struct modelBarang{
 char kodebarang[10];
 char namabarang[100];
 char unitbarang[5];
}modelBarang;

char namaFile[30] = "database.dat";
char tempnamaFile[30] = "tempdatabase.dat";
modelBarang dtBarang;


void create(int n){
    ofstream fo; 
    
    cout << "JUMLAH DATA YANG AKAN DIINPUT: ";
    cin >> n;
    fo.open(namaFile, ios::binary | ios::app);
    for(int i=1; i<=n; i++)
    {
        cout << "\nBARANG " << i;
        cout << "\nKODE BARANG : ";
        cin >> dtBarang.kodebarang;
        
        cout << "NAMA BARANG: ";
        
        cin >> dtBarang.namabarang;
        
        cout << "UNIT BARANG: ";
        cin >> dtBarang.unitbarang;
        
        fo.write((char *) &dtBarang, sizeof(dtBarang)); 
    }
    fo.close();
  
}

void search(char kodebarang[10] )
{
	ifstream fi;
	modelBarang dtBarang;
	
	cout << "\nMASUKAN KODE BARANG YANG DICARI : ";
    cin >> kodebarang;
    fi.open(namaFile, ios::binary);
    int isFind = 0;
    while(fi.read((char *) &dtBarang, sizeof(dtBarang)))
    {
        if(strcmp(dtBarang.kodebarang, kodebarang) == 0)
        {
            cout << "\nDATA DITEMUKAN: ";
            cout << "\nKODE BARANG: " << dtBarang.kodebarang;
            cout << "\nNAMA BARANG: " << dtBarang.namabarang;
            cout << "\nUNIT BARANG: " << dtBarang.unitbarang;
            isFind =1;
        }
        else
        {
          isFind =0;	
		}
    }
    if (isFind=0 ){
	 cout << "\nDATA TIDAK DITEMUKAN! ";
	}
    fi.close();
}
 
void read(){
	ifstream fi;
	modelBarang dtBarang;
 	fi.open(namaFile, ios::binary);
    int j = 1;
    cout << "================================================================";
    cout << "\nNO \tKODE BARANG \tNAMA BARANG  \tUNIT BARANG " ;
    cout << "\n================================================================";
    while(fi.read((char *) &dtBarang, sizeof(dtBarang)))
    {
        cout <<"\n"<<j++<<"      \t"<<dtBarang.kodebarang<<"        \t"<<dtBarang.namabarang<<"       \t"<<dtBarang.unitbarang;
        
    }
    fi.close();

}

void del(char kodebarang[10] )
{
	ifstream fi;
	ofstream fo;
	modelBarang dtBarang;
	
	cout << "\nMASUKAN KODE BARANG YANG AKAN DIHAPUS : ";
    cin >> kodebarang;
    fi.open(namaFile, ios::binary);
    fo.open(tempnamaFile, ios::binary);
    while(fi.read((char *) &dtBarang, sizeof(dtBarang)))
    {
        if(strcmp(dtBarang.kodebarang, kodebarang) != 0)
        {
        	
            fo.write((char *) &dtBarang, sizeof(dtBarang)); 
           
        }
        else
        {
        	cout << "\nDATA YANG DIHAPUS: ";
            cout << "\nKODE BARANG: " << dtBarang.kodebarang;
            cout << "\nNAMA BARANG: " << dtBarang.namabarang;
            cout << "\nUNIT BARANG: " << dtBarang.unitbarang;
		}
       
    }
    fi.close();
    fo.close();
    remove(namaFile);
    rename(tempnamaFile,namaFile);
    
}

void edit(char kodebarang[10] )
{
	fstream  fi;
	
	modelBarang dtBarang;
	
	cout << "\nMASUKAN KODE BARANG YANG AKAN DIUBAH : ";
    cin >> kodebarang;
    fi.open(namaFile,ios::in | ios::binary | ios::out);
    
    while(fi.read((char *) &dtBarang, sizeof(dtBarang)))
    {
        if(strcmp(dtBarang.kodebarang, kodebarang) == 0)
        {
        	cout << "\nDATA SEBELUM DIUBAH : ";
            cout << "\nKODE BARANG: " << dtBarang.kodebarang;
            cout << "\nNAMA BARANG: " << dtBarang.namabarang;
            cout << "\nUNIT BARANG: " << dtBarang.unitbarang;
            
            cout << "\nKODE BARANG : ";
	        cin >> dtBarang.kodebarang;
	        cout << "NAMA BARANG: ";
	        cin >> dtBarang.namabarang;
	        cout << "UNIT BARANG: ";
	        cin >> dtBarang.unitbarang;
	        fi.write((char *) &dtBarang, sizeof(dtBarang));//Masih belum benar 
			  
            cout << "\nDATA YANG DIUBAH : ";
            cout << "\nKODE BARANG: " << dtBarang.kodebarang;
            cout << "\nNAMA BARANG: " << dtBarang.namabarang;
            cout << "\nUNIT BARANG: " << dtBarang.unitbarang;                         
        }
       
       
    }
    fi.close();

	 
}
void repeatMenu(int menu,int data,char isexit, char searchKodebarang[10]){
system ("CLS");	
cout<<"MENU UTAMA"<<endl;
	cout<<"==================================="<<endl;
	cout<<"1. TAMBAH DATA BARANG"<<endl;
	cout<<"2. TAMPILKAN DATA"<<endl;
 	cout<<"3. CARI"<<endl;
 	cout<<"4. HAPUS"<<endl;
 	cout<<"5. UBAH"<<endl;
 	cout<<"6. KELUAR"<<endl;
 	cout<<"==================================="<<endl;
 	cout<<"INPUTAN DATA TIDAK BOLEH ADA SPASI KARENA TYPE DATA CHAR"<<endl;
 	cout<<"ON TASK : UPDATE SORTING"<<endl;

do {
switch (menu){
case 1:
   create(data);
   break;
case 2:
   read();
   break;
case 3:
   search(searchKodebarang);
   break;
case 4:
   del(searchKodebarang);
   break;
case 5:
   edit(searchKodebarang);
   break;
case 6:
   exit(0);
}	

cout<<"\nPILIHAN MENU : ";cin>>menu;
repeatMenu(menu,data,isexit,searchKodebarang);
}while (isexit=='Y');//looping forever wkwkwkwkw
}
int main(int argc, char** argv) {
	int menu;
	int data;
	char searchKodebarang[10];
	char isexit;
	
	cout<<"MENU UTAMA"<<endl;
	cout<<"==================================="<<endl;
	cout<<"1. TAMBAH DATA BARANG"<<endl;
	cout<<"2. TAMPILKAN DATA"<<endl;
 	cout<<"3. CARI"<<endl;
 	cout<<"4. HAPUS"<<endl;
 	cout<<"5. UBAH"<<endl;
 	cout<<"6. KELUAR"<<endl;
 	cout<<"==================================="<<endl;
 	cout<<" PILIHAN MENU : ";cin>>menu;

do {
switch (menu){
case 1:
   create(data);
   break;
case 2:
   read();
   break;
case 3:
   search(searchKodebarang);
   break;
case 4:
   del(searchKodebarang);
   break;
case 5:
   edit(searchKodebarang);
   break;
case 6:
   return 1;
}	

cout<<"\nPILIHAN MENU : ";cin>>menu;
repeatMenu(menu,data,isexit,searchKodebarang);
}while (isexit=='Y');//looping forever wkwkwkwkw
getch();
return 0;
}
