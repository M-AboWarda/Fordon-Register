#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

#define MAX_VEHICLES 10
vehicle DataList;

// getVehicles function read the struct from the file into the program
vehicle * getVehicles(){
  static vehicle vehicles [MAX_VEHICLES]; //Variable to store the struct with size 10
  FILE * fp = NULL; //Point the pointer to NULL
  if((fp = fopen("cars.dat", "rb")) == NULL){//If NULL when opening the file print error
    printf("Error Oppening the file");
  }else{
    int i = 0;
    while( !feof(fp) ){// Keeps looping until reaching the end-of-file of the file fp
      int res = fread(&vehicles[i], sizeof(vehicle), 1, fp);// Reads the struct from the file and store it in the variable vehicles[i]
      i++;
    }
    fclose(fp);// Close the file when done
  }
  return &vehicles[0];// return the array with the vehicles
}
