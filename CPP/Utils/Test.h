#ifndef TEST__H__
#define TEST__H__

#define __GREEN						            printf("\033[1;32m");
#define __RED						            printf("\033[1;31m");
#define __BLUE						            printf("\033[0;34m");
#define __DEFAULT					            printf("\033[0m");


#define TEST(testName)							void\
												_##TEST##_##testName##_\
												(void)
#define START_TEST(testName)					__BLUE printf("----------------------------------------------------------\n"); __BLUE printf(#testName); printf(" RESULTS: \n"); printf("----------------------------------------------------------\n");


#define RUN_TEST(testName)						 _##TEST##_##testName##_\
													();

class Test {
public :
    template <typename T>
    static void ExpectEQ(T expected, T actual);
    template <typename T>
    static void ExpectNotEQ(T Expected, T Found);
};

#endif //TEST__H__