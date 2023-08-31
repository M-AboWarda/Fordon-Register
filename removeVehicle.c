#include <stdbool.h>
#include "structures.h"

//Function to remove a vehicle from the struct and return True och Flase
bool removeVehicle(vehicle *list, int position, int length){
  if(position > length){// If input larger than the length of the array return false
    return false;
  }

  if(list[position].person.name[0] != 0){ // If the array in the position is not NULL
    for(int i = position; i < length; i++){ // Start from the position and move the next position to the previous until reaching the end
      list[i] = list[i + 1];
    }
    
    return true;// Return true when done
  }
  return false; //Return false when nothing removed
}