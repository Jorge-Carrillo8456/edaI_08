# Compilador
CC = gcc

# Bandera de compilacion
CFLAGS = -Wall -Wextra -Iinclude

# Archivos a compilar
SRC=src/*.c main.c

#Nombre del ejecutable
TARGET=lista_ligada

# Regla principalpara compilar el programa
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regla para ejecutar
run:all
	./$(TARGET)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(TARGET)