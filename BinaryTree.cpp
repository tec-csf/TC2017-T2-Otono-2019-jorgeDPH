#include <iostream>
#include <ctime> 

//algoritmo de ordenamiento sacado de: https://www.geeksforgeeks.org/tree-sort/ 

using namespace std;


struct Node 
{ 
	int llave; 
	struct Node *izquierda, *derecha; 
}; 

struct Node *newNode(int item) 
{ 
	struct Node *temporal = new Node; 
	temporal->llave = item; 
	temporal->izquierda = temporal->derecha = NULL; 
	return temporal; 
} 

void storeSorted(Node *root, int arreglo[], int &i) 
{ 
	if (root != NULL) 
	{ 
		storeSorted(root->izquierda, arreglo, i); 
		arreglo[i++] = root->llave; 
		storeSorted(root->derecha, arreglo, i); 
	} 
} 
  

Node* insert(Node* node, int llave) 
{ 
	if (node == NULL) return newNode(llave); 
  
	if (llave < node->llave) 
		node->izquierda  = insert(node->izquierda, llave); 
	else if (llave > node->llave) 
		node->derecha = insert(node->derecha, llave); 
  
	return node; 
} 
  
void treeSort(int arreglo[], int n) 
{ 
	struct Node *root = NULL; 
  

	root = insert(root, arreglo[0]); 
	for (int i=1; i<n; i++) 
		insert(root, arreglo[i]); 
  
	int i = 0; 
	storeSorted(root, arreglo, i); 
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
		treeSort(arreglo,n);
		
		t1 = clock();
		double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<" "<<endl;
		cout<< "Tiempo en segundos: "<<tiempo<<endl; 
		cout << " " << " " ;
//		imprimir(arreglo, n); //imprime el arreglo ya ordenado
		

}