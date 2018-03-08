HOME = .

LIB = $(HOME)/lib
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj

all :  clean $(BIN)/I_PosicionPrimerBlanco $(BIN)/I_SaltaPrimeraPalabra $(BIN)/I_DemoCadenasClasicas

$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	g++ -o $(BIN)/I_PosicionPrimerBlanco $(SRC)/I_PosicionPrimerBlanco.cpp

$(BIN)/I_SaltaPrimeraPalabra : $(SRC)/I_SaltaPrimeraPalabra.cpp
	g++ -o $(BIN)/I_SaltaPrimeraPalabra $(SRC)/I_SaltaPrimeraPalabra.cpp

$(BIN)/I_DemoCadenasClasicas : $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	g++ -o $(BIN)/I_DemoCadenasClasicas $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o

$(OBJ)/I_DemoCadenasClasicas.o : $(SRC)/I_DemoCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/I_DemoCadenasClasicas.o $(SRC)/I_DemoCadenasClasicas.cpp -I$(INCLUDE)

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE)
	

clean :
	-rm $(OBJ)/*