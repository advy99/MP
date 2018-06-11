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
		$(BIN)/Demo \
		finalizado


################################################################################

$(BIN)/Demo : $(OBJ)/Demo.o $(OBJ)/Ruta.o

	g++ -o $(BIN)/Demo $(OBJ)/Demo.o $(OBJ)/Ruta.o

$(OBJ)/Demo.o : $(SRC)/Demo.cpp $(INCLUDE)/Ruta.h
	g++ -c -o $(OBJ)/Demo.o $(SRC)/Demo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Ruta.o : $(SRC)/Ruta.cpp $(INCLUDE)/Ruta.h
	g++ -c -o $(OBJ)/Ruta.o $(SRC)/Ruta.cpp -I$(INCLUDE) -std=c++11



################################################################################

inicio :
	-mkdir include src bin obj lib
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