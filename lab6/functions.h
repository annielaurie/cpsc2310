/*********************************
 * Annie Hayes                   *
 * CPSC2310 Spring 2021          *
 * UserName: ahayes5             *
 * Instructor:  Dr. Yvon Feaster *
**********************************/

#include <stdio.h>
#include <stdlib.h>

/*
parameters:   a, b - two values
description:  finds maximum value
              if no maximum value, returns b
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
parameters:   a, b - two values
description:  finds minimum value
              if no minimum value, returns a
*/
#define MIN(a, b) ((b) < (a) ? (b) : (a))

/*
parameters:   x - value
description:  finds absolute value
*/
#define ABS(x) ((x) > 0 ? (x) : (x) < 0 ? (-x) : 0)

/*
parameters:   a, b, c - 3 values
description:  finds largest value
              if no largest value, returns c
*/
#define LARGEST(a, b, c) ((MAX(a, b)) > (MAX(b, c)) ? (MAX(a, b)) : (c))

/*
parameters:   a, b, c - 3 values
description:  finds smallest value
              if no smallest value, returns a
*/
#define SMALLEST(a, b, c) ((MIN((a),(b))) < (MIN((b),(c))) ? (MIN((a),(b))) : (a))

/*
parameters:   none
description:  prints line debugging
              is on
*/
#define DEBUG_FPRINT fprintf(stderr,"in %s %d\n", __FILE__, __LINE__);

/*
parameters:   x - value
description:  checks if number is
              even or odd
*/
#define ISEVEN_ODD(x) ((x) % 2 == 0 ? ("even") : ("odd"))

/*
parameters:   a, b - 2 values,
              a number and a data type
description:  allocates memory
              for a specific number of
              elements for a data type
*/
#define MALLOC(a, b) ((b*)malloc(a))

/*
parameters: sum_number, value -
            2 values, a specific number
            related to another variable and
            the value to be added
description: sums two numbers
            together and returns total
*/
#define ADD_TO_SUM(sum_number, value) sum ## sum_number += value

/*
parameters:   int a, int b, int
              action - 2 numbers and an action
description:  tests ternary
              operators
return:       int - returns value based
              on action passed in
*/
int printReturn(int a, int b, int action);
