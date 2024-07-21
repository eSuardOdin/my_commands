#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../errors/errors.h"
#include "utils.h"

#define MAX_PATH_LEN 4096
// Change this by adding dynamic buffer allocation
#define MAX_LINE_LEN 1024
#define TEMP_PATH "temp.txt"

/**
 * @brief Checks if a file is openable, exits with error if not.
 * 
 * @param filepath The filepath checked
 * @return FILE* Pointer to the checked file if OK
 */
FILE *checkFile(char *filepath)
{
    // Check if filename not too long
    if ((int)strlen(filepath) > MAX_PATH_LEN)
    {
        char buff[64];
        sprintf(buff, "Filepath is too long : %d max characters", MAX_PATH_LEN);
        handleError(-2, buff);
    }  
    // Open file to read
    FILE *fp = fopen(filepath, "r");
    // Check if file exists
    if(fp == NULL)
    {
        char *baseErr = "Unable to open the file : ";

        char *errMess = malloc(strlen(filepath) + strlen(baseErr) + 1);
        sprintf(errMess, "%s%s\n", baseErr, filepath);
        handleError(-1, errMess);
        free(errMess);
    }

    return fp;
}


/**
 * @brief Prints a file
 * @param source File to print
 * @param dest Where to print it, warning: If NULL, print to stdout 
 */
void printFile(FILE *source)
{
    // --- Print doc ---
    char line[MAX_LINE_LEN];
    while(fgets(line, MAX_LINE_LEN, source) != NULL)
    {
        printf("%s", line);
    }
    // Closing source file
    fclose(source);
}

/**
 * @brief Remove temporary file. If can't do, exit with error.
 * 
 */
void removeTemp()
{
    int errCode = remove(TEMP_PATH);
    if(errCode != 0)
    {
        handleError(errCode, "Error on deleting temp file");
    }
}

/**
 * @brief Concat source to temporary text file
 * 
 * @param source The file we are reading from
 */
void appendTemp(FILE *source)
{
    // Open temp file to append
    FILE *fp = fopen(TEMP_PATH, "a");
    if(fp == NULL)
    {
        handleError(-3, "Unable to open temp file.");
    }
    // --- Print doc ---
    char line[MAX_LINE_LEN];
    while(fgets(line, MAX_LINE_LEN, source) != NULL)
    {
        fprintf(fp, "%s", line);
    }
    fclose(fp);
    fclose(source);
}

/**
 * @brief Fill two arrays : Options and Variables
 * 
 * @param n Number of command line arguments
 * @param args Arguments array
 * @param opt Option array to fill
 * @param var Variables array to fill
 */
void initVariables(int n, char *args[], char *opt[], char *var[])
{
    // int began_vars = 0;
    int i_opt = 0;
    int i_var = 0;
    // Getting arrays of options and filepaths (too long)
    for(int i = 1; i < n; i++)
    {
        // If getting an option before any filepath
        if(args[i][0] == '-')
        {
            /* Don't care about options position
            // If we placed options after file path, error
            if(began_vars)
            {
                handleError(-4, "Error, command must be formatted as so : \"[OPTIONS]...[FILES]\"\n");
            }
            */
            opt[i_opt] = args[i];
            printf("Option %s is args[%d] and seen as opt[%d]\n", args[i], i, i_opt);
            i_opt++;
        }
        else
        {
            /*
            if(!began_vars)
            {
                began_vars = 1;
            }
            */
            var[i_var] = args[i];
            i_var++;
        }
    }

    // Cleaning arrays
    for(int i = i_opt; i < n; i++)
    {
        opt[i] = "";
    }
    for(int i = i_var; i < n; i++)
    {
        var[i] = "";
    }

    // // Debug
    // printf("Debug from initVariables()\nOptions :\n");
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%s\n",opt[i]);
    // }
    // printf("Variables :\n");
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%s\n",var[i]);
    // }
}

