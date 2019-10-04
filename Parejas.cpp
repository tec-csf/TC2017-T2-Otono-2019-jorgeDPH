//Algoritmo de https://www.geeksforgeeks.org/stable-marriage-problem/ 

#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  
// Number of Men or Women 
#define N  4 
  
// comprobar las preferencias de cada quien
bool preferencias(int prefer[2*N][N], int w, int m, int m1) 
{ 
// Checa si esta disponible o no
	for (int i = 0; i < N; i++) 
	{ 

		if (prefer[w][i] == m1) 
			return true; 

		if (prefer[w][i] == m) 
		return false; 
	} 
} 

void parejasEstables(int prefer[2*N][N]) { 

//tabla de las parejas 
	int pareja[N]; 
	bool mFree[N]; 

	// Libera los arreglos para que esten vacios 
	memset(pareja, -1, sizeof(pareja)); 
	memset(mFree, false, sizeof(mFree)); 
	int contadorOlteros = N; 
  
//	Minetras haya hombres disponibles los empareja con una mujer según la tabla de preferencias que se forma anteriormente 
	while (contadorOlteros > 0) { 
		int m; 
		for (m = 0; m < N; m++) 
			if (mFree[m] == false) 
				break; 
  

		for (int i = 0; i < N && mFree[m] == false; i++) { 
			int w = prefer[m][i]; 
  

			if (pareja[w-N] == -1) { 
				pareja[w-N] = m; 
				mFree[m] = true; 
				contadorOlteros--; 
			} 
  
			else { 
	
				int m1 = pareja[w-N]; 
  
				
				if (preferencias(prefer, w, m, m1) == false) { 
					pareja[w-N] = m; 
					mFree[m] = true; 
					mFree[m1] = false; 
				} 
			} // End of Else 
		} // End of the for loop 
	} // End of main while loop 
  
  
	// Imprimir la solución
	cout << "Mujer   Hombre" << endl; 
	for (int i = 0; i < N; i++) 
	   cout << " " << i+N << "\t" << pareja[i] << endl; 
} 

int main() 
{ 
	int prefer[2*N][N] = { {7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
	}; 
	parejasEstables(prefer); 
  
	return 0; 
}