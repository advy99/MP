HOME = .

LIB = $(HOME)/lib
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj

all :  clean $(BIN)/I_PosicionPrimerBlanco $(BIN)/I_SaltaPrimeraPalabra $(BIN)/I_DemoCadenasClasicas finalizado

$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	@echo -e "Generando $(BIN)/I_PosicionPrimerBlanco"
	g++ -o $(BIN)/I_PosicionPrimerBlanco $(SRC)/I_PosicionPrimerBlanco.cpp
	@echo -e "Generado correctamente \n"

$(BIN)/I_SaltaPrimeraPalabra : $(SRC)/I_SaltaPrimeraPalabra.cpp
	@echo "Generando $(BIN)/I_SaltaPrimeraPalabra"
	g++ -o $(BIN)/I_SaltaPrimeraPalabra $(SRC)/I_SaltaPrimeraPalabra.cpp
	@echo -e "Generado correctamente \n"

$(BIN)/I_DemoCadenasClasicas : $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	@echo -e "Generando $(BIN)/I_DemoCadenasClasicas"
	g++ -o $(BIN)/I_DemoCadenasClasicas $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	@echo -e "Generado correctamente \n"

$(OBJ)/I_DemoCadenasClasicas.o : $(SRC)/I_DemoCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo -e "Generando objetos necesarios"
	g++ -c -o $(OBJ)/I_DemoCadenasClasicas.o $(SRC)/I_DemoCadenasClasicas.cpp -I$(INCLUDE)
	@echo

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo -e "Generando objetos necesarios"
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE)
	@echo

finalizado :
	@echo -e "/***********************************************************/"
	@echo -e "\nTodas las tareas han sido ejecutadas correctamente \n"
	@echo -e "/***********************************************************/\n"

clean :

	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*