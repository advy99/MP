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

using namespace std;

/*******************************************************************************/

char ** SepararCadena(string, int &);

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
	
	
	for (int i = 0; i < num_lineas; i++){
		cout << v[i] << endl;
	}

}

/*******************************************************************************/

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