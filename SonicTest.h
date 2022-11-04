#ifndef __SONIC_TEST_
#define __SONIC_TEST_

#define __GREEN						            printf("\033[1;32m");
#define __RED						            printf("\033[1;31m");
#define __BLUE						            printf("\033[0;34m");
#define __DEFAULT					            printf("\033[0m");

#define TEST(testName)							void\
												_##TEST##_##testName##_\
												(void)

#define START_TEST(testName)					__BLUE printf("----------------------------------------------------------\n"); __BLUE printf(#testName); printf(" RESULTS: \n"); printf("----------------------------------------------------------\n");

#define EXPECT_EQ(EXPECTED,ACTUAL)				if(ACTUAL == EXPECTED) {__GREEN printf("[PASSED] : ");__DEFAULT printf("EXPECTED : %d",EXPECTED);__DEFAULT printf("\t \t %5s %d\n","FOUND : ",ACTUAL);}\
                                    			else  { __RED printf("[FAILED] : "); __DEFAULT printf("EXPECTED : %d",EXPECTED);__DEFAULT printf("\t \tFOUND : %d\n",ACTUAL);}

#define EXPECT_TRUE(ACTUAL)                     if(ACTUAL == 1) {__GREEN printf("[PASSED] : ");__DEFAULT printf("EXPECTED : 1\t");__DEFAULT printf("\t\tFOUND : %d\t\n",ACTUAL);}\
                                                else  { __RED printf("[FAILED] : "); __DEFAULT printf("EXPECTED : 1");__DEFAULT printf("\t\tFOUND : %d\t\n",ACTUAL);}

#define EXPECT_FALSE(ACTUAL)                    if(ACTUAL == EXPECTED) {__GREEN printf("[PASSED] : ");__DEFAULT printf("EXPECTED : 0\t");__DEFAULT printf("\t\tFOUND : %d\t\n",ACTUAL);}\
                                                else  { __RED printf("[FAILED] : "); __DEFAULT printf("EXPECTED : 0");__DEFAULT printf("\t\tFOUND : %d\t\n",ACTUAL);}

#define RUN_TEST(testName)						 _##TEST##_##testName##_\
													();

#endif //__SONIC_TEST_