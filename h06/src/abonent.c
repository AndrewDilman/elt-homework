#include "abonent.h"

// Принт меню
void print_menu() {
  printf("\nPlease enter one of the numbers:\n"
         "1) Add abonent\n"
         "2) Delete abonent\n"
         "3) Search abonent by name\n"
         "4) Print all abonents\n"
         "5) Exit\n");
}

// вывод инфы об абоненте
void _print_abonent(struct Abonent *ab) {
  printf("\nAbonent name: %s\n", ab->name);
  printf("Abonent second name: %s\n", ab->second_name);
  printf("Abonent number: %s\n", ab->tel);
}

// циклическое считываение введённого номера меню
int get_menu_number() { // обрабатывает ввод числа для меню
  int num = 0;
  if (read_number(&num)) // ввели не цифру
    num = get_menu_number();

  if (!(num >= 1 && num <= 5)) { // ввели не ту цифру
    printf("\n");
    print_menu();
    num = get_menu_number();
  }
  return num;
}

// ручное заполнение абонента
int fill_abonent(struct Abonent *ab) {
  printf("Type abonent's first name:\n");
  if (read_string(ab->name)) {
    printf("Can't write abonent first name!\n");
    return 1;
  }
  printf("Type abonent's second name:\n");
  if (read_string(ab->second_name)) {
    printf("Can't write abonent second name!\n");
    return 1;
  }
  printf("Type abonent's number:\n");
  if (read_string(ab->tel)) {
    printf("Can't write abonent number!\n");
    return 1;
  }
  return 0;
}

// аннулируем мервый бит имени абонента
void clear_abonent(struct Abonent *ab) { ab->name[0] = '\0'; }

// заполнение первого абонента с нулевым именем
struct Abonent *create_abonent(struct Abonent book[BOOK_SIZE]) {
  for (int i = 0; i < BOOK_SIZE; i++) {
    if (book[i].name[0] == '\0') {
      if (fill_abonent(&book[i]) != 0) {
        return NULL;
      }
      return &book[i];
    }
  }
  printf("Book is full\n");
  return NULL;
}

// поиск абонента
struct Abonent *_find_abonent(const char name[NAME_LEN],
                             struct Abonent book[BOOK_SIZE]) {
  for (int i = 0; i < BOOK_SIZE; i++) {
    if (!strcmp(book[i].name, name)) {
      return &book[i]; // Правмльно ли вот так возвращать указатель для
                       // дальнейшей аботы?
    }
  }
  return NULL;
}

// обёртка для поиска
int search_for_abonent(struct Abonent book[BOOK_SIZE]) {
  printf("Enter name of searched abonent:\n");
  char name[NAME_LEN];
  if (read_string(name)) {
    printf("Can't read abonent name!\n");
    return 1;
  }

  struct Abonent *ab = _find_abonent(name, book);
  if (ab == NULL) {
    printf("Can't find abonent!\n");
    return 1;
  }

  printf("Abonent found!\n");
  _print_abonent(ab);
  return 0;
}

// обёртка для удаления
int delete_abonent(struct Abonent book[BOOK_SIZE]) {
  printf("Enter name of abonent to delete:\n");
  char name[NAME_LEN];
  if (read_string(name)) {
    printf("Can't read abonent name!\n");
    return 1;
  }

  struct Abonent *ab = _find_abonent(name, book);
  if (ab == NULL) {
    printf("Can't find abonent!\n");
    return 1;
  }

  clear_abonent(ab);
  printf("Abonent deleted!\n");
  return 0;
}

// вывод всех ненулевых абонентов
void print_all_abonents(struct Abonent book[BOOK_SIZE]) {
  int abonent_counter = 0;
  for (int i = 0; i < BOOK_SIZE; i++) {
    if (book[i].name[0] != '\0') {
      _print_abonent(&book[i]);
      abonent_counter++;
    }
  }
  if (abonent_counter == 0) {
    printf("Book is empty\n");
  }
  return;
}

// цикличный вызов работы с книгой
void run_book(struct Abonent book[BOOK_SIZE]) {
  while (1) {
    print_menu();
    int num = get_menu_number();
    printf("\n");
    switch (num) {
    case 1:
      create_abonent(book);
      break;
    case 2:
      delete_abonent(book);
      break;
    case 3:
      search_for_abonent(book);
      break;
    case 4:
      print_all_abonents(book);
      break;
    case 5:
      return;
    default:
      break;
    }
  }
}

// Функция старта
void start_book() {
  // зануление выделенной памяти
  struct Abonent book[BOOK_SIZE] = {0};
  run_book(book);
}
