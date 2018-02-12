/*
* Nicolle Ayon C. 
* nayoncam
* This program takes in a file, and outputs all of the words backwards
* each on a separate line (Like Filereverse.java from Lab2). 
* Code for main taken from fileIO.c given in Lab3
* fileReverse.c
* To compile, run " make " and run by  " ./fileReverse <inFile> <outFile> "
* =============================================================================
*/ 
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void stringReverse(char* s); //function definition

int main(int argc, char* argv[]){
    FILE* in;  /* file handle for input */
    FILE* out; /* file handle for output */
    char word[256]; /* char array to store words from input file */

    /* check command line for correct number of arguments */
    if( argc != 3 ){ //***** arg0 = name of program, arg1 = inputfile, arg2 = output file
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* open input file for reading */
    in = fopen(argv[1], "r");
    if( in==NULL ){
        printf("Unable to read from file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

   /* open output file for writing */
    out = fopen(argv[2], "w");
    if( out==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
    }

    /* read words from input file, print on separate lines to output file*/
    while( fscanf(in, " %s", word) != EOF ){
        stringReverse(word); //***** added stringReverse
        if (feof(in)) //*****checks to see if its at the end of file
            fprintf(out, "%s", word); //***** if it is, dont print new line afterwards
        else 
            fprintf(out, "%s\n", word); //print new line after word
    }
   
    /* close input and output files */
    fclose(in);
    fclose(out);
    return(EXIT_SUCCESS);
}

void stringReverse(char* s){

    int wL = strlen(s)-1; //creater a variable to hold length of char array

    for(int i = 0; i < wL; i++){ // for the length of the array
         char temp = s[i]; //saves variable you swapping in a temp
         s[i]  = s[wL]; // set i to corresponding wl-i
         s[wL] = temp; // set the (now duplicated) letter to the temporary char
         wL--; //decrease wL so it goes to the next one to left
    }

}


