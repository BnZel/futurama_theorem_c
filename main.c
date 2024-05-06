#include <stdio.h>
#include <stdlib.h>


struct Person
{
    int mind;
    int body;
};

void print_people(struct Person *people, int num_people, int start)
{
    for(int i=start; i<num_people; i++)
    {
        printf("mind: %d | body: %d\n", people[i].mind, people[i].body);   
    }
}

void swap(struct Person *p1, struct Person *p2)
{
    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);

    int tempMind;
    tempMind = p1->mind;
    p1->mind = p2->mind;
    p2->mind = tempMind;

    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);
}

// need two extra helpers without swaps
// to swap main people properly
static void initialize_helpers(struct Person *x, struct Person *y, int size)
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
static void unshuffle_first_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size)
{
    printf("\n\033[0m====================START====================\n\n-----------------FIRST CYCLE-----------------\n");

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

            if(backCounter == 1)
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
static void unshuffle_second_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size)
{
    printf("\n\033[0m-----------------SECOND CYCLE-----------------\n");

    int secondLast, last;
    secondLast = size-2;
    last = size-1;

    swap(helper_2, &people[secondLast]);

    swap(helper_1, &people[last]);

    swap(helper_2, &people[last]);

    swap(helper_1, &people[secondLast]);

    printf("\n\033[0m====================END====================\n");
}

static void initialize_people(int num_people)
{
    printf("\n-----INPUT-----");

    struct Person people[num_people];
    int n = sizeof(people) / sizeof(people[0]);
    int first_cycle = n-2;
    int second_cycle = n-3;
    
    for(int i=0; i<first_cycle; i++)
    {
        people[i].mind = i;
        people[i].body = i+1;        

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
    print_people(people, first_cycle, 0);
    
    printf("\nsecond cycle:\n");
    print_people(people, second_cycle+3, first_cycle);

    struct Person x,y;
    initialize_helpers(&x, &y, n);

    unshuffle_first_cycle(&x, &y, people, n);
    unshuffle_second_cycle(&x, &y, people, n);

    printf("\n\033[0m-----OUTPUT-----\n");
    print_people(people, n, 0);
}

// request user input
// return number of people
// to struct 
void initialize(void)
{   
    int num_people;
    int result;

    printf("How many people: ");
    result = scanf("%d", &num_people);
    
    if(result != 1 || (num_people <= 0 || num_people <= 2))
    {
        printf("Input error\n");   
        printf("Also make sure there's enough people! Gather 3 or more to help...\n"); 
        exit(1);
    }

    printf("Entered: %d\n", num_people);

    initialize_people(num_people);
}

// NOTE: unit test the for loop
//       make sure first and second cycle
//       is correctly placed in the struct
//       look into this...
int main(void)
{
    initialize();
    return 0;
}