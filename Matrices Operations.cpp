#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[20][20], b[20][20],sum[20][20] ,i,j,n,digsal=0, digsar=0, digsbl=0,digsbr=0;
    
    //enetring the matrices 

    cout<<"\nEnter the number elements of the rows and columns the square matrices: ";
       cin>>n;
    cout<<"\nEnter the elements of the first matrix: \n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"\nEnter the elements of the second matrix: \n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>b[i][j];

    //finding summation of both matrices

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            sum[i][j]=a[i][j]+b[i][j];
    cout<<"\n\nThe summation of both matrices is:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<sum[i][j]<<"\t";
        }
        cout<<endl;
    }
   
    //diagonal operation of 1st matrix

    cout<<"\n\nThe diagonal elemets of the first matrix are: \n";
    cout<<"\nLeft diagonal elements:  ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j)
                {
                    cout<<a[i][j]<<",";
                    digsal=digsal+a[i][j];                        //'digsal' stands for " Diagonal Sum of matrix 'a' Left "
                }
    cout<<"\nThe summation of left diagonal elements is: "<<digsal;
    cout<<"\nRight diagonal elements:  ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i+j==n-1)
            {
                cout<<a[i][j]<<",";
                digsar=digsar+a[i][j];                          //'digsar' stands for " Diagonal Sum of matrix 'a' Right "
            }
    cout<<"\nThe summation of right diagonal elements is: "<<digsar;

//diagonal operation of 2nd matrix

    cout<<"\n\nThe diagonal elemets of the second matrix are: \n";
    cout<<"\nLeft diagonal elements:  ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j)
            {
                cout<<b[i][j]<<",";
                digsbl=digsbl+b[i][j];                            //'digsbl' stands for " Diagonal Sum of matrix 'b' Left "
            }
    cout<<"\nThe summation of left diagonal elements is: "<<digsbl;
    cout<<"\nRight diagonal elements:  ";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i+j==n-1)
            {
                cout<<b[i][j]<<",";
                digsbr=digsbr+b[i][j];                                //'digsbl' stands for " Diagonal Sum of matrix 'b' Right "
            }
    cout<<"\nThe summation of right diagonal elements is: "<<digsbr;

    cout<<"\n\n Lets Print only diagonal elements of a matrix: \n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            
            if(i==j || i+j==n-1)
            {
                cout<<" X ";
            }
            else
            {
                cout<<" | ";
            }
                
        }
        cout<<endl;
    }
    


    return 0;
}




    
