###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 8                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
		$(BIN)/II_BasicosLista \
		$(BIN)/II_OrdenarLista \
		$(BIN)/II_GestionarListaOrdenada \
		$(BIN)/II_MezclarListasOrdenadas

################################################################################

$(BIN)/II_BasicosLista : $(OBJ)/II_BasicosLista.o \
                         $(LIB)/libLista.a
	g++ -o $(BIN)/II_BasicosLista $(OBJ)/II_BasicosLista.o \
	                              -L$(LIB) -lLista


$(OBJ)/II_BasicosLista.o : $(SRC)/II_BasicosLista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_BasicosLista.o $(SRC)/II_BasicosLista.cpp -I$(INCLUDE)

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/TipoBase.h $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)


################################################################################

$(BIN)/II_OrdenarLista : $(OBJ)/II_OrdenarLista.o \
                         $(LIB)/libLista.a
	g++ -o $(BIN)/II_OrdenarLista $(OBJ)/II_OrdenarLista.o \
	                              -L$(LIB) -lLista

$(OBJ)/II_OrdenarLista.o : $(SRC)/II_OrdenarLista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_OrdenarLista.o $(SRC)/II_OrdenarLista.cpp -I$(INCLUDE)

################################################################################

$(BIN)/II_GestionarListaOrdenada : $(OBJ)/II_GestionarListaOrdenada.o \
                                $(LIB)/libLista.a
	g++ -o $(BIN)/II_GestionarListaOrdenada $(OBJ)/II_GestionarListaOrdenada.o \
	                                  -L$(LIB) -lLista

$(OBJ)/II_GestionarListaOrdenada.o : $(SRC)/II_GestionarListaOrdenada.cpp \
                                  $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_GestionarListaOrdenada.o \
	                                       $(SRC)/II_GestionarListaOrdenada.cpp \
	                                       -I$(INCLUDE)

################################################################################

$(BIN)/II_MezclarListasOrdenadas : $(OBJ)/II_MezclarListasOrdenadas.o \
                                   $(LIB)/libLista.a
	g++ -o $(BIN)/II_MezclarListasOrdenadas $(OBJ)/II_MezclarListasOrdenadas.o \
	                                  -L$(LIB) -lLista

$(OBJ)/II_MezclarListasOrdenadas.o : $(SRC)/II_MezclarListasOrdenadas.cpp \
                                  $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_MezclarListasOrdenadas.o \
	                                       $(SRC)/II_MezclarListasOrdenadas.cpp \
	                                       -I$(INCLUDE)


$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o


inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**  Makefile sesion 8                                     **/"
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