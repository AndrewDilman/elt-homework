#pragma once
#include "read.h"
#include "debug.h"
#include <string.h>

#define BOOK_SIZE 100
#define NAME_LEN 10
#define PHONE_LEN 10

struct Abonent {
    char name[NAME_LEN];
    char second_name[NAME_LEN];
    char tel[PHONE_LEN];
    struct Abonent *prev;
    struct Abonent *next;
};

struct Book {
    struct Abonent *head;
    struct Abonent *tail;
};

void _print_menu();
void _print_abonent(struct Abonent *ab);
int _get_menu_number();
int _fill_abonent(struct Abonent *ab);
void _clear_abonent(struct Abonent *ab, struct Book *book);
struct Abonent *_create_abonent();
int _add_abonent(struct Book *book);
struct Abonent *_find_abonent(const char name[NAME_LEN], struct Book *book);
int _search_for_abonent(struct Book *book);
int _delete_abonent(struct Book *book);
void _print_all_abonents(struct Book *book);
void _shut_down(struct Book *book);
void _run_book(struct Book *book);
void start_book();