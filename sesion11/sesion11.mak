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
		$(BIN)/CuentaLineasNoVacias-peek \
		$(BIN)/MuestraLineasNoVacias \
		$(BIN)/ComprimeLineas \
		$(BIN)/CopiaLineasSinAlmohadilla \
		$(BIN)/CopiaEnteros \
		$(BIN)/CopiaEnterosSeparados \
		$(BIN)/SumaEnteros  \
		$(BIN)/CuentaCaracteresConcretos \
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

$(BIN)/CuentaLineasNoVacias-peek : $(SRC)/CuentaLineasNoVacias-peek.cpp
	g++ -o $(BIN)/CuentaLineasNoVacias-peek \
	       $(SRC)/CuentaLineasNoVacias-peek.cpp -std=c++11


################################################################################

$(BIN)/MuestraLineasNoVacias : $(SRC)/MuestraLineasNoVacias.cpp
	g++ -o $(BIN)/MuestraLineasNoVacias \
	       $(SRC)/MuestraLineasNoVacias.cpp -std=c++11


################################################################################

$(BIN)/ComprimeLineas : $(SRC)/ComprimeLineas.cpp
	g++ -o $(BIN)/ComprimeLineas \
	       $(SRC)/ComprimeLineas.cpp -std=c++11


################################################################################

$(BIN)/CopiaLineasSinAlmohadilla : $(SRC)/CopiaLineasSinAlmohadilla.cpp
	g++ -o $(BIN)/CopiaLineasSinAlmohadilla \
	       $(SRC)/CopiaLineasSinAlmohadilla.cpp -std=c++11


################################################################################

$(BIN)/CopiaEnteros : $(SRC)/CopiaEnteros.cpp
	g++ -o $(BIN)/CopiaEnteros \
	       $(SRC)/CopiaEnteros.cpp -std=c++11


################################################################################

$(BIN)/CopiaEnterosSeparados : $(SRC)/CopiaEnterosSeparados.cpp
	g++ -o $(BIN)/CopiaEnterosSeparados \
	       $(SRC)/CopiaEnterosSeparados.cpp -std=c++11


################################################################################


$(BIN)/SumaEnteros : $(SRC)/SumaEnteros.cpp
	g++ -o $(BIN)/SumaEnteros \
	       $(SRC)/SumaEnteros.cpp -std=c++11


################################################################################


$(BIN)/CuentaCaracteresConcretos : $(SRC)/CuentaCaracteresConcretos.cpp
	g++ -o $(BIN)/CuentaCaracteresConcretos \
	       $(SRC)/CuentaCaracteresConcretos.cpp -std=c++11


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