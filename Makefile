INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# Opções do compilador
CC = g++
CFLAGS = -pg -Wall -c -I$(INCLUDE_FOLDER)
LIBS = -lm

# Arquivos
TARGET = $(BIN_FOLDER)/TP2.exe
HDR_FILES = $(INCLUDE_FOLDER)/TipoItem.hpp $(INCLUDE_FOLDER)/HashTable.hpp $(INCLUDE_FOLDER)/ArvoreBinaria.hpp
OBJ_FILES = $(OBJ_FOLDER)/TipoItem.o $(OBJ_FOLDER)/HashTable.o $(OBJ_FOLDER)/ArvoreBinaria.o $(OBJ_FOLDER)/Main.o
 
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/Main.o: $(SRC_FOLDER)/Main.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Main.o $(SRC_FOLDER)/Main.cpp 

$(OBJ_FOLDER)/TipoItem.o: $(HDR_FILES) $(SRC_FOLDER)/TipoItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/TipoItem.o $(SRC_FOLDER)/TipoItem.cpp
	
$(OBJ_FOLDER)/HashTable.o: $(HDR_FILES) $(SRC_FOLDER)/HashTable.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/HashTable.o $(SRC_FOLDER)/HashTable.cpp 

$(OBJ_FOLDER)/ArvoreBinaria.o: $(HDR_FILES) $(SRC_FOLDER)/ArvoreBinaria.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/ArvoreBinaria.o $(SRC_FOLDER)/ArvoreBinaria.cpp

clean:
	rm $(TARGET) $(OBJ_FILES) 
