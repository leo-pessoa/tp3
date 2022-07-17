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
HDR_FILES = $(INCLUDE_FOLDER)/tipoItem.hpp $(INCLUDE_FOLDER)/hashTable.hpp $(INCLUDE_FOLDER)/arvoreBinaria.hpp
OBJ_FILES = $(OBJ_FOLDER)/tipoItem.o $(OBJ_FOLDER)/hashTable.o $(OBJ_FOLDER)/arvoreBinaria.o $(OBJ_FOLDER)/Main.o
 
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/Main.o: $(SRC_FOLDER)/Main.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/Main.o $(SRC_FOLDER)/Main.cpp 

$(OBJ_FOLDER)/tipoItem.o: $(HDR_FILES) $(SRC_FOLDER)/tipoItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/tipoItem.o $(SRC_FOLDER)/tipoItem.cpp
	
$(OBJ_FOLDER)/hashTable.o: $(HDR_FILES) $(SRC_FOLDER)/hashTable.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/hashTable.o $(SRC_FOLDER)/hashTable.cpp 

$(OBJ_FOLDER)/arvoreBinaria.o: $(HDR_FILES) $(SRC_FOLDER)/arvoreBinaria.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/arvoreBinaria.o $(SRC_FOLDER)/arvoreBinaria.cpp

clean:
	rm $(TARGET) $(OBJ_FILES) 
