
#include <iostream>
#include <vector>

using namespace std;

bool DevolverCambio(int P, const vector<int>& C, vector<int>& X) {
	int act = 0;
	int j = C.size() - 1;
	
	for (int i = 0; i < X.size(); i++) {
		X[i] = 0;
	}
	
	while (act != P) {
		while (C[j] > (P - act) && j > 0) {
			j--;
		}
		
		if (j == 0 && C[j] > (P - act)) {
			return false;
		}
		
		X[j] = (P - act) / C[j];
		act += C[j] * X[j];
	}
	
	return true;
}

int main() {
	int P = 21;
	vector<int> C = {1, 2, 5, 10, 20, 50, 100, 200};
	vector<int> X(C.size());
	
	if (DevolverCambio(P, C, X)) {
		cout << "Cambio devuelto:" << endl;
		for (int i = 0; i < X.size(); i++) {
			if (X[i] > 0) {
				cout << C[i] << " x " << X[i] << endl;
			}
		}
	} else {
		cout << "No existe solución" << endl;
	}
	
	return 0;
}
