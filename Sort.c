#include "structures.h"
#include <stdio.h>

#define a 96
#define z 122
#define DIFFERENCE 32


//Bubble sort function to sort the vehicles by the model
void bubbleSort(vehicle *vehicle_list, int length){
  int i;
  int tmp;
  int has_swapped;

  do{
    has_swapped = 0;
    for(i = 0; i < length - 1; i++){// Loops the entire struct array
      if(vehicle_list[i].modell[0] >= a && vehicle_list[i].modell[0] <= z){ //Convert the fist lowercase letters to uppercases
        vehicle_list[i].modell[0] -= DIFFERENCE;
      }
      if(vehicle_list[i +1].modell[0] >= a && vehicle_list[i +1].modell[0] <= z){// Convert the first lowecase letters to upper cases in the second place in the array 
        vehicle_list[i +1].modell[0] -= DIFFERENCE;
      }

      
      if((vehicle_list[i].modell[0]) > vehicle_list[i + 1].modell[0] && vehicle_list[i + 1].modell[0] != 0){// If the first letter is larger than the first letter in the next element, and not equal to NULL
        vehicle tmp = vehicle_list[i];
        vehicle_list[i] = vehicle_list[i + 1]; // Change places
        vehicle_list[i + 1] = tmp;
        has_swapped = 1;
      }
    }
  } while (has_swapped); // Loop until all elements are sorted
}
