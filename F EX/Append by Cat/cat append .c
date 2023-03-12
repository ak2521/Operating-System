#include <stdio.h>
 
// Function that appends the contents
void appendFiles(char source[],
                 char destination[])
{
    // declaring file pointers
    FILE *fp1, *fp2;
 
    // opening files
    fp1 = fopen(source, "a+");
    fp2 = fopen(destination, "a+");
 
    // If file is not found then return.
    if (!fp1 && !fp2) {
        printf("Unable to open/"
               "detect file(s)\n");
        return;
    }
 
    char buf[100];
 
    // explicitly writing "\n"
    // to the destination file
    // so to enhance readability.
    fprintf(fp2, "\n");
 
    // writing the contents of
    // source file to destination file.
    while (!feof(fp1)) {
        fgets(buf, sizeof(buf), fp1);
        fprintf(fp2, "%s", buf);
    }
 
    rewind(fp2);
 
    // printing contents of
    // destination file to stdout.
    while (!feof(fp2)) {
        fgets(buf, sizeof(buf), fp2);
        printf("%s", buf);
    }
}
 
// Driver Code
int main()
{
    char source[] = "file1.txt",
         destination[] = "file2.txt";
 
    // calling Function with file names.
    appendFiles(source, destination);
 
    return 0;
}