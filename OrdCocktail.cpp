#include <iostream>
#include <ctime> 

using namespace std;

//Método de algoritmo coktail 
void OrdCocktal(int arreglo[], int n){
	
	bool cambio = true;
	int inicio =0; 
	int final = n-1;
	
	while (cambio) {
		cambio = false;
		
		for(int i =0; i < final; i++ ){
			if(arreglo[i]>arreglo[i+1]){
				
				swap(arreglo[i], arreglo[i + 1]); 
				cambio = true; 
			}
		}
		
		if (!cambio) 
			break;
		
		cambio = false;
		
		--final; 
		
		for (int i = final - 1; i >= inicio; --i) {
			if (arreglo[i] > arreglo[i + 1]) {
				
				swap(arreglo[i], arreglo[i + 1]); 
				cambio = true;
			}
		}
		
		
	++ inicio; 
	}
}





//Parte es para imprimir el arreglo y ver si funciona el algoritmo 
	void imprimir(int arreglo[], int n) { 
	for (int a=0; a<n; a++) 
		cout << arreglo[a] << " "; 
} 

int main(int argc, char *argv[]) {
	
	int n = 1000000;
	int arreglo[n];
	
	//int random[n];


//esta parte genera valores aleatorios para llenar el arreglo dependiendo de n que es el tamaño del arreglo y lo llena entre valores de 1-10,100,10000... dependiedo del tamaño del arreglo
	srand((unsigned)time(NULL));

		for (int i = 0; i < n; i++) {

		arreglo[i] = 1 + rand() % n;
//	cout << arreglo[i] << " " ;//imprime el arreglo desordenado
		
	}
//	se cuenta el tiempo
		unsigned t0,t1;
		t0 = clock();
		OrdCocktal(arreglo, n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
}