###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
		$(BIN)/Demo-Conjunto \
		finalizado


################################################################################

$(BIN)/Demo-Conjunto : $(OBJ)/Demo-Conjunto.o $(OBJ)/Conjunto.o

	g++ -o $(BIN)/Demo-Conjunto $(OBJ)/Demo-Conjunto.o $(OBJ)/Conjunto.o

$(OBJ)/Demo-Conjunto.o : $(SRC)/Demo-Conjunto.cpp $(INCLUDE)/Conjunto.h
	g++ -c -o $(OBJ)/Demo-Conjunto.o $(SRC)/Demo-Conjunto.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Conjunto.o : $(SRC)/Conjunto.cpp $(INCLUDE)/Conjunto.h
	g++ -c -o $(OBJ)/Conjunto.o $(SRC)/Conjunto.cpp -I$(INCLUDE) -std=c++11



################################################################################

inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/************************************************************/"
	@echo -e



finalizado :
	@echo -e
	@echo -e "/****************************************************************/"
	@echo -e	"/**                                                            **/"
	@echo -e "/**     Todas las acciones se han realizado correctamente      **/"
	@echo -e	"/**                                                            **/"
	@echo -e "/****************************************************************/"

################################################################################

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*