#define MAX_NAME_LENGTH 255
#define MAX_TYPE_LENGTH 255
#define MAX_MODELL_LENGTH 255
#define MAX_REG_LENGTH 255
// 255 because 1 byte == 256 values ---> 0 to 255 = 256

typedef struct{
  char name[MAX_NAME_LENGTH];
  int age;
}owner;

typedef struct{
  char type[MAX_TYPE_LENGTH];
  char modell[MAX_MODELL_LENGTH];
  char reg[MAX_REG_LENGTH];
  owner person;
}vehicle;

