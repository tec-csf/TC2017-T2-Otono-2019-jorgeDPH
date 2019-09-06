#include <iostream>
#include <ctime> 

//algoritmo de ordenamiento sacado de: https://www.geeksforgeeks.org/radix-sort/

using namespace std;
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 
  
 
void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 
  
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 
  

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 
  
 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
  

	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 


void radixsort(int arr[], int n) 
{ 
	int m = getMax(arr, n); 
 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
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
		radixsort(arreglo,n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
		

}