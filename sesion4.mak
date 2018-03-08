HOME = .

LIB = $(HOME)/lib
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj

all : $(BIN)/I_PosicionPrimerBlanco clean

$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	g++ -o $(BIN)/I_PosicionPrimerBlanco $(SRC)/I_PosicionPrimerBlanco.cpp


clean :
	-rm $(OBJ)/*