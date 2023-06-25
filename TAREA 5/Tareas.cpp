#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;

struct Tarea
{
	int id;
	int beneficio;
	int duracion;
};

bool compararPorBeneficio(const Tarea & tarea1, const Tarea & tarea2) {
	return tarea1.beneficio > tarea2.beneficio;
}

template<size_t Size>
	void inicializarTareas(array<Tarea, Size> & tareas, array<Tarea, Size> & candidatos) {
	sort(tareas.begin(), tareas.end(), compararPorBeneficio);
	int i = 0;
	for (const auto& tarea : tareas) {
		candidatos[i++] = tarea;
	}
}
	
	bool puedeSerSeleccionada(int id, vector<int> & tareasSeleccionadas) {
		for(int tareaId : tareasSeleccionadas) {
			if(id == tareaId) return false;
		}
		return true;
	}
	
	template<size_t Size>
		Tarea * buscarTareaFactible(int tiempo, array<Tarea, Size> & candidatos, vector<int> & tareasSeleccionadas, bool ordenProgresivo = true) {
		for(Tarea & candidato : candidatos) {
			if(!ordenProgresivo) {
				if(candidato.duracion == tiempo &&
				   puedeSerSeleccionada(candidato.id, tareasSeleccionadas)
				   ) {
					tareasSeleccionadas.push_back(candidato.id);
					return &candidato; 
				}
			} else {
				if(candidato.duracion >= tiempo &&
				   puedeSerSeleccionada(candidato.id, tareasSeleccionadas)
				   ) {
					tareasSeleccionadas.push_back(candidato.id);
					return &candidato; 
				}
			}
		}
		return nullptr;
	}
		
		template<size_t Size>
			void algoritmoMochila(vector<Tarea> & resultado, array<Tarea, Size> & candidatos, int n) {
			int tiempo = 1;
			vector<int> tareasSeleccionadas;
			
			while (tiempo <= n) {
				Tarea * tareaFactible = buscarTareaFactible(tiempo, candidatos, tareasSeleccionadas, false);
				if(tareaFactible) {
					if(resultado.size() == 0)
						resultado.push_back(*tareaFactible);
					else if(resultado.rbegin()->duracion <= tareaFactible->duracion)
						resultado.push_back(*tareaFactible);
				} 
				tiempo++;
			}
			
			tiempo = 1;
			if(resultado.size() < resultado.rbegin()->duracion) {
				while (tiempo <= n) {
					if(resultado.size() == resultado.rbegin()->duracion) break;
					Tarea * tareaFactible = buscarTareaFactible(tiempo, candidatos, tareasSeleccionadas, true);
					if(tareaFactible) {
						if(resultado.size() == 0)
							resultado.push_back(*tareaFactible);
						else if(resultado.rbegin()->duracion <= tareaFactible->duracion)
							resultado.push_back(*tareaFactible);
					} 
					tiempo++;
				}
			}
		}
			
			int main() {
				const size_t numTareas = 6;
				array<Tarea, numTareas> candidatos;
				
				array<Tarea, numTareas> tareas = {
					Tarea{1, 20, 3},
						Tarea{2, 15, 1},
						Tarea{3, 10, 1},
						Tarea{4, 7, 3},
						Tarea{5, 5, 1},
						Tarea{6, 3, 3}
				};
				
				vector<Tarea> resultado;
				inicializarTareas(tareas, candidatos);
				algoritmoMochila(resultado, candidatos, numTareas);
				
				for(Tarea & tarea : resultado) {
					std::cout << "id = " << tarea.id << " beneficio = " << tarea.beneficio << " duracion = " << tarea.duracion << endl;
				}
				
				return 0;
			}
			

