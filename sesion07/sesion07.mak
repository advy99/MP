###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 7                                      ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
      $(BIN)/II_Demo-Matriz2D_1 \
		$(BIN)/II_ProblemaAsignacion \
		$(BIN)/II_ProblemaViajanteComercio \
		finalizado

###############################################################################

$(BIN)/II_Demo-Matriz2D_1 : $(OBJ)/II_Demo-Matriz2D_1.o \
                            $(OBJ)/Matriz2D_1.o \
									 $(OBJ)/GeneradorAleatorioEnteros.o

	g++ -o $(BIN)/II_Demo-Matriz2D_1 $(OBJ)/II_Demo-Matriz2D_1.o \
	                                 $(OBJ)/Matriz2D_1.o \
												$(OBJ)/GeneradorAleatorioEnteros.o

$(OBJ)/II_Demo-Matriz2D_1.o : $(SRC)/II_Demo-Matriz2D_1.cpp \
                              $(INCLUDE)/Matriz2D_1.h \
								    	$(INCLUDE)/TipoBase.h

	g++ -c -o $(OBJ)/II_Demo-Matriz2D_1.o $(SRC)/II_Demo-Matriz2D_1.cpp \
	       -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp \
							 $(INCLUDE)/Matriz2D_1.h \
							 $(INCLUDE)/TipoBase.h \
							 $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp \
										   -I$(INCLUDE) -std=c++11


$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
                                     $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	          $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++11

################################################################################


$(BIN)/II_ProblemaAsignacion : $(OBJ)/II_ProblemaAsignacion.o \
                               $(OBJ)/Matriz2D_1.o \
										 $(OBJ)/GeneradorAleatorioEnteros.o
	g++ -o $(BIN)/II_ProblemaAsignacion $(OBJ)/II_ProblemaAsignacion.o \
                                       $(OBJ)/Matriz2D_1.o \
													$(OBJ)/GeneradorAleatorioEnteros.o

$(OBJ)/II_ProblemaAsignacion.o : $(SRC)/II_ProblemaAsignacion.cpp \
                                 $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/II_ProblemaAsignacion.o $(SRC)/II_ProblemaAsignacion.cpp \
	    -I$(INCLUDE) -std=c++11

################################################################################

$(BIN)/II_ProblemaViajanteComercio : $(OBJ)/II_ProblemaViajanteComercio.o \
                                     $(OBJ)/Matriz2D_1.o \
					       					 $(OBJ)/GeneradorAleatorioEnteros.o
	g++ -o $(BIN)/II_ProblemaViajanteComercio \
	                                       $(OBJ)/II_ProblemaViajanteComercio.o \
                                          $(OBJ)/Matriz2D_1.o \
                                          $(OBJ)/GeneradorAleatorioEnteros.o

$(OBJ)/II_ProblemaViajanteComercio.o : $(SRC)/II_ProblemaViajanteComercio.cpp \
                                       $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/II_ProblemaViajanteComercio.o \
	          $(SRC)/II_ProblemaViajanteComercio.cpp \
	         -I$(INCLUDE) -std=c++11

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

################################################################################

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*