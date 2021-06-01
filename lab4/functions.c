
/**************************
 *Annie Hayes             *
 *CPSC2310 Lab4           *
 *UserName:ahayes5        *
 *Lab Section: 003        *
**************************/

/** CPSC 2310 Lab 4

    Nibble routines

    Nibbles are 4-bit parts of a 32 bit unsigned integer variable.
    Nibbles are numbered 0-7 from left to right.

**/
#include "functions.h"


unsigned int nget(unsigned int val, int position)
   /** STUBBED **/
{
  //set variables
  int maxBitVal = 8;
  int maxNibVal = 4;
  int returnVal = val >> ((maxBitVal - position - 1) * maxNibVal) & 0xF;
  return returnVal;
}

unsigned int nset(unsigned int val, unsigned int nVal, int position)
   /** STUBBED **/
{
  //set variables
  int maxBitVal = 8;
  int maxNibVal = 4;
  //shift value
  int shifting = (maxBitVal - position - 1) * maxNibVal;
  //mask value
  int masking = 0xf << shifting;
  int returnVal = (val & ~masking) | (nVal << shifting & masking);
  return returnVal;
}

unsigned int nlrotate(unsigned int val)
{
  //set variables
  int maxRotate = 7;
  //get start value
  unsigned int startVal = nget(val, 0);
  for (int i = 0; i < maxRotate; ++i)
  {
    //set nibbles
    val = nset(val, nget(val, i + 1), i);
  }
  int returnVal = nset(val, startVal, maxRotate);
  return returnVal;
}
