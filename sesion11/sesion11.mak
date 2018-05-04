###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 11                                     ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
		$(BIN)/CopiaTodo \
		$(BIN)/CopiaExceptoVocales \
		$(BIN)/CuentaCaracteres \
		$(BIN)/CuentaLineasNoVacias \
		finalizado

################################################################################


$(BIN)/CopiaTodo : $(SRC)/CopiaTodo.cpp
	g++ -o $(BIN)/CopiaTodo $(SRC)/CopiaTodo.cpp -std=c++11

################################################################################

$(BIN)/CopiaExceptoVocales : $(SRC)/CopiaExceptoVocales.cpp
	g++ -o $(BIN)/CopiaExceptoVocales $(SRC)/CopiaExceptoVocales.cpp -std=c++11

################################################################################

$(BIN)/CuentaCaracteres : $(SRC)/CuentaCaracteres.cpp
	g++ -o $(BIN)/CuentaCaracteres $(SRC)/CuentaCaracteres.cpp -std=c++11


################################################################################


$(BIN)/CuentaLineasNoVacias : $(SRC)/CuentaLineasNoVacias.cpp
	g++ -o $(BIN)/CuentaLineasNoVacias $(SRC)/CuentaLineasNoVacias.cpp -std=c++11


################################################################################


inicio :
	@echo 
	@echo 	"/************************************************************/"
	@echo 	"/**                                                        **/"
	@echo 	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo 	"/**  1GII - Universidad de Granada                         **/"
	@echo 	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo 	"/**  Makefile sesion 11                                    **/"
	@echo 	"/**                                                        **/"
	@echo 	"/************************************************************/"
	@echo 



finalizado :
	@echo 
	@echo  "/****************************************************************/"
	@echo  "/**                                                            **/"
	@echo  "/**     Todas las acciones se han realizado correctamente      **/"
	@echo  "/**                                                            **/"
	@echo  "/****************************************************************/"

################################################################################

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*
	-rm $(LIB)/*