#include <iostream>

using namespace std;

int main( void ){
	const int TOPE = 100;
	float v1 [TOPE] = {2,3,8,22,44,88,99,100,101,255,665};
	float v2 [TOPE] = {1,3,4,5,6,25,87,89,99,100,500,1000};
	float res [2*TOPE];

	int tam_v1 = 11, tam_v2 = 12;  // 0 <= tam_v1, tam_v2 < TOPE
	int tam_res = tam_v1 + tam_v2; // 0 <= tam_res < 2 * TOPE

	float *p_v1, *p_v2, *p_res;

	p_v1 = v1;
	p_v2 = v2;
	p_res = res;
	
	int j = 0;
	int k = 0;


	for (int i = 0; i < tam_res; i++){
		
		if ( *(p_v1 + j) < *(p_v2 + k) ){
			*(p_res + i ) = *(p_v1 + j);
			j++;
		}
		else{
			*(p_res + i ) = *(p_v2 + k);
			k++;
		}
	}

	for (int i = 0; i < tam_res; i++){
		cout << *(p_res + i) << " "; 
	}
}