#include <iostream>

using namespace std;


int main(void){
	const int MAX = 100;
	char cadenaC [MAX];
	char *p_char;
	int posicion = 1;
	
	cout << "Introduzca una cadena: " << endl;
	cin.getline(cadenaC, MAX);

	p_char = cadenaC;

	while( *p_char != ' '  && *p_char != '\0'){
		posicion++;
		p_char++;
	}

	if (*p_char == ' ')
		cout << "Hay un espacio en la posicion " << posicion << endl;
	else
		cout << "No se ha encontrado ningun espacio." << endl;

	return (0);
}