# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -g -O0 -Wall -Wextra -fno-stack-protector -no-pie

# Имя исполняемого файла
TARGET = main

# Папки
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Исходные файлы
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Объектные файлы
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Исполняемый файл
TARGET_PATH = $(BIN_DIR)/$(TARGET)

# Цель по умолчанию
all: $(TARGET_PATH)

# Сборка исполняемого файла из объектных файлов
$(TARGET_PATH): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_FILES) -o $@

# Компиляция каждого .c файла в объектный файл
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов
clean:
	rm -rf $(OBJ_DIR)/*

# Очистка объектных файлов и исполняемого файла
distclean: clean
	rm -rf $(BIN_DIR)

# Указываем, что цели all, clean и distclean являются фиктивными
.PHONY: all clean distclean

debug:
	gdb ./bin/$(TARGET) --command=.gdb