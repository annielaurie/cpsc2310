/*********************************
 * Annie Hayes                   *
 * CPSC2310 Spring 2021          *
 * UserName: ahayes5             *
 * Instructor:  Dr. Yvon Feaster *
**********************************/

#include "functions.h"
#include <assert.h>

int main(int argc, char *argv[])
{
  assert(absValue(-100) == abs(100));
  assert(binaryAnd(6, 5) == 4);
  assert(binaryNotOr(0x6, 0x5) == 0xFFFFFFF8);
  assert(binaryOr(6, 5) == 7);
  assert(binaryXor(4, 5) == 1);
  assert(unsignedAddOK(6, 5) == 1);
  assert(twosAddOk(6, 5) == 1);
  assert(twosSubtractOK(6, 5) == 1);
  return 0;
}
