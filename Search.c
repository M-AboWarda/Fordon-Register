#include "structures.h"
#include <stdbool.h>
#include "Search.h"
#include "UI.h"


// Function to print the info about a specefic vehicle
bool print_info(vehicle *list, int position, int length){
  if(position > length){// If input larger than the length of the array return false
    return false;
  }

  if(list[position].reg[0] == 0){ // If the specified place is == NULL return false
    return false;
  }

  print_register(list, position, position + 1);// If there is a vehicle print the vehicle info with the print_register function and return true
  return true;
}
