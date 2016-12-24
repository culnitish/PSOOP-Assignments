#include<iostream>
#include<fstream>
using namespace std;
class personal
{   protected:
    string name;
    string dob;
    char sex;
public:
    void getdata()
    {   cout<<"\n Personal Information:-";
        cout<<"\nEnter Name: ";
        cin>>name;
        cout<<"\nEnter Gender: ";
        cin>>sex;
        cout<<"\nEnter DOB eg.(15/05/1997): " ;
        cin>>dob;
    }
    void putdata()
    {   cout<<"\n Personal Information:-\n";
        cout<<"Name: "<<name<<"\n"<<"Gender: "<<sex<<"\n"<<"DOB"<<dob<<"\n";
    }
};
class professional:virtual public personal
{
    protected:
    string workplace;
    int experience;
    int salary;
public:
    void getdata1()
    {
        cout<<"\n Enter Professional Information:-";
        cout<<"\nEnter Workplace :";
        cin>>workplace;
        cout<<"\nEnter Years of Experience: ";
        cin>>experience;
        cout<<"\nEnter CTC :";
        cin>>salary;
    }
    void putdata1()
    {
       cout<<"\n Professional Information:-\n";
       cout<<"Workplace: "<<workplace<<"\n"<<"Experience: "<<experience<<"\n"<<"Salary: "<<salary<<"\n";
    }

};
class academic: virtual public personal
{
    protected:
    double  agree;
    string schooln;
    string collegn;
public:
    void getdata2()
    {
        cout<<"\n Enter Academics Information:-";
        cout<<"\nEnter Agrregates in UG: ";
        cin>>agree;
        cout<<"\nEnter School Name: ";
        cin>>schooln;
        cout<<"\nEnter College Name: ";
        cin>>collegn;
    }
    void putdata2()
    {
        cout<<"\n Academics Information:-\n";
        cout<<"Agree: "<<agree<<"\n"<<"SchoolN: "<<schooln<<"\n"<<"CollegN: "<<collegn<<"\n";
    }

};
class employee :public professional,public academic
{
public:
    void getdata3()
    {
        getdata();
        getdata1();
        getdata2();
    }
    void putdata3()
    {
        putdata();
        putdata1();
        putdata2();
    }

};
int main()
{
    employee e;
    e.getdata3();
    e.putdata3();
    return 0;
}

