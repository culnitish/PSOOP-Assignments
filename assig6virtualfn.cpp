#include<bits/stdc++.h>
using namespace std;
#define pi 3.141
class Shape
{
protected:
    double x,y;
    public:
    void getdata()
    {
    	cin>>x>>y;
	}
    virtual double area()=0;
};

class Triangle: public Shape
{
public:
    double area()
    {
        return (0.5*x*y);
    }

};
class Square: public Shape
{

public:
    double area()
    {
        return x*x;

    }
};

class Circle: public Shape
{

public:
    double area()
    {
        return pi*x*x;
    }
};

int main()
{
    Shape *bp;
    int ch;
    double r;
    Circle C;
    Triangle T;
    Square S;
    do
    {
    cout<<"\n AREA MENU ";
cout<<"\n1.TRIANGLE";
cout<<"\n2.SQUARE";
cout<<"\n3.CIRCLE";
cout<<"\nEnter ur Choice(1-3): ";
cin>>ch;
switch(ch)
{
case 1:

bp=&T;
bp->getdata();
r=bp->area();
cout<<r;
 break;

case 2:

bp=&S;
bp->getdata();
r=bp->area();
cout<<r;
 break;

case 3:

bp=&C;
bp->getdata();
r=bp->area();
cout<<r;
break;
    default: cout<<"\nWRONG CHOICE SORRY!!";

}
	}while(ch>=1&&ch<=3);

    return 0;
}
