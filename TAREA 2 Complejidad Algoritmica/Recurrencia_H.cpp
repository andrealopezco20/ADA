//una recurrencia homogénea se refiere a una relación de recurrencia 
//en la que todos los términos están definidos en función de términos anteriores sin ninguna influencia externa
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

