#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


int main (int argc, char **argv){

  char* x = malloc(24);
  char* y = malloc(17);
  char* z = malloc(32);
  
  printf("x = %p\n", x);
  printf("y = %p\n", y);
  printf("z = %p\n", z);
  printf("\n");

  printf("testing whether a new block is allocated only when the size exceeds that of the old one:\n");
  x = malloc(32);
  printf("x = %p\n",x);
  printf("reallocating x with SMALLER size\n");
  y = realloc(x,24);
  printf("new allocation goes to %p\n",y);

  printf("reallocating x with LARGER size\n");
  y = realloc(x,44);
  printf("new allocation goes to %p\n",y);
  printf("\n");
  
  printf("testing whether the contents are copied correctly:\n");
  char* str = (char*) malloc(5*sizeof(char));
  strcpy(str,"abcd");
  printf("allocated 5 bytes for the string: %s\n",str);
  printf("reallocating 8 bytes\n");
  str = realloc(str,(8*sizeof(char)));
  printf("adding another two letter to the string...\n");
  str[4]='e';
  str[5]='f';
  printf("result: %s\n",str);
  printf("the original four letters were copied successfully\n");
  printf("\n");
  
  printf("testing block alignment\n");
  bool aligned = false; 
  printf("allocating 5 bytes\n");
  x=malloc(5);
  aligned = ((intptr_t)x % 4 == 0);
  printf("aligned = %s\n",aligned ? "true":"false");
  printf("allocating 17 bytes\n");
  x=malloc(17);
  aligned = ((intptr_t)x % 4 == 0);
  printf("aligned = %s\n",aligned ? "true":"false");
 printf("allocating 4 bytes\n");
  x=malloc(4);
  aligned = ((intptr_t)x % 4 == 0);
  printf("aligned = %s\n",aligned ? "true":"false");
   printf("allocating 1 byte\n");
  x=malloc(1);
  aligned = ((intptr_t)x % 4 == 0);
  printf("aligned = %s\n",aligned ? "true":"false");


}
