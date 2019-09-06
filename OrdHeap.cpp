#include <iostream>
#include <ctime> 

//algoritmo de ordenamiento sacado de: https://www.geeksforgeeks.org


using namespace std;

void heapify(int arreglo[], int n, int i) 
{ 
	int largest = i;  
	int l = 2*i + 1; 
	int r = 2*i + 2; 
  
	if (l < n && arreglo[l] > arreglo[largest]) 
		largest = l; 
  
	if (r < n && arreglo[r] > arreglo[largest]) 
		largest = r; 
  
	if (largest != i) 
	{ 
		swap(arreglo[i], arreglo[largest]); 
  
		heapify(arreglo, n, largest); 
	} 
} 
  
void OrdHeap(int arreglo[], int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arreglo, n, i); 
  
	for (int i=n-1; i>=0; i--) 
	{ 
		swap(arreglo[0], arreglo[i]); 
  
		heapify(arreglo, i, 0); 
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
	
		unsigned t0,t1;
		t0 = clock();
		OrdHeap(arreglo,n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
		

}