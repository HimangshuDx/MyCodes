#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cout<<"\n\nASSAM POWER DISTRIBUTION COMPANY LIMITED\n\n"<<endl;

    cout<<"Enter the amount to pay: ";
    cin>>n;

    if(n>0)
    {
        cout<<"\nElectricity Serving: Yes\n";
        cout<<"Power: 240Volt\n";
        cout<<"Line: CLEAR";

        cout<<"\n\nSTATUS:\n\n";
        cout<<"Bill of this month is: Rs "<<n; 
        cout<<"\nBill Status: PAID";
        cout<<"\nElectricity Supply: YES";
        cout<<"\nConsumer Recieving: YES"; 
        cout<<"\n\n THANK YOU FOR PAYING THE BILL. YOUR SERVICE WILL CONTINUE.\n\n";
    }
    else
    {
        cout<<"\nElectricity Serving: No\n";
        cout<<"Power: 0Volt\n";
        cout<<"Line: CUT OFF";

        cout<<"\n\nSTATUS:\n\n";
        cout<<"Bill of this month is NOT PAID."; 
        cout<<"\nBill Status: NOT PAID";
        cout<<"\nElectricity Supply: NO";
        cout<<"\nConsumer Recieving: NO"; 
        cout<<"\n\n PLEASE PAY THE BILL TO CONTINUE THE SERVICE.\n\n";
    }
    return 0;
}