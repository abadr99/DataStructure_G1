#include "STD_TYPES.h"
static sint32_t BinaryHelper(sint32_t Array[] , sint32_t First , sint32_t Last ,sint32_t Key );
static sint32_t BinaryHelper(sint32_t Array[] , sint32_t First , sint32_t Last ,sint32_t Key )
{
   sint32_t Mid = (First+Last)/2;
   if (Last<First)
   {
    return  NOT_FOUND ;
   }
   if (Array[Mid]==Key)
   {
    return Mid ;
   }
   else if (Array[Mid]>Key)
   {
    return BinaryHelper(Array , First , Mid-1 , Key);
   }else if (Array[Mid]<Key)
   {
    return BinaryHelper(Array , Mid+1 , Last , Key);
   }
}
sint32_t SearchingAlgorithm_BinaryIterative(sint32_t Array[] , uint32_t Size,sint32_t Key)
{
	sint32_t LocReturn = NOT_FOUND;
	sint32_t First = 0;
	sint32_t Last  = Size-1;
	uint32_t Mid   = (First+Last)/2;
	while(Last >= First)
	{
		if(Array[Mid] == Key)
		{
			LocReturn = Mid;
			break;

		}else if(Array[Mid] > Key)
		{
			Last = Mid - 1;
			Mid  = (First+Last)/2;

		}else if(Array[Mid] < Key)
		{
			First = Mid + 1;
			Mid  = (First+Last)/2;
		}
	}
	return LocReturn;
}

sint32_t SearchingAlgorithm_BinaryRecursive(sint32_t Array[], uint32_t size , sint32_t Key)
{
 return BinaryHelper(Array , 0 , size-1,Key);
}
