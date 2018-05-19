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
      $(BIN)/CopiaEnteros \
		$(BIN)/CopiaEnteros-Bloques512 \
		$(BIN)/ParteFicheroPorNumBytes \
		$(BIN)/Reconstruye \
		$(BIN)/Binariza \
		finalizado


$(BIN)/CopiaEnteros : $(OBJ)/CopiaEnteros.o $(OBJ)/Util.o
	g++ -o $(BIN)/CopiaEnteros $(OBJ)/CopiaEnteros.o $(OBJ)/Util.o

$(OBJ)/CopiaEnteros.o : $(SRC)/CopiaEnteros.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/CopiaEnteros.o $(SRC)/CopiaEnteros.cpp \
	    -I$(INCLUDE) -std=c++11

$(OBJ)/Util.o : $(SRC)/Util.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Util.o $(SRC)/Util.cpp -I$(INCLUDE) -std=c++11

################################################################################


$(BIN)/CopiaEnteros-Bloques512 : $(OBJ)/CopiaEnteros-Bloques512.o $(OBJ)/Util.o
	g++ -o $(BIN)/CopiaEnteros-Bloques512 $(OBJ)/CopiaEnteros-Bloques512.o \
	       $(OBJ)/Util.o


$(OBJ)/CopiaEnteros-Bloques512.o : $(SRC)/CopiaEnteros-Bloques512.cpp \
                                   $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/CopiaEnteros-Bloques512.o \
	          $(SRC)/CopiaEnteros-Bloques512.cpp \
	         -I$(INCLUDE) -std=c++11

################################################################################

$(BIN)/ParteFicheroPorNumBytes : $(OBJ)/ParteFicheroPorNumBytes.o $(OBJ)/Util.o
	g++ -o $(BIN)/ParteFicheroPorNumBytes $(OBJ)/ParteFicheroPorNumBytes.o \
	       $(OBJ)/Util.o


$(OBJ)/ParteFicheroPorNumBytes.o : $(SRC)/ParteFicheroPorNumBytes.cpp \
                                   $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/ParteFicheroPorNumBytes.o \
	          $(SRC)/ParteFicheroPorNumBytes.cpp \
				 -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/Reconstruye : $(OBJ)/Reconstruye.o $(OBJ)/Util.o
	g++ -o $(BIN)/Reconstruye $(OBJ)/Reconstruye.o \
	       $(OBJ)/Util.o


$(OBJ)/Reconstruye.o : $(SRC)/Reconstruye.cpp \
                       $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Reconstruye.o \
	          $(SRC)/Reconstruye.cpp \
				 -I$(INCLUDE) -std=c++11


################################################################################

$(BIN)/Binariza : $(OBJ)/Binariza.o $(OBJ)/Util.o
	g++ -o $(BIN)/Binariza $(OBJ)/Binariza.o \
	       $(OBJ)/Util.o


$(OBJ)/Binariza.o : $(SRC)/Binariza.cpp \
                    $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Binariza.o \
	          $(SRC)/Binariza.cpp \
				 -I$(INCLUDE) -std=c++11

################################################################################

inicio :
	@echo 
	@echo 	"/************************************************************/"
	@echo 	"/**                                                        **/"
	@echo 	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo 	"/**  1GII - Universidad de Granada                         **/"
	@echo 	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo 	"/**  Makefile sesion 13                                    **/"
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