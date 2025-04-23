# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -g -O0 -Wall -Wextra -Iinclude

# Имя исполняемого файла
TARGET = main

# Директории
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIBCALC_SRC_DIR = $(SRC_DIR)/libcalc
LIBCALC_OBJ_DIR = $(OBJ_DIR)/libcalc
LIBREAD_SRC_DIR = $(SRC_DIR)/libread
LIBREAD_OBJ_DIR = $(OBJ_DIR)/libread

# Файлы
MAIN_SRC = $(SRC_DIR)/main.c
LIBCALC_SRC_FILES = $(wildcard $(LIBCALC_SRC_DIR)/*.c)
LIBREAD_SRC_FILES = $(wildcard $(LIBREAD_SRC_DIR)/*.c)

# Объектные файлы
MAIN_OBJ = $(OBJ_DIR)/main.o
LIBCALC_OBJ_FILES = $(LIBCALC_SRC_FILES:$(LIBCALC_SRC_DIR)/%.c=$(LIBCALC_OBJ_DIR)/%.o)
LIBREAD_OBJ_FILES = $(LIBREAD_SRC_FILES:$(LIBREAD_SRC_DIR)/%.c=$(LIBREAD_OBJ_DIR)/%.o)

# Статическая библиотека
LIBCALC_NAME = libcalc.a
LIBCALC_PATH = $(LIBCALC_OBJ_DIR)/$(LIBCALC_NAME)
LIBREAD_NAME = libread.a
LIBREAD_PATH = $(LIBREAD_OBJ_DIR)/$(LIBREAD_NAME)

# Исполняемый файл
TARGET_PATH = $(BIN_DIR)/$(TARGET)

# Цель по умолчанию
all: $(TARGET_PATH)

# Сборка исполняемого файла
$(TARGET_PATH): $(MAIN_OBJ) $(LIBCALC_PATH) $(LIBREAD_PATH)
	@mkdir -p $(BIN_DIR)
# здесь компилируем всю программу,
# привязывая библиотеки и укащывая где их искать через -L
# и указывая имена через -l
	$(CC) $(MAIN_OBJ) -L$(LIBCALC_OBJ_DIR) -L$(LIBREAD_OBJ_DIR) -lcalc  -lread -o $@

# Сборка статической библиотеки калькулятора
$(LIBCALC_PATH): $(LIBCALC_OBJ_FILES)
	ar rcs $@ $^

# Сборка статической библиотеки ридера
$(LIBREAD_PATH): $(LIBREAD_OBJ_FILES)
	ar rcs $@ $^

# Компиляция main.o
$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция модулей библиотеки калькулятора
$(LIBCALC_OBJ_DIR)/%.o: $(LIBCALC_SRC_DIR)/%.c
	@mkdir -p $(LIBCALC_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция модулей библиотеки ввода
$(LIBREAD_OBJ_DIR)/%.o: $(LIBREAD_SRC_DIR)/%.c
	@mkdir -p $(LIBREAD_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(OBJ_DIR)/*

distclean: clean
	rm -rf $(BIN_DIR)

.PHONY: all clean distclean

debug:
	gdb ./bin/$(TARGET) --command=.gdb


