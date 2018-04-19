###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 9                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
		$(BIN)/III_Demo-VectorDinamico_ConstructorCopia \
		finalizado

################################################################################

$(BIN)/III_Demo-VectorDinamico_ConstructorCopia : \
         $(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
			$(LIB)/libVectorDinamico_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-VectorDinamico_ConstructorCopia \
                $(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
			       -L$(LIB) -lVectorDinamico_ConstructorCopia

$(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o : \
         $(SRC)/III_Demo-VectorDinamico_ConstructorCopia.cpp \
			$(INCLUDE)/TipoBase.h \
			$(INCLUDE)/VectorDinamico_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
	          $(SRC)/III_Demo-VectorDinamico_ConstructorCopia.cpp \
				 -I$(INCLUDE) -std=c++11

$(OBJ)/VectorDinamico_ConstructorCopia.o : \
         $(SRC)/VectorDinamico_ConstructorCopia.cpp \
			$(INCLUDE)/VectorDinamico_ConstructorCopia.h \
			$(INCLUDE)/TipoBase.h \
			$(INCLUDE)/RedimensionVector.h
	g++ -c -o $(OBJ)/VectorDinamico_ConstructorCopia.o \
             $(SRC)/VectorDinamico_ConstructorCopia.cpp \
				 -I$(INCLUDE)


$(LIB)/libVectorDinamico_ConstructorCopia.a : \
         $(OBJ)/VectorDinamico_ConstructorCopia.o
	ar -rvs $(LIB)/libVectorDinamico_ConstructorCopia.a \
	          $(OBJ)/VectorDinamico_ConstructorCopia.o


inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**  Makefile sesion 9                                     **/"
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
	-rm $(LIB)/*