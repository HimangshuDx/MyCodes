#include<iostream>
using namespace std;
int main()
{
    int a[10], i,j,n,t;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])                 //for descending order use a[j]<a[j+1]
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    cout<<"The sorted array is: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"   ";      
    }
}