#include <stdio.h>
void appendFiles(char source[],
                 char destination[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(source, "a+");
    fp2 = fopen(destination, "a+");
    if (!fp1 && !fp2) {
        printf("Unable to open/"
               "detect file(s)\n");
        return;
    }
    char buf[100];
    fprintf(fp2, "\n");
    while (!feof(fp1)) {
        fgets(buf, sizeof(buf), fp1);
        fprintf(fp2, "%s", buf);
    }
 
    rewind(fp2);
    while (!feof(fp2)) {
        fgets(buf, sizeof(buf), fp2);
        printf("%s", buf);
    }
}
int main(int argc,char *args[])
{
	if (argc == 4 && args[3] == ">>")
	{
    char source[] = args[1],
         destination[] = args[3];
    appendFiles(source, destination);
}
else 
 printf("invalid args");
    return 0;
}
