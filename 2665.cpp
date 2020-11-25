#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

struct ponto{
	int x, y;

	double A, B; // arcocosseno do angulo A e B

};

void OrdenaPontos(ponto* Ordena, int n) // ordena os pontos de acordo com o angulo B
{
   int i, j;
   struct ponto aux;
   
   for (j=n-1; j>0; j--){
        for (i=0; i<j; i++){
            if (Ordena[i].B > Ordena[i+1].B){                            
                aux = Ordena[i];
                Ordena[i] = Ordena[i+1];
                Ordena[i+1] = aux;             
            }
        }
    }
}

int main(){
	int n, xa, xb, i, k, j;

	cin >> n >> xa >> xb;

	ponto pontos[n];

	double T[n+1], O[n+1], B[n+1];

	for(i=1; i<=n; i++){
		cin >> pontos[i].x >> pontos[i].y;

		pontos[i].A = acos((pontos[i].x - xa)/hypot(pontos[i].y, pontos[i].x-xa));
		pontos[i].B = acos((xb - pontos[i].x)/hypot(pontos[i].y, pontos[i].x-xb));
	
	}

	OrdenaPontos(pontos, n); // ordenando a estrutura



	//algoritmo SCM do slide

	k=1;
	T[1] = pontos[1].A;
	O[1] = 1;

	for(i=2; i<=n; i++){
		if(pontos[i].A > T[k]){
			k=k+1; 
			T[k]=pontos[i].A;
			O[i]=k;
		}
		else{
			j = lower_bound(T+1, T+k, pontos[i].A)-T;
			T[j] = pontos[i].A;
			O[i] = j;
		}
	}

	cout << k << endl; // imprimindo o tamanho da SCM

	return 0;
}