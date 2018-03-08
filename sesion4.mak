HOME = .

LIB = $(HOME)/lib
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj

all :  clean $(BIN)/I_PosicionPrimerBlanco $(BIN)/I_SaltaPrimeraPalabra

$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	g++ -o $(BIN)/I_PosicionPrimerBlanco $(SRC)/I_PosicionPrimerBlanco.cpp

$(BIN)/I_SaltaPrimeraPalabra : $(SRC)/I_SaltaPrimeraPalabra.cpp
	g++ -o $(BIN)/I_SaltaPrimeraPalabra $(SRC)/I_SaltaPrimeraPalabra.cpp


clean :
	-rm $(OBJ)/*