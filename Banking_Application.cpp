#include<bits/stdc++.h>
using namespace std;

class Account
{
    private:
    string first_name;
    string last_name;
    float balance;
            
    public:
    Account(){}
    Account(string f_name,string l_name,float bal);
    
    friend ifstream & operator>>(ifstream &fis,Account &acc);
    friend ofstream & operator<<(ofstream &fos,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);

};

Account::Account(string f_name,string l_name,float bal)
{
    first_name = f_name;
    last_name = l_name;
    balance = bal;
}

ofstream & operator<<(ofstream &fos,Account &acc)
{
    fos<<acc.first_name<<endl<<acc.last_name<<endl<<acc.balance<<endl;
    return fos;
}

ifstream & operator>>(ifstream &fis,Account &acc)
{
    fis>>acc.first_name>>acc.last_name>>acc.balance;
    return fis;
}

ostream & operator<<(ostream &os,Account &acc)
{
    os<<acc.first_name<<endl<<acc.last_name<<endl<<acc.balance<<endl;
    return os;
}


void create_account() {

    string f_name, l_name;
    float bal;
    cout<<"Enter First Name: "<<endl;
    cin>>f_name;
    cout<<"Enter Last Name: "<<endl;
    cin>>l_name;
    cout<<"Enter Opening Balance (Min. Rs 1000): "<<endl;
    cin>>bal;
    Account acc(f_name, l_name, bal);
    ofstream ofs("accounts_data.txt", ios::app);
    ofs<<acc<<endl;
    ofs.close();
    
}

void show_accounts() {

    Account acc;
    ifstream fis("accounts_data.txt");
    
    for(int i=0;i<3;i++)
    {
        fis>>acc;
        cout<<"Item "<<i<<endl<<acc<<endl;
    }
    
}

int main() {

    int choice;
    cout<<"********** BANKING SYSTEM **********"<<endl;
    do {
        cout<<"1.Open an Account \n2.Balance Enquiry \n3.Deposit \n4.Withdrawal \n5.Close an Account \n6.Show all Accounts \n7.Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 6:
            show_accounts();
            break;
        
        default:
            break;
        }

    } while (choice < 7);

    return 0;
}