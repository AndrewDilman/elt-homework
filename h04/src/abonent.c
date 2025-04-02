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

void print_abonent(struct abonent *ab) {
  printf("Abonent name: %s\n", ab->name);
  printf("Abonent second name: %s\n", ab->second_name);
  printf("Abonent number: %s\n", ab->tel);
}

void clear_abonent(struct abonent *ab) { ab->name[0] = '\0'; }

struct abonent *find_abonent(const char name[NAME_LEN],
                             struct abonent book[BOOK_SIZE]) {
  struct abonent *ab;
  for (int i = 0; i < BOOK_SIZE; i++) {
    if (!strcmp(book[i].name, name)) {
      return &book[i]; // Правмльно ли вот так возвращать указатель для дальнейшей аботы?
    }
  }
  return NULL;
}

int search_for_abonent(struct abonent book[BOOK_SIZE]) {
  printf("Enter name of searched abonent:\n");
  char name[NAME_LEN];
  if (read_string(name)) {
    printf("Can't read abonent name!\n");
    return 1;
  }
  
  struct abonent *ab = find_abonent(name, book);
  if(ab==NULL){
    printf("Can't find abonent!\n");
    return 1;
  }

  printf("Abonent found!\n");
  print_abonent(ab);
  return 0;
}

void run_book() {
  // зануление выделенной памяти
  struct abonent book[BOOK_SIZE] = {0};
  // каждый бит - заполненный или нет абонент
  char book_fullness[BOOK_SIZE] = {0};

  // print_menu();
  // int menu_number = get_menu_number();
  // printf("selected number: %d\n", menu_number);

  fill_abonent(&book[99]);
  // print_struct_array_bits(book, BOOK_SIZE);
  search_for_abonent(book);
}
