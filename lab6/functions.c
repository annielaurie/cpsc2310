/*********************************
 * Annie Hayes                   *
 * CPSC2310 Spring 2021          *
 * UserName: ahayes5             *
 * Instructor:  Dr. Yvon Feaster *
**********************************/

#include "functions.h"

/* format:
*   if a then b
*   else if c then d
*   else if e then f
*   else g
*/
int printReturn(int a, int b, int action)
{
return (action == 1 ? a==b
: action == 2 ? a < b
: action == 3 ? a > b
: -50000 );
}
