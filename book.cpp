#include<bits/stdc++.h>
using namespace std;
class book
{
    char *title,*author,*publisher;
    int stock;
    double price;
   public:
       static int t,tr;
     book()
     {
         stock=0;
         price=0;
         title=new char[1];
         author=new char[1];
         publisher=new char[1];
     }
     void add(char *);
     void display();
     void modify();
     void purchase();
     void no_transaction()
     {
         cout<<"\n No. Of Sucessful Transactions "<<t;
         cout<<"\n No. Of UnSucessful Transactions "<<tr;
     }
     char* rtitle()
     {
         return title;
     }

};
int book::t;
int book::tr;
void book::display()
{
    cout<<title<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<price<<"\t"<<stock<<"\n";
}
void book::add(char *b)
{
    char s[100];
    strcpy(title,b);
    cout<<"\nENTER AUTHOR NAME: ";
    cin>>s;
    strcpy(author,s);
    cout<<"\nENTER PUBLISHER NAME: ";
    cin>>s;
    strcpy(publisher,s);
    do
    {
    cout<<"\nENTER PRICE: ";
    cin>>price;
    }while(price<=0);

    do
    {
     cout<<"\n ENTER STOCK: ";
     cin>>stock;
    }while(stock<=0);


}

void book::modify()
{
    char s[100];
    int ch;
    cout<<"\n1.BOOK NAME";
    cout<<"\n2.AUTHOR NAME: ";
    cout<<"\n3.PUBLISHER NAME: ";
    cout<<"\n4.PRICE: ";
    cout<<"\n5.STOCK: ";
    cout<<"\n enter your Choice to update: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
       cout<<"\n ENTER BOOK TITLE: ";
       cin>>s;
       strcpy(title,s);
       break;
       case 2:
        cout<<"\nENTER AUTHOR NAME: ";
    cin>>s;
    strcpy(author,s);
    break;
    case 3:
    cout<<"\nENTER PUBLISHER NAME: ";
    cin>>s;
    strcpy(publisher,s);
    break;
    case 4:
   do
    {
    cout<<"\nENTER PRICE: ";
    cin>>price;
    }while(price<=0);
    break;
    case 5:
    do
    {
     cout<<"\n ENTER STOCK: ";
     cin>>stock;
    }while(stock<=0);
    break;
    default: cout<<"\nWrong Choice!!";
    }
cout<<"\n BOOK DATA UPDATED";
}

void book::purchase()
{
    int no;
    float tpr;
    cout<<"\n Enter How many books";
    cin>>no;
    if(no<=stock&&no>0)
    {
        stock-=no;
        tpr=no*price;
        cout<<"\n BOOK DETAILS TO PURCHASE:\n ";
         cout<<"TITLE\t"<<"AUTHOR\t"<<"PUBLISHER\t"<<"PRICE\t"<<"QNTY\t"<<"T_PRICE"<<"\n";
         cout<<title<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<price<<"\t"<<no<<"\t"<<tpr<<"\n";
         cout<<"\n PROCESSED BOOK PURCHASED";
         t++;
    }
    else
       {
         cout<<"\n NOT MUCH COPY OF THAT BOOK";
           tr++;
       }
}

int main()
{
    book b[20];
    char str[100],c;
    int i=0,ch,k=1,j=0,f=0;
    //book b1=new book();
    cout<<"\nBOOK DEPO";
    cout<<"\n ENTER TITLE OF BOOK: ";
          cin>>str;
          b[j].add(str);
          j++;
           k=j;
    do
    {
    cout<<"\nBOOK DEPO";
    cout<<"\n1.ADD BOOKS TO DEPO ";
    cout<<"\n2.DISPLAY BOOKS";
    cout<<"\n3.SEARCH A BOOK ";
    cout<<"\n4.BOOK MODIFY ";
    cout<<"\n5.PURCHASE  BOOKS ";
    cout<<"\n6.NO OF TRANSACTIONS TILL DATE";
    cout<<"\n  Enter your choice(1-6): ";
    cin>>ch;
    switch(ch)
    {
      case 1:
          do
          {
           c='n';
             f=0;
          cout<<"\n ENTER TITLE OF BOOK: ";
          cin>>str;
             for(int l=0;l<k;l++)
                {
                   if(strcmp(b[l].rtitle(),str)==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                   {
                     b[j].add(str);
                     j++;
                     k=j;
                   }
                else
                   {
                     cout<<"\n TRY AGAIN BOOK NAME ALREADY EXIST";
                     cout<<"\n Want TO try again (Y/N) ";
                     cin>>c;
                   }

          }while(c=='Y'||c=='y');

         break;
       case 2:
       cout<<"TITLE\t"<<"AUTHOR\t"<<"PUBLISHER\t"<<"PRICE\t"<<"STOCK\n";
        for(i=0;i<k;i++)
        b[i].display();
        break;
       case 3:
           f=0;
       cout<<"\n ENTER BOOK NAME TO SEARCH: ";
    cin>>str;
    for(i=0;i<k;i++)
    {
         if(strcmp(b[i].rtitle(),str)==0)
         {
         f=1;
          cout<<"\n FOUND\n";
          cout<<"TITLE\t"<<"AUTHOR\t"<<"PUBLISHER\t"<<"PRICE\t"<<"STOCK\n";
          b[i].display();
          break;
         }
    }
    if(f==0)
        cout<<"\n SORRY!!! WRONG BOOK NAME!! TRY AGAIN";
    break;
       case 4:
           f=0;
            cout<<"\n ENTER BOOK NAME TO MODIFY: ";
    cin>>str;
    for(i=0;i<k;i++)
    {

         if(strcmp(b[i].rtitle(),str)==0)
         {
             f=1;
             cout<<"\n FOUND\n";
             b[i].modify();
             break;

         }
    }
     if(f==0)
        cout<<"\n SORRY!!! WRONG BOOK NAME!! TRY AGAIN";
    break;
     case 5:
         f=0;
       cout<<"\n ENTER BOOK NAME TO PURCHASE: ";
    cin>>str;
    for(i=0;i<k;i++)
    {

         if(strcmp(b[i].rtitle(),str)==0)
         {
             f=1;
             cout<<"\n FOUND\n";
             b[i].purchase();
             break;
         }
    }
    if(f==0)
    {
        b[i].tr++;
         cout<<"\n SORRY!!! WRONG BOOK NAME!! TRY AGAIN";
    }

    break;
    case 6:
     b[i].no_transaction();
     break;
    }
    }while(ch>=1&&ch<=6);

    return 0;
}
