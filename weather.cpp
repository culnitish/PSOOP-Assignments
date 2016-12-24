#include<iostream>
using namespace std;
class weather
{
int d,ht,lt,ar,as;
public:
weather()
	{
	ht=0;
	lt=0;
	as=0;
	ar=0;

	}
	int rday()
	{
	    return d;
	}
	void getdata(int);
	void display();
	int dispspeci(int);
	int del(int);
	void average(int,int);
	int modify(int);
};

void weather::getdata(int n)
{     int flag=0,i,r;
      d=n;
	  cout<<"\nhigh temprature: ";
	  cin>>ht;
	  cout<<"\nlow temprature: ";
	  cin>>lt;
	  cout<<"\namount of rain: ";
	  cin>>ar;
	  cout<<"\namount of snow: ";
	  cin>>as;
}

int weather:: dispspeci(int r)
{
  int flag=0;
  if(d==r)
  {  cout<<"DAY"<<"\t"<<"HT"<<"\t"<<"LT"<<"\t"<<"RAIN"<<"\t"<<"SNOW"<<"\t"<<"\n";
     cout<<d<<"\t"<<ht<<"\t"<<lt<<"\t"<<ar<<"\t"<<as;
     flag=1;
  }
   return flag;
}
void weather::display()
{
cout<<d<<"\t"<<ht<<"\t"<<lt<<"\t"<<ar<<"\t"<<as;
}
int weather::modify(int r)
{
    int flag=0;
    if(r==d)
    {  flag=1;
       getdata(r);
    }

    return flag;

}
void weather::average(int n,int r)
{  static int sht,slt,sar,sas,cnt;


 if(ht!=0&&lt!=0&&ar!=0&&as!=0)
  {
  sht+=ht;
  slt+=lt;
  sar+=ar;
  sas+=as;
  cnt++;
  }

if(n-1==r)
{
   cout<<"htemp"<<"\t"<<"ltemp"<<"\t"<<"arain"<<"\t"<<"asnow"<<"\t"<<"\n";
    cout<<sht/cnt<<"\t"<<slt/cnt<<"\t"<<sar/cnt<<"\t"<<sas/cnt;
    sht=0;slt=0;sar=0;sas=0;cnt=0;
}

}
int weather::del(int r)
{
    int flag=0;
    if(r==d)
    {
    d=0;
    ht=0;
	lt=0;
	as=0;
	ar=0;
	flag=1;
	}
	return flag;
}

int main()
{
	weather w[10];
	int i,m,t,j,day,r,k=0,f=0,n=0,ch;
	char c;
	 	do
	   {
	    cout<<"\n WEATHER MENU";
		cout<<"\n1.ACCEPT RECORD\n";
		cout<<"2.DISPLAY RECORD \n";
		cout<<"3.SPECIFIC DAY WEATHER REPORT\n";
		cout<<"4.MODIFY DAY REPORT\n";
		cout<<"5.DELETE REPORT\n";
		cout<<"6.AVERAGE OF REPORT\n ";
		cout<<"  ENTER UR CHOICE(1-6) : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
        do
         {
            for(i=n;i<n+1;i++,k++)
			{ f=0;c='n';
		     cout<<"\nEnter the data  "<<"\n";
		     cout<<"\nday of month: ";
		     cin>>day;
		     if(i==0)
			 w[i].getdata(day);
			 else
             {
                 for(j=0;j<i;j++)
                 {
                    r=w[j].rday();
                    if(r==day)
                    {
                        cout<<"\n day already exist ";
                        cout<<"\n WANT TO TRY(y/n)";
                        cin>>c;
                        k--;
                        f=1;
                        break;
                    }
                 }
              if(f==0)
               w[i].getdata(day);
             }

			}
			n=k;
         }while(c=='y'||c=='Y');


			break;

			case 2:
            cout<<"Display the data\n";
			cout<<"DAY"<<"\t"<<"HT"<<"\t"<<"LT"<<"\t"<<"RAIN"<<"\t"<<"SNOW"<<"\t"<<"\n";
			for(i=0;i<n;i++)
			{
				w[i].display();
				cout<<"\n";
			}
			break;

			case 3:
            do
            {
            cout<<"Enter the day to display: ";
			cin>>m;

			for(i=0;i<n;i++)
			 {
			    r=w[i].dispspeci(m);
			    if(r==1)
                    break;
			 }
			if(r==0)
               {
                cout<<"\nNOT FOUND DAY ";
                cout<<"\n WANT AGAIN TO TRY(y/n): ";
                cin>>c;
               }
			cout<<"\n";
            }while(c=='y'||c=='Y');
           break;
			case 4:
			   do
               {
                  cout<<"enter the data to modify: ";
			     cin>>m;
			     for(i=0;i<n;i++)
			     {
			    r=w[i].modify(m);
			    if(r==1)
                    {   cout<<"\nDAY MODIFIED\n";
                        break;
                    }
			     }
			    if(r==0)
                {
                    cout<<"\nNOT FOUND DAY ";
                   cout<<"\n WANT AGAIN TO TRY(y/n): ";
                   cin>>c;
                }

               }while(c=='y'||c=='Y');
            break;

			case 5:
            do
            { f=0;
              cout<<"\n enter the day to delete the data: ";
            cin>>m;
            for(i=0;i<n;i++)
            {
                r=w[i].del(m);
                if(r==1)
                   {
                      cout<<"\nDAY DATA DELETED\n";
                      f=1;
                     break;
                   }
            }
            if(r==0)
              {
                cout<<"\nNOT FOUND DAY ";
                   cout<<"\n WANT AGAIN TO TRY(y/n): ";
                   cin>>c;

              }
              if(f==1)
                break;

            }while(c=='y'||c=='Y');

            break;

            case 6:
            cout<<"\n AVERAGE OF WEATHER REPORT\n";
            for(i=0;i<n;i++)
                w[i].average(n,i);
		}

	}while(ch>=1&&ch<=6);
	return 0;

}

