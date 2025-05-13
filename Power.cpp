#include<iostream>
#include<conio.h>
using namespace std;
class power
{
    private: int a,b,c;
    public:
        power()
        {
            c=1;
        }
        void in()
        {
            cout<<"\nEnter the base number: ";
                cin>>a;
            cout<<"Enter the Power: ";
                cin>>b;
        }
        void cal()
        {
            for(int i=0;i<b;i++)
                c=c*a;
        }
        void out()
        {
            cout<<"\nThe result is: "<<c;
        }
};
int main()
{
    power p;
    p.in();
    p.cal();
    p.out();
}