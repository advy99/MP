###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 6                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio $(BIN)/II-RedimensionaVectorDinamico \
             $(BIN)/II-VectorDinamicoCadenas \
				 $(BIN)/I_EncuentraInicioPalabras \
				 finalizado
				 
$(BIN)/II-RedimensionaVectorDinamico : $(SRC)/II-RedimensionaVectorDinamico.cpp
	g++ -o $(BIN)/II-RedimensionaVectorDinamico \
	       $(SRC)/II-RedimensionaVectorDinamico.cpp -std=c++11

#################################################################################

$(BIN)/II-VectorDinamicoCadenas : $(SRC)/II-VectorDinamicoCadenas.cpp
	g++ -o $(BIN)/II-VectorDinamicoCadenas $(SRC)/II-VectorDinamicoCadenas.cpp \
	    -std=c++11

#################################################################################

$(BIN)/I_EncuentraInicioPalabras : $(SRC)/I_EncuentraInicioPalabras.cpp
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(SRC)/I_EncuentraInicioPalabras.cpp \
	    -std=c++11

#################################################################################

inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**  Makefile sesion 5                                     **/"
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

#################################################################################

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*
