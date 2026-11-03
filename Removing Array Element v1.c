// removing an element from the array [version 1]
#include <stdio.h>

int main()
{
    int a[100], n, i, rem;

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
            for(int j=i; j<n-1; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            i--;
        }
    }

    printf("\nThe new array after removing %d is: ", rem);
    for(i=0; i<n; i++)
    {
        printf("%d    ", a[i]);
    }

    return 0;
}

//if(a[i] == rem)-e matching element bisare.
//Inner for loop-e element-bur left side-loi shift kore.
//n-- e array-or effective size komai.
//i-- e same index-tu punorai check kore, karon shift huwa pisot tat notun element ahise.