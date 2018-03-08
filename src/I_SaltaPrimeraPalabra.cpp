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


	while( *p_char != ' '  && *p_char != '\0'){
		p_char++;
	}

	if (*p_char != '\0')
		strcpy(cadenaC_recortada, p_char);
	
	cout << cadenaC_recortada;
}