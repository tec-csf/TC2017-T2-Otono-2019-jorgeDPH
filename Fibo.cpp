#include <iostream>

using namespace std;

int FibRecu(int n){
	
	if(n==0 || n==1){
		return 1;
	}
	
	else 
	return FibRecu(n-1)+FibRecu(n-2);
}

int FiboItera(int n){
	int suma, x ,y;
	
	if(n<=1) return 1;
	
	else {
		x = 1;
		y = 1;
		
		for(int i = 2; i < n; ++i){
			suma = x+y;
			y = x;
			x = suma;
		}
		cout<<"Rsultado: "<<suma<<endl;

		return suma;
	}
}
int main(int argc, char *argv[]) {
	
	int n = 10;
	unsigned t0,t1;
	t0 = clock();
		
//	FibRecu(n);
	FiboItera(n);
	
	t1 = clock();
	double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
	cout<< "Tiempo en segundos: "<<tiempo<<endl; 
	cout << " " << " " ;

	
}