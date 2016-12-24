#include <bits/stdc++.h>
using namespace std;

ofstream fout;
ifstream fin;

class personal
{
protected:
    string name;
	int id,age,date,month,year,weight,height;
public:
	void getdata()
	{
	    cout<<"Enter person ID number::";
	    cin>>id;
		cout<<"Enter name of person::";
		cin>>name;
		cout<<"Enter age::";
		cin>>age;
		cout<<"Enter DOB::";
		cin>>date>>month>>year;
		cout<<"Enter weight::";
		cin>>weight;
		cout<<"Enter height::";
		cin>>height;
	}
};

class academic:virtual public personal
{
protected:
    string nos;
	int c1,c2;
public:
	void getdata()
	{
		cout<<"Enter the school name::";
		cin>>nos;
		cout<<"Enter class 10 CGPA::";
		cin>>c1;
		cout<<"Enter class 12 percent::";
		cin>>c2;
	}
};

class professional:virtual public personal
{
protected:
	int salary,yoe;
	string cn,position;
public:
	void getdata()
	{   cin.ignore();
        fflush(stdin);
		cout<<"Enter company name::";
		cin>>cn;
		cout<<"Enter the position::";
		cin>>position;
		cout<<"Enter the salary::";
		cin>>salary;
		cout<<"Enter years of exp::";
		cin>>yoe;
	}
};

class master:public academic,public professional
{
public:
    master()
    {
        name="\0",nos="\0",cn="\0",position="\0";
        age=0,date=0,month=0,year=0,weight=0,height=0,c1=0,c2=0,salary=0,yoe=0;
    }
	void getdata()
	{
		personal::getdata();
		academic::getdata();
		professional::getdata();
		fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
	}
	void display()
	{
	    fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
	    cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<date<<"/"<<month<<"/"<<year<<"\t"<<weight<<"\t"<<height<<"\t"<<nos<<"\t\t"<<c1<<"\t"<<c2<<"\t\t"<<cn<<"\t\t"<<position<<"\t"<<salary<<"\t"<<yoe<<endl;
	}
	void searching()
	{
	    int pno;
        cout<<"Enter the person ID no. you want to search::";
        cin>>pno;
	    fin.open("f://test.txt",ios::in);
	    int flag=0;
	    while(fin)
        {
            fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
            if(id==pno)
            {
                flag=1;
                cout<<"\nRecord found!!!\n\n";
                cout<<"IDNo.\tNAME\tAGE\tDOB\tWEIGHT\tHEIGHT\tSCHOOL NAME 10th CGPA\t12th PERCENT COMPANY NAME\tPOSITION\tSALARY EXP."<<endl;
                cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<date<<"/"<<month<<"/"<<year<<"\t"<<weight<<"\t"<<height<<"\t"<<nos<<"\t\t"<<c1<<"\t"<<c2<<"\t\t"<<cn<<"\t\t"<<position<<"\t"<<salary<<"\t"<<yoe<<endl;
                break;
            }
        }
        fin.close();
        if(flag==0)
            cout<<"\nRecord not found\n";
	}
	int deleting()
	{
	    int pno;
        cout<<"Enter the person ID no. you want to delete::";
        cin>>pno;
	    fin.open("f://test.txt",ios::in);
	    fout.open("f://temp.txt",ios::out);
	    int flag=0;
	    while(fin)
        {
            fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
            if(id==pno)
                flag=1;
            else
                fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
        }
        fin.close();
        fout.close();
        if(flag==0)
            cout<<"\nRecord not found\n";
        if(flag==1)
        {
            fin.open("f://temp.txt",ios::in);
            fout.open("f://test.txt",ios::out);
            while(fin)
            {
                fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
                fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
            }
            fin.close();
            fout.close();
            return 1;
        }
	}
	int modify()
	{
	    int pno,c;
        cout<<"Enter the person ID no. you want to modify::";
        cin>>pno;
	    fin.open("f://test.txt",ios::in);
	    fout.open("f://temp.txt",ios::out);
	    int flag=0;
	    while(fin)
        {
            fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
            if(id==pno)
            {
                flag=1;
                do
                {
                    cout<<"\nWhat do you want to modify->\n1. Age\n2. Weight\n3. Height\n4. Company name\n5. Position\n6. Salary\n7. Experience\n8. Exit\nEnter your choice::";
                    cin>>c;
                    switch(c)
                    {
                        case 1 :cout<<"Enter the new age::";
                                cin>>age;
                                break;
                        case 2 :cout<<"Enter the new weight::";
                                cin>>weight;
                                break;
                        case 3 :cout<<"Enter the new height::";
                                cin>>height;
                                break;
                        case 4 :cout<<"Enter the new company name::";
                                cin>>cn;
                                break;
                        case 5 :cout<<"Enter the new position::";
                                cin>>position;
                                break;
                        case 6 :cout<<"Enter the new salary::";
                                cin>>salary;
                                break;
                        case 7 :cout<<"Enter the new experience::";
                                cin>>yoe;
                                break;
                        case 8 :return 0;
                                break;
                        default:cout<<"Invalid Input!!!\n";
                    }
                }while(c!=8);
                fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
            }
            else
                fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
        }
        fin.close();
        fout.close();
        if(flag==0)
            cout<<"\nRecord not found\n";
        if(flag==1)
        {
            fin.open("f://temp.txt",ios::in);
            fout.open("f://test.txt",ios::out);
            while(fin)
            {
                fin>>id>>name>>age>>date>>month>>year>>weight>>height>>nos>>c1>>c2>>cn>>position>>salary>>yoe;
                fout<<id<<" "<<name<<" "<<age<<" "<<date<<" "<<month<<" "<<year<<" "<<weight<<" "<<height<<" "<<nos<<" "<<c1<<" "<<c2<<" "<<cn<<" "<<position<<" "<<salary<<" "<<yoe<<endl;
            }
            fin.close();
            fout.close();
        }
	}
};

int main()
{
    master ob;
    int ch,i,j=0,temp=0;
    char c;
    do
    {
        cout<<"\n1. Enter data\n2. Display data\n3. Search\n4. Delete\n5. Update\n6. Exit\nEnter your choice::";
        cin>>ch;
        switch(ch)
        {
            case 1 :fout.open("f://test.txt",ios::app);
                    ob.getdata();
                    j++;
                    fout.close();
                    break;
            case 2 :fin.open("f://test.txt",ios::in);
                    /*if(j==0)
                    {
                        cout<<"\nNo records to display!!!\n";
                        break;
                    }
                    cout<<"IDNo.\tNAME\tAGE\tDOB\tWEIGHT\tHEIGHT\tSCHOOL NAME 10th CGPA\t12th PERCENT COMPANY NAME\tPOSITION\tSALARY EXP."<<endl;
                    for(i=0;i<j;i++)*/
                        while(fin){
                        c=fin.get();
                        cout<<c;
                        }

                    fin.close();
                    break;
            case 3 :ob.searching();
                    break;
            case 4 :temp=ob.deleting();
                    if(temp==1)
                        j--;
                    break;
            case 5 :ob.modify();
                    break;
            case 6 :return 0;
                    break;
            default:cout<<"Invalid Input!!!\n";
        }
	}while(ch!=6);
    return 0;
}
