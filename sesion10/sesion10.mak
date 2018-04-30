###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 10                                     ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
      $(BIN)/IV_Demo-Matriz2D_1_Todo \
		$(BIN)/IV_Demo-Lista_Todo \
		$(BIN)/IV_Demo-PoliLinea \
		$(BIN)/IV_Demo-RedCiudades \
		finalizado

################################################################################

$(BIN)/IV_Demo-Matriz2D_1_Todo : $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
                                 $(LIB)/libMatriz2D_1.a \
											$(OBJ)/GeneradorAleatorioEnteros.o
	
	g++ -o $(BIN)/IV_Demo-Matriz2D_1_Todo $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
	                                      $(OBJ)/GeneradorAleatorioEnteros.o \
                                         -L$(LIB) -lMatriz2D_1


$(LIB)/libMatriz2D_1.a : $(OBJ)/Matriz2D_1.o
	ar -rvs $(LIB)/libMatriz2D_1.a $(OBJ)/Matriz2D_1.o



$(OBJ)/IV_Demo-Matriz2D_1_Todo.o : $(SRC)/IV_Demo-Matriz2D_1_Todo.cpp \
                                   $(INCLUDE)/TipoBase.h \
											  $(INCLUDE)/Matriz2D_1.h

	g++ -c -o $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
	          $(SRC)/IV_Demo-Matriz2D_1_Todo.cpp \
				 -I$(INCLUDE) -std=c++11

	
$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp \
                      $(INCLUDE)/Matriz2D_1.h \
							 $(INCLUDE)/TipoBase.h \
							 $(INCLUDE)/GeneradorAleatorioEnteros.h
	
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
                                     $(INCLUDE)/GeneradorAleatorioEnteros.h

	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	          $(SRC)/GeneradorAleatorioEnteros.cpp \
				 -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/IV_Demo-Lista_Todo : $(OBJ)/IV_Demo-Lista_Todo.o \
                            $(LIB)/libLista.a
	g++ -o $(BIN)/IV_Demo-Lista_Todo $(OBJ)/IV_Demo-Lista_Todo.o \
	                                 -L$(LIB) -lLista


$(OBJ)/IV_Demo-Lista_Todo.o : $(SRC)/IV_Demo-Lista_Todo.cpp \
                              $(INCLUDE)/Lista.h

	g++ -c -o $(OBJ)/IV_Demo-Lista_Todo.o $(SRC)/IV_Demo-Lista_Todo.cpp \
	          -I$(INCLUDE) -std=c++11

$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/TipoBase.h

	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/IV_Demo-PoliLinea : $(OBJ)/IV_Demo-PoliLinea.o \
                           $(LIB)/libPoliLinea.a
	g++ -o $(BIN)/IV_Demo-PoliLinea $(OBJ)/IV_Demo-PoliLinea.o \
	                               -L$(LIB) -lPoliLinea

$(OBJ)/IV_Demo-PoliLinea.o : $(SRC)/IV_Demo-PoliLinea.cpp \
                             $(INCLUDE)/PoliLinea.h
	g++ -c -o $(OBJ)/IV_Demo-PoliLinea.o $(SRC)/IV_Demo-PoliLinea.cpp \
	                                     -I$(INCLUDE) -std=c++11

$(LIB)/libPoliLinea.a : $(OBJ)/PoliLinea.o
	ar -rvs $(LIB)/libPoliLinea.a $(OBJ)/PoliLinea.o

$(OBJ)/PoliLinea.o : $(SRC)/PoliLinea.cpp $(INCLUDE)/PoliLinea.h
	g++ -c -o $(OBJ)/PoliLinea.o $(SRC)/PoliLinea.cpp -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/IV_Demo-RedCiudades : $(OBJ)/IV_Demo-RedCiudades.o \
                             $(LIB)/libRedCiudades.a
	g++ -o $(BIN)/IV_Demo-RedCiudades $(OBJ)/IV_Demo-RedCiudades.o \
                                     -L$(LIB) -lRedCiudades

$(OBJ)/IV_Demo-RedCiudades.o : $(SRC)/IV_Demo-RedCiudades.cpp \
                               $(INCLUDE)/RedCiudades.h
	g++ -c -o $(OBJ)/IV_Demo-RedCiudades.o $(SRC)/IV_Demo-RedCiudades.cpp \
	                                       -I$(INCLUDE) -std=c++11


$(LIB)/libRedCiudades.a : $(OBJ)/RedCiudades.o

	ar -rvs $(LIB)/libRedCiudades.a $(OBJ)/RedCiudades.o


$(OBJ)/RedCiudades.o : $(SRC)/RedCiudades.cpp $(INCLUDE)/RedCiudades.h
	g++ -c -o $(OBJ)/RedCiudades.o $(SRC)/RedCiudades.cpp -I$(INCLUDE) -std=c++11

################################################################################

$(BIN)/IV_Demo-VectorDinamico_Todo : \
         $(OBJ)/IV_Demo-VectorDinamico_Todo.o \
			$(LIB)/libVectorDinamico.a
	g++ -o $(BIN)/IV_Demo-VectorDinamico_Todo \
                $(OBJ)/IV_Demo-VectorDinamico.o \
			       -L$(LIB) -lVectorDinamico

$(OBJ)/IV_Demo-VectorDinamico_Todo.o : \
         $(SRC)/IV_Demo-VectorDinamico_Todo.cpp \
			$(INCLUDE)/TipoBase.h \
			$(INCLUDE)/VectorDinamico.h
	g++ -c -o $(OBJ)/IV_Demo-VectorDinamico_Todo.o \
	          $(SRC)/IV_Demo-VectorDinamico_Todo.cpp \
				 -I$(INCLUDE) -std=c++11

$(OBJ)/VectorDinamico.o : \
         $(SRC)/VectorDinamico.cpp \
			$(INCLUDE)/VectorDinamico.h \
			$(INCLUDE)/TipoBase.h \
			$(INCLUDE)/RedimensionVector.h
	g++ -c -o $(OBJ)/VectorDinamico.o \
             $(SRC)/VectorDinamico.cpp \
				 -I$(INCLUDE) -std=c++11


$(LIB)/libVectorDinamico.a : \
         $(OBJ)/VectorDinamico.o
	ar -rvs $(LIB)/libVectorDinamico.a \
	          $(OBJ)/VectorDinamico.o


inicio :
	@echo -e
	@echo -e	"/************************************************************/"
	@echo -e	"/**                                                        **/"
	@echo -e	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo -e	"/**  1GII - Universidad de Granada                         **/"
	@echo -e	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo -e	"/**  Makefile sesion 10                                    **/"
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