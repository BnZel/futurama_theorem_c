#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "../include/mindswap.h"

// writes to a text file (.txt)
// in the format: file_num.txt
void write_file(int file_num, const char *data)
{
    DIR *dir;
    struct dirent *entry;
    char filename[50];

    if ((dir = opendir(".")) == NULL)
    {
        perror("Could not open './swaps' directory");
    }

    snprintf(filename, sizeof(filename), "%d.txt", file_num);

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, filename) == 0)
        {
            FILE *fptr = fopen(filename, "a");
            if (fptr == NULL)
            {
                perror("Could not append file");
                closedir(dir);

                exit(1);
            }

            fprintf(fptr, "%s", data);

            fclose(fptr);
            break;
        }
    }

    closedir(dir);
}

// prints output to console
// as well as write to text file
void print_people(struct Person *people, int num_people, int start)
{
    char buffer[20];

    for (int i = start; i < num_people; i++)
    {
        printf("mind: %d | body: %d\n", people[i].mind, people[i].body);

        sprintf(buffer, "mind: %d | body: %d\n", people[i].mind, people[i].body);
        write_file(file_num, buffer);
    }
}

// search for ./swaps directory
// create if it does not exists
// return false if there is an unknown error
int search_dir(void)
{
    DIR *dir = opendir("./swaps");

    if (dir)
    {
        printf("'./swaps' Directory exists, using that...\n\n");
        return 0;
    }
    else if (ENOENT == errno)
    {
        printf("Directory DOES NOT exists, created directory: './swaps'...\n\n");
        mkdir("./swaps", S_IRWXU);
        return 2;
    }
    else
    {
        perror("Unknown error, try again....");
        return 1;
    }
}

// check if specific file exists
// change into created directory
// if found inform user
// otherwise create it in the format
// of num_people.txt
bool has_file(int num_people)
{
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir("./swaps")) == NULL)
    {
        perror("Could not open './swaps' directory");
    }

    chdir("./swaps");

    // parse textfile "num_people.txt"
    // read only the num_people
    // true if it is found
    while ((entry = readdir(dir)) != NULL)
    {
        char *parse = strchr(entry->d_name, '.');

        if (parse != NULL)
        {
            int parse_num = atoi(entry->d_name);
            if (parse_num == num_people)
            {
                printf("%d.txt EXISTS, check './swap' directory\n", num_people);
                closedir(dir);
                return true;
            }
        }
    }

    // creates the text file
    // if search does not find
    // a duplicate
    char filename[20];
    sprintf(filename, "%d.txt", num_people);
    FILE *fp = fopen(filename, "w");
    closedir(dir);

    file_num = num_people;

    return false;
}

void swap(struct Person *p1, struct Person *p2)
{
    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);

    char buffer[2048];
    snprintf(buffer, sizeof(buffer), "\nSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);
    write_file(file_num, buffer);

    int tempMind;
    tempMind = p1->mind;
    p1->mind = p2->mind;
    p2->mind = tempMind;

    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);

    snprintf(buffer, sizeof(buffer), "\nSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);
    write_file(file_num, buffer);
}

// need two extra helpers without swaps
// to swap main people properly
void initialize_helpers(struct Person *x, struct Person *y, int size)
{
    printf("\nhelpers:\n");

    x->mind = size + 1;
    x->body = size + 1;

    y->mind = size + 2;
    y->body = size + 2;

    print_people(x, 1, 0);
    print_people(y, 1, 0);
}

// first cycle unshuffle minds procedure:
//          (1). y swaps with starting point
//          (2). x swaps with second point
//          (3). y swaps with everyone else backwards until second point
//          (4). x swaps with starting point
void unshuffle_first_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size)
{
    printf("\n\033[0m====================START====================\n\n-----------------FIRST CYCLE-----------------\n");
    write_file(file_num, "\n====================START====================\n\n-----------------FIRST CYCLE-----------------\n");

    for (int index = 0; index < size; index++)
    {
        if (index == 0)
        {
            swap(helper_2, &people[index]);
        }
        else if (index == 1)
        {
            swap(helper_1, &people[index]);
        }
        else
        {
            int backCounter;
            backCounter = size - index - 1;

            swap(helper_2, &people[backCounter]);

            if (backCounter == 1)
            {
                swap(helper_1, &people[0]);
                break;
            }
        }
    }
}

// second cycle unshuffle minds procedure:
//      (1). y swaps with 7
//      (2). x swaps with 8
//      (3). y swaps with 8
//      (4). x swaps with 7
void unshuffle_second_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size)
{
    printf("\n\033[0m-----------------SECOND CYCLE-----------------\n");
    write_file(file_num, "\n-----------------SECOND CYCLE-----------------\n");

    int secondLast, last;
    secondLast = size - 2;
    last = size - 1;

    swap(helper_2, &people[secondLast]);

    swap(helper_1, &people[last]);

    swap(helper_2, &people[last]);

    swap(helper_1, &people[secondLast]);

    printf("\n\033[0m====================END====================\n");
    write_file(file_num, "\n====================END====================\n");
}

void initialize_people(int num_people)
{

    printf("\n-----INPUT-----");
    write_file(file_num, "\n-----INPUT-----");

    struct Person people[num_people];
    int n = sizeof(people) / sizeof(people[0]);
    int first_cycle = n - 2;
    int second_cycle = n - 3;

    for (int i = 0; i < first_cycle; i++)
    {
        people[i].mind = i;
        people[i].body = i + 1;

        if (people[i].body == first_cycle)
        {
            people[i].body = people[0].mind;
        }

        if (i == second_cycle)
        {
            int j = i + 1;
            int k = i + 2;

            people[j].body = k;
            people[j].mind = j;

            people[k].body = j;
            people[k].mind = k;
        }
    }

    printf("\nfirst cycle:\n");
    write_file(file_num, "\nfirst cycle:\n");
    print_people(people, first_cycle, 0);

    printf("\nsecond cycle:\n");
    write_file(file_num, "\nsecond cycle:\n");
    print_people(people, second_cycle + 3, first_cycle);

    struct Person x, y;
    initialize_helpers(&x, &y, n);

    unshuffle_first_cycle(&x, &y, people, n);
    unshuffle_second_cycle(&x, &y, people, n);

    printf("\n\033[0m-----OUTPUT-----\n");
    write_file(file_num, "\n-----OUTPUT-----\n");
    print_people(people, n, 0);
}

// request user input
// return number of people
// to struct
void initialize_swap(void)
{
    int num_people;
    int result;
    bool file_exists;

    printf("How many people: ");
    result = scanf("%d", &num_people);

    if (!(file_exists = has_file(num_people)))
    {
        if (result != 1 || (num_people <= 0 || num_people <= 2) || (num_people >= 1000) )
        {
            printf("------Input error------\n");
            printf("Check these conditions:\n");
            printf("    - Input is greater than 2\n");
            printf("    - Input is NOT greater than 1000\n");
            printf("    - Input is numeric\n");
            printf("    - Input is NOT negative\n");
            printf("    - Input is NOT a decimal\n");

            exit(1);
        }

        printf("Entered: %d\n", num_people);
        initialize_people(num_people);
    }
    else
    {
        exit(1);
    }
}
