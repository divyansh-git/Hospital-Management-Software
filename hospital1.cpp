
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<curses.h>
using namespace std;
void interface()
{
	cout<<"WELCOME!!!                      WELCOME!!!\n\n\n";
	cout<<"1.ADD PATIENT\n";
	cout<<"2.ADD DOCTOR\n";
	cout<<"3.VIEW PATIENTS\n";
	cout<<"4.SEARCH PATIENT\n";
	cout<<"5.VIEW DOCTORS\n";
	cout<<"6.SEARCH DOCTORs\n";
	cout<<"7.DELETE A DOCTOR\n";
	cout<<"8.DELETE A PATIENT\n";
	cout<<"9.SEE OCCUPIED ROOMS";
	cout<<"\n\n";
    
}
class patient
{
	char filename[20];
	char firstname[20];
	char lastname [20];
	char ID[5];
	int age;
	long int phn;
	int room;
	char disease[20];
	int a[20];

	public:
	void set_patient()
	{
		int j;
		int i;
      cout<<"Add the details of the patient below\n";
       cout<<"occupied rooms are:";int count=occupiedroom();
      cout<<"\nfirst name: " ;cin>>firstname; 
      cout<<"last name: "; cin>>lastname;
      cout<<"age: "; cin>>age;
      cout<<"phone number: "; cin>>phn;
      cout<<"disease: "; cin>>disease;
      cout<<"ID: "; cin>>ID;
      cout<<"room no. alloted: "; cin>>room;
     while(room>=21||room<=0)
     {
         cout<<"There is no room with number "<<room<<" .Try for another one\n";
     	cout<<"room no. alloted: "; cin>>room;
     }
     do
     {
     	 while(room>=21||room<=0)
     {
         cout<<"There is no room with number "<<room<<" .Try for another one\n";
     	cout<<"room no. alloted: "; cin>>room;
     }
     	j=0;
      for(i=0;i<count;i++)
      { 
      	if(room==a[i])
      	{
       	j++;
       	cout<<"This room is already assigned.Try another one\n";    
        cout<<"room no. alloted: "; cin>>room;
        i=-1;
        }
      }

     }while(j);
  	}
	void upload_pdata()
	{
		ofstream fout;
		fout.open("patient.dat",ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		fout<<"\npatient added successfully\n\n";
		
	}
	void getall_pdata()
	{
		ifstream fin;
		fin.open("patient.dat",ios::in);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			show_pdata();
			cout<<"\n\n-----------------------------------------\n";
			fin.read((char*)this,sizeof(*this));
			cout<<"\n";
		}
		fin.close();
	}
	void show_pdata()
	{
      cout<<"first name: " ;cout<<firstname; cout<<"\n";
      cout<<"last name: "; cout<<lastname;cout<<"\n";
      cout<<"age: "; cout<<age;cout<<"\n";
      cout<<"phone number: "; cout<<phn;cout<<"\n";
      cout<<"disease: "; cout<<disease;cout<<"\n";
      cout<<"room no. alloted"; cout<<room;cout<<"\n";
      cout<<"ID: "; cout<<ID;cout<<"\n";
	}
	void searchp()
	{
		char name[20];
		int count=0;
		cout<<"enter the first name of the patient.\n";
		cin>>name;
      ifstream fin;
      fin.open("patient.dat",ios::in);
      fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {

      	if(!strcmp(name,this->firstname))
      	{
      		show_pdata();
      		count++;
      	}
      	fin.read((char*)this,sizeof(*this));
      }
      if(count==0)
      	cout<<"no record found with such name";
      fin.close();
    }
    void deletep()
    {
    	int count=0,i=0;
    	char name[20];
    	cout<<"enter the first name of the patient to be deleted\n";
    	cin>>name;
    	ofstream fout;
    	ifstream fin;
    	fout.open("temp.dat",ios::out);
    	fin.open("patient.dat",ios::in);
    	fin.read((char*)this,sizeof(*this));
    	while(!fin.eof())
    	{
    		i++;
    	if(strcmp(name,firstname))
    	 {
           fout.write((char*)this,sizeof(*this));
           count++;
         }
            fin.read((char*)this,sizeof(*this));
        }
        if(count==i)
        	cout<<"no such name exists\n";
        else
        	cout<<"\npatient deleted successfully\n";
        fin.close();
        fout.close();
        remove("patient.dat");
        rename("temp.dat","patient.dat");
    }
    int occupiedroom()
    {
    	int count=0,i;
       ifstream fin;
       fin.open("patient.dat",ios::in);
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
       {
       	a[count]=this->room;
       	 count++;
       	 fin.read((char*)this,sizeof(*this));
       }
       for(i=0;i<count;i++)
       {
       	cout<<a[i]<<",";
       }
       if(count==0)
       	cout<<"there is no room occupied";
       fin.close();
       return(count);       
    }

};
class doctor
{
	public:
	char filename[20];
	char firstname[20];
	char lastname [20];
	char ID[5];
	int age;
	long int  phn;
	int exp;
	void set_doctor()
	{
      cout<<"Add the details of the doctor below\n";
      cout<<"first name: "; cin>>firstname; 
      cout<<"last name: " ;cin>>lastname;
      cout<<"age: "; cin>>age;
      cout<<"phone number: " ;cin>>phn;
      cout<<"expirience in years: " ;cin>>exp;
      cout<<"ID: " ;cin>>ID;
	}
	void upload_ddata()
	{
		ofstream fout;
		fout.open("doctor.dat",ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		fout<<"\ndoctor added successfully\n";
		
	}
	void getall_ddata()
	{
		ifstream fin;
		fin.open("doctor.dat",ios::in);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			show_ddata();cout<<"\n";
			cout<<"\n\n-----------------------------------------\n";
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
	}
	void show_ddata()
	{
      cout<<"first name: "; cout<<firstname; cout<<"\n";
      cout<<"last name: " ;cout<<lastname;cout<<"\n";
      cout<<"age: "; cout<<age;cout<<"\n";
      cout<<"phone number: " ;cout<<phn;cout<<"\n";
      cout<<"expirience in years: " ;cout<<exp;cout<<"\n";
      cout<<"ID: " ;cout<<ID;cout<<"\n";
	}
	void searchd()
	{
		char name[20];
		int count=0;
		cout<<"enter the first name of the doctor.\n";
		cin>>name;
      ifstream fin;
      fin.open("doctor.dat",ios::in);
      fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
      	if(!strcmp(name,this->firstname))
      	{
      		show_ddata();
      		count++;
      	}
      	fin.read((char*)this,sizeof(*this));
      }
      if(count==0)
      	cout<<"no record found with such name";
      fin.close();
  }
  void deleted()
    {
    	int e;
    	int count=0,i=0;
    	char name[20];
    	cout<<"enter the first name of the doctor to be deleted\n";
    	cin>>name;
    	ofstream fout;
    	ifstream fin;
    	fout.open("temp.dat",ios::out);
    	fin.open("doctor.dat",ios::in);
    	fin.read((char*)this,sizeof(*this));
    	while(!fin.eof())
    	{
    		i++;
    	if(strcmp(name,firstname))
    	 {

           fout.write((char*)this,sizeof(*this));
           count++;
         }
            fin.read((char*)this,sizeof(*this));
        }
        if(count==i)
        	cout<<"no such name exists\n";
        else
        	  cout<<"\nname removed successfully\n";
        fin.close();
        fout.close();
        remove("doctor.dat");
        rename("temp.dat","doctor.dat");
    }
    
};
int main()
{   
	char e;
	patient p;
	doctor d;
	int choice;
	while(1)
	{
    system("clear");
	interface();
	cin>>choice;
	system("clear");
	switch(choice)
	{
		case 1:
		{
          p.set_patient();
          p.upload_pdata();
          cin>>e;
          break;
		}
		case 2:
		{
			d.set_doctor();
			d.upload_ddata();
			cin>>e;
			break;
		}
		case 3:
		{
			p.getall_pdata();
			cin>>e;
			break;
		}
		case 4:
		{
			p.searchp();
			cin>>e;
			break;
		}
		case 5:
		{
			d.getall_ddata();
			cin>>e;
			break;
		}
		case 6:
		{
			d.searchd();
			cin>>e;
			break;
		}
		case 7:
		{
			d.deleted();
			cin>>e;
			break;
		}
		case 8:
		{
			p.deletep();
			cin>>e;
			break;
		}
		case 9:
		{
         p.occupiedroom();
         cout<<"\n";
          cin>>e;
          break;
		}
		case 0:
		{
			exit (0);
		}
		default:
		cout<<"\ninvalid input"; 
	}
}
return 0;
}