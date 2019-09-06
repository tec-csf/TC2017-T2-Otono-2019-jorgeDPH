#include <iostream>
#include <ctime> 

//algoritmo de ordenamiento sacado de: https://stackoverflow.com/questions/9317248/writing-bucket-sort-in-c

using namespace std;

void BucketOrd(int arreglo[], int n) {
	const int max = n;
	
	int bucket[10][max+1];

	for(int x=0;x<10;x++) bucket[x][max] = 0;

	for(int digit = 1; digit <= 1000000000; digit *= 10) {

		for(int i = 0; i < max; i++) {
	
			int dig = (arreglo[i] / digit) % 10;
	
			bucket[dig][bucket[dig][max]++] = arreglo[i];
		}

		int idx = 0;
		for(int x = 0; x < 10; x++) {
			for(int y = 0; y < bucket[x][max]; y++) {
				arreglo[idx++] = bucket[x][y];
			}

			bucket[x][max] = 0;
		}
	}
}



//Parte es para imprimir el arreglo y ver si funciona el algoritmo 
	void imprimir(int arreglo[], int n) { 
	for (int a=0; a<n; a++) 
		cout << arreglo[a] << " "; 
} 

int main(int argc, char *argv[]) {


	int n = 100;
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
		BucketOrd(arreglo,n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
	imprimir(arreglo, n); //imprime el arreglo ya ordenado
		
}