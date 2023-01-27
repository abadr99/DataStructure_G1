/*
 * Vector.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Mohamed Refat
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include "STD_TYPES.h"
typedef uint32_t VECTORTYPE;

typedef struct vector
{
	uint32_t Size ;
	uint32_t LastIndex ;
	uint32_t *pArray ;
}Vector_t;

void Vector_Init(Vector_t *pVector );
void Vector_PushBack(Vector_t *pVector ,VECTORTYPE Entry);
VECTORTYPE Vector_PopBack(Vector_t *pVector);
VECTORTYPE Vector_GetTop(Vector_t  *pVector );
void Vector_Destroy(Vector_t *pVector);
uint32_t Vector_GetSize(Vector_t *pVector );


#endif /* VECTOR_H_ */
