#pragma once
#include <stdio.h>
#include <stdint.h>  // Для uint8_t и точного побитового доступа
#include "abonent.h"

struct abonent; // Нужно для предотвращения редупреждения у функции print_struct_array_bits

void print_bits(const void *data, size_t size);

void print_struct_array_bits(struct abonent *array, size_t count);

void print_abonent(struct abonent *ab);