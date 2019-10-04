#include <iostream> 
using namespace std; 

int Stops(int N, int K, int M, int compulsory[]) {
	
//	esta parte del código lo que hace es comparar los km y las distancias para ver si es necesario poener gasolina 
	
	int contador = 0; 
	int i = 0; 
	int recorridokm = 0; 

	while (recorridokm < N) { 
		
		if (i < M && compulsory[i] <= (recorridokm + K)) { 
			recorridokm = compulsory[i]; 
			i++; 
			
		} else{
			recorridokm += K; 
		}
			
 
		if (recorridokm < N){
			
			contador++; 
		}
	} 

	return contador; 
} 


int main() { 
	
	int km; 
	int tanque; 
	int gasolineras; 
	int p;
	
	cout << "Distancia total: "<<endl;
	cin >> km;
	
	cout << "Capacidad del tanque" <<endl;
	cin >> tanque;
	
	int gas[8];

	cout << "Insertar en orden de el km de las gasolineras " <<endl;
	
	for (int i = 0; i<8; i++) {

		cout << "Gasolinera: " << i << endl;
		cin >> gasolineras;
		gas[i] = gasolineras;
		
	}
//	el resultado que imprime es la cantidad mínima que se tiene que parar.  
	cout << "Número de paradas mínimas necesarias:"<<Stops(km, tanque, p, gas)<<endl;
	return 0;
} 