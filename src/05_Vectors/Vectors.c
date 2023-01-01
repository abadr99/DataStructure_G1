#include "Vectors.h"

void Create(vector_t *V)
{
	V->CurrSize=0;
	V->MaxSize=0;
	V->ptr=0;
}
void pushBack(vector_t *V,VectorType e)
{
 if((V->CurrSize==0)&&(V->MaxSize==0))
 {
	 V->MaxSize=1;
	 V->ptr=(VectorType*)calloc(2*(V->MaxSize),sizeof(VectorType));
	 V->ptr[V->CurrSize]=e;
 }
 else if((V->CurrSize)==(V->MaxSize))
 {
	 VectorType* temp=V->ptr;
	 V->ptr=(VectorType*)calloc(2*(V->MaxSize),sizeof(VectorType));
	 for(VectorType i=0;i<V->MaxSize;i++)
	 {
		 V->ptr[i]=temp[i];
	 }
	 free(temp);
	 V->ptr[V->CurrSize]=e;
	 (V->MaxSize) *=2;
 }
 else if((V->CurrSize)<(V->MaxSize))
 {
	 V->ptr[V->CurrSize]=e;
 }
 (V->CurrSize)++;
}
void popBack(vector_t *V)
{
	if((V->CurrSize)<(V->MaxSize)&&(V->CurrSize)==((V->MaxSize/2)+1))
	{
		VectorType* temp=V->ptr;
		(V->MaxSize) /=2;
		for(VectorType i=0;i<V->MaxSize;i++)
		{
			V->ptr[i]=temp[i];
		}
		free(temp);
	}
	(V->CurrSize)--;
}

