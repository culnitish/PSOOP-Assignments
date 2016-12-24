#include<iostream>
using namespace std;
class tvmodel
{
	int model,size,price,m,k,flag;
	public:
    friend istream &operator >>(istream &input,tvmodel &s);
    friend ostream &operator <<(ostream &output,tvmodel &s);
};

	istream &operator >>(istream &input,tvmodel &s)
	{
				tag:
				try
				{
					cout<<"enter the model number : ";
					input>>s.model;
					if(s.model<0||s.model>100)
					{
						throw s.model;
					}
				}
				catch(int)
				{

				cout<<"invalid entry\n"	;
				goto tag;
				}
				tag4:
			try
				{
					cout<<"enter the size number : ";
					input>>s.size;
					if(s.size<12||s.size>70)
					{
						throw s.size;
					}
				}
				catch(int)
				{
				cout<<"invalid entry\n"	;
				goto tag4;
				}
				tag5:
			try
				{
					cout<<"enter the price : ";
					input>>s.price ;
					if(s.price<0||s.price>50000)
					{
						throw s.price;
					}
				}
				catch(int)
				{
				cout<<"invalid entry\n"	;
				goto tag5;
				}
			}



		ostream &operator <<(ostream &output,tvmodel &s)
		{   output<<"\nModel number :"<<s.model<<"\n";
    		output<<"price of device:"<<s.price<<"\n";
    		output<<"Size of device:"<<s.size<<"\n";

		}
	int main()
{
    tvmodel m[5];
    int n,i,j,k;
    do{
        cout<<"1.enter data\n2.diplay\n";
        cin>>k;
    switch(k)
    {
    case 1:
    cout<<"Enter no. of data you want to take :  ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m[i];

    }
    break;
    case 2:
    for(i=0;i<n;i++)
    {
        cout<<m[i];
    }
    break;
    }
    }while(k!=2);
    return 0;
}

