#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

//save the modified list of vehicles to the register 
void writeToFile(vehicle * vehicles, int amount){

//oppen the file 'cars.dat' in binary writing mode, if any problem occur while oppinging the file display an error massege
FILE *fp = NULL;
  if ((fp = fopen("cars.dat", "wb")) == NULL){
    puts("File could not be opened\n");
  }else{
    // srart writing the vehicles data one by one to the file in binary 
    for (int i = 0; i < amount; i++){
      fwrite(&vehicles[i], sizeof(vehicle), 1, fp);
    }
    // close the file
    fclose(fp);

    // print success massege
    puts("The register was successfully written in the file.\n");
  }
}

// we might need this in case we break anything in the future

// void writeToFile(vehicle * vehicles, int amount){

// vehicle DataList[] = {
//     {"Aircraft", "Guizhou JL-9", "101XLM", "Mohammad", 1},
//     {"Aircraft", "Sukhoi Su-47", "70-XGI", "Abo Omar", 2},
//     {"Airstrike", "BM-21 Grand", "FK-Isr", "Abo Obida", 3},
//     {"SUV", "Subaru", "222AAK", "Abo Warda", 4},
//     {"SUV", "BMW", "123ABC", "Nour", 5},
//     {"SUV", "BMW", "123ABC", "Nour", 6},
//     {"zzz", "zzz", "ZGZ987", "ZORO", 7},
//     {"SUV", "BMW", "123ABC", "Nour", 8},
//     {"SUV", "BMW", "123ABC", "Nour", 9},
//     {"SUV", "BMW", "123ABC", "Nour", 10}
//   };
// FILE *fp = NULL;
// if ((fp = fopen("cars.dat", "wb")) == NULL){
//         puts("File could not be opened\n");
//       }else{
//         for (int i = 0; i < amount; i++){
//           fwrite(&vehicles[i], sizeof(vehicle), 1, fp);//dynamic dataset
//           //fwrite(&DataList[i], sizeof(vehicle), 1, fp);// fixed dataset
//         }
//         puts("The register was successfully written in the file.\n");
//         fclose(fp);
//       }
// }