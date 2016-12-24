#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <class T,int size>
class matrix
{
    T m[size][size];
    T n[size][size];
    T r[size][size];
public:
    void addition();
    void subtraction();
    void multiplication();
    void getdata(int a,int b,int a1,int b1)
    {
       for(int i=0;i<a;i++)
       {
           for(int j=0;j<b;j++)
            cin>>m[i][j];
       }
        for(int i=0;i<a1;i++)
       {
           for(int j=0;j<b1;j++)
            cin>>n[i][j];
       }
    }
    void putdata(int a,int b1)
    {
        for(int i=0;i<a;i++)
       {
           for(int j=0;j<b1;j++)
            cout<<r[i][j]<<" ";
            cout<<"\n";
       }

    }
    void addition(int a,int b,int a1,int b1)
{
    for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            r[i][j]=m[i][j]+n[i][j];
        }
        putdata(a,b1);
}
void subtraction(int a,int b,int a1,int b1)
{
    for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            r[i][j]=m[i][j]-n[i][j];
        }
        putdata(a,b1);
}
void multiplication(int a,int b,int a1,int b1)
{
    for(int i=0;i<a;i++)
    {
    for(int j=0;j<b1;j++)
     { r[i][j]=0;
    for(int k=0;k<a1;k++)
      {
        r[i][j]+=m[i][k]*n[k][j];//a*b1
      }
     }
    }
   putdata(a,b1);
}

};

int main()
{
matrix<int,10> m1;
matrix<float,10>m2;
int ch,w,x,y,z;
do
{
cout<<"\n MATRIX MENU";
cout<<"\n1.GET ARRAY";
cout<<"\n2. ADDITION OF TWO ARRAY";
cout<<"\n3. SUBTRACTION OF TWO ARRAY";
cout<<"\n4. MULTIPLICATION OF TWO ARRAY";
cout<<"\n Enter ur Choice(1-3): ";
cin>>ch;
switch(ch)
{
    case 1:
    cout<<"\n Enter 1st array row nd Column Size";
    cin>>w>>x;
    cout<<"\n Enter 2nd array row nd Column Size";
    cin>>y>>z;
    m1.getdata(w,x,y,z);
    break;
    case 2:
        if(w!=y||x!=z)
        {
            cout<<"\n ADDITION NOT POSSIBLE ";
            break;
        }
        else
         m1.addition(w,x,y,z);

        break;
    case 3:
        if(w!=y||x!=z)
        {
            cout<<"\n SUBTRACTION NOT POSSIBLE ";
            break;
        }
    m1.subtraction(w,x,y,z);
    break;
    case 4:
        if(x==y)
        m1.multiplication(w,x,y,z);
        else
            cout<<"\n MULTIPLICATION NOT POSSIBLE ";
        break;
        default: cout<<"\n WRONG CHOICE!!!";

}
}while(ch>=1&&ch<=4);
return 0;
}
