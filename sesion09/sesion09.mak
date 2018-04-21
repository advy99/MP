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
		$(BIN)/III_Demo-Matriz2D_1_ConstructorCopia \
		$(BIN)/III_Demo-Lista_ConstructorCopia \
		$(BIN)/III_Demo-Matriz2D_2_ConstructorCopia \
		$(BIN)/III_Demo-Pila_ConstructorCopia \
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
				 -I$(INCLUDE) -std=c++11


$(LIB)/libVectorDinamico_ConstructorCopia.a : \
         $(OBJ)/VectorDinamico_ConstructorCopia.o
	ar -rvs $(LIB)/libVectorDinamico_ConstructorCopia.a \
	          $(OBJ)/VectorDinamico_ConstructorCopia.o

###############################################################################

$(BIN)/III_Demo-Matriz2D_1_ConstructorCopia : \
               $(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
					$(LIB)/libMatriz2D_1_ConstructorCopia.a \
					$(OBJ)/GeneradorAleatorioEnteros.o
	g++ -o $(BIN)/III_Demo-Matriz2D_1_ConstructorCopia \
               $(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
					$(OBJ)/GeneradorAleatorioEnteros.o \
					-L$(LIB) -lMatriz2D_1_ConstructorCopia

$(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o : \
            $(SRC)/III_Demo-Matriz2D_1_ConstructorCopia.cpp \
				$(INCLUDE)/TipoBase.h \
				$(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
	          $(SRC)/III_Demo-Matriz2D_1_ConstructorCopia.cpp \
				 -I$(INCLUDE) -std=c++11

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
                                     $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	          $(SRC)/GeneradorAleatorioEnteros.cpp \
				 -I$(INCLUDE) -std=c++11
			
$(LIB)/libMatriz2D_1_ConstructorCopia.a : \
             $(OBJ)/Matriz2D_1_ConstructorCopia.o
	ar -rvs $(LIB)/libMatriz2D_1_ConstructorCopia.a \
              $(OBJ)/Matriz2D_1_ConstructorCopia.o

$(OBJ)/Matriz2D_1_ConstructorCopia.o : $(SRC)/Matriz2D_1_ConstructorCopia.cpp \
            $(INCLUDE)/TipoBase.h \
            $(INCLUDE)/Matriz2D_1_ConstructorCopia.h \
				$(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/Matriz2D_1_ConstructorCopia.o \
	          $(SRC)/Matriz2D_1_ConstructorCopia.cpp -I$(INCLUDE) -std=c++11

################################################################################

$(BIN)/III_Demo-Lista_ConstructorCopia : \
                  $(OBJ)/III_Demo-Lista_ConstructorCopia.o \
						$(LIB)/libLista_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-Lista_ConstructorCopia \
                  $(OBJ)/III_Demo-Lista_ConstructorCopia.o \
						-L$(LIB) -lLista_ConstructorCopia

$(OBJ)/III_Demo-Lista_ConstructorCopia.o : \
                  $(SRC)/III_Demo-Lista_ConstructorCopia.cpp \
						$(INCLUDE)/Lista_ConstructorCopia.h \
						$(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/III_Demo-Lista_ConstructorCopia.o \
	          $(SRC)/III_Demo-Lista_ConstructorCopia.cpp \
				 -I$(INCLUDE) -std=c++11

$(LIB)/libLista_ConstructorCopia.a : $(OBJ)/Lista_ConstructorCopia.o 
	ar -rvs $(LIB)/libLista_ConstructorCopia.a $(OBJ)/Lista_ConstructorCopia.o

$(OBJ)/Lista_ConstructorCopia.o : $(SRC)/Lista_ConstructorCopia.cpp \
                                  $(INCLUDE)/Lista_ConstructorCopia.h \
											 $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Lista_ConstructorCopia.o $(SRC)/Lista_ConstructorCopia.cpp \
	                                          -I$(INCLUDE) -std=c++11


###############################################################################

$(BIN)/III_Demo-Matriz2D_2_ConstructorCopia : \
               $(OBJ)/III_Demo-Matriz2D_2_ConstructorCopia.o \
					$(LIB)/libMatriz2D_2_ConstructorCopia.a \
					$(OBJ)/GeneradorAleatorioEnteros.o
	g++ -o $(BIN)/III_Demo-Matriz2D_2_ConstructorCopia \
               $(OBJ)/III_Demo-Matriz2D_2_ConstructorCopia.o \
					$(OBJ)/GeneradorAleatorioEnteros.o \
					-L$(LIB) -lMatriz2D_2_ConstructorCopia

$(OBJ)/III_Demo-Matriz2D_2_ConstructorCopia.o : \
            $(SRC)/III_Demo-Matriz2D_2_ConstructorCopia.cpp \
				$(INCLUDE)/TipoBase.h \
				$(INCLUDE)/Matriz2D_2_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-Matriz2D_2_ConstructorCopia.o \
	          $(SRC)/III_Demo-Matriz2D_2_ConstructorCopia.cpp \
				 -I$(INCLUDE) -std=c++11

$(LIB)/libMatriz2D_2_ConstructorCopia.a : \
             $(OBJ)/Matriz2D_2_ConstructorCopia.o
	ar -rvs $(LIB)/libMatriz2D_2_ConstructorCopia.a \
              $(OBJ)/Matriz2D_2_ConstructorCopia.o

$(OBJ)/Matriz2D_2_ConstructorCopia.o : $(SRC)/Matriz2D_2_ConstructorCopia.cpp \
            $(INCLUDE)/TipoBase.h \
            $(INCLUDE)/Matriz2D_2_ConstructorCopia.h \
				$(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/Matriz2D_2_ConstructorCopia.o \
	          $(SRC)/Matriz2D_2_ConstructorCopia.cpp -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/III_Demo-Pila_ConstructorCopia : \
                  $(OBJ)/III_Demo-Pila_ConstructorCopia.o \
						$(LIB)/libPila_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-Pila_ConstructorCopia \
                  $(OBJ)/III_Demo-Pila_ConstructorCopia.o \
						-L$(LIB) -lPila_ConstructorCopia

$(OBJ)/III_Demo-Pila_ConstructorCopia.o : \
                  $(SRC)/III_Demo-Pila_ConstructorCopia.cpp \
						$(INCLUDE)/Pila_ConstructorCopia.h \
						$(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/III_Demo-Pila_ConstructorCopia.o \
	          $(SRC)/III_Demo-Pila_ConstructorCopia.cpp \
				 -I$(INCLUDE) -std=c++11

$(LIB)/libPila_ConstructorCopia.a : $(OBJ)/Pila_ConstructorCopia.o 
	ar -rvs $(LIB)/libPila_ConstructorCopia.a $(OBJ)/Pila_ConstructorCopia.o

$(OBJ)/Pila_ConstructorCopia.o : $(SRC)/Pila_ConstructorCopia.cpp \
                                  $(INCLUDE)/Pila_ConstructorCopia.h \
											 $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Pila_ConstructorCopia.o $(SRC)/Pila_ConstructorCopia.cpp \
	                                          -I$(INCLUDE) -std=c++11

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