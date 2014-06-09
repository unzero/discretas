#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

ifstream fin("confg.txt");
ofstream fout("input.txt");
#define cin fin
#define cout fout

vector<vector<char> > encode_matrix;


int main(){
	for(int x=0;x<100000;++x){}
	/*PLANTA LA SEMILLA PARA LA GENERACION DE NUMEROS ALEATORIOS*/
	
	string line;
	int n;
	/*LECTURA DE LA CONFIGURACION INICIAL DEL PROGRAMA*/
	ifstream confg("confg.txt");
	confg>>n;
	getline(confg,line);
	getline(confg,line);
	for(int x=0;x<n;++x){
		vector<char> new_vector;
		encode_matrix.push_back(new_vector);
		getline(confg,line);
		for(int i=0;i<n;++i){
			encode_matrix[x].push_back(line[i]);
		}
	}
	srand(time(NULL));
	unsigned long long longt = rand()%2000+1;
	for(unsigned long long x=0;x<longt;++x){
	    cout<<encode_matrix[rand()%n][rand()%n];
	}
	cout<<endl;
	  
}
