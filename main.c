#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


struct Person
{
    int mind;
    int body;
    bool switched;
};


// NOTE: unit test the for loop
//       make sure first and second cycle
//       is correctly placed in the struct
//       look into this...
int main(void)
{
    struct Person p_n[9];
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

    // NOTE: maybe need to be in the same struct...
    //       look into this later on when coding
    //       as this could change

    // need two extra helpers without swaps
    // to swap main people properly
    printf("\nhelpers:\n");
    struct Person p_helpers[2], x, y;
    x.mind = n + 1;
    x.body = n + 1;
    y.mind = n + 2;
    y.body = n + 2;
    p_helpers[0] = x; p_helpers[1] = y;

    printf("mind: %d | body: %d \nmind: %d | body: %d\n", x.mind, x.body, y.mind, y.body);


    printf("\n====================START====================\n\n-----------------FIRST CYCLE-----------------\n");

    // NOTE: ONLY swap mind/body ONCE per mind/body
    //       CANNOT swap same mind/body twice
    //       relates to true/false

    // TODO: put swapping operation 
    //       into function to remove redunancy

    // first cycle unshuffle minds procedure:
    //      first cycle:
    //          (1). y: p_helper[1] swaps with starting point
    //          (2). x: p_helper[0] swaps with second point
    //          (3). y: p_helper[1] swaps with everyone else backwards until second point
    //          (4). x: p_helper[0] swaps with starting point
    for (int index = 0; index < n; index++)
    {   
        int *tempMind;
        if (index == 0)
        {
            printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[index].mind, p_n[index].body);

            tempMind = y.mind;

            y.mind = p_n[index].mind;
            p_n[index].mind = tempMind;

            y.switched = true;
            p_n[index].switched = true;

            printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[index].mind, p_n[index].body);
        }
        else if (index == 1)
        {
            printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[index].mind, p_n[index].body);

            tempMind = x.mind;

            x.mind = p_n[index].mind;
            p_n[index].mind = tempMind;

            x.switched = true;
            p_n[index].switched = true;

            printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[index].mind, p_n[index].body);
        }
        else
        {
            // TODO: this output portion shouldn't happen
            //       x.mind should start swapping at 
            //       backCounter=0, not y.mind
            //       check notes...
            //
            // SWITCHING MIND:
            // mind: 10 | body: 11 <---> mind: 11 | body: 1
            //
            // SWITCHED MIND:
            // mind: 11 | body: 11 <---> mind: 10 | body: 1
            //
            // SWITCHING MIND:
            // mind: 1 | body: 10 <---> mind: 10 | body: 1
            //
            // SWITCHED MIND:
            // mind: 10 | body: 10 <---> mind: 1 | body: 1
            int backCounter;
            backCounter = n - index - 1;

            if(!(y.mind == y.body) && !(p_n[backCounter].mind == p_n[backCounter].body))
            {
                printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[backCounter].mind, p_n[backCounter].body);

                tempMind = y.mind;
                y.mind = p_n[backCounter].mind;
                p_n[backCounter].mind = tempMind;
                
                p_n[backCounter].switched = true;

                printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[backCounter].mind, p_n[backCounter].body);

                if(backCounter == 0)
                {   
                    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[backCounter].mind, p_n[backCounter].body);
                    
                    tempMind = x.mind;
                    x.mind = p_n[backCounter].mind;

                    p_n[backCounter].mind = tempMind;
                    p_n[backCounter].switched = true;

                    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[backCounter].mind, p_n[backCounter].body);   
                }

            }
        }
    }

    printf("\n-----------------SECOND CYCLE-----------------\n");

    // second cycle unshuffle minds procedure:
    //      (1). y: p_helper[1] swaps with 7
    //      (2). x: p_helper[0] swaps with 8
    //      (3). y: p_helper[1] swaps with 8
    //      (4). x: p_helper[0] swaps with 7
    int secondLast, last, *tempY, *tempX;
    secondLast = n-2;
    last = n-1;

    printf("\033[0;37mSECOND LAST INDEX: %d\nLAST INDEX: %d\n", secondLast, last);

    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[secondLast].mind, p_n[secondLast].body);   
    tempY = y.mind;
    y.mind = p_n[secondLast].mind;
    p_n[secondLast].mind = tempY;
    p_n[secondLast].switched = true;
    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[secondLast].mind, p_n[secondLast].body);   


    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[last].mind, p_n[last].body);   
    tempX = x.mind;
    x.mind = p_n[last].mind;
    p_n[last].mind = tempX;
    p_n[last].switched = true;
    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[last].mind, p_n[last].body);   

    
    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[secondLast].mind, p_n[secondLast].body);   
    tempX = x.mind;
    x.mind = p_n[secondLast].mind;
    p_n[secondLast].mind = tempX;
    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, p_n[secondLast].mind, p_n[secondLast].body);   


    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[last].mind, p_n[last].body);   
    tempY = y.mind;
    y.mind = p_n[last].mind;
    p_n[last].mind = tempY;
    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", y.mind, y.body, p_n[last].mind, p_n[last].body);   


    printf("\n\033[0;36mSWITCHING MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, y.mind, y.body);   
    tempX = x.mind; tempY = y.mind;

    y.mind = tempX;
    x.mind = tempY;
    printf("\n\033[0;31mSWITCHED MIND:\nmind: %d | body: %d <---> mind: %d | body: %d\n\n", x.mind, x.body, y.mind, y.body);   


    printf("\n====================END====================\n");

    printf("\n\033[0m-----OUTPUT-----\n");
    for(int l=0; l<n; l++)
    {
        printf("mind: %d | body: %d\n", p_n[l].mind, p_n[l].body);
    }

    printf("\nx.mind: %d | x.body: %d\ny.mind: %d | y.body: %d\n", x.mind, x.body, y.mind, y.body);

    return 0;
}