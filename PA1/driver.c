/********************************
* Annie Hayes                   *
* CPSC 2310 Spring 21           *
* UserName: ahayes5             *
* Instructor: Dr. Yvon Feaster  *
*********************************/
#include "functions.h"

int main(int argc, char *argv[])
{
  char* inputFileName = argv[1];
  char* outputFileName = argv[2];
  char choice;

  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");

  checkArgs(argc);
  checkFile(input, inputFileName);
  checkFile(output, outputFileName);
  node_t *list = createList(input, NULL);

  do{
    MenuPrintEC();
    scanf("%s", &choice);
    if (choice == '1')
    {
      PrintName(output, list);
      PrintName(stderr, list);
    }
    else if (choice == '2')
    {
      PrintBDay(output, list);
      PrintBDay(stderr, list);
    }
    else if (choice == '3')
    {
      Song(output, list);
      Song(stderr, list);
    }
    else if (choice == '4')
    {
      PrintList(output,list);
      PrintList(stderr,list);
    }
    else if (choice == '5')
    {
      PrintList(output,list);
      PrintList(stderr,list);
    }
    else
    {
      printf("Invalid Input.");
    }
  }while (choice != '5');

  //deleteList(&list);
  fclose(output);
  fclose(input);
  return 0;
}
