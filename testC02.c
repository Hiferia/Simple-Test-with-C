#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 500

int main()
{
    char data[DATA_SIZE]; //simple variable to store user content
    FILE *filePtr;          //file pointer to hold reference

    filePtr = fopen("fileTestC.txt", "w");      //we create the file in "w" (write) mode

    if(filePtr == NULL)     //return null if the program failed to create and open the file
    {
        printf("Error: unable to create file txt");     //print the error
        exit(EXIT_FAILURE);                             //exit from the program
    }

    printf("Enter your text to store in file: \n");     
    fgets(data, DATA_SIZE, stdin);                      //get the input from user and store it in data, stdin = standard input

    fputs(data, filePtr);                               //put the content of data into file

    fclose(filePtr);                                    //close the file and save data

    printf("File created and saved successfully\n");


    int controlV, controlC;                             //2 variables to control vowels and consonants

    char *pointer = data;                               //copy data into pointer
    controlC = 0;
    controlV = 0;

    while(*pointer!='\0')                               //we exit from the while when the program read 0
    {
        if(*pointer == 'A' || *pointer == 'E' || *pointer == 'I' || *pointer == 'O' || *pointer == 'U' ||
         *pointer == 'a' || *pointer == 'e' || *pointer == 'i' || *pointer == 'o' || *pointer == 'u')
         {
             controlV++;            //if read a vowel increments the variable for vowels control
         }
        else if (*pointer == ' ')
        {
            //if read a space does nothing
        }
        else
        {
            controlC++;             //if read a consonant increments the variable for consonants control
        }
        pointer++;                  //increment the pointer to read the next character
    }

    printf("Number of vowels: %d\n Number of consonants: %d\n", controlV, controlC);
    return 0;
}