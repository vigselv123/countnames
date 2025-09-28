/**
 * Description: This module implements reading and counting names from a .txt file and printing the result.
 * Author name: Vignesh Selvaraj
 * Author email: vignesh.selvaraj@sjsu.edu
 * Last modified date: 10/1/2025
 * Creation date: 9/27/2025
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 30

/**
* This function reads names from a file and counts how many times each name shows up in the file.
* Assumptions: The max number of distinct names is 100 and a name can be up to 30 characters long.
* Input parameters: fileName, names, countNames
* Returns: j which is the total number of distinct names in the file
**/
int countNames(const char *fileName, char names[MAX_NAMES][MAX_LENGTH], int countNames[MAX_NAMES]) {
    FILE *file = fopen(fileName, "r");

    //Checks if file exists, if not, prints error message and exits with status code 1
    if (file==NULL) { 
        fprintf(stderr, "error: cannot open file\n");
        exit(1);
    }

    int line = 1;
    int j = 0;
    int notUniqueName = 0;
    char buf[MAX_LENGTH];

    //Loops through each line of the file while storing the current line in temporary array buf
    while(fgets(buf, 30, file)) {
        //if there is a newline, replace it with null
        if(buf[strlen(buf)-1]=='\n'){
            buf[strlen(buf)-1]='\0';
        }
        //if there is an empty line, print a warning message, increment the amount of lines, and continue to the next iteration of the loop 
        if(strlen(buf)<1) {
            fprintf(stderr, "Warning - Line %d is empty.\n", line);
            line++;
            continue;
        }

        //compares each name in names array to the name currently stored in buf to see if the name is already in names
        //if the name is already stored, the count for it in countNames is increased and the name is set as not a unique name
        for(int i = 0; i < MAX_NAMES; i++) {
            if(strcmp(names[i], buf)==0) { 
                countNames[i]++;
                notUniqueName=1;
                break;
            }
         }

         //if the name is unique, it is copied from buf into the names array and its count is initialized to 1
         //then increment j which is the number of distinct names
         if (notUniqueName==0) { 
            strcpy(names[j], buf);
            countNames[j]=1;
            j++;
         }

         //reset notUniqueName to 0 for the next iteration in the loop
        notUniqueName=0;

        //increment the number of lines
        line++;

     }

    fclose(file);
    return j;
 }


int main(int argc, char *argv[])
{
    //if no files or parameters are entered, exit and return 0
    if(argc==1) { 
        exit(0);
    }
    char names[MAX_NAMES][MAX_LENGTH];
    int count[MAX_NAMES];

    int totalNames = countNames(argv[1], names, count);

    //if the file is empty or has no names, exit
    if (totalNames == 0) {
        exit(1);
     }

     //loop through the names and count arrays to print the distinct names alongside the count for each name
    for(int i = 0; i< totalNames; i++) {
        printf("%s: %d\n", names[i], count[i]);
     }
    
    exit(0);
}