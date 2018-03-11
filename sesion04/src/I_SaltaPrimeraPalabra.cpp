#include <iostream>
#include <cstring>

using namespace std;

int main ( void ){
	const int MAX = 100;
	char cadenaC [MAX];
	char cadenaC_recortada [MAX] = {' '};
	char *p_char = cadenaC;

	cout << "Introduce una cadena de caracteres : " << endl;
	cin.getline(cadenaC, MAX);

	//Buscamos el primer espacio
	while( *p_char != ' '  && *p_char != '\0'){
		p_char++;
	}

	// Si ha encontrado el espacio, saltamos la posicion de este
	//y copiamos la cadena en otra a partir de ese espacio
	if (*p_char != '\0'){
		p_char++;
		strcpy(cadenaC_recortada, p_char);
	}
	
	cout << cadenaC_recortada;
}