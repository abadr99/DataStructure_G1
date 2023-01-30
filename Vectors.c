
#include "Vectors.h"

void Create(Vector *pv)
{

	pv->maxsize=0;
	pv->top=0;
	pv->arr = (int *)malloc(sizeof(int));
}

void push(Vector *pv, int element){

 if( pv->maxsize == 0 )
	{
		pv->arr[pv->maxsize] = element ;
		pv->maxsize++;
		pv->top++;

	}
	else if(pv->top >= pv->maxsize)
	{
		int i;
		int *temp =  pv->arr ;
		pv->maxsize *= 2;
		pv->arr = (int *)malloc(pv->maxsize *sizeof(int));
		for(i=0 ; i< pv->top ;i++)
		{
			pv->arr[i]= temp[i];
		}
		pv->arr[pv->top] = element;
		pv->top++;
		free(temp);
	}
	else
	{
		pv->arr[pv->top] = element;
		pv->top++;
	}
}


void pop(Vector *pv ){
  int retval;
	if(pv->top == 1)
	{

		retval = pv->arr[0];
		Destroy(pv);

	}
	else if(pv->top == (pv->maxsize/2)+1)
	{
		int i;
		int *temp =  pv->arr ;
		pv->maxsize /=2 ;
		pv->arr = (int *)malloc(pv->maxsize *sizeof(int));
		for(i = 0 ; i<pv->top ; i++)
		{
					pv->arr[i]= temp[i];
		}
		retval = pv->arr[pv->top-1];
		pv->top--;

	}else
	{
		retval = pv->arr[pv->top-1];
		pv->top--;
	}

	return retval;
}

int GetTop(Vector *pv )
{
	return pv->arr[pv->top-1] ;
}
int GetSize(Vector *pv )
{
	return pv->top;
}
void Destroy(Vector *pv)
{
	pv->top = 0;
	pv->maxsize = 0;
	free(pv->arr);
}



