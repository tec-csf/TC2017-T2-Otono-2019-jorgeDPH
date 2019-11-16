// Compilar usando: gcc-9 -fopenmp numeros.c por la librería omp 


#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	int n = 1000000;
	int suma = 0;
	int i;
	int suma_local = 0;

	int numeros[n];

	for (i = 0; i < n; i++)
	{
		numeros[i] = 1;
	}
#pragma omp parallel private(i)
	{
		int numH = omp_get_num_threads();
		int tid = omp_get_thread_num();
		
	
		for (i = 0; i < n; i++)
		#pragma omp critical
		{
			suma += numeros[i];
		}
		printf("Soy el hilo %d de %d\n", tid + 1, numH);
	}

	printf("La suma es %d\n", suma);

	return 0;
}
