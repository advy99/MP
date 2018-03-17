###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 5                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib	

all : inicio  $(BIN)/I_LeeEntero $(BIN)/I_MaxMin_Array $(BIN)/I_PosMayor \
      $(BIN)/I_MezclaArrays $(BIN)/I_Sucursales_Matriz_Clasica \
		$(BIN)/I_OrdenConPunteros finalizado

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

#################################################################################

$(BIN)/I_LeeEntero : $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o

	@echo -e
	@echo -e Generando binario $(BIN)/I_LeeEntero  ...
	g++ -o $(BIN)/I_LeeEntero $(OBJ)/I_LeeEntero.o $(OBJ)/Lectura.o
	@echo -e El archivo $(BIN)/I_LeeEntero generado correctamente
	@echo -e

$(OBJ)/I_LeeEntero.o : $(SRC)/I_LeeEntero.cpp $(INCLUDE)/Lectura.h

	@echo -e
	@echo -e Generando objeto $(OBJ)/I_LeeEntero.o  ...
	g++ -c -o  $(OBJ)/I_LeeEntero.o $(SRC)/I_LeeEntero.cpp -I$(INCLUDE) \
	-std=c++11
	@echo -e El archivo $(OBJ)/I_LeeEntero.o generado correctamente
	@echo -e

$(OBJ)/Lectura.o : $(SRC)/Lectura.cpp $(INCLUDE)/Lectura.h

	@echo -e
	@echo -e Generando objeto $(OBJ)/Lectura.o  ...
	g++ -c -o  $(OBJ)/Lectura.o $(SRC)/Lectura.cpp -I$(INCLUDE) -std=c++11
	@echo -e El archivo $(OBJ)/Lectura.o generado correctamente
	@echo -e


#################################################################################

$(BIN)/I_MaxMin_Array : $(OBJ)/I_MaxMin_Array.o $(OBJ)/GestionVector.o
	@echo -e
	@echo -e Generando binario $(BIN)/I_MaxMin_Array  ...
	g++ -o $(BIN)/I_MaxMin_Array $(OBJ)/I_MaxMin_Array.o $(OBJ)/GestionVector.o
	@echo -e El archivo $(BIN)/I_MaxMin_Array generado correctamente
	@echo -e

$(OBJ)/I_MaxMin_Array.o : $(SRC)/I_MaxMin_Array.cpp $(INCLUDE)/GestionVector.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/I_MaxMin_Array.o  ...
	g++ -c -o  $(OBJ)/I_MaxMin_Array.o $(SRC)/I_MaxMin_Array.cpp -I$(INCLUDE) \
	-std=c++11
	@echo -e El archivo $(OBJ)/I_MaxMin_Array.o generado correctamente
	@echo -e

$(OBJ)/GestionVector.o : $(SRC)/GestionVector.cpp $(INCLUDE)/GestionVector.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/GestionVector.o  ...
	g++ -c -o  $(OBJ)/GestionVector.o $(SRC)/GestionVector.cpp -I$(INCLUDE) \
	-std=c++11
	@echo -e El archivo $(OBJ)/GestionVector.o generado correctamente
	@echo -e

#################################################################################

$(BIN)/I_PosMayor : $(OBJ)/I_PosMayor.o $(OBJ)/GestionVector.o $(OBJ)/Lectura.o
	@echo -e
	@echo -e Generando objeto $(BIN)/I_PosMayor  ...
	g++ -o $(BIN)/I_PosMayor $(OBJ)/I_PosMayor.o $(OBJ)/GestionVector.o \
          $(OBJ)/Lectura.o
	@echo -e El archivo $(BIN)/I_PosMayor generado correctamente
	@echo -e

$(OBJ)/I_PosMayor.o : $(SRC)/I_PosMayor.cpp $(INCLUDE)/GestionVector.h \
                      $(INCLUDE)/Lectura.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/I_PosMayor.o  ...
	g++ -c -o  $(OBJ)/I_PosMayor.o $(SRC)/I_PosMayor.cpp -I$(INCLUDE) \
	-std=c++11
	@echo -e El archivo $(OBJ)/I_PosMayor.o generado correctamente
	@echo -e

#################################################################################

$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o $(OBJ)/GestionVector.o \
                        $(OBJ)/Lectura.o
	@echo -e
	@echo -e Generando objeto $(BIN)/I_MezclaArrays  ...
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o $(OBJ)/GestionVector.o \
                                $(OBJ)/Lectura.o
	@echo -e El archivo $(BIN)/I_MezclaArrays generado correctamente
	@echo -e

$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp $(INCLUDE)/GestionVector.h \
                          $(INCLUDE)/Lectura.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/I_MezclaArrays.o  ...
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp -I$(INCLUDE) \
	    -std=c++11
	@echo -e El archivo $(OBJ)/I_MezclaArrays.o generado correctamente
	@echo -e

#################################################################################

$(BIN)/I_Sucursales_Matriz_Clasica : $(OBJ)/I_Sucursales_Matriz_Clasica.o \
                                     $(OBJ)/GestionSucursales.o \
												 $(OBJ)/GestionVector.o
	@echo -e
	@echo -e Generando objeto $(BIN)/I_Sucursales_Matriz_Clasica  ...
	g++  -o $(BIN)/I_Sucursales_Matriz_Clasica \
	       $(OBJ)/I_Sucursales_Matriz_Clasica.o $(OBJ)/GestionSucursales.o \
			 $(OBJ)/GestionVector.o
	@echo -e El archivo $(BIN)/I_Sucursales_Matriz_Clasica generado correctamente
	@echo -e

$(OBJ)/I_Sucursales_Matriz_Clasica.o : $(SRC)/I_Sucursales_Matriz_Clasica.cpp \
                                       $(INCLUDE)/GestionVector.h \
													$(INCLUDE)/GestionSucursales.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/I_Sucursales_Matriz_Clasica.o  ...
	g++ -c -o $(OBJ)/I_Sucursales_Matriz_Clasica.o \
	          $(SRC)/I_Sucursales_Matriz_Clasica.cpp -I$(INCLUDE) -std=c++11
	@echo -e El archivo $(OBJ)/I_Sucursales_Matriz_Clasica.o generado correctamente
	@echo -e

$(OBJ)/GestionSucursales.o : $(SRC)/GestionSucursales.cpp \
							        $(INCLUDE)/GestionSucursales.h
	@echo -e
	@echo -e Generando objeto $(OBJ)/GestionSucursales.o  ...
	g++ -c -o $(OBJ)/GestionSucursales.o $(SRC)/GestionSucursales.cpp \
	          -I$(INCLUDE) -std=c++11
	@echo -e El archivo $(OBJ)/GestionSucursales.o generado correctamente
	@echo -e

##################################################################################

$(BIN)/I_OrdenConPunteros : $(OBJ)/I_OrdenConPunteros.o $(OBJ)/GestionVector.o \
                            $(OBJ)/Lectura.o
	@echo -e
	@echo -e Generando objeto $(BIN)/I_OrdenConPunteros  ...
	g++ -o $(BIN)/I_OrdenConPunteros \
	       $(OBJ)/I_OrdenConPunteros.o \
			 $(OBJ)/GestionVector.o \
			 $(OBJ)/Lectura.o			 
	@echo -e El archivo $(BIN)/I_OrdenConPunteros generado correctamente
	@echo -e

$(OBJ)/I_OrdenConPunteros.o : $(SRC)/I_OrdenConPunteros.cpp \
                              $(INCLUDE)/GestionVector.h $(INCLUDE)/Lectura.h
	g++ -c -o $(OBJ)/I_OrdenConPunteros.o $(SRC)/I_OrdenConPunteros.cpp \
	          -I$(INCLUDE)

##################################################################################

finalizado :
	@echo -e "/****************************************************************/"
	@echo -e	"/**                                                            **/"
	@echo -e "/**     Todas las acciones se han realizado correctamente      **/"
	@echo -e	"/**                                                            **/"
	@echo -e "/****************************************************************/"


clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
