#include<iostream>
using namespace std;
int main()
{
    int a[10],i,j,t, n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        t= a[i];
        j=i-1;
        while(a[j]>t && j>=0)    //for descending order change a[j]>t to a[j]<t
        {
            a[j+1]=a[j];            
            j--;        
        }
        a[j+1]=t;
    }
    cout<<"Array after sorting: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"   ";
    }
    return 0;
}