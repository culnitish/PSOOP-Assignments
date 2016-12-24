#include<iostream>
#include<fstream>
using namespace std;
class Sample
{
    char s[20];
    int a;
    float b;
public:
    void getdata();
    void putdata();
};
void Sample::getdata()
{
    ofstream f;
    f.open("f://abc.txt",ios::app);
    cout<<"\n Enter Name: ";
    cin>>s;
    f<<s<<" ";
    cout<<"\n Enter Roll NO.: ";
    cin>>a;
    f<<a<<" ";
    cout<<"\n Enter your Marks: ";
    cin>>b;
    f<<b<<"\n";
    f.close();
}
void Sample::putdata()
{
    char line[100],ch;
    ifstream f;
    cout<<"NAME\t"<<"ROLL NO\t"<<"MARKS\n";
    f.open("f://abc.txt");
 while(f!=NULL)
 {
    // f.getline(line,100);
    // cout<<line;
    ch=f.get();
     if(ch=='\n')
     cout<<"\n";
     cout<<ch;

 }
 f.close();


}

int main()
{
    Sample s;
    s.getdata();
    s.putdata();


    return 0;
}
