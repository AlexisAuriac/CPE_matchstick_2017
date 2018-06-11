/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by libmy.a.
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdbool.h>

#define ALLOW "abcdefghijklmnopqrstuvwxyz"
#define ALUP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"

#define IS_ALLOW 1
#define IS_ALUP 2
#define IS_NUM 4

#define READ_SIZE 10

//write
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterr(char const *str);
int my_put_nbr(int nb);

//conversion
int my_getnbr(char const *str);

//files
char *get_next_line(int fd);

//alloc
void *my_malloc(int size);
void *my_realloc(void *ptr, int const size);
void *my_memset(void *s, char c, size_t n);

//my_str
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *str);
char *my_append(char *str, char const *cat);
int in_str(char const c, char const *str);
bool my_str_is(const char *str, const int option);

#endif
