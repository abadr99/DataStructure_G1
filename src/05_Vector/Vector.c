/*
 * Vector.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Mohamed Refat
 */
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Vector.h"

void Vector_Init(Vector_t *pVector )
{
	pVector->Size=0;
	pVector->LastIndex=0;
	pVector->pArray = (VECTORTYPE *)malloc(sizeof(VECTORTYPE));
}

void Vector_PushBack(Vector_t *pVector ,VECTORTYPE Entry)
{
	if(pVector->Size == 0 )
	{
		pVector->pArray[pVector->Size] = Entry ;
		pVector->Size++;
		pVector->LastIndex++;

	}
	else if(pVector->LastIndex >=  pVector->Size  )
	{
		uint32_t Counter;
		VECTORTYPE *Loc_pTemp =  pVector->pArray ;
		pVector->Size *=2;
		pVector->pArray = (VECTORTYPE *)malloc(pVector->Size *sizeof(VECTORTYPE));
		for(Counter = 0 ; Counter<pVector->LastIndex ; Counter++)
		{
			pVector->pArray[Counter]= Loc_pTemp[Counter];
		}
		pVector->pArray[pVector->LastIndex] = Entry;
		pVector->LastIndex++;
		free(Loc_pTemp);
	}else
	{
		pVector->pArray[pVector->LastIndex] = Entry;
		pVector->LastIndex++;
	}
}
VECTORTYPE Vector_PopBack(Vector_t *pVector)
{
	VECTORTYPE LocReturn;
	if(pVector->LastIndex == 1)
	{

		LocReturn = pVector->pArray[0];
		Vector_Destroy(pVector);

	}else if(pVector->LastIndex == (pVector->Size/2)+1)
	{
		uint32_t Counter;
		VECTORTYPE *Loc_pTemp =  pVector->pArray ;
		pVector->Size /=2 ;
		pVector->pArray = (VECTORTYPE *)malloc(pVector->Size *sizeof(VECTORTYPE));
		for(Counter = 0 ; Counter<pVector->LastIndex ; Counter++)
		{
					pVector->pArray[Counter]= Loc_pTemp[Counter];
		}
		LocReturn = pVector->pArray[pVector->LastIndex-1];
		pVector->LastIndex--;

	}else
	{
		LocReturn = pVector->pArray[pVector->LastIndex-1];
		pVector->LastIndex--;
	}

	return LocReturn;
}
VECTORTYPE Vector_GetTop(Vector_t *pVector )
{
	return pVector->pArray[pVector->LastIndex-1] ;
}
uint32_t Vector_GetSize(Vector_t *pVector )
{
	return pVector->LastIndex;
}
void Vector_Destroy(Vector_t *pVector)
{
	pVector->LastIndex = 0;
	pVector->Size = 0;
	free(pVector->pArray);
}








