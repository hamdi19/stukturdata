#include<conio.h>   	
#include<iostream> 
 

 
 using namespace std;
//   Creating a NODE Structure
struct node
{
   int no_pung;
   string nama;
   string posisi;
   struct node *next;
};
 
// Creating a class QUEUE
class queue
{
   struct node *frnt,*rear;
   public:
      queue() // constructure
      {
	 frnt=rear=NULL;
      }
      void insert(); // to insert an element
      void del();  // to delete an element
      void show(); // to show the stack
};
// Insertion
void queue::insert()
{
   int nilai;
   string nilai1;
   string nilai2;
   struct node *ptr;
   cout<<"\nInsertion\n";
   cout<<"Masukan No punggung: ";
   cin>>nilai;
   cout<<"Masukan Nama: ";
   cin>>nilai1;
   cout<<"Masukan Posisi: ";
   cin>>nilai2;
   ptr=new node;
   ptr->no_pung=nilai;
   ptr->nama=nilai1;
   ptr->posisi=nilai2;
   ptr->next=NULL;
   if(frnt==NULL)
      frnt=ptr;
   else
      rear->next=ptr;
   rear=ptr;
   cout<<"\DATA BARU BERHASIL DIMASUKKAN!!!";
   getch();
}
 
// Deletion
void queue::del()
{
   if(frnt==NULL)
   {
      cout<<"\nANTRIAN KOSONG!!";
      getch();
      return;
   }
   struct node *temp;
   temp=frnt;
   frnt=frnt->next;
   cout<<"\nDeletion Operation........\nDeleted value is "<<temp->no_pung<<temp->nama<<temp->posisi;
   delete temp;
   getch();
}
 
// Show Queue
void queue::show()
{
   struct node *ptr1=frnt;
   if(frnt==NULL)
   {
      cout<<"YANG MASUKKAN KOSONG!!";
      getch();
      return;
   }
   cout<<"\nYANG DIMASUKKAN ADALAH\n";
   while(ptr1!=NULL)
   {
      cout<<ptr1->no_pung<<" ->";
      cout<<ptr1->nama<<" ->";
      cout<<ptr1->posisi<<" ->";
      ptr1=ptr1->next;
      cout<<endl;
   }
   cout<<"END";
   getch();
}
 
// Main function
int main()
{
   system("cls");
   queue q;
   int choice;
   while(1)
   {
      cout<<"\n\t-----------------------------------------------------------";
      cout<<"\n\t\t\tANTRIAN MENGGUNAKAN LINK LIST\n\n";
      cout<<"\t 1:MASUKKAN\n\t 2:DIKELUARKAN\n\t 3:TAMPIL YANG DIMASUKKAN\n\t 4:EXIT";
      cout<<"\n\t MASUKKAN PILIHAN ANDA(1-4): ";
      cin>>choice;
      switch(choice)
      {
       case 1:
	  q.insert();
	  break;
       case 2:
	  q.del();
	  break;
       case 3:
	  q.show();
	  break;
       case 4:
	  exit(0);
	  break;
       default:
	  cout<<"SILAHKAN PERIKSA YANG ANDA MASUKKAN(1-4)!!";
	  getch();
	  break;
       }
   }
   return 0;
}
