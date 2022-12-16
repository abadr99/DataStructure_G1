#include "SearchingAlgrothims.h"
Element_Type RecBinarySearch(Element_Type arr[],Element_Type number,Element_Type first,Element_Type last)
{
	while(first<=last)
   {
	Element_Type mid;
	mid=(first+last)/2;
	if(arr[mid]==number)
	{
		return mid;
	}
	else if(arr[mid]>number)
	{
		return RecBinarySearch(arr,number,first,mid-1);
	}
	else
	{

	    return RecBinarySearch(arr,number,mid+1,last);
	}
   }
	    return -1;
}
void sort(Element_Type arr[],Element_Type length)
{
	for(Element_Type i=0;i<length;i++)
	{
		for(Element_Type j=i+1;j<length;j++)
		{
			if(arr[i]>arr[j])
			{
				Element_Type temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
