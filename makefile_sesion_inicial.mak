
HOME = .

SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all : $(BIN)/I_CambiaNegs $(BIN)/I_CambiaNegs_PtrFinal $(BIN)/I_MezclaSencillaVectores $(BIN)/I_ReorganizaVector

$(BIN)/I_CambiaNegs : $(SRC)/I_CambiaNegs.cpp
	g++ -o $(BIN)/I_CambiaNegs $(SRC)/I_CambiaNegs.cpp

$(BIN)/I_CambiaNegs_PtrFinal : $(SRC)/I_CambiaNegs_PtrFinal.cpp
	g++ -o $(BIN)/I_CambiaNegs_PtrFinal $(SRC)/I_CambiaNegs_PtrFinal.cpp

$(BIN)/I_MezclaSencillaVectores : $(SRC)/I_MezclaSencillaVectores.cpp
	g++ -o $(BIN)/I_MezclaSencillaVectores $(SRC)/I_MezclaSencillaVectores.cpp

$(BIN)/I_ReorganizaVector : $(SRC)/I_ReorganizaVector.cpp
	g++ -o $(BIN)/I_ReorganizaVector $(SRC)/I_ReorganizaVector.cpp
	

clean :
	rm $(OBJ)/*

mrproper :
	rm $(BIN)/*