#include "abonent.h"

void print_menu() {
  printf("Please enter one of the numbers:\n"
         "1) Add abonent\n"
         "2) Delete abonent\n"
         "3) Search abonent by name\n"
         "4) Print all abonents\n"
         "5) Exit\n");
}

int get_menu_number() { // обрабатывает ввод числа для меню
  int num = 0;

  if (!read_number(&num)) // ввели не цифру
    get_menu_number();

  if (!(num >= 1 && num <= 5)) { // ввели не ту цифру
    printf("\n");
    print_menu();
    get_menu_number();
  }
  return num;
}

int fill_abonent(struct abonent *ab) {
  printf("Type abonent's first name:\n");
  if (read_string(ab->name)) {
    printf("Can't read abonent first name!\n");
    return 1;
  }
  printf("Type abonent's second name:\n");
  if (read_string(ab->second_name)) {
    printf("Can't read abonent second name!\n");
    return 1;
  }
  printf("Type abonent's number:\n");
  if (read_string(ab->tel)) {
    printf("Can't read abonent number!\n");
    return 1;
  }
  return 0;
}

void run_book() {
  // зануление выделенной памяти
  struct abonent book[BOOK_SIZE] = {0};
  // каждый бит - заполненный или нет абонент
  char book_fullness[BOOK_SIZE] = {0};

  print_menu();
  // int menu_number = get_menu_number();
  // printf("selected number: %d\n", menu_number);


  fill_abonent(&book[99]);
  // print_struct_array_bits(book, BOOK_SIZE);
  print_abonent(&book[99]);
}
