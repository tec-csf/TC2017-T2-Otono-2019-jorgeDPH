#include <iostream>

using namespace std;

//algoritmo de ordenamiento sacado de: https://www.bogotobogo.com/Algorithms/countingsort.php 

void countSort(int arreglo[], int n) {
	int i, j, k;
	int idx = 0;
	int min, max;
 
	min = max = arreglo[0];
	for(i = 1; i < n; i++) {
		min = (arreglo[i] < min) ? arreglo[i] : min;
		max = (arreglo[i] > max) ? arreglo[i] : max;
	}
 
	k = max - min + 1;

	int *B = new int [k]; 
	for(i = 0; i < k; i++) B[i] = 0;

	for(i = 0; i < n; i++) B[arreglo[i] - min]++;
	for(i = min; i <= max; i++) 
		for(j = 0; j < B[i - min]; j++) arreglo[idx++] = i;
 

	delete [] B;
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
		countSort(arreglo,n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//	imprimir(arreglo, n); //imprime el arreglo ya ordenado
		
}