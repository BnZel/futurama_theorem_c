#include "../unity_test/unity.h"
#include "../../mindswap.h"


void setUp(void){ }
void tearDown(void){ }


void test_initialize_people_with_less_than_3(void){

    TEST_MESSAGE("TESTING INPUT THAT'S LESS THAN 3");

    int input = 2;

    TEST_ASSERT_FALSE(initialize(input));
}

void test_initialize_people_with_char(void){

    TEST_MESSAGE("TESTING INPUT WITH CHAR");

    char input = '3';

    TEST_ASSERT_FALSE(initialize(input));

}

void test_initialize_people_with_negative_int(void){

    TEST_MESSAGE("TESTING INPUT WITH NEGATIVE INTEGERS");

    int input = -3;

    TEST_ASSERT_FALSE(initialize(input));

}

void test_initialize_people_with_float(void){
    

    TEST_MESSAGE("TESTING INPUT WITH FLOAT");

    int input = 3.14;

    TEST_ASSERT_FALSE(initialize(input));
}

void test_initialize_people_with_integers(void){
    
    TEST_MESSAGE("TESTING APPROPRIATE DEFAULT VALUES FROM 3 TO 9");

    for(int input=3; input<10; input++)
    {
        TEST_ASSERT_TRUE(initialize(input));
    }
}

int main(void) 
{
    UNITY_BEGIN();

    // PASS when there's an input error
    RUN_TEST(test_initialize_people_with_less_than_3);
    RUN_TEST(test_initialize_people_with_char);
    RUN_TEST(test_initialize_people_with_negative_int);

    // PASS by default
    RUN_TEST(test_initialize_people_with_integers);
    
    return UNITY_END();
}