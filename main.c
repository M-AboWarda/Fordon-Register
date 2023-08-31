

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"

#include "read_from_file.h"
#include "Input.h"
#include "write_to_file.h"
#include "CheckRegister.h"
#include "Sort.h"
#include "Search.h"
#include "addVehicle.h"
#include "removeVehicle.h"
#include "UI.h"




#define MAX_VEHICLES 10
#define INVALID -1
#define SUCCESS 1

int main(void) {
  int * input = NULL;

  //the amount of taken places in the register
  int places = 0;

  //vehicles array placeholder 
  vehicle * vehicles = (vehicle *)calloc(MAX_VEHICLES, sizeof(vehicle));

  //get all vehicles in the register file "cars.dat"
  vehicles = getVehicles(); 
 
  //calculating the vehicles quantity in the register 
  for(int i = 0; i < MAX_VEHICLES; i++){
    if(vehicles[i].person.age == 0){
      break;
    }else{
      places++;
    }
  }

  do{
    
    printMenu();
    
    //take the input from the user
    input = (int *) scans( 2, 'R');
    
    //clear the screen
    system("clear");
    
    //validat the input if anyting went wrong irritate
    if(input == NULL){printf("Invalid Input!\n");continue;}

    //decided according the the user input
    switch(*input){

      //exit the program and save the changes
      case 0:
      writeToFile(vehicles, places);
      break;
      
      //Add a vehcle to the register
      case 1:
      // if the register is not full
      if(places < MAX_VEHICLES){
        // try to add a vehicle to the register
        // and if it is added show me the vehicle then increment the vehcles conter with one (places ++)
        if( addVehicle(vehicles, places) == SUCCESS ){
          //print_register(vehicles, places -1, places);
          places++;
        }else{// if something went wrong with adding a vehicle to the register print an error massege to the user
          printf("No change occurred to the register!");
        }
      }else{
        printf("The register if full!\n");
      }
      break;

      // Remove a vehicle from the register 
      case 2:
      {
        // Ask the user for input unti a valid input is given
        int * input = NULL;
        while(input == NULL){
          printf("Vehicle ID: \n");

          input = (int *)scans( 2, 'R');

          if(input == NULL){
            printf("Invaild vehicle ID.\n");
          }
        }
        //try to remove the vehicle if something went wrong display an error massege to the user
        if(removeVehicle(vehicles, *input, places) == false){
          printf("Vehicle ID does not exist in the register\n");
        }else{ //  decrement the vehcles conter with one (places--)
          places--;
          printf("Vehicle has been removed\n");
        }
      }
      break;
      
      //sort the register in alphabetical order according to the vehicle model
      case 3:
      bubbleSort(vehicles, places);
      printf("The register has been sorted\n");
      break;
      
      //search for a specific vehicle and display its information
      case 4:
      {
        input = NULL;
        //ask the user for a vehicle id until a valid input is given
        while(input == NULL){
          printf("Choose vehicle ID: \n");
          input = (int *)scans( 2, 'R');
          if(input == NULL){printf("Please write a valid input\n");}
          
        } 
        // if the vehicle id is not in the register display error massege
        // otherwise display the information about the vehicle
        if(print_info(vehicles, *input, places) == false){
          printf("The vehicle does not exist\n");
        }
      }
      break;
      
      //show the entier register in a table format
      case 5:
      print_register(vehicles, 0, places);
      break;
      
      //if the user input is not from the list it will be considered as an invalid input
      default:
      printf("Invalid Input\n");
      break;

    }
  //continue irtating until the user chooses to close the program
  }while(*input != 0);
  
  //free(vehicles);
  return 0;
}