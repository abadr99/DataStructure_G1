#include <stdio.h>
#include <stdlib.h>
int binary_search(int *array,int first,int last,int key);
int main()
{
    int arr[8] ={0,3,5,7,9,12,16,20};
    int location;
    location=binary_search(arr,0,7,30);

    if(location!=-1){
        printf("element is at index %d\n",location);
    }
    else{
        printf("element is not exist\n");
    }
}
int binary_search(int *array,int first,int last,int key){
    int mid,index;
    mid=(first+last)/2;

 if(first>last){
        index=-1;
    }

 else{
    if(array[mid]==key){
        index=mid;
    }

    else if(array[mid]>key){
        index=binary_search(array,first,mid-1,key);
    }
    else if(array[mid]<key){
        index=binary_search(array,mid+1,last,key);
    }
 }

    return index;
}
