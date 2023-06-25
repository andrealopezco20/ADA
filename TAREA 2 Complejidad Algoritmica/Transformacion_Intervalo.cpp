//para mapear un intervalo de valores a otro intervalo, 
//generalmente con el objetivo de simplificar cálculos o reducir la complejidad de un algoritmo.
#include <iostream>
using namespace std;

int TransformacionIntervalo(int n)
{
	if (n == 0){
		return 1;
	}
	else if (n % 2 == 0){
		return TransformacionIntervalo(n / 2);
	}
	else
	{
		return TransformacionIntervalo(n - 1) + 1;
	}
}

int main()
{
	int x = 4;
	int resultado = TransformacionIntervalo(x);
	cout << "Resultado: " << resultado <<endl;
	
	return 0;
}
