#include<iostream>
using namespace std;
class base
{
    string s;
public:
    friend void operator ==(base x,base y);
    friend istream& operator >> (istream & in, base &x);
    friend ostream& operator << (ostream & out, base &x);
    friend int operator / (base x, base y);
};

void operator ==(base x,base y)
{
    x.s=y.s;
}
istream& operator >> (istream & in, base &x)
{
    in>>x.s;
    return in;
}
ostream& operator << (ostream & out, base &x)
{
    out<<x.s;
    return out;
}
int operator / (base x, base y)
{
    string a=x.s;
    int l=a.length()-1;
    for(int i=0;i<=l/2;i++)
    {
        char t=a[i];
        a[i]=a[l-i];
        a[l-i]=t;
    }
    if(a==x.s)
        return 1;
    else
        return 0;
}

int main()
{
    base a,b;
    int f=0,c;
    while(1)
    {
        cout<<"\n\n1.input\n2.display\n3.copy\n4.check for palindrome\n5.exit \n Enter your choice:";
        cin>>c;
        switch(c)
        {
            case 1: cout<<"\nenter the string : ";
                    cin>>a;
                    f=1;
                    break;
            case 2: if(f==0)
                    {
                        cout<<"\nenter the string : ";
                        cin>>a;
                        f=1;
                    }
                    cout<<a;
                    break;
            case 3: if(f==0)
                    {
                        cout<<"\nenter the string : ";
                        cin>>a;
                        f=1;
                    }
                    b==a;
                    cout<<b;
                    break;
            case 4: if(f==0)
                    {
                        cout<<"\nenter the string : ";
                        cin>>a;
                        f=1;
                    }
                    if(a/a)
                        cout<<"\nPalindrome";
                    else
                        cout<<"\nNot a palindrome";
                    break;
            case 5: return 0;
        }
    }
}
