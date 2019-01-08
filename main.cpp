#include <iostream>
#include <conio.h>
#include<stdlib.h>

using namespace std;

using namespace std;
typedef struct mylinkedlist{
	string plat_nomor;
	string jenis_kendaraan;
	mylinkedlist *next;
}mylist;
 mylist *head; mylist *tail;
 int n=0;

void tambah_depan(){
 	mylist *baru;
 	baru=new mylist;
 	cout<<endl;
 	cout<<endl;
 	cout<<"Masukan Data kendaraan"<<endl;
 	cout<<"masukan plat nomor : ";cin>>baru->plat_nomor;
 	cout<<"jenis kendaraan : ";cin>>baru->jenis_kendaraan;
 	cout<<endl;
 	cout<<"+==============================================+"<<endl;
 	baru->next=NULL;
 	if (head==NULL){
 		head=baru;tail=baru;
	 }else{
	 	baru->next=head;head=baru;
	 }
	 cout<<endl;
	 	cout<<"data kendaraan berhasil dimasukan"<<endl;
	 	cout<<endl;
     cout<<"-------------------------------------------"<<endl;
 }
 void cetak_list(mylist *X,mylist *Y){
 	mylist *bantu;
 	bantu=new mylist;
 	int i=0;
 	cout<<endl;
 	cout<<"      Daftar Kendaraan Parkir"<<endl;
 	cout<<"______________________________________"<<endl;
 	cout<<" no    plat number   jenis kendaraan  "<<endl;
 	cout<<"______________________________________"<<endl;
 	bantu=X;
 	while (bantu !=NULL){
 		i++;cout<<"  "<<i<<"       "<<bantu->plat_nomor<< "       "<<bantu->jenis_kendaraan<<endl;
 		bantu=bantu->next;
	 }
	cout<<endl;
	 cout<<"jumlah kendaraan = "<<i<<endl;
	 n=i;
 }

 void hapus_depan(){
 	mylist *hapus;hapus=new mylist;
 	hapus=head;
 	cout<<"data yang dihapus : "<<endl;
 	cout<<"plat nomor : "<<hapus->plat_nomor<<"\n"<<"jenis kendaraan : "<<hapus->jenis_kendaraan<<endl;
 	head=head->next;
 	delete hapus;
 	cout<<endl;
 	cout<<"data pertama sudah dihapus "<<endl;
 }

 void hapus_akhir(){
 	mylist *hapus;hapus=new mylist;
 	mylist *bantu;bantu=new mylist;
 	bantu=head;
 	if(head==tail){
 		hapus_depan();
	 }else{
	 	while (((bantu->next->next))!=NULL){
	 		bantu=bantu->next;
		 }
		 hapus=bantu->next;bantu->next=NULL;
		 tail=bantu;
		 cout<<"data yang dihapus : "<<endl;
		 cout<<"plat nomor: "<<hapus->plat_nomor<<"\n"<<"jenis kendaraan: "<<hapus->jenis_kendaraan<<endl;
	 }
 }

 void hapus_nama()
	 {
	 	mylist *hapus;hapus=new mylist;
	 	mylist *bantu;bantu=new mylist;
	 	string nama_hapus;
	 	int lama =0;
	 	int bayar=0;
	 	string jenis_kendaraan;
	 	bool ada=false;
	 	cout<<endl;
	 	cout<<"menghapus plat terntentu dari "<<endl;
	 	cetak_list(head,tail);
	 	cout<<"masukan lama parkir : ";cin>>lama;
	 	cout<<endl;
	 	cout<<"masukan jenis kendaraan : "; cin>>jenis_kendaraan;
	 	if (lama <= 2 && jenis_kendaraan=="mobil" ){
            bayar=2000;
	 	} else if(lama>2 && jenis_kendaraan=="mobil"){
	 	bayar=lama*1000;
	 	}
	 	else if(lama<=2 && jenis_kendaraan=="motor"){
            bayar=1000;
	 	}
	 	else if(lama>2 && jenis_kendaraan=="motor"){
            bayar=lama*1000;
	 	}
	 	else{
            cout<<"tidak ada";
	 	}
	 	cout<<"masukkan plat nomor yang akan keluar dari Daftar  parkir :  ";cin>>nama_hapus;
	 	if(head->plat_nomor==nama_hapus){
	 		ada=true;hapus_depan();
		 }else if(tail->plat_nomor==nama_hapus){
		 	ada=true;hapus_akhir();
		 }else{
		 	bantu=head;
		 	while (bantu->next!=NULL){
		 		if(bantu->next->plat_nomor==nama_hapus){
		 			ada=true;
		 			hapus=bantu->next;
		 			cout<<"kendaraan dengan plat   = "<<"\n"<<endl<<"dihapus"<<endl;
		 			bantu->next=hapus->next;
				 }
				 bantu=bantu->next;
			 }
		 }
		 if(ada==true){
		 	cout<<"penghapusan berhasil dengan lama parkir : "<<lama<< " Jam "<<endl;
		 	cout<<endl;
		 	cout<<"silahkan Membayar Sebesar "<<"Rp."<<bayar <<" Rupiah "<<endl;
		 	cout<<endl;
		 }else{
		 	cout<<"penghapusan gagal nama tidak ditemukan"<<endl;
		 }
		 delete hapus;
	 }

void cari_dinode()
 { mylist *bantu;bantu=new mylist;
 string cari;
 int i=0;bool ada=false;
 cout<<"Mencari Kendaraan dalam daftar parkir"<<endl;
 cout<<endl;
 cout<<"masukan plat yang anda akan cari : ";cin>>cari;
 bantu=head;
 while (bantu!=NULL)
 {i++;
 if (bantu->plat_nomor==cari){ada=true;cout<<"plat = "<<cari<<"\n"<<"ada di Block nomor = "<<i<<endl;
 }
 bantu=bantu->next;
 }
 if (not ada) { cout<<"plat"<<cari<<"tidak di temukan"<<endl;
 }
  }

int main()
{
   head=NULL;tail=NULL;
  	int pilih=0;
  	lagi:
  		system("cls");
  		cout<<"+=========================================+"<<endl;
        cout<<"+        \t Menu Parkir               +"<<endl;
  		cout<<"+ \t1.tambah kendaraan                 +"<<endl;
  		cout<<"+ \t2.kendaraan keluar                 +"<<endl;
  		cout<<"+ \t3.Daftar parkir kendaraan          +"<<endl;
  		cout<<"+ \t4.cari kendaraan                   +"<<endl;
  		cout<<"+ \t0.selesai                          +"<<endl;
  		cout<<"+==========================================+";
  		cout<<endl;
		  cout<<"pilih menu : ";cin>>pilih;
  		switch (pilih)
  		{
  			case 1 : {
  				tambah_depan();
				break;
			  }
			case 2 : {
				hapus_nama();
				break;
			}
			case 3 : {
				if (head==NULL){
					cout<<"data kosong"<<endl;
				}else{
					cetak_list(head,tail);
				}
				break;
			}
			case 4 : {
				if (head==NULL){
					cout<<"Linked list masih kosong"<<endl;
				}else{
					cari_dinode();
				}
				break;
			}
			case 0 : {
				cout<<"Terima kasih"<<endl;
				break;
			}
			default : {
				cout<<"salah pilih menu"<<endl;
				break;
			}

		}
		system("pause");
		if(pilih!=0) goto lagi;
		delete head; delete tail;//release pointer
}
