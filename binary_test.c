#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"
int main ()
{
int n ,i,j,element;
printf ("enter size of array\n");
scanf("%d",&n);
int arr[n];
printf ("enter elements of array\n");
for (i=0;i<n;i++)
{
    scanf("%d",&arr[i]);

}
sort(arr,n);
printf("sorted arr is\n");
for (i=0;i<n;i++)
{
   printf ("%d\n",arr[i]);

}
printf ("please enter the element you want to search");
scanf ("%d",&element);
int result=binary_search(arr,element,n-1,0);
if (result==-1)
printf ("not found");
else
    printf ("element found at this index is%d",result);

return 0;
}

