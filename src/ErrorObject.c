#include "ErrorObject.h"
#include "CException.h"
#include <stdlib.h>

void ThrowError(char* message, ErrorCode errCode){
  ErrorObject* errorObject = malloc(sizeof(ErrorObject));  
  errorObject->errorMsg = message;
  errorObject->errorCode = errCode;
  Throw(errorObject);
}

void freeError(ErrorObject *errObj){
  free(errObj);
}