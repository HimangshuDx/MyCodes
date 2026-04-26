#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[10],n,i,j,t;
    cout<<"Enter the sixe of the array: ";
        cin>>n;
    cout<<"\nEnter the elements of the array:\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    cout<<"\nThe array elements after sorting is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<",";
    getch();
}