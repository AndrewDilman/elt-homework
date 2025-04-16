#pragma once
#include <stdio.h>
#include <stdint.h>  // Для uint8_t и точного побитового доступа
#include <stdlib.h>
#include "abonent.h"

struct Abonent; // Нужно для предотвращения редупреждения у функции print_struct_array_bits

void print_bits(const void *data, size_t size);

void print_struct_array_bits(struct Abonent *array, size_t count);
