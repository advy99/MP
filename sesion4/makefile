# Fichero: makefile

HOME = .

SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all : clean $(BIN)/saludo $(BIN)/unico makefile_sesion_inicial

$(BIN)/saludo : $(SRC)/saludo.cpp
	@echo Compilando...
	g++ $(SRC)/saludo.cpp -o $(BIN)/saludo
	@echo Terminado

$(BIN)/unico : $(OBJ)/unico.o
	g++ -o $(BIN)/unico $(OBJ)/unico.o

$(OBJ)/unico.o : $(SRC)/unico.cpp
	g++ -c -o $(OBJ)/unico.o $(SRC)/unico.cpp

makefile_sesion_inicial :
	@echo
	@echo "Generando sesion inicial"
	
	make -f $(HOME)/makefile_sesion_inicial.mak

	@echo "Sesion inicial generada"
	@echo

clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
