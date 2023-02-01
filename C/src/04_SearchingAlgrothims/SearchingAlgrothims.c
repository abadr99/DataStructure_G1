#include "STD_TYPES.h"
static sint32_t BinaryHelper(sint32_t Array[] , sint32_t First_index , sint32_t Last_index ,sint32_t Key );
static sint32_t BinaryHelper(sint32_t Array[] , sint32_t First_index , sint32_t Last_index ,sint32_t Key )
{
   sint32_t Middle_index = (First_index+Last_index)/2;
   if (Last_index<First_index)
   {
    return  NOT_FOUND ;
   }
   if (Array[Middle_index]==Key)
   {
    return Middle_index ;
   }
   else if (Array[Middle_index]>Key)
   {
    return BinaryHelper(Array , First_index , Middle_index-1 , Key);
   }else if (Array[Middle_index]<Key)
   {
    return BinaryHelper(Array , Middle_index+1 , Last_index , Key);
   }
}
sint32_t SearchingAlgorithm_BinaryIterative(sint32_t Array[] , uint32_t Size,sint32_t Key)
{
	sint32_t LocReturn = NOT_FOUND;
	sint32_t First_index = 0;
	sint32_t Last_index  = Size-1;
	uint32_t Middle_index   = (First_index+Last_index)/2;
	while(Last_index >= First_index)
	{
		if(Array[Middle_index] == Key)
		{
			LocReturn = Middle_index;
			break;

		}else if(Array[Middle_index] > Key)
		{
			Last_index = Middle_index - 1;
			Middle_index  = (First_index+Last_index)/2;

		}else if(Array[Middle_index] < Key)
		{
			First_index = Middle_index + 1;
			Middle_index  = (First_index+Last_index)/2;
		}
	}
	return LocReturn;
}

sint32_t SearchingAlgorithm_BinaryRecursive(sint32_t Array[], uint32_t size , sint32_t Key)
{
 return BinaryHelper(Array , 0 , size-1,Key);
}
