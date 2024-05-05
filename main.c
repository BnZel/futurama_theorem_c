#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Person
{
    int mind;
    int body;
};


void swap(struct Person *p1, struct Person *p2)
{
    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);

    int tempMind;
    tempMind = p1->mind;
    p1->mind = p2->mind;
    p2->mind = tempMind;

    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", p1->mind, p1->body, p2->mind, p2->body);
}


int initialize(void)
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

    return num_people;
}

// NOTE: unit test the for loop
//       make sure first and second cycle
//       is correctly placed in the struct
//       look into this...
int main(void)
{

    int num_people;
    num_people = initialize();
    
    struct Person p_n[num_people];
    int n = sizeof(p_n) / sizeof(p_n[0]);
    int firstCycle = n - 2;
    int secondCycle = n - 3;

    printf("\n-----INPUT-----");

    printf("\nfirst cycle:\n");
    for (int i = 0; i < firstCycle; i++)
    {
        // for the first cycle
        // form a conga line circle
        p_n[i].mind = i;
        p_n[i].body = i + 1;

        // last body wraps around to first mind
        if (p_n[i].body == firstCycle)
        {
            p_n[i].body = p_n[0].mind;
        }

        printf("mind: %d | body: %d\n", p_n[i].mind, p_n[i].body);

        // second cycle
        // for the last two
        if (i == secondCycle)
        {
            printf("\nsecond cycle:\n");

            int j = i + 1;
            int k = i + 2;

            p_n[j].body = k;
            p_n[j].mind = j;

            p_n[k].body = j;
            p_n[k].mind = k;

            printf("mind: %d | body: %d\n", p_n[j].mind, p_n[j].body);
            printf("mind: %d | body: %d\n", p_n[k].mind, p_n[k].body);
        }
    }

    // need two extra helpers without swaps
    // to swap main people properly
    printf("\nhelpers:\n");
    struct Person x, y;
    x.mind = n + 1;
    x.body = n + 1;
    y.mind = n + 2;
    y.body = n + 2;

    printf("mind: %d | body: %d \nmind: %d | body: %d\n", x.mind, x.body, y.mind, y.body);


    printf("\n====================START====================\n\n-----------------FIRST CYCLE-----------------\n");

    // first cycle unshuffle minds procedure:
    //      first cycle:
    //          (1). y: p_helper[1] swaps with starting point
    //          (2). x: p_helper[0] swaps with second point
    //          (3). y: p_helper[1] swaps with everyone else backwards until second point
    //          (4). x: p_helper[0] swaps with starting point
    for (int index = 0; index < n; index++)
    {   
        if (index == 0)
        {
            swap(&y, &p_n[index]);
        }
        else if (index == 1)
        {
            swap(&x, &p_n[index]);
        }
        else
        {
            int backCounter;
            backCounter = n - index - 1;

            swap(&y,&p_n[backCounter]);

            if(backCounter == 1)
            {   
                swap(&x, &p_n[0]);
                break;
            }
        }
    }

    printf("\n\033[0m-----------------SECOND CYCLE-----------------\n");

    // second cycle unshuffle minds procedure:
    //      (1). y: p_helper[1] swaps with 7
    //      (2). x: p_helper[0] swaps with 8
    //      (3). y: p_helper[1] swaps with 8
    //      (4). x: p_helper[0] swaps with 7
    int secondLast, last;
    secondLast = n-2;
    last = n-1;

    swap(&y, &p_n[secondLast]);

    swap(&x, &p_n[last]);

    swap(&y, &p_n[last]);

    swap(&x, &p_n[secondLast]);

    printf("\n\033[0m====================END====================\n");

    printf("\n\033[0m-----OUTPUT-----\n");
    for(int l=0; l<n; l++)
    {
        printf("mind: %d | body: %d\n", p_n[l].mind, p_n[l].body);
    }

    printf("\nx.mind: %d | x.body: %d\ny.mind: %d | y.body: %d\n", x.mind, x.body, y.mind, y.body);

    return 0;
}