/*********************************
 * Annie Hayes                   *
 * CPSC2310 Spring 2021          *
 * UserName: ahayes5             *
 * Instructor:  Dr. Yvon Feaster *
**********************************/

#include "functions.h"

int main()
{
  //print return test
  printf("\n\n%d\n", printReturn(20, 10, 1));
  printf("%d\n", printReturn(3, 13, 2));
  printf("%d\n", printReturn(2, 24, 3));
  printf("%d\n\n", printReturn(10, 3, 4));

  //1.) find maximum value tests
  printf("Max: %d\n", MAX(5, 4));
  printf("Max: %.1f\n", MAX(10.5, 11.9));
  printf("Max: %s\n\n", MAX("a", "b"));

  //2.) find minimum value tests
  printf("Min: %d\n", MIN(5, 4));
  printf("Min: %.1f\n", MIN(10.5, 11.9));
  printf("Min: %s\n\n", MIN("a", "b"));

  //3.) find absolute value tests
  printf("Abs: %d\n", (ABS(3)));
  printf("Abs: %d\n", (ABS(-3)));
  printf("Abs: %d\n\n", (ABS(0)));

  //4.) find largest value tests
  printf("Largest: %d\n", LARGEST(1, 2, 3));
  printf("Largest: %s\n", LARGEST("a", "b", "c"));
  printf("Largest: %s\n\n", LARGEST("a", "b", "c"));

  //5.) find smallest value tests
  printf("Smallest: %d\n", SMALLEST(1, 2, 3));
  printf("Smallest: %s\n", SMALLEST("a", "b", "c"));
  printf("Smallest: %s\n\n", SMALLEST("a", "b", "c"));

  //6.) print debug line test
  DEBUG_FPRINT;

  //7.) find even or odd tests
  printf("\n4 is %s\n", ISEVEN_ODD(4));
  printf("1 is %s\n\n", ISEVEN_ODD(1));

  //8.)allocate memory tests
  int *test = NULL;
  test = (MALLOC(5, int));
  if (test == NULL)
  {
    printf("malloc failed");
  } else {
    printf("The address of num is: %p\n\n", &test);
  }

  //9.) add to sum test
  int sum5 = 10;
  int add = 15;
  printf("sum5: %d \n", sum5);
  printf("adding: %d \n", add);
  printf("adding to sum: %d\n\n",(ADD_TO_SUM(5, 15)));


    return 0;

}
