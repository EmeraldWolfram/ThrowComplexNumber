#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"
#include <stdlib.h>
#include <stdio.h>

int shouldFail = 1;

void doThing(){
  // ErrorObject* err;
  // Try{
    doSomething();
    // }Catch(err){
    // printf("Error: %s\n", err->errorMsg);
    // freeError(err);
  // }
}

int doSomething(){
  if(shouldFail){
    ThrowError("Hey! Something is really wrong here.", ERR_DUNNO_WHAT_HAPPEN);
  }
  return 1;
}
/**
 *  Add two number. The first Number must be negative.
 *  The second number must be positive no more than 50.
 */

int specialAdd(int negVal, int posVal){
  ErrorObject* errObj = malloc(sizeof(ErrorObject));
  if(negVal >= 0)
    ThrowError("No~ First Number not negative!", ERR_NUMBER_NOT_NEGATIVE);
  else if(posVal < 0)
    ThrowError("No~ Second Number not positive!", ERR_NUMBER_NOT_POSITIVE);
  else if(posVal > 50)
    ThrowError("Hey! Number over 50", ERR_NUMBER_TOO_LARGE);

  return negVal + posVal;
}


