#include "debug.h"

/*
ВАЖНО!
Конкретно эти функции были сгенерированны ии
для проверки битов структур
*/


void print_bits(const void *data, size_t size) {
    const uint8_t *bytes = (const uint8_t *)data;
    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (bytes[i] >> j) & 1);
        }
        printf(" ");
        if ((i + 1) % 8 == 0) printf("\n");  // Форматирование по 8 байт
    }
    printf("\n");
}

void print_struct_array_bits(struct Abonent *array, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("\n--- Struct %zu ---\n", i);
        print_bits(&array[i], sizeof(struct Abonent));
    }
}