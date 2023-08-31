#include "structures.h"

// Function to check if the register is full or not. It returns How many empty places is there
int RegisterFull(vehicle *vehicles_list, int vehicles_list_length){
  for(int i = 0; i<vehicles_list_length; i++){
    if(vehicles_list[i].reg[0] == 0){ //Checks if the array has a free place by checking if reg[0] == NULL
      return i;
    }
  }
  return -1;
}
