/*
https://www.man7.org/linux/ man-pages/man1/cat.1.html

- sudo gcc -o /usr/local/bin/mycat main.c utils/utils.c errors/errors.c
*/
#include <stdio.h>
#include "./utils/utils.h"

int main(int argc, char *argv[])
{

    int n = argc;
    char *opt[n];
    char *var[n];
    initVariables(argc, argv, opt, var);

    // printf("Options : \n");
    // for(int i = 0; i < n; i++)
    // {
    //     if(opt[i] != "")
    //     {
    //         printf("%s\n", opt[i]);
    //     }
    // }

    // printf("Vars : \n");
    // for(int i = 0; i < n; i++)
    // {
    //     if(var[i] != "")
    //     {
    //         printf("%s\n", var[i]);
    //     }
    // }



/*
    o-----------------o
    |  Main behavior  |
    o-----------------o
*/
    
    // for(int i = 0; i < n; i++)
    // {
    //     if(var[i] == "") break;
    //     appendTemp(checkFile(var[i]));
    // }

    // printFile(checkFile("temp.txt"));
    // removeTemp();

    return 0;
}

// Etape 1 : Afficher le contenu d'un fichier en argument -> OK
//  - Check si chemin est > à MAX_PATH_LEN
//  - Check si le fichier est valide (gestion et affichage erreur à prévoir)
//  - Afficher fichier ou afficher erreur
// Etape 2 : Concaténer si differents fichiers en arguments -> OK
//  - Séparer Check d'un fichier et affichage
//  - Créer un fichier temp avec les fichiers concaténés prints à l'interieur
// Etape 3 : Get les options et les arguments séparements -> OK
// Etape 4 : Les options doivent pouvoir avoir la forme -abc et -a -b -c
// Etape 5 : Prendre les options en compte


/*
    Improvements :
    
*/