#include "abonent.h"

// Принт меню
void _print_menu() {
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
  printf("Abonent number: %s\n\n", ab->tel);
}

// циклическое считываение введённого номера меню
int _get_menu_number() { // обрабатывает ввод числа для меню
  int num = 0;
  if (read_number(&num)) // ввели не цифру
    num = _get_menu_number();

  if (!(num >= 1 && num <= 5)) { // ввели не ту цифру
    printf("\n");
    _print_menu();
    num = _get_menu_number();
  }
  return num;
}

// ручное заполнение абонента
int _fill_abonent(struct Abonent *ab) {
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
void _clear_abonent(struct Abonent *ab, struct Book *book) {
  // Скрепляем предыдущий и следующий элементы
  if (ab->prev != NULL)
    ab->prev->next = ab->next;
  if (ab->next != NULL)
    ab->next->prev = ab->prev;

  // если элементы в самой книге
  if (book->head == ab)
    book->head = ab->prev;

  if (book->tail == ab)
    book->tail = ab->next;
}

// Выделем память и создаём абонента
struct Abonent *_create_abonent() {
  struct Abonent *ab = malloc(sizeof(struct Abonent));
  if (ab == NULL) {
    printf("Can't initialize memory for abnent!\n");
    return NULL;
  }
  return ab;
}

// Добавление абонента в книгу
int _add_abonent(struct Book *book) {
  struct Abonent *ab = _create_abonent();
  if (ab == NULL) {
    printf("Can't create abonent! \n");
    return 1;
  }
  ab->next = NULL;
  ab->prev = NULL;

  if (_fill_abonent(ab)) {
    printf("Can't create abonent! \n");
    free(ab);
    return 1;
  }

  // запись первого абонента
  if (book->tail == NULL)
    book->tail = ab;

  if (book->head != NULL) {
    // добавляем указатель на себя последнему абоненту
    book->head->next = ab;
    // добавляем последнего абонента себе
    ab->prev = book->head;
  }
  // Записываем себя как последний элемент
  book->head = ab;

  return 0;
}

// поиск абонента
struct Abonent *_find_abonent(const char name[NAME_LEN], struct Book *book) {
  struct Abonent *ab = book->tail;
  while (ab != NULL) {
    if (!strcmp(ab->name, name))
      return ab;
    ab = ab->next;
  }
  return NULL;
}

// обёртка для поиска
int _search_for_abonent(struct Book *book) {
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
int _delete_abonent(struct Book *book) {
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

  _clear_abonent(ab, book);
  printf("Abonent deleted!\n");
  return 0;
}

// вывод всех ненулевых абонентов
void _print_all_abonents(struct Book *book) {
  if (book->tail == NULL) {
    printf("Book is empty\n");
    return;
  }

  struct Abonent *ab = book->tail;
  while (ab != NULL) {
    _print_abonent(ab);
    ab = ab->next;
  }

  return;
}

void _shut_down(struct Book *book) {
  struct Abonent *ab = book->tail;
  while (ab != NULL) {
    struct Abonent *ab_next = ab->next;
    free(ab);
    ab = ab_next;
  }
  // Книгу не надо удалять, тк эта память не выделяеться маллоком
}

// цикличный вызов работы с книгой
void _run_book(struct Book *book) {
  while (1) {
    _print_menu();
    int num = _get_menu_number();
    printf("\n");
    switch (num) {
    case 1:
      _add_abonent(book);
      break;
    case 2:
      _delete_abonent(book);
      break;
    case 3:
      _search_for_abonent(book);
      break;
    case 4:
      _print_all_abonents(book);
      break;
    case 5:
      _shut_down(book);
      return;
    default:
      break;
    }
  }
}

// Функция старта
void start_book() {
  // зануление структуры
  struct Book book = {NULL, NULL};
  _run_book(&book);
}