# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.cpp

HOME = .

SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all : clean $(BIN)/saludo $(BIN)/unico $(BIN)/I_CambiaNegs $(BIN)/I_CambiaNegs_PtrFinal

$(BIN)/saludo : $(SRC)/saludo.cpp
	@echo Compilando...
	g++ $(SRC)/saludo.cpp -o $(BIN)/saludo
	@echo Terminado

$(BIN)/unico : $(OBJ)/unico.o
	g++ -o $(BIN)/unico $(OBJ)/unico.o

$(OBJ)/unico.o : $(SRC)/unico.cpp
	g++ -c -o $(OBJ)/unico.o $(SRC)/unico.cpp

$(BIN)/I_CambiaNegs : $(SRC)/I_CambiaNegs.cpp
	g++ -o $(BIN)/I_CambiaNegs $(SRC)/I_CambiaNegs.cpp

$(BIN)/I_CambiaNegs_PtrFinal : $(SRC)/I_CambiaNegs_PtrFinal.cpp
	g++ -o $(BIN)/I_CambiaNegs_PtrFinal $(SRC)/I_CambiaNegs_PtrFinal.cpp



clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
