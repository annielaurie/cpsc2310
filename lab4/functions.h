
/**************************
 *Annie Hayes             *
 *CPSC2310 Lab4           *
 *UserName:ahayes5        *
 *Lab Section: 003        *
**************************/

/** Include file for nibble routines */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
/* Parameters: unsigned int val   number value
 * Parameters: int position       position of nibble
 * Return: unsigned int           returns binary value
 *
 * returns binary value for nibble at position
 */
unsigned int nget(unsigned int val, int position);

/* Parameters: unsigned int val   number value
 * Parameters: unsigned int nVal  position of nibble
 * Parameters: int position       position of nibble
 * Return: unsigned int           returns binary value
 *
 * set binary value at position to nVal and returns binary
 * value for nibble at position
 */
unsigned int nset(unsigned int val, unsigned int nVal, int position);

/* Parameters: unsigned int val   number value
 * Return: unsigned int           returns binary value
 *
 * returns binary value after val has been rotated left 4 positions
 */
unsigned int nlrotate(unsigned int val);

#endif
