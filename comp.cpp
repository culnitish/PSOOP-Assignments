#include<iostream>
using namespace std;
class complex
{
	double real;
	double img;
public:
void putdata();
	complex()
   {
   real=0;
   img=0;
   }
   complex(int a,int b)
   {
    real=a;
    img=b;
   }

   complex operator +(complex c1)
   {
    complex c;
    c.real=real+c1.real;
    c.img=img+c1.img;
    return c;
   }

   complex operator -(complex c1)
   {
    complex c2;
    c2.real=real-c1.real;
    c2.img=img-c1.img;
    return c2;
   }
friend complex operator *(complex,complex);
friend complex operator /(complex,complex);

};

   complex operator *(complex c3,complex c4)
   {
   complex c;
   c.real=c3.real*c4.real+(-1)*(c3.img*c4.img);
   c.img=c3.img*c4.real+c3.real*c4.img;
   return c;
   }

   complex operator /(complex c3,complex c4)
   {
   complex c;
   c.real=(c3.real*c4.real+(-1)*(c3.img*-c4.img))/(c4.real*c4.real-c4.img*c4.img);
   c.img= (c3.img*c4.real+c3.real*c4.img)/(c4.real*c4.real-c4.img*c4.img);
   return c;
   }

  void complex::putdata()
  {
    if(img>0)
    cout<<real<<"+"<<img<<"i";
    else
    cout<<real<<img<<"i";
  }
int main()
{
int ch,d;
double x,y;
complex ob2;
cout<<"\n ENTER 1ST COMPLEX NUMBER (X+iY) FORM ";
cin>>x>>y;

complex ob(x,y);
cout<<"\n ENTER 2ND COMPLEX NUMBER (X+iY) FORM ";
cin>>x>>y;
 complex ob1(x,y);
do
{
cout<<"\n\n\tCOMPLEX MENU";
cout<<"\n1.USING MEMBER FUNCTION ";
cout<<"\n2.USING FRIEND FUNCTION ";
cout<<"\n ENTER UR CHOICE: ";
  cin>>ch;
  switch(ch)
  {
   case 1:
     cout<<"\n1. ADDITION ";
     cout<<"\n2. SUBSTRACTION ";
      cout<<"\n ENTER UR CHOICE: ";
      cin>>d;
       if(d==1)
      {
           ob2=ob+ob1;
           ob2.putdata();

      }
      else if(d==2)
      {
           ob2=ob-ob1;
           ob2.putdata();

      }
     else
      {
       cout<<"\n WRONG CHOICE";

      }
     break;
   case 2:
   cout<<"\n1.MULTIPLICATION ";
   cout<<"\n2.DIVISION ";
   cout<<"\n ENTER UR CHOICE: ";
   cin>>d;
   if(d==1)
      {
           ob2=ob*ob1;
           ob2.putdata();

      }
      else if(d==2)
      {
           ob2=ob/ob1;
           ob2.putdata();

      }
     else
      {
       cout<<"\n WRONG CHOICE";

      }


  }
}while(ch>=1&&ch<=2);
  return 0;
}

