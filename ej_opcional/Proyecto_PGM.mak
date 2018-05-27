###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 13                                     ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
      $(BIN)/Eliminar_Cabecera_PGM \
		$(BIN)/Calcular_Cols_Fils_PGM \
		finalizado


$(BIN)/Eliminar_Cabecera_PGM : $(OBJ)/Eliminar_Cabecera_PGM.o \
                               $(OBJ)/Util.o
	g++ -o $(BIN)/Eliminar_Cabecera_PGM $(OBJ)/Eliminar_Cabecera_PGM.o \
	                                    $(OBJ)/Util.o

$(OBJ)/Eliminar_Cabecera_PGM.o : $(SRC)/Eliminar_Cabecera_PGM.cpp \
                                 $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Eliminar_Cabecera_PGM.o $(SRC)/Eliminar_Cabecera_PGM.cpp \
	    -I$(INCLUDE) -std=c++11

$(OBJ)/Util.o : $(SRC)/Util.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Util.o $(SRC)/Util.cpp -I$(INCLUDE) -std=c++11

################################################################################

$(BIN)/Calcular_Cols_Fils_PGM : $(OBJ)/Calcular_Cols_Fils_PGM.o $(OBJ)/Util.o
	g++ -o $(BIN)/Calcular_Cols_Fils_PGM $(OBJ)/Calcular_Cols_Fils_PGM.o \
	       $(OBJ)/Util.o


$(OBJ)/Calcular_Cols_Fils_PGM.o : $(SRC)/Calcular_Cols_Fils_PGM.cpp \
                                   $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Calcular_Cols_Fils_PGM.o \
	          $(SRC)/Calcular_Cols_Fils_PGM.cpp \
				 -I$(INCLUDE) -std=c++11

################################################################################


inicio :
	@echo 
	@echo 	"/************************************************************/"
	@echo 	"/**                                                        **/"
	@echo 	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo 	"/**  1GII - Universidad de Granada                         **/"
	@echo 	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo 	"/**  Makefile ejercicio opcional                           **/"
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