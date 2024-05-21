#ifndef MINDSWAP_H
#define MINDSWAP_H

static int file_num;

struct Person
{
    int mind;
    int body;
};

void write_file(int file_num, const char *data);
void print_people(struct Person *people, int num_people, int start);
int search_dir(void);
bool has_file(int num_people);
void swap(struct Person *p1, struct Person *p2);
void initialize_helpers(struct Person *x, struct Person *y, int size);
void unshuffle_first_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size);
void unshuffle_second_cycle(struct Person *helper_1, struct Person *helper_2, struct Person *people, int size);
void initialize_people(int num_people);
void initialize_swap(void);

#endif