// Algoritmo de: https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include <iostream>
#include<string.h> 

using namespace std;

int SubM(char *x, char *y, int m, int n) { 
	// Crea la tabla con los valores de longitud

	int tabla[m+1][n+1]; 
	int resultado = 0;  // guarda la longitud del substring más grande

	for (int i=0; i<=m; i++) { 
		for (int j=0; j<=n; j++) { 

			if (i == 0 || j == 0) 
				tabla[i][j] = 0; 

			else if (x[i-1] == y[j-1]) { 
				tabla[i][j] = tabla[i-1][j-1] + 1; 
				resultado = max(resultado, tabla[i][j]); 
			} 
			else tabla[i][j] = 0; 
		} 
	} 
	return resultado; 
} 


int main() {
	
	char x[] = "zxabcdezy";
	char y[] = "yzabcdezx";
	
	/*cout<<"Dame el string x"<<endl;
	cin>>x;
	
	cout<<"Dame el string y"<<endl;
	cin>>y;*/

	int m = strlen(x); 
	int n = strlen(y); 
	
	cout << "La longitud del substring más grande es de: " << SubM(x, y, m, n); 
	return 0; 
	
}