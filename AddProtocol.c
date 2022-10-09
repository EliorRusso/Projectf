#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048
int AddStruct(){
    int arrindex = 0;
    int x;
    scanf("%d", &x);
    int y = x;
    int sizearray[y];
    fflush(stdin);
    getchar();
    char structt[7] = "union ";
    char structt2[7] = "struct ";
    char protocolname[10];
    FILE *fptr;
    fptr = fopen("AddProtocol.h", "w");
    printf("Enter the protcol name:");
    fgets(protocolname, sizeof(protocolname), stdin);
    fprintf(fptr, "typedef ");
    fprintf(fptr, "%s{\n", structt); //protocol name
    fprintf(fptr, "%s{\n", structt2); //protocol name
    while(x>0){
        char unsignedint[15] = "unsigned int ";
        fprintf(fptr, "%s\n", unsignedint);
        char field[15]; //name of field
        int size = 0;
        printf("Enter a field:");
        fgets(field, sizeof(field), stdin);
        strcat(field, ":");
        printf("Enter a size:");
        scanf("%d",&size);
        sizearray[arrindex] = size;
        fprintf(fptr, "%s", field);
        fprintf(fptr,"%d;\n",size);
        x--;
        arrindex++;
        fflush(stdin);
        memset(field, 0, sizeof(field));
        getchar();
    }
    fflush(stdin);
    char close[19] = "} InstanceProtocol;";
    char close2[25] = "}; unsigned int array[";
    fprintf(fptr, "%s", close2);
    fprintf(fptr, "%d", y);
    fprintf(fptr, "];\n");
    fprintf(fptr, "%s", close);
    fclose(fptr);
    fflush(stdin);
    printf("\n");
}
int WriteToALine()
{
  FILE *file, *temp;
  char filename[FILENAME_SIZE] = "fuzz.c";
  char temp_filename[FILENAME_SIZE];
  char buffer[MAX_LINE];
  char newline[MAX_LINE];
  int write_line = 0;
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  printf("Line Number: ");
  scanf("%d", &write_line);
  fflush(stdin);
  printf("New Line: ");
  fgets(newline, MAX_LINE, stdin);
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    fgets(buffer, MAX_LINE, file);
    if (feof(file)) keep_reading = false;
    else if (current_line == write_line)
    {
      fputs(newline, temp);
      fputs(buffer, temp);
    }
    else fputs(buffer, temp);
    current_line++;
  } while (keep_reading);
  fclose(file);
  fclose(temp);
  remove(filename);
  rename(temp_filename, filename);
  return 0;
}
int main() {
    AddStruct();
    //WriteToALine();
}