//una recurrencia homog�nea se refiere a una relaci�n de recurrencia 
//en la que todos los t�rminos est�n definidos en funci�n de t�rminos anteriores sin ninguna influencia externa
#include <iostream>
using namespace std;

int RecurrenciaHomogenea(int n){
	if (n == 0){
		return 1;
	}
	else if (n == 1){
		return 2;
	}
	else{
		return 3 * RecurrenciaHomogenea(n - 1) - 2 * RecurrenciaHomogenea(n - 2);
	}
}

int main(){
	int x = 4;
	int respuesta = RecurrenciaHomogenea(x);
	std::cout << respuesta << std::endl;
	
	return 0;
}

