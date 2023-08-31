#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UI.h"



void * scans(int positions, char mode){

  char * input = (char *)malloc((positions + 1) *sizeof(char));
  int * res = (int *)malloc( (positions + 1) * sizeof(int));
  printPrefix();
  fflush (stdin);
  char * status = fgets(input, 30, stdin);
  
  if(status == NULL) return NULL;

  int check = 0; // this will represent the type of the input 
  // 0 -> starting postion waiting to be modified
  // 1 -> the output is a name
  // 2 -> the output is a text and may contain numbers
  // 3 -> the output is a number
  //-1 -> the output is invalid or none of the above
  for(int i = 0; i < strlen(input); i++){
    //printf("%d \n", i);
    int upper = (input[i] >= 'A' && input[i] <= 'Z') ? 1 : 0;
    int lower = (input[i] >= 'a' && input[i] <= 'z') ? 1 : 0;
    int number= (input[i] >= '0' && input[i] <= '9') ? 1 : 0;
    int space = (input[i] == ' ' )                   ? 1 : 0;
    int end = (input[i] == '\0')                     ? 1 : 0;
    int newLine = (input [i] == 10 || input [i] == 13 || input [i] == 26 )? 1 : 0;
    // printf("upper %d   lower %d   number %d   space %d   newLine %d   end %d", upper,lower,number,space, newLine, end);
    // printf("%c %d\n",input[i], (int) input[i]);

    if(i == 0 && newLine){
      return NULL;
    }
    
    if(newLine){
      input[i] = ' ';
    }
    
    //valid name char;
    if( (mode == 'I') && (upper || lower || space || newLine || end) ){// 'I' for Ism (name)
      if(check == 0){
        check = 1;
      }
      continue;// Success

      //strcpy( (char *)address, input);//the result later

    }else if( (mode == 'N') && (upper || lower || number || newLine || end) ){// 'N' for Nas (text)
      if(check == 0){
        check = 2;
      }
      continue;// Success

      //strcpy( (char *)address, input);//the result later

    }else if(mode == 'R' && (number  || newLine || end) ){// 'R' for rqam (number)
      if(check == 0){
        check = 3;
      }
      continue;// Success

      //*(int *)address = atoi(input);//the result later

    }else{// invalid input
      check = -1;
      //printf("oh no you are you crying?");
      
      // Failed
      return NULL;
    }

  }
  if(check == 1 || check == 2){// it is a string
    //strcpy( (char *)address, input);
    return input;

  }else if(check == 3){// it is a number
  *res = atoi(input);  
    return res;
  

  }
  return NULL;

}


