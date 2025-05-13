#include<iostream>
#include<conio.h>
using namespace std;
class No
{
    private:
     float a;
     float b;
    public:
     void input()
     {
        cout<<"Enter the first nmuber: ";
        cin>>a;
        cout<<"\nEnter the second number: ";
        cin>>b;
     }
     int check()
    {
        if (a>b)
            return a;
        else 
            return b;
    }
    void output()
    {
        int c;
        c=check();
        cout<<"\nThe greater number is:"<<c;
    }
};
int main()
{
    No n;
    n.input();
    n.check();
    n.output();
}