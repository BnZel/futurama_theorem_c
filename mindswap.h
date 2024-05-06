#ifndef MINDSWAP_H
#define MINDSWAP_H

#include <stdbool.h>

struct Person
{
    int mind;
    int body;
};

void print_people(struct Person *people, int num_people, int start);
void swap(struct Person *p1, struct Person *p2);
static void initialize_helpers(struct Person *x, struct Person *y, int size);
static void unshuffle_first_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size);
static void unshuffle_second_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size);
static void initialize_people(int num_people);
bool initialize(int num_people);

#endif