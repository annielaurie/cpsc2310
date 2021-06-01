/********************************
* Annie Hayes                   *
* CPSC 2310 Spring 21           *
* UserName: ahayes5             *
* Instructor: Dr. Yvon Feaster  *
*********************************/
#include "functions.h"


//month name string
const char* monthStr[] = {" ", "January", "February", "March", "April",
                          "May", "June", "July", "August", "September",
                          "October", "November", "December"};
//enum month
enum Month {January = 1, February, March, April, May, June, July, August,
            September, October, November, December};



//adds a node to the linked list
void add(node_t **node, node_t **head)
{
  //sets the head pointer->next equal to the node being added
  //so if head = 1, node now equals 2
  (*head)->next = *node;

}

//reads data from input file & allocates memory for linked list
node_t* readNodeInfo(FILE* input)
{
  //char arrays & ints for data values
  char first[100];
  char last[100];
  char music[100];
  char str[100];
  int m, d, y;

  //allocate memory for linked list
  node_t* list = (node_t*)malloc(sizeof(node_t));

  //if the line is equal to EOF return null
  if ((fscanf(input,"%[^,]%*c", last)) == EOF)
  {
    return NULL;
  }

  //scan info into char arrays & ints
  fscanf(input,"%[^,]%*c",first);
  fscanf(input,"%[^,]%*c", str);
  m = atoi(str);
  fscanf(input,"%[^,]%*c", str);
  d = atoi(str);
  fscanf(input,"%[^,]%*c", str);
  y = atoi(str);
  fscanf(input,"%[^,\n]%*c", music);

  //create bday_t variables
  bday_t bday;
  bday.month = m;
  bday.day = d;
  bday.year = y;

  //if bday isnt valid, return head pointer
  if (checkDate(bday))
  {
    strcpy(list->lastName, last);
    strcpy(list->firstName, first);
    list->bday.month = m;
    list->bday.day = bday.day;
    list->bday.year = bday.year;
    strcpy(list->song, music);
  }

  return list;
}


//reads file & adds to list
node_t* createList(FILE* input, node_t** head)
{
  /*this is easier to visualize
  if i assign numbers to the pointers*/

  //head = 1
  node_t *headPtr = readNodeInfo(input);
  //new = 2
  node_t *newNode = readNodeInfo(input);
  //prev = 1
  node_t *prevNode = headPtr;

  while (newNode != NULL)
  {
    //links pointers
    //prev = 1, new = 2
    add(&newNode, &prevNode);
    //prev = 2
    prevNode = newNode;
    //new = 3
    newNode = readNodeInfo(input);
  }

  return headPtr;
}

//prints data
void PrintList(FILE* output, node_t* list)
{
  printBorder(output);

  //set temp node equal to head pointer (list)
  node_t* temp = list;

  //if the next nodes are empty
  if (temp->next == NULL || temp == NULL)
  {
    //print error message & exit the program
    fprintf(stderr, "\nlist is empty.\n");
    exit(0);
  }
  //print statement for starting the list
  fprintf(output,"LIST INFO:\n");

  //while the next node has data
  while(temp->next != NULL)
  {
    if (temp->bday.year == 0)
    {
      temp = temp->next;
    } else {
    //set an enum equal to bday month
    enum Month m = temp->bday.month;
    //print data
    fprintf(output,"%s, %s, ",temp->lastName, temp->firstName);
    fprintf(output,"%s %d, %d,",monthStr[m], temp->bday.day, temp->bday.year);
    fprintf(output," %s \n", temp->song);
    //set temp equal to the next node
    temp = temp->next;
  }
  }
  //print the last temp node
  enum Month m = temp->bday.month;
  fprintf(output,"%s, %s, ",temp->lastName, temp->firstName);
  fprintf(output,"%s %d, %d,",monthStr[m], temp->bday.day, temp->bday.year);
  fprintf(output," %s \n", temp->song);
  //final output
  fprintf(output,":\n:\n");
  printBorder(output);
}

//prints only names of the data
void PrintName(FILE* output, node_t* list)
{
  printBorder(output);
  node_t* temp = list;
  if (temp->next == NULL || temp == NULL)
  {
    fprintf(stderr, "list is empty.");
    exit(0);
  }
  while(temp->next != NULL)
  {
    fprintf(output, "%s, %s\n",temp->lastName, temp->firstName);
    temp = temp->next;
  }
  fprintf(output, "%s, %s\n",temp->lastName, temp->firstName);
  printBorder(output);

}

//prints only birthdays of the data
void PrintBDay(FILE* output, node_t* list)
{
  printBorder(output);
  node_t* temp = list;
  enum Month m = temp->bday.month;
  while(temp->next != NULL)
  {
    fprintf(output,"%s %s's date of birth is ",temp->firstName,temp->lastName);
    fprintf(output,"%s %d, %d\n", monthStr[m],temp->bday.day,temp->bday.year);
    temp = temp->next;
  }
  fprintf(output,"%s %s's date of birth is ",temp->firstName,temp->lastName);
  fprintf(output,"%s %d, %d\n", monthStr[m],temp->bday.day,temp->bday.year);
  printBorder(output);

}

//prints only songs of the data
void Song(FILE* output, node_t* list)
{
  printBorder(output);
  node_t* temp = list;
  while(temp->next != NULL)
  {
    fprintf(output,"%s %s's favorite song is",temp->firstName,temp->lastName);
    fprintf(output," %s\n",temp->song);
    temp = temp->next;
  }
  fprintf(output,"%s %s's favorite song is",temp->firstName,temp->lastName);
  fprintf(output," %s\n",temp->song);
  printBorder(output);
}

//prints 80 asterisks
void printBorder(FILE* output)
{
  int maxStar = 80;
  for (int i = 0; i <= maxStar; i++)
  {
    fprintf(output, "*");
  }
  fprintf(output, "\n");

}

//prints all info
void print(void (*fp)(FILE* output, node_t* list), FILE* output, node_t* list)
{
  fp(output, list);
}

//checks number of arguments
void checkArgs(int args)
{
  //if arguments are not enough
  if (args != 3)
  {
    fprintf(stderr, "\nNot enough or too many command line arguments.\n");
    fprintf(stderr, "Exiting Program\n");
    exit(0);
  }
}

//checks to see if file opened
void checkFile(FILE* input, char* fileName)
{
  if (input == NULL)
    {
      fprintf(stderr, "\nError: could not open file %s."
              "Exiting program.\n", fileName);
      exit(0);
    }
}

//deallocates memory
void deleteList(node_t** list)
{
  //set start to head
  node_t *startNode = *list;

  node_t  *nextNode = startNode->next;

  //while start is not null
  while(startNode != NULL)
  {
    //set next equal to the next node
    nextNode = startNode->next;
    //delete node
    free(startNode);
    //set node equal to next node
    startNode = nextNode;

  }
  //free(startNode);
  return;

}

//checks valid date
bool checkDate(bday_t bday)
{
  int m = bday.month;
  int d = bday.day;
  int y = bday.year;

  //error for when month is smaller than 0 or greater than 12
  if (m <= 0 || m > 12)
  {
    fprintf(stderr, "Bday month is not valid.\nFailed checkDate month.\n");
    return false;
  }
  //error for when year is smaller than 1900 or greater than 2020
  if (y < 1900 || y > 2020)
  {
    fprintf(stderr, "Bday year is not valid.\nFailed checkDate year.\n");
    return false;
  }
  //error for when day is invalid
  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 31)
  {
    if (d > 31)
    {
      fprintf(stderr, "BDay day is not valid.\nFailed checkDate day.\n");
      return false;
    }
  }
  if (m == 4 || m == 6 ||m == 9 || m == 11)
  {
    if (d > 30)
    {
      fprintf(stderr, "BDay day is not valid.\n Failed checkDate day.");
      return false;
    }

  }
  //check leap year
  if (m == 2 && d == 29)
  {
    if (isLeapYear(y) == false)
    {
      fprintf(stderr, "BDay day is not valid.\n Failed checkDate day.");
      return false;
    }
  }
  return true;
}

//checks if year is a leap year
bool isLeapYear(int year)
{
  //if the year is divisible by 4 or 400 return true
  if (year % 4 == 0)
  {
    return true;
  }
  return false;
}

//prints menu
void MenuPrintEC()
{
  printf("\n\nMENU:\nWhat would you like to print?");
  printf("\n1: Name");
  printf("\n2. Birthday");
  printf("\n3. Song");
  printf("\n4. All of the Above");
  printf("\n5. Quit\n");
}
