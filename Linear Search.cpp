#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[10],n,key,i,f=0;
    cout<<"Enter how many numbers is the array:  ";
    cin>>n;
    cout<<"\nEnter the element to be searched: ";
    cin>>key;
    cout<<"\nEnter the elements of the arry:\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"\nThe search is successful.";
    else
        cout<<"\nThe search is not successful.";
    getch();
}
