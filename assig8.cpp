#include<iostream>
#include<fstream>
using namespace std;
ifstream ifile,itemp;
ofstream ofile,otemp;
class Personnel
{
	protected:
		char name[20];
		int rolno;
	public:
		void getData()
		{
			cout<<endl<<"Enter Name: ";
			cin>>name;
			cout<<endl<<"Enter Roll No: ";
			cin>>rolno;
		}
};
class Academic:public Personnel
{
    private:
    static int cnt;
	protected:
		int maths,chem,phy;
	public:
		void getData()
		{
			Personnel::getData();
			cout<<endl<<"Enter marks for Maths: ";
			cin>>maths;
			cout<<endl<<"Enter marks for Chemistry: ";
			cin>>chem;
			cout<<endl<<"Enter marks for Physics: ";
			cin>>phy;
		}
		void infile();
		void outfile();
		int del();
		void modify();
};
int Academic::cnt;  // defination of static variable
void Academic::infile()
{
	ofile.open("Result.txt",ios::app);
	ofile<<endl;
	ofile<<rolno<<"\t"<<name<<"\t"<<maths<<"\t"<<chem<<"\t"<<phy<<endl;
	ofile.close();
	cnt++;
}
void Academic::outfile()
{
	int r,m,p,c;
	char n[20];
	cout<<"Roll No"<<" Name"<<" Maths"<<" Chemistry"<<" Physics"<<endl;
	ifile.open("Result.txt",ios::in);
	for(int i=0;i<cnt;i++)
	{
		ifile>>r>>n>>m>>c>>p;
		cout<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
	}
	ifile.close();
}
int Academic::del()
{
	int r,m,p,c;
	char n[20];
	cout<<"Enter the Roll No to delete: "<<endl;
	int key;
	cin>>key;
	bool found=false;
	otemp.open("Temp.txt",ios::out);
	ifile.open("Result.txt",ios::in);
	for(int i=0;i<cnt;i++)
	{
		ifile>>r>>n>>m>>c>>p;
		if(r==key)
		{
			found=true;
		}
		else
		{
			otemp<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
		}
	}
	rename("Result.txt","Temp.txt");
	otemp.close();
	ifile.close();
	//ofile.open("Result.txt",ios::out);
	//itemp.open("Temp.txt",ios::in);
	/*for(int i=0;i<cnt-1;i++)
	{
		itemp>>r>>n>>m>>c>>p;
		ofile<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
	}
	ofile.close();
	itemp.close(); */
	if(found==false)
    {
        cout<<"Record Not Found"<<endl;
        return 0;
    }
    cnt--;
	return 1;
}
void Academic::modify()
{
	int r,m,p,c;
	char n[20];
	cout<<"Enter the Roll No to Modified: "<<endl;
	int key;
	cin>>key;
	bool found=false;
	otemp.open("Temp.txt",ios::out);
	ifile.open("Result.txt",ios::in);
	for(int i=0;i<cnt;i++)
	{
		ifile>>r>>n>>m>>c>>p;
		if(r==key)
		{
			found=true;
			cout<<endl<<"Enter Name: ";
			cin>>n;
			cout<<endl<<"Enter marks for Maths: ";
			cin>>m;
			cout<<endl<<"Enter marks for Chemistry: ";
			cin>>c;
			cout<<endl<<"Enter marks for Physics: ";
			cin>>p;
			otemp<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
		}
		else
		{
			otemp<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
		}
	}
	if(found==false)
    {
        cout<<"Roll No. Not Found";
    }
	otemp.close();
	ifile.close();
	ofile.open("Result.txt",ios::out);
	itemp.open("Temp.txt",ios::in);
	for(int i=0;i<cnt;i++)
	{
		itemp>>r>>n>>m>>c>>p;
		ofile<<r<<"\t"<<n<<"\t"<<m<<"\t"<<c<<"\t"<<p<<endl;
	}
	ofile.close();
	itemp.close();
}
int main()
{
	Academic Acad;
	int ch;
	ofile.open("Result.txt",ios::out);
	ofile.close();
	do{
		cout<<"1. Add Record to Database."<<endl;
		cout<<"2. Display all records from Database."<<endl;
		cout<<"3. Delete a record from Database."<<endl;
		cout<<"4. Modify record."<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter your choice:: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					Acad.getData();
					Acad.infile();
					break;
			case 2:
					Acad.outfile();
					break;
			case 3:
					Acad.del();
					break;
			case 4:
					Acad.modify();
					break;
			case 5:
					break;
			default:
					cout<<"Invalid Request"<<endl;
		}
	}while(ch>0&&ch<6);
}


