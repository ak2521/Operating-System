#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
   char ch;// source_file[20], target_file[20];
   FILE *source, *target;
   char source_file[]="x1.txt";
   char target_file[]="x2.txt";
   source = fopen(source_file, "r");
   if (source == NULL) {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   target = fopen(target_file, "w");
   if (target == NULL) {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
   printf("File copied successfully.\n");
   fclose(source);
   fclose(target);
   return 0;
}
raja
Sudhir sharma
