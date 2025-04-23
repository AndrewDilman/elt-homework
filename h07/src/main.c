
#include "./libcalc/calc.h"
#include "./libread/read.h"

void _print_menu() {
  printf("\nPlease enter one of the numbers:\n"
         "1) Add two numbers\n"
         "2) Subtract two numbers\n"
         "3) Multiply two numbers\n"
         "4) Devide two numbers\n"
         "5) Exit\n");
}

int _get_menu_number() { // обрабатывает ввод числа для меню
  int num = 0;
  if (read_int(&num)) // ввели не цифру
    num = _get_menu_number();

  if (!(num >= 1 && num <= 5)) { // ввели не ту цифру
    printf("\n");
    _print_menu();
    num = _get_menu_number();
  }
  return num;
}

int read_numbers(float *v1, float *v2) {
  if (read_float(v1)) {
    printf("Stop getting numbers\n");
    return 1;
  }
  if (read_float(v2)) {
    printf("Stop getting numbers\n");
    return 1;
  }
  return 0;
}

void run_calc() {
  while (1) {
    _print_menu();

    float v1 = 0, v2 = 0; // числа с которыми будем работать

    int num = _get_menu_number();
    printf("\n");
    switch (num) {
    case 1:
      printf("Ttpe two numbers to add\n");
      if (!read_numbers(&v1, &v2))
        printf("result: %f", c_add(v1, v2));
      break;
    case 2:
      printf("Ttpe two numbers to substract\n");
      if (!read_numbers(&v1, &v2))
        printf("result: %f", c_sub(v1, v2));
      break;
    case 3:
      printf("Ttpe two numbers to multiply\n");
      if (!read_numbers(&v1, &v2))
        printf("result: %f", c_mul(v1, v2));
      break;
    case 4:
      printf("Ttpe two numbers to devide\n");
      if (!read_numbers(&v1, &v2))
        printf("result: %f", c_div(v1, v2));
      break;
    case 5:
      return;
    default:
      break;
    }
  }
}

int main() {
  run_calc();
  return 0;
}
