#include<iostream>
#include<conio.h>
using namespace std;
class fibonacci
{
    private:
        int a, b ,c,n;
    public:
        fibonacci()
        {
            a=0;
            b=1;
            c=a+b;
        }
        void input()
        {
            cout<<"\nEnter the number of terms to be displayed: ";
            cin>>n;
        }
        void calculate()
        {
          cout<<a<<"     "<<b<<"     ";
          for(int i=3; i<=n;i++)
            {
                c=a+b;
                cout<<c<<"    ";
                a=b;
                b=c;
            }
        }
        void output()
        {
            cout<<"\nThe value of "<<n<<"th term is: ";
            
        }
};
int main()
{
    fibonacci f;
    f.input();
    f.output();
    f.calculate();
    
}