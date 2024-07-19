#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "../utils/utils.h"

void handleError(int errCode, char *errMessage)
{
    printf("Error %d : %s\n", errCode, errMessage);
    // Try to del temp if exists
    FILE *fp = fopen("temp.txt", "r");
    if(fp != NULL)
    {
        fclose(fp);
        removeTemp();
    }
    exit(errCode);
}