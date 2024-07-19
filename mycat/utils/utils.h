#ifndef UTILS_H
#define UTILS_H
void printFile(FILE *fp);
FILE *checkFile(char *filepath);
void appendTemp(FILE *source);
void initVariables(int n, char *args[], char *opt[], char *files[]);
void removeTemp();

#endif