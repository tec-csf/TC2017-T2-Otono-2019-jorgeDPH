#include <iostream>
#include <ctime> 

using namespace std;

//algoritmo de ordenamiento sacado de: https://www.geeksforgeeks.org/merge-sort/


void merge(int arreglo[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 
  
	int L[n1], R[n2]; 
  
	for (i = 0; i < n1; i++) 
		L[i] = arreglo[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arreglo[m + 1+ j]; 
  
	i = 0; 
	j = 0;
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arreglo[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arreglo[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arreglo[k] = L[i]; 
		i++; 
		k++; 
	} 
  

	while (j < n2) 
	{ 
		arreglo[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
  

void OrdMerg(int arreglo[], int l, int r) 
{ 
	if (l < r) 
	{ 

		int m = l+(r-l)/2; 
  

		OrdMerg(arreglo, l, m); 
		OrdMerg(arreglo, m+1, r); 
  
		merge(arreglo, l, m, r); 
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
		OrdMerg(arreglo,0,n-1);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
		

}