#include<iostream>
#include<fstream>
#include<string>


using namespace std;

struct book
{
    string name;
    int year;
    string author;
    int id;
    float price;
};

struct cashier
{
    string name;
    int pass;
};

bool login();
void forgotpass();
bool search(string bn);
float add(string bn,string cn);
void dataupdate();
void quotation(string cn);
void discount(string cn,float total);
void bills (string billid);

int main()
{
    //variables
    char rollcon,cuscon,srccon,lcon,cshiaddcon;
    string cname,sbname,cshibname,billno;
    float tot,cashitot;
    bool l1,status,cshilo2;
    int billid = 20001;

    cout<<"\n\t\t.-' **** Nethra Book Shop **** '-.\t\t\n\n";
    cout<<"> Choose your roll_ \n\n1. customer\n2. cashier\n3. admin\n";
    cin>>rollcon;
    
    switch (rollcon)
    {
    //customer
    case '1':
    {
        //incorrect command loop
        bool cusloop1;
        
        cout<<"\nEnter your name: "; 
        cin>>cname;
        cout<<"\n**********************************************************************\n\n";
        cout<<" Welcome, "<<cname<<"!\n\n";

            do
            {
             cout<<"1. cart\n2. book list\n";
             cin>>cuscon;

                if (cuscon=='1')
                {
                    bool loop2,catsearch;
                    char billcon;

                    do
                    {
                        cout<<"# Book name: "; 
                        cin>>sbname;

                        catsearch = search(sbname);

                        if(!catsearch)
                        {
                            loop2 = true;
                        }
                        else
                        {
                            cout<<"\n1. Add to cart\n2. Research\n"; 
                            cin>>srccon;

                            if(srccon=='1')
                            {
                                tot += add (sbname,cname);
                                cout<<"\n> Print bill\n   yes(y)    no(n)\n";
                                cin>>billcon;

                                if(billcon=='y'||billcon=='Y')
                                {
                                    cout<<"\n**********************************************************************\n";
                                    discount(cname,tot);
                                    quotation(cname);
                                    bills(cname);
                                    loop2=false;
                                }
                                else
                                {
                                    loop2=true;
                                }
                            }
                            else if(srccon=='2')
                            {
                                loop2=true;
                            }
                            else
                            {
                                cout<<"incorrect command";
                                loop2=true;
                            }
                        }

                    }while(loop2==true);

                    cusloop1 = false;
                }
                else if (cuscon=='2')
                {
                    //book list
                    cusloop1 = false;
                }
                else
                {
                    cout<<"\nIncorrect command !!\n\n";
                    cusloop1=true;
                }
            }while (cusloop1==true);

            main();

    break;
    }
    //cashier
    case '2':
        char cshilogcon;
        bool cshirlo3;

        do
        {
            cout<<"\n1. Login\n2. exit\n";
            cin>>cshilogcon;
            if (cshilogcon == '1')
            {
                do
                {
                    status = login();

                    if(!status)
                    {
                        cout<<"\n1. retry\n2. forget password\n";
                        cin>>lcon;
                        if (lcon == '1')
                        {
                            l1 = true;
                        }
                        else if (lcon == '2')
                        {
                            forgotpass();
                            l1 = true;
                        }
                    }
                    else
                    {
                        char cshircon2;
                        bool cshirlo4,cashisvalue;

                        do
                        {
                            cout<<"\n1.counter\n2.Logout\n";
                            cin>>cshircon2;

                            if (cshircon2 == '1')
                            {
                                cout<<"\n**********************************************************************\n\t\t\t>> Counter page <<\n";
                                do
                                {
                                    cout<<"# Book Name: ";
                                    cin>>cshibname;

                                    cashisvalue = search(cshibname);

                                    if(!cashisvalue)
                                    {
                                        cshilo2 = true;
                                    }
                                    else
                                    {
                                        cout<<"\n1. add   2. research\n";
                                        cin>>cshiaddcon;

                                        if (cshiaddcon == '1')
                                        {

                                            char cshibillcon;

                                            billno = to_string(billid);

                                            cashitot += add(cshibname,billno);

                                            cout<<"\n> Print bill\n   yes(y)    no(n)\n\n";
                                            cin>>cshibillcon;
                    
                                            if(cshibillcon == 'y')
                                            {
                                                discount(billno,cashitot);
                                                quotation(billno);

                                                bills(billno);

                                                cshilo2 = false;
                                                cshirlo4 = true;

                                                billid ++;
                                            }
                                            else
                                            {
                                                cshilo2 = true;
                                            }
                                        }
                                        else
                                        {
                                            cshilo2 = true;
                                        }
                                    }

                                }while(cshilo2 == true);
                            }
                            else
                            {
                                cshirlo3 = true;
                                cshirlo4 = false;
                                l1 = false;
                            }
                        } while (cshirlo4 == true);
                    }
                } while (l1 == true);
            }
            else
            {
                cout<<"\nHave a nice day !!";
                cshirlo3 = false;
            }
        } while (cshirlo3 == true);
        
        break;
    
        //admin
    case '3':
        char adcon1,adcon2,adcon3;
        bool adbool1,adlop1,adlop2,adlop3;

        do
        {
            cout<<"\n1. Login\n2. Exit";
            cin>>adcon1;

            if (adcon1 == '1')
            {
                do
                {
                    adbool1 = login();

                    if (!adbool1)
                    {
                        cout<<"\n1. retry\n2. forget password\n";
                        cin>>adcon2;
                        if (adcon2 == '1')
                        {
                            adlop2 = true;
                        }
                        else if (adcon2 == '2')
                        {
                            forgotpass();
                            adlop2 = true;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout<<"\n1. Data base\n2. Orders\n3. Logout ";
                            cin>>adcon3;

                            switch (adcon3)
                            {
                            case '1':
                            
                                dataupdate();
                                adlop3 = true;

                                break;
                            case '2':
                                {
                                string line;

                                fstream ord ("bills.txt");

                                while (getline(ord,line))
                                {
                                    cout<<line<<endl;
                                }
                                ord.close();

                                break;
                                }
                            case '3':
                                adlop3 = false;
                                adlop2 = false;
                                adlop1 = true;
                        
                            default:

                                cout<<"\nIncorrect command !!\n\n";
                                adlop3 = true;

                                break;
                            }
                        } while (adlop3 == true);
                        
                    }
                }while (adlop2 == true);
            }
            else
            {
                adlop1 = false;
            }

        } while (adlop1 == true);

        break;
    default:
        main();
        break;
    }

    return 0;
}

bool login()
{
    string username,pass,cu,cp;
    cout<<"**********************************************************************\n\t\t\t>> Login Page <<\n";
    cout<<"\t# User name: "; 
    cin>>username;
    cout<<"\t# Password : "; 
    cin>>pass;

    ifstream read(username + ".txt");
    getline(read,cu);
    getline(read,cp);

    if (username==cu && pass==cp)
    {
        cout<<"\nLogin successful !!\n\n**********************************************************************\n Hi, "<<cu<<".\n";
        return true;
    }
    else
    {
        cout<<"\nLogin feild !!\n\n**********************************************************************\n";
        return false;
    }
    
}

void forgotpass()
{
    //variable
    string fuser,un,pa;

    cout<<"**********************************************************************\n\t\t\t>> Forgot Password Page <<\n";
    cout<<"\t# Enter user name: "; 
    cin>>fuser;

    ifstream find(fuser+".txt");
    getline(find,un);
    getline(find,pa);

    if(fuser==un)
    {
        cout<<"\n\tHurry!!, Password Founded.\n";
        cout<<"\tPassword : "<<pa<<endl<<endl;
    }
    else
    {
        cout<<"Something went wrong !!, Please contact your admin";
        main();
    }
}

bool search(string bn)
{
    string bname,year,author,bid,bprice;

    ifstream book(bn +"details.txt");
    getline(book,bname);
    getline(book,year);
    getline(book,author);
    getline(book,bid);
    getline(book,bprice);

    if(book.is_open())
    {
        cout<<"\n  # Name   : "<<bname<<endl<<"  # Year   : "<<year<<endl<<"  # Author : "<<author<<endl<<"  # price  : "<<bprice<<endl;
        return true;
    }
    else
    {
        cout<<"\n Book is not available !!\n\n";
        return false;
    }
}

float add(string bn,string cn)

{
    string bname,year,author,bid,bprice;
    int qnty;
    float fprice;
    char billcon;

    cout<<"# Quantity :"; cin>>qnty;

    ifstream book(bn+"details.txt");

    getline(book,bname);
    getline(book,year);
    getline(book,author);
    getline(book,bid);
    getline(book,bprice);

    fprice=stof(bprice);

    ofstream q1(cn+"_bill.txt",ios::app);

    q1<<bname<<"  "<<fprice<<" * "<<qnty<<"  = Rs. "<<fprice*qnty<<endl;

    book.close();
    q1.close();

    return fprice*qnty;
}

void dataupdate()
{
    // structures
    book b;
    cashier c;
    char con1;

    cout<<"\n1. add book to database\n2. create cashier ID ";
    cin>>con1;
    switch (con1)
    {
    case '1':
        {
            cout<<"\t# Book name : "; 
            cin.ignore();
            getline(cin,b.name);
            cout<<"\t# Written year : "; 
            cin>>b.year;
            cout<<"\t# Author : ";
            cin.ignore(); 
            getline(cin,b.author);
            cout<<"\t# Book ID : "; 
            cin>>b.id;
            cout<<"\t# Price : "; 
            cin>>b.price;

            //creat data profile
            ofstream details(b.name+"details.txt",ios::app);

            details<<b.name<<endl<<b.year<<endl<<b.author<<endl<<b.id<<endl<<b.price;

            cout<<" * Successfully added *\n\n";

        break;

        }
        
     case '2':
        {
            cout<<"\n# Cashier name: "; cin>>c.name;
            cout<<"\n# Password: "; cin>>c.pass;

            //creat cashier profile
            ofstream profile(c.name+".txt",ios::app);

            profile<<c.name<<endl<<c.pass;

            cout<<"\n* Cashier profile created *\n\n";

        break;
        }
    
    }

}

void discount(string cn,float total)
{
    float totamnt;
    int dis;

    if(total < 1000)
    {
        dis = 0;
    }
    else if(total >= 1000 && total < 2000)
    {
        dis = 10;
    }
    else
    {
        dis = 20;
    }

    totamnt = (total / 100) * (100 - dis);

    ofstream bill(cn + "_bill.txt",ios::app);

    bill<<endl<<endl<<"# Total : Rs."<<total<<endl<<"# Discount : "<<dis<<"%"<<endl<<"# Total amount : Rs."<<totamnt<<endl<<"\nCome Again !!";
}

void quotation(string cn)
{
    string line;

    ifstream quota(cn + "_bill.txt");

    while(getline(quota,line))
    {
        cout<<line<<endl;
    }

    quota.close();
}

void bills (string billid)
{
    string line;

    ifstream datafile (billid + "_bill.txt");
    fstream cfile("bills.txt",ios :: app);

    while(getline(datafile,line))
    {
        cfile<<line<<endl;
    }

    cfile<<endl<<endl<<"***********************************************\n";

    datafile.close();
    cfile.close();
}