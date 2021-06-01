/*********************************
 * Annie Hayes                   *
 * CPSC2310 Spring 2021          *
 * UserName: ahayes5             *
 * Instructor:  Dr. Yvon Feaster *
**********************************/

#include "functions.h"

/*
 * absValue - returns the absolute value of x
 *   Example: absValue(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absValue(int x)
{
  return ((x + (x>>31))^(x>>31));
}

/*
 * binaryAnd - x&y using only ~ and |
 *   Example: binaryAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binaryAnd(int x, int y)
{
  return ~(~x | ~y);
}
/*
 * binaryNotOr - ~(x|y) using only ~ and &
 *   Example: binaryNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binaryNotOr(int x, int y)
{
  return ~x & ~y;
  //return ~(~(~x&~y));
}

/*
 * binaryOr - x|y using only ~ and &
 *   Example: binaryOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binaryOr(int x, int y)
{
  return ~(~x & ~y);
}

/*
 * binaryXor - x^y using only ~ and &
 *   Example: binaryXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binaryXor(int x, int y)
{
  return ~(~x & ~y) & ~(x & y);
  //return ~(~(~x & y) & ~(x & ~y));
}

/*
 * unsignedAddOk - determines if two unsigned int's can be added
 * without an overflow
 * Legal ops: all
 */

int unsignedAddOK(unsigned x, unsigned y)
{
  int newX = x >> 31;
  int newY = y >> 31;
  int add = (x + y) >> 31;
  return !!(newX ^ newY) | (!(newX ^ add) & !(newY ^ add));
}

/*
 * twosAddOk - determines if two int's can be added
 * without an overflow
 * Legal ops: all
 */

int twosAddOk(int x, int y)
{
  int sum = x + y;
  return !(((x ^ sum) & (y ^ sum)) >> 31);
}


/*
 *  int twosSubOk - Determine whether arguments can be subracted
 *  without overflow
 *  Legal ops: all
 */

int twosSubtractOK(int x, int y)
{
  int signDifference = x + ~y + 1;
  return !(((x ^ y) & (x ^ signDifference)) >> 31);
}
