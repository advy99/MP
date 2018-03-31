/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 4 - Vector dinámico de cadenas    **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*******************************************************************************/

char ** SepararCadena(string, int &);
int NumLineasVacias(char ** , const int );
int NumParrafos (char ** , const int );
bool LineaEnBlanco(char ** , const int );

/*******************************************************************************/

int main(){
	string cadena;
	string cadena_completa = "";
	int num_lineas = 0;
	

	while (getline (cin,cadena)){
		cadena_completa = cadena_completa + cadena;
		cadena_completa.push_back('\n');
	}

	char ** v = SepararCadena(cadena_completa, num_lineas);
	
	
	cout << "El archivo tiene " << num_lineas
	     << " lineas de las cuales " << NumLineasVacias (v, num_lineas) 
	     << " estan vacias. " << endl << endl
		  << "El archivo esta compuesto por " << NumParrafos (v,num_lineas)
		  << " parrafos " << endl;


	delete [] v;

	return 0;
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Separa un string en vectores de cadenas clasicas      **/
/**                                                         **/
/**   Recibe: String donde se almacenan las lineas          **/
/**           Numero de lineas del documento                **/
/**                                                         **/
/**   Devuelve: Puntero a vector de char donde se           **/
/**           almacenan las filas                           **/
/**                                                         **/
/*************************************************************/

char ** SepararCadena(string cadena, int & num_lineas){
	int tam_cadena_completa;
	int j = 0;

	tam_cadena_completa = cadena.size();

	for (int i = 0; i < tam_cadena_completa; i++){
		if (cadena[i] == '\n')	
			num_lineas++;
	}


	char ** cadenas = new char * [num_lineas];

	for (int i = 0; i < num_lineas; i++){
		string fila = "";

		while (cadena[j] != '\n'){
			fila = fila + cadena[j];
			j++;
		}
		j++;

		char * linea = new char [fila.size()];

		strcpy(linea, fila.c_str());

		cadenas[i] = linea;
	}

	return cadenas;
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cuenta el numero de lineas vacias en un documento     **/
/**                                                         **/
/**   Recibe: Vector donde se almacenan las lineas          **/
/**           Numero de lineas del documento                **/
/**                                                         **/
/**   Devuelve: Numero de lineas vacias del documento       **/
/**                                                         **/
/*************************************************************/

int NumLineasVacias(char ** documento, const int NUM_LINEAS){
	int lineas_vacias;
	//Si el primer elemento de la linea es el fin de linea, la linea esta vacia
	for (int i = 0; i < NUM_LINEAS;i++){
		if (documento[i][0] == '\0')
			lineas_vacias++;
	}
	return lineas_vacias;
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Cuenta el numero de parrafos en un documento          **/
/**                                                         **/
/**   Recibe: Vector donde se almacenan las lineas          **/
/**           Numero de lineas del documento                **/
/**                                                         **/
/**   Devuelve: Numero de parrafos del documento            **/
/**                                                         **/
/*************************************************************/

int NumParrafos (char ** documento,const int NUM_LINEAS){
	int num_parrafos = 0;
	//Comprobamos si en la primera linea comienza un parrafo
	bool mismo_parrafo = !LineaEnBlanco(documento, 0);

	//Comprobamos hasta la ultima linea, si la siguiente linea esta en blanco,
	//acaba el parrafo, y continua hasta que la siguiente no este en blanco,
	for(int i = 0; i < NUM_LINEAS - 1 ; i++){
		if (mismo_parrafo){
			if ( LineaEnBlanco(documento, i + 1) ){
				num_parrafos++;
				mismo_parrafo = false;
			}
		}
		else{
			mismo_parrafo = !LineaEnBlanco(documento, i + 1);
		} 
	}

	//Comprobamos ultima linea
	if(mismo_parrafo)
		num_parrafos++;

	return num_parrafos;
}

/*******************************************************************************/

/*************************************************************/
/**                                                         **/
/**   Comprueba si una linea de un documento esta en blanco **/
/**                                                         **/
/**   Recibe: Vector donde se almacenan las lineas          **/
/**           Linea a comprobar si esta en blanco           **/
/**                                                         **/
/**   Devuelve: Verdadero o false                           **/
/**                                                         **/
/*************************************************************/

bool LineaEnBlanco(char ** documento, const int NUM_LINEA){
	//Nos centramos en la linea que queremos comprobar
	char * linea = documento[NUM_LINEA];

	bool linea_blanco = true;
	//Recorremos la linea
	while ( *linea && linea_blanco){
		//Si encontramos un elemento que no sea un espaciador esa linea no
		//esta vacia
		if ( !isspace ( *linea ) ){
			linea_blanco = false;
		}
		linea++;
	}

	return linea_blanco;
}