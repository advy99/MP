#include <iostream>
#include "opers.h"

using namespace std;


int main (void)
{
   int num1, num2; 

   cout << "Introduce un numero: "; 
   cin >> num1; 
   cout << "Introduce otro numero: "; 
   cin >> num2; 

   cout << "La suma es = " << suma (num1, num2) << "\n"; 
   cout << "La resta es = " << resta (num1, num2) << "\n"; 
   cout << "La multiplicación es = " << multiplica (num1, num2) << "\n"; 
   cout << "La división es = " << divide (num1, num2) << "\n"; 

   return (0);
}
