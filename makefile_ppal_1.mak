HOME = .

SRC = $(HOME)/src
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include

all : clean $(BIN)/ppal_1

$(BIN)/ppal_1 : $(OBJ)/ppal_1.o $(OBJ)/opers.o
	g++ -o $(BIN)/ppal_1 $(OBJ)/ppal_1.o $(OBJ)/opers.o

$(OBJ)/ppal_1.o : $(SRC)/ppal_1.cpp $(INCLUDE)/opers.h
	g++ -c -o $(OBJ)/ppal_1.o $(SRC)/ppal_1.cpp -I$(INCLUDE)

$(OBJ)/opers.o : $(SRC)/opers.cpp $(INCLUDE)/opers.h
	g++ -c -o $(OBJ)/opers.o $(SRC)/opers.cpp -I$(INCLUDE)

clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
