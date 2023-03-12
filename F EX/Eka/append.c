#include<stdio.h>
#include<conio.h>
int main()
{
    FILE *fsOne, *fsTwo, *fTarget;
    char fName1[20], fName2[20], fName3[30], ch;
    printf("Enter the Name of First Source File: ");
    gets(fName1);
    printf("Enter the Name of Second Source File: ");
    gets(fName2);
    printf("\nEnter the Name of Target File: ");
    gets(fName3);
    fsOne = fopen(fName1, "r");
    fsTwo = fopen(fName2, "r");
    if(fsOne==NULL || fsTwo==NULL)
    {
        printf("\nError Occurred while Opening the Source File!");
    }
    else
    {
        fTarget = fopen(fName3, "w");
        if(fTarget==NULL)
        {
            printf("\nError Occurred while Opening the Target File!");
        }
        else
        {
            ch = fgetc(fsOne);
            while(ch!=EOF)
            {
               fputc(ch, fTarget);
               ch = fgetc(fsOne);
            }
            ch = fgetc(fsTwo);
            while(ch!=EOF)
            {
                fputc(ch, fTarget);
                ch = fgetc(fsTwo);
            }
            printf("\n%s and %s Merged into %s Successfully!", fName1, fName2, fName3);
        }
    }
    fclose(fsOne);
    fclose(fsTwo);
    fclose(fTarget);
    getch();
    return 0;
}