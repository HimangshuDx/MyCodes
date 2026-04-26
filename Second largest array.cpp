#include<iostream>
using namespace std;

void array()
{
    int n,i;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array:\n";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int l= a[0];
    for (i=0;i<n;i++)
    {
        if (a[i]>l)
        {
            l=a[i];
        }
    }

    bool allEqual = true;
    for (int j = 1; j < n; j++) 
    {
        if ((a[j] != a[0])) {
            allEqual = false;
            break;
        }
    }
    if (allEqual)
    {
       cout<<"-1";
    }
    else{
            cout<<"The second largest element in the array is:"<<l-1;
    }

};
int main()
{
    array();
    return 0;
}
