#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"
int binary_search(int arr[],int element,int high,int low)
{
    while (low<=high)
    {  int mid=low+(high-low)/2;
        if (element==arr[mid])
           return mid;   //best case
        else if (element >arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
void sort (int arr[],int n)
{
int  i,j;
for (i=0;i<n;i++)
{
    for (j=i+1;j<n;j++)
        if (arr[i]>arr[j])
    {
        arr[i]=arr[i]^arr[j];
        arr[j]=arr[i]^arr[j];
        arr[i]=arr[i]^arr[j];
    }
}
}
