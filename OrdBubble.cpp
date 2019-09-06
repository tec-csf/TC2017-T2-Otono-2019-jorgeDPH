#include <iostream>
#include <ctime> 

using namespace std;

void swap(int *xpoi, int *ypoi){
	
	int temporal = *xpoi;
	*xpoi = *ypoi;
	*ypoi = temporal;
	
}

void BubbleSort(int arreglo[], int n){
	
	int a, b;
	
	for (a = 0; a < n-1; a++) {
		for(b = 0; b < n-a-1; b++)
		
		if (arreglo[b]>arreglo[b+1]) {
		swap(&arreglo[b], &arreglo[b+1]);  
		}
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
	
		unsigned t0,t1;
		t0 = clock();
		BubbleSort(arreglo, n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
}