HOME = .

SRC = $(HOME)/src
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

all : clean $(BIN)/ppal_2

$(BIN)/ppal_2 : $(OBJ)/ppal_2.o $(LIB)/libopers.a
	g++ -o $(BIN)/ppal_2 $(OBJ)/ppal_2.o -lopers -L$(LIB)

$(OBJ)/ppal_2.o : $(SRC)/ppal_2.cpp $(INCLUDE)/adicion.h $(INCLUDE)/producto.h
	g++ -c -o $(OBJ)/ppal_2.o $(SRC)/ppal_2.cpp -I$(INCLUDE)

$(LIB)/libopers.a : $(OBJ)/adicion.o $(OBJ)/producto.o
	ar rvs $(LIB)/libopers.a $(OBJ)/adicion.o $(OBJ)/producto.o

$(OBJ)/adicion.o : $(SRC)/adicion.cpp $(INCLUDE)/adicion.h
	g++ -c -o $(OBJ)/adicion.o $(SRC)/adicion.cpp -I$(INCLUDE)

$(OBJ)/producto.o : $(SRC)/producto.cpp $(INCLUDE)/producto.h
	g++ -c -o $(OBJ)/producto.o $(SRC)/producto.cpp -I$(INCLUDE)

clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
