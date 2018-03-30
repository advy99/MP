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
				 $(BIN)/I_EncuentraPalabras \
				 $(BIN)/II-EncuentraPalabras_MemDin \
				 $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
				 finalizado
				 
$(BIN)/II-RedimensionaVectorDinamico : $(SRC)/II-RedimensionaVectorDinamico.cpp

	@echo
	@echo "Generando $(BIN)/II-RedimensionaVectorDinamico"
	@echo
	g++ -o $(BIN)/II-RedimensionaVectorDinamico \
	       $(SRC)/II-RedimensionaVectorDinamico.cpp -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################

$(BIN)/II-VectorDinamicoCadenas : $(SRC)/II-VectorDinamicoCadenas.cpp
	@echo
	@echo "Generando $(BIN)/II-VectorDinamicoCadenas"
	@echo
	g++ -o $(BIN)/II-VectorDinamicoCadenas $(SRC)/II-VectorDinamicoCadenas.cpp \
	    -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################

$(BIN)/I_EncuentraInicioPalabras : $(SRC)/I_EncuentraInicioPalabras.cpp
	@echo
	@echo "Generando $(BIN)/I_EncuentraInicioPalabras"
	@echo
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(SRC)/I_EncuentraInicioPalabras.cpp \
	    -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################

$(BIN)/I_EncuentraPalabras : $(SRC)/I_EncuentraPalabras.cpp
	@echo
	@echo "Generando $(BIN)/I_EncuentraPalabras"
	@echo
	g++ -o $(BIN)/I_EncuentraPalabras $(SRC)/I_EncuentraPalabras.cpp -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################

$(BIN)/II-EncuentraPalabras_MemDin : $(SRC)/II-EncuentraPalabras_MemDin.cpp
	@echo
	@echo "Generando $(BIN)/II-EncuentraPalabras_MemDin"
	@echo
	g++ -o $(BIN)/II-EncuentraPalabras_MemDin \
	       $(SRC)/II-EncuentraPalabras_MemDin.cpp -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################

$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos : \
                              $(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp
	@echo
	@echo "Generando $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos"
	@echo
	g++ -o $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
	       $(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp -std=c++11
	@echo
	@echo "Ejecutable generado correctamente"
	@echo

#################################################################################


inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**  Makefile sesion 6                                     **/"
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
