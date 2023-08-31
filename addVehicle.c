#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "Input.h"


int addVehicle(vehicle * vehicles, int index){
  static vehicle newVehicle;
  char * ownerName,  * modell, * regNum, * type;
  int * owner_age;

  printf("Owner name: \n");
  do{
    ownerName = (char *) scans( 20, 'I');
    (ownerName == NULL) ? printf("something went wrong! try one more time...\n") : 0;
  }while(ownerName == NULL);

  printf("Owner Age: \n");
  do{
    owner_age = (int *)scans( 20, 'R');
    (owner_age == NULL) ? printf("something went wrong! try one more time...\n") : 0;
  }while(owner_age == NULL);

  printf("vehicle type: \n");
  do{
    type = (char *) scans( 20, 'N');
    (type == NULL) ? printf("something went wrong! try one more time...\n") : 0;
  }while(type == NULL);

  printf("vehicle model: \n");
  do{
    modell = (char *) scans( 20, 'N');
    (modell == NULL) ? printf("something went wrong! try one more time...\n") : 0;
  }while(modell == NULL);
  
  printf("vehicle registration number: \n");
  do{
    regNum = (char *) scans( 20, 'N');
    (regNum == NULL) ? printf("something went wrong! try one more time...\n") : 0;
  }while(regNum == NULL);

  strcpy(newVehicle.person.name, ownerName);
  newVehicle.person.age = *owner_age;
  strcpy(newVehicle.modell, modell);
  strcpy(newVehicle.reg, regNum);
  strcpy(newVehicle.type, type);
  
  
  //add the new vehicle the the vehicles list
  vehicles[index] = newVehicle;
  
  return 1;
}
