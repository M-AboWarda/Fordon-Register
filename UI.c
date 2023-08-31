#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "UI.h"


// Function to print the menu in red
void printMenu(){
  printf("\e[31;06m");
  printf("1. Add a vehicle\n");
  printf("2. Remove a vehicle\n");
  printf("3. Sort the vehicles by model\n");
  printf("4. Print out information about a specefic vehicle\n");
  printf("5. Print out the whole register\n");
  printf("0. Write to file and exit\n");
  printf("\n");
}

// Function to print a prefix in cyan
void printPrefix(){
  printf("\033[1;34m");
  printf("Input>> ");
  printf("\033[0m");
}

// Function to print the a tabell and insert the element centered in cells.
void print_register(vehicle *list, int position, int length){
  printf("|-----|------------------|------------------|------------------|------------------|------------------|\n");
  printf("|  #  |       Type       |       Model      | Register Number  |       Name       |       Age        |\n");
  printf("|-----|------------------|------------------|------------------|------------------|------------------|\n");

  for(int i = position; i < length; i++){
    if(list[i].person.age != 0){// If value not NULL continue
      char *id = centerText(converter(i, "%d"), 5); // convert the center the text with width = 5 in variable
      char *name = centerText(list[i].person.name, 18);// center the text with width = 18 in variable
      char *age = centerText(converter(list[i].person.age, "%d"), 18);// convert the center the text with width = 18 in variable
      char *type = centerText(list[i].type, 18);// center the text with width = 18 in variable
      char *model = centerText(list[i].modell, 18);// center the text with width = 18 in variable
      char *reg = centerText(list[i].reg, 18);// center the text with width = 18 in variable

      // Print the variables with som beauty 
      printf("|%s", id);
      printf("|%s", type);
      printf("|%s", model);
      printf("|%s", reg);
      printf("|%s", name);
      printf("|%s|", age);
      printf("\n");

      // Deallocate the memory
      free(id);
      free(name);
      free(age);
      free(type);
      free(model);
      free(reg);

      //Close the tabell
      printf("|-----|------------------|------------------|------------------|------------------|------------------|\n");
    }
  }
}

// Function to center strings
char * centerText(char * text, int width){
  char *string = (char *)malloc((width + 1) * sizeof(char));// Allocate memory
  memset(string, ' ', (width + 1) * sizeof(char));// Fill the memory with empty spaces with memset()
  int position = (width - strlen(text)) / 2; // Center the text
  for(int i = 0; i < strlen(text); i++){
    string[position + i] = text[i]; // Insert the text in the string variable 
  }
  string[width] = '\0';// Put the Null-terminating string '\0' in the end of the string
  return string;// Return the string
}


// Function to convert integer to string
char *converter(int value, char*out){
  char * intToString = (char *)malloc(sizeof(int) * 10);
  sprintf(intToString, out, value);
  return intToString;
}