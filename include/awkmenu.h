#ifndef AWKMENU_H
#define AWKMENU_H

#include <stdbool.h>

void initialize_menu(void);
void command(int choice, const char *filename);
void list_files(void);
void file_menu(const char *filename);
void check_file(const char *filename);

#endif