#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_NO_ERROR,
  ERR_WRONG_CODE,
  ERR_ILLEGAL_IDENTIFIER,
  ERR_FLOATING_POINT_MALFORMED,
  ERR_DUNNO_WHAT_HAPPEN,
  ERR_NUMBER_NOT_NEGATIVE,
  ERR_NUMBER_NOT_POSITIVE,
  ERR_NUMBER_TOO_LARGE,
}ErrorCode;

typedef struct{
  char* errorMsg;
  ErrorCode errorCode;
}ErrorObject;

void ThrowError(char* message, ErrorCode errCode);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
