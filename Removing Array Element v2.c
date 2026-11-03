// removing an element from the array [version 2]
#include <stdio.h>

int main()
{
    int a[100], n, i, rem,k;

    printf("\nEnter the number of elements in the ARRAY: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the ARRAY: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the element to be removed: ");
    scanf("%d", &rem);

    for(i=0; i<n; i++)
    {
        if(a[i] == rem)
        {
            k = i;
            while((k+1) <= (n-1))
            {
                a[k] = a[k+1];
                k++;
            }
            n--;
            i--;
        }
    }

    printf("\nThe new array after removing %d is: ", rem);
    for(i = 0; i < n; i++)
    {
        printf("%d    ", a[i]);
    }

    return 0;
}

// i e main searching loop control kori ase. k e matching element tu remove korar pisot remaining elements shift koribo.