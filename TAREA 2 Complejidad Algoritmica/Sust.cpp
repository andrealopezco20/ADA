//para simplificar o transformar una expresi�n o ecuaci�n en una forma m�s manejable. 
//Consiste en reemplazar una parte de la expresi�n o ecuaci�n con una nueva variable o funci�n, 
//lo que puede ayudar a simplificar la l�gica o la estructura del algoritmo.
#include <iostream>
int FuncionRecursiva(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return 2 * FuncionRecursiva(n - 1);
	}
}

int main()
{
	int n = 5;
	int resultado = FuncionRecursiva(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
