//para simplificar o transformar una expresión o ecuación en una forma más manejable. 
//Consiste en reemplazar una parte de la expresión o ecuación con una nueva variable o función, 
//lo que puede ayudar a simplificar la lógica o la estructura del algoritmo.
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
