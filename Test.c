#include <stdio.h>
#include <stdlib.h>
#include "SonicTest.h"
#include "Test.h"


int sum(int x , int y)
{
	return x+y;
}

TEST(SUM)
{
	START_TEST(SUM);
	EXPECT_EQ(5,sum(2,3));
	EXPECT_EQ(9,sum(4,3));  // write a woring test case
}
