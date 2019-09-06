#include <iostream>
#include <ctime> 

using namespace std;

void InserOrd(int arreglo[], int n){
	
	int i = 0;
	int llave, j;
	
	for (i =1; i<n; i++) {
		llave = arreglo[i];  
		j = i - 1;  
		
		while (j>=0 && arreglo[j]>llave) {
			arreglo[j + 1] = arreglo[j];  
			j = j - 1;
		}
		
		arreglo[j + 1] = llave;
		
	}
}


//Parte es para imprimir el arreglo y ver si funciona el algoritmo 
	void imprimir(int arreglo[], int n) { 
	for (int a=0; a<n; a++) 
		cout << arreglo[a] << " "; 
} 




int main(int argc, char *argv[]) {
	
	int n = 10;
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
		InserOrd(arreglo, n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
}