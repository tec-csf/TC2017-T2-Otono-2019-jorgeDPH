
#include<stdio.h>
 
#define N 10
 
void mostrarLista(int*);
int main(int argc, char** argv){
 
	int arreglo[N]={23,12,4,56,31,8,12,24,1,10};
 
	int i,key,j;
 
   //Recorrer el arreglo
	for (i = 1; i < N; i++){
	   
		key = *(arreglo+i);
		j = i-1;
 
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 0 && *(arreglo+j) > key){
			//Insertar el valor donde corresponda
			*(arreglo+j+1) = *(arreglo+j);
			j = j-1;
		}
		*(arreglo+j+1) = key;
		mostrarLista(arreglo);
	} 
   
	mostrarLista(arreglo);
  
	return 0;
}
//Función para mostrar estado de la lista
void mostrarLista(int *lista){
	int i;
	for (i=0; i< N; i++){
		printf("%d ",*(lista+i));
	}
	printf("\n");;
   
}