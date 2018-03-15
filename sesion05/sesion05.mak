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

all : clean $(BIN)/I_LeeEntero $(BIN)/I_MaxMin_Array $(BIN)/I_PosMayor

$(BIN)/I_LeeEntero : $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o
	g++ -o $(BIN)/I_LeeEntero $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o

$(OBJ)/I_LeeEntero.o : $(SRC)/I_LeeEntero.cpp $(INCLUDE)/Lectura.h
	g++ -c -o  $(OBJ)/I_LeeEntero.o $(SRC)/I_LeeEntero.cpp -I$(INCLUDE) \
	-std=c++11

$(OBJ)/Lectura.o : $(SRC)/Lectura.cpp $(INCLUDE)/Lectura.h
	g++ -c -o  $(OBJ)/Lectura.o $(SRC)/Lectura.cpp -I$(INCLUDE) -std=c++11


#################################################################################

$(BIN)/I_MaxMin_Array : $(OBJ)/I_MaxMin_Array.o $(OBJ)/GestionVector.o
	g++ -o $(BIN)/I_MaxMin_Array $(OBJ)/I_MaxMin_Array.o $(OBJ)/GestionVector.o

$(OBJ)/I_MaxMin_Array.o : $(SRC)/I_MaxMin_Array.cpp $(INCLUDE)/GestionVector.h
	g++ -c -o  $(OBJ)/I_MaxMin_Array.o $(SRC)/I_MaxMin_Array.cpp -I$(INCLUDE) \
	-std=c++11

$(OBJ)/GestionVector.o : $(SRC)/GestionVector.cpp $(INCLUDE)/GestionVector.h
	g++ -c -o  $(OBJ)/GestionVector.o $(SRC)/GestionVector.cpp -I$(INCLUDE) \
	-std=c++11

#################################################################################

$(BIN)/I_PosMayor : $(OBJ)/I_PosMayor.o $(OBJ)/GestionVector.o $(OBJ)/Lectura.o
	g++ -o $(BIN)/I_PosMayor $(OBJ)/I_PosMayor.o $(OBJ)/GestionVector.o \
          $(OBJ)/Lectura.o

$(OBJ)/I_PosMayor.o : $(SRC)/I_PosMayor.cpp $(INCLUDE)/GestionVector.h \
                      $(INCLUDE)/Lectura.h
	g++ -c -o  $(OBJ)/I_PosMayor.o $(SRC)/I_PosMayor.cpp -I$(INCLUDE) \
	-std=c++11

clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
