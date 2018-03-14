###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 5                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib	

all : clean $(BIN)/I_LeeEntero

$(BIN)/I_LeeEntero : $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o
	g++ -o $(BIN)/I_LeeEntero $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o

$(OBJ)/I_LeeEntero.o : $(SRC)/I_LeeEntero.cpp $(INCLUDE)/Lectura.h
	g++ -c -o  $(OBJ)/I_LeeEntero.o $(SRC)/I_LeeEntero.cpp -I$(INCLUDE) \
	-std=c++11

$(OBJ)/Lectura.o : $(SRC)/Lectura.cpp $(INCLUDE)/Lectura.h
	g++ -c -o  $(OBJ)/Lectura.o $(SRC)/Lectura.cpp -I$(INCLUDE) -std=c++11

clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
