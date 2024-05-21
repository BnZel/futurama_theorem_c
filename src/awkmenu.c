#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "../include/awkmenu.h"

char filename[50];

void list_files(void)
{
    DIR *dir = opendir("./swaps");
    struct dirent *entry;

    if(!dir)
    {
        perror("Error opening directory");
    }

    printf("-----ALL FILES-----\n");

    while((entry = readdir(dir)))
    {
        if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
        {
            continue;
        }
        else
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void file_menu(const char *filename)
{
    int choice; 
    char awk_command[100];

    do
    {
        printf("=============== SELECTION ===============\n");
        printf("[1]. Display number of lines\n");
        printf("[2]. Display number of words\n");
        printf("[3]. Display number of characters\n");
        printf("[4]. BACK\n");
        printf("[5]. EXIT\n");
        printf("=========================================\n"); 

        printf("Enter option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                sprintf(awk_command, "awk 'END {print NR}' %s", filename);
                system(awk_command);
                printf("\n\n\n");
                break;
            
            case 2:
                sprintf(awk_command, "awk '{ total += NF } END {print total}' %s", filename);
                system(awk_command);
                printf("\n\n\n");
                break;

            case 3:
                sprintf(awk_command, "awk '{print length}' %s | awk '{ total += $1 } END {print total}'", filename);
                system(awk_command);
                printf("\n\n\n");
                break;

            case 4:
                system("clear");
                chdir("../");
                initialize_menu();
                break;

            case 5:
                printf("\n\nEXITING...\n\n");
                break;

            default:
                system("clear");
                break;
        }

    } while ((choice <= 0) || (choice != 5));
    
  
}

void check_file(const char *filename)
{
    DIR *dir = opendir("./swaps");
    struct dirent *entry;

    while((entry = readdir(dir)))
    {
        if(strcmp(entry->d_name, filename) == 0)
        {
            chdir("./swaps");
            file_menu(filename);
        }
    }

    closedir(dir);
}

void initialize_menu(void)
{
    system("clear");

    list_files();

    printf("Choose File: ");
    scanf("%s", filename);

    check_file(filename);
}





