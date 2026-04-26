#include<iostream>
#include<conio.h>
using namespace std;
class employee 
{
    private:
        char name[30];
        float  basic,net_income, total_income, total_deduction;
    public:
        void input()
        {
            cout<<"\nEnter the name of the employee: ";
                cin>>name;
             cout<<"Enter the basic salary: ";
                cin>>basic;
        }
        void cal_total_income()
        {
            float DA ,HRA, CA=300;
            DA=23.0/100* basic;
               cout<<"\nDA= "<<DA;
            HRA=15.0/100*basic+DA;
               cout<<"\nHRA= "<<HRA;
               cout<<"\nCA= "<<CA;
            total_income= basic+DA+HRA+CA;
        }
        void cal_total_deduction()
        {
            float PF, insurance =300;
            PF= 10.0/100*basic;
            total_deduction= PF+insurance;
               cout<<"\nPF= "<<PF;
               cout<<"\nInsurance= "<<insurance;
        }
        void cal_net_income()
        {
            net_income= total_income-total_deduction;
            cout<<"\nThe NET INCOME is= "<<net_income;
        }
};
int main()
{   
    int n;
    employee e[10];
    cout<<"Enter the total number of employees: ";
    cin>>n;
     for(int i=0;i<n;i++)
     {
        cout<<"\nDETAILS OF EMPLOYEE "<<i+1<<":";
        e[i]. input();
        e[i]. cal_total_income();
        e[i]. cal_total_deduction();
        e[i]. cal_net_income();
        cout<<"\n\n";
     }
}
