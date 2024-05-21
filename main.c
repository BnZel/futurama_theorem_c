#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "include/awkmenu.h"
#include "include/mindswap.h"

int main(void)
{
    int choice;
    int dir_check = search_dir();

    do
    {
        printf("\n=====MIND SWAPPER======\n");
        printf("[1]: Mind Swap\n");
        printf("[2]: Read Files\n");
        printf("[3]: EXIT\n");
        printf("=======================\n\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            if (dir_check == 0){
                system("clear");
                initialize_swap();
            }

            break;

        case 2:
            if(dir_check == 2){
                system("clear");
                printf("Directory is EMPTY, redirecting to mind swapping menu...\n\n");
                initialize_swap();

                printf("\n\n\n");
                chdir("../");

                system("clear");
                initialize_menu();
            }
            else if(dir_check == 0){
                system("clear");
                initialize_menu();
            }
            
            break;

        case 3:
            printf("\n\nEXITING...\n\n");
            return 1;
            break;

        default:
            system("clear");
            break;
        }
    } while ((choice <= 0) || (choice >= 4));

    return 0;
}