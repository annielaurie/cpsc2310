/********************************
* Annie Hayes                   *
* CPSC 2310 Spring 21           *
* UserName: ahayes5             *
* Instructor: Dr. Yvon Feaster  *
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct bday
{
  int month;
  int day;
  int year;

} bday_t;

typedef struct node
{
  char firstName[100];
  char lastName[100];
  bday_t bday;
  char song[100];
  struct node* next;

} node_t;


/*
* Parameters:   node_t **node - node being added to list
*               node_t **head - pointer to head node
* Return:       void
* Description:  adds a node to the linked list
*/
void add(node_t **node, node_t **head);

/*
* Parameters:   FILE* input - input file being read
* Return:       node_t* - linked list
* Description:  reads data from input file & allocates
*               memory for linked list
*/
node_t* readNodeInfo(FILE* input);

/*
* Parameters:   FILE* input - input file
*               node_t** list - list being made
* Return:       node_t* - pointer to head of list
* Description:  reads file & adds to list
*/
node_t* createList(FILE* input, node_t** list);

/*
* Parameters:   FILE* output - output file
*               node_t* list - list being printed
* Return:       void
* Description:  prints data to output file
*/
void PrintList(FILE* output, node_t* list);

/*
* Parameters:   FILE* output - output file
*               node_t* list - list being printed
* Return:       void
* Description:  prints only names of the data
*/
void PrintName(FILE* output, node_t* list);

/*
* Parameters:   FILE* output - output file
*               node_t* list - list being printed
* Return:       void
* Description:  prints only birthdays of the data
*/
void PrintBDay(FILE* output, node_t* list);

/*
* Parameters:   FILE* input - input file
*               node_t* list - list being printed
* Return:       void
* Description:  prints only songs of the data
*/
void Song(FILE* output, node_t* list);

/*
* Parameters:   FILE* input - input file
* Return:       void
* Description:  prints 80 asterisks
*/
void printBorder(FILE* output);

/*
* Parameters:   *fp - function pointer
                FILE* - output file
                node_t* list - list being printed
* Return:       void
* Description:  prints all info to output file
*/
void print(void (*fp)(FILE* output, node_t* list), FILE* output, node_t* list);

/*
* Parameters:   int args - number of arguments
*               passed through the command line
* Return:       void
* Description:  checks number of arguments
*/
void checkArgs(int args);

/*
* Parameters:   FILE* input - input file
*               char* fileName - name of file
* Return:       void
* Description:  checks to see if file opened
*/
void checkFile(FILE* input, char* fileName);

/*
* Parameters:   node_t** list - linked list
* Return:       void
* Description:  deallocates memory
*/
void deleteList(node_t** list);

/*
* Parameters:   bday_t bday - date
* Return:       void
* Description:  checks valid date
*/
bool checkDate(bday_t bday);

/*
* Parameters:   int year - birth year
* Return:       bool - true or false
* Description:  checks if year is a leap year
*/
bool isLeapYear(int year);


/*
* Parameters:   void
* Return:       void
* Description:  prints start menu
*/
void MenuPrintEC();
