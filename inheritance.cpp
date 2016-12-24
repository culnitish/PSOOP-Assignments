#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
class A

{
   protected:
   char bg[30],dob[34];
   char name[45];
   public:
};
class B
{
    protected:
    float ht,wt;
    public:
};
class C
{
    protected:
    char ipno[45];
    char contact[100];
    public:
};
class D:public A,protected B,public C
{
    int tno;
	char dlno[100];
    public:

        static int count;
        void getdata(char*);
        void display();
        char *getipno();
        void modify();
        void deleted(char*);


}o[10],b;
int D::count=0;
void D::getdata(char *x)
{
    cout<<"enter the name\n";
    cin>>name;
    cout<<"Enter D.O.B  :";
    cin>>dob;
    cout<<"Enter Blood Group :";
    cin>>bg;
    cout<<"Enter Height(in cms) :";
    cin>>ht;
    cout<<"Enter Weight(in kg):";
    cin>>wt;
   // cout<<"Enter Insurance policy number  :";
    strcpy(ipno,x);
    cout<<"Enter Contact :";
    cin>>contact;
    cout<<"enter the telephone number";
    cin>>tno;
    cout<<"enter the driving lisense number:";
    cin>>dlno;
    count++;

}

void D::display()
{
    cout<<name;
    cout<<"\t";
    cout<<dob;
    cout<<"\t";
    cout<<bg;
    cout<<"\t";
    cout<<ht;
    cout<<"\t";
    cout<<wt;
    cout<<"\t";
    cout<<ipno;
    cout<<"\t";
    cout<<contact;
    cout<<"\t";
    cout<<tno;
    cout<<"\t";
    cout<<dlno;
    cout<<"\n";

}
char* D::getipno()
{

    return ipno ;
}
void D::deleted(char *ipno1)
{    int j,k,i;
      for(i=0;i<count;i++)
       if(strcmp(o[i].getipno(),ipno1)==0)
           {
          /* for(k=i,j=k+1;j<count;k++,j++)
           {
               o[k]=o[j];
           }*/
           o[i]=o[count-1];
            count--;
           }

}
void D::modify()
{
  	char s[100];
  	float f;
	int c,d,p;
	do
	{
		cout<<"1.name\n2.dob \n3.bg\n4.heigt\n5.weight\n6.insurnpo_no\n7.telephone_no\n8.dl_no\n";
		cout<<"what u want to modify\n";
	    cin>>c;
	switch(c)
	{
		case 1:
			cout<<"name of the person\n";
			cin>>s;
			strcpy(name,s);
			break;
		case 2:
			cout<<"write the DOB\n";
			cin>>s;
			strcpy(dob,s);
			break;
		case 3:
			cout<<"write the blood group\n";
			cin>>s;
			strcpy(bg,s);
			break;
		case 4:
			cout<<"enter the height\n";
			cin>>f;
			ht=f;
            break;
		case 5:
			cout<<"enter the weight\n";
			cin>>f;
			wt=f;
			break;
       case 6:
			cout<<"enter the isurance policy number\n";
			cin>>s;
			strcpy(ipno,s);
			break;
    case 7:
			cout<<"enter the telephone number\n";
			cin>>p;
			tno=p;
			break;
    case 8:
			cout<<"enter the driving liesence\n";
			cin>>s;
			strcpy(dlno,s);
			break;
		}
		cout<<"press 1 to modify again in this data or 2 to exit\n";
		cin>>d;
	}while(d==1);
}


int main()
{
    int n,j,i=0,m=0,l,x,flag=0;
    char ipno2[45];
    char t[100];
    char h[30];

    do{
       cout<<"1.entering the data\n2.displaying of the data\n3.seaching the name\n4.modifying the data\n5.deleting the data\n";
       cout<<"enter your choice\n";
       cin>>l;
       switch(l)
    {

   case 1:
    			do
    			{
    			cout<<"Enter the ipno\n";
    			cin>>t;
    			flag=1;
    			for(int j=0;j<D::count;j++)
                       if(strcmp(o[j].getipno(),t)==0)
                       {
                           flag=0;
                           break;
                           }
                    if(flag==1)
                    {
                        o[i++].getdata(t);


                    }
                    else
                    {
                        cout<<"ipno already exist\n";
                    }
    			cout<<"press 1 to continue\n";
    			cin>>x;
				}while(x==1);
    			break;
    case 2:cout<<"Name\tDOB\tBGroup\tHeight\tWeight\tI.PNO\tCont\tteleph\tDLNO\n";
                   for(j=0;j<D::count;j++)
                   o[j].display();
                   break;

    case 3:  cout<<"enter the ipno to be searched ";
             cin>>ipno2;
             m=0;
            for(i=0;i<D::count;i++)
             {
            if(strcmp(o[i].getipno(),ipno2)==0)
            {
			cout<<"found\n";
            m=1;
        }
             }
        if(m==0)cout<<"not found\n";
        break;
    case 4:
    				m=0;
					cout<<"enter the ipno to modify\n";
					cin>>ipno2;
					for(int j=0;j<D::count;j++)
					{
						if(strcmp(o[j].getipno(),ipno2)==0)
    					{
    						flag=1;
    						cout<<"person found\n";
    						m=1;
    						o[j].modify();
    						break;
						}
					}
						if(m==0)
						cout<<"not found\n";

        break;
     case 5:	do
				{
					m=0;
					cout<<"enter the ipno to delete\n";
					cin>>ipno2;
					for(int j=0;j<D::count;j++)
					{
						if(strcmp(o[j].getipno(),ipno2)==0)
    					{
    						flag=1;
    						cout<<"person found\n";
    						m=1;
    						o[j].deleted(ipno2);
    						break;
						}
					}
					if(m==0)
					cout<<"not found\n";
				    cout<<"press 1 to delete again or 2 to exit\n";
    			    cin>>x;
				}while(x==1);
             break;
        default: cout<<"wrong choice entered";
    }
        cout<<"press 1 to show the list again or 2 to exit\n";
        cin>>x;
	}while(x==1);
}
