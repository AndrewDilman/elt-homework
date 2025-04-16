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

void run_book(struct Book *book);
void start_book();