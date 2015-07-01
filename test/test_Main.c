#include "unity.h"
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"
#include <stdlib.h>

void setUp(void){}

void tearDown(void){}

void test_doThing(void){
  ErrorObject* err;
  
  Try{
    doThing();
    TEST_FAIL_MESSAGE("Expected ERR_DUNNO_WHAT_HAPPEN to be thrown."\
    " But none thrown");
  }Catch(err){
    TEST_ASSERT_EQUAL_STRING("Hey! Something is really wrong here.", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_DUNNO_WHAT_HAPPEN, err->errorCode);
    freeError(err);
  }
}

void test_specialAdd_given_minus_5_and_11_should_return_6(void){
  int result = specialAdd(-5, 11);
  TEST_ASSERT_EQUAL(6, result);
}

void test_specialAdd_given_7_and_18_should_throw_ERR_NUMBER_NOT_NEGATIVE(void){
  ErrorObject* err;
  Try{
    int result = specialAdd(7, 18);
    TEST_FAIL_MESSAGE("Expected ERR_NUMBER_NOT_NEGATIVE to be thrown."\
    " But none thrown");
  }Catch(err){
    TEST_ASSERT_EQUAL_STRING("No~ First Number not negative!", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
  }
}

void test_specialAdd_given_minus_5_and_minus_11_should_throw_ERR_NUMBER_NOT_POSITIVE(void){
  ErrorObject* err;
  Try{
    int result = specialAdd(-5, -11);
    TEST_FAIL_MESSAGE("Expected ERR_NUMBER_NOT_POSITIVE to be thrown."\
    " But none thrown");
  }Catch(err){
    TEST_ASSERT_EQUAL_STRING("No~ Second Number not positive!", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_POSITIVE, err->errorCode);
  }
}

void test_specialAdd_given_minus_5_and_55_should_throw_ERR_NUMBER_TOO_LARGE(void){
  ErrorObject* err;
  Try{
    int result = specialAdd(-5, 55);
    TEST_FAIL_MESSAGE("Expected ERR_NUMBER_TOO_LARGE to be thrown."\
    " But none thrown");
  }Catch(err){
    TEST_ASSERT_EQUAL_STRING("Hey! Number over 50", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_TOO_LARGE, err->errorCode);
  }
}