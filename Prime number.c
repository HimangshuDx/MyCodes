//Entered number is prime or not>> check
//Print all prime numbers between 1 to n
// concept by Chandan sir.

#include<stdio.h>

int prime(int n)
{
    int i,f=0;
    for(i=1; i<=n;i++)
    {
        if(n%i==0)
            f++;
    }
    if(f==2)
        return 1;
    else
        return 0;
}

int main()
{
    int n,b,i;
    printf("\nEnter the last number: ");
    scanf("%d",&n);

    //check is n prime or not>>

    b= prime(n);
    if(b==1)
        printf("\n%d is a Prime Number.",n);
    else
        printf("\n%d is not a Prime Number.",n);

    //display all prime numbers between 1 to n

    printf("\nAll Prime Numbers from 1 to %d are: ",n);
    for(i=1;i<=n;i++)
    {
        if(prime(i))
            printf("%d, ",i);

    }
    
    return 0;
}