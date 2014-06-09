/*
	CODIGO FUENTE
	PROYECTO FINAL DE MATEMATICAS DISCRETAS II
	FRACTALES APLICADOS A LA CRIPTOGRAFIA
	
	PRESENTADO POR:
	CIRO IVAN GARCIA LOPEZ
	MANUEL ARTURO RAMIREZ PISCO
	DAVID RICARDO DAGER MORA

	PRESENTADO A:
	ANDRES VILLACES NIÑO

	BOGOTA JUNIO DE 2014
	
	ESTE PROGRAMA REQUIERE DE LA SIGUIENTE LISTA DE ARCHIVOS PARA SU CORRECTA EJECUCION
		-confg.txt (ARCHIVO DE CONFIGURACION DEL PROGRAMA)
		-input.txt (ARCHIVO DE ENTRADA PARA EL PROGRAMA)
	EL ARCHIVO confg ES DADO CON EL PRESENTE PROGRAMA SIN EMBARGO EL ARCHVIO input.txt
	DEBE SER DADO POR EL USUARIO
*/

/* LIBRERIAS QUE NECESITA EL PROGRAMA*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

/*REDIRECCIONAMIENTO DE FLUJO DEL PROGRAMA*/
ofstream fout("output.txt");
ifstream fin("input.txt");
#define cout fout
#define cin fin

#define mpi(table,it) for(map<char,pair<int,int> >::iterator it = table.begin();it!=table.end();++it)
#define fi(x,y) if(x>=9 || y>=9 || x<0 || y<0)puts("ERROR")

/*ESTRUCTURAS DE ALMECENAMIENTO TEMPORAL*/
struct encode_struct{
	char mu;
	int varphi;
};
struct message{
	vector<string> text;
	unsigned long long length;
}original_message;
vector<vector<char> > encode_matrix;
map <char,pair<int,int> > encode_index;
map<char,int> is_valid_character;
int n,g;
vector<int> lambda;
vector<int> sigma;
vector<encode_struct> encode_message;

/*FIRMAS DE LOS METODOS*/
void generate_encode_matrix();
void generate_baker_psi();
void generate_baker_keys();
pair<int,int> baker_map(int x,int y);
char encode_function(char alpha,int varphi,int rho);
pair<int,int> collatzFrac (int x,int y, int cont, int iter);
void print();

int main(){
  
	/*PLANTA LA SEMILLA PARA LA GENERACION DE NUMEROS ALEATORIOS*/
	srand((unsigned)time(NULL));
	string line;
	
	/*LECTURA DE LA CONFIGURACION INICIAL DEL PROGRAMA*/
	ifstream confg("confg.txt");
	confg>>n;
	getline(confg,line);
	confg>>g;
	getline(confg,line);
	int j = 32;
	for(int x=0;x<n;++x){
		vector<char> new_vector;
		encode_matrix.push_back(new_vector);
		getline(confg,line);
		for(int i=0;i<n;++i){
			encode_matrix[x].push_back(line[i]);
			encode_index[encode_matrix[x][i]] = make_pair(x,i);
			is_valid_character[encode_matrix[x][i]] = 100;
		}
	}	
	
	/*LECTURA DEL MENSAJE*/
	original_message.length = 0;
	original_message.text.clear();	
	while(getline(cin,line)){
		line = line +" ";
		original_message.text.push_back(line);
		original_message.length += line.size();
	}
	

	/*MANEJO DEL CASO EN EL CUAL NO HAY MENSAJE DE ENTRADA*/
	if(original_message.length == 0){
		puts("ERROR NO HAY MENSAJE DE ENTRADA");
		puts("PROGRAMA TERMINADO DE FORMA ANORMAL");
		return -1;
	}

	/*SE GENERA LA MARTRIZ DE CIFRADO PARA EL MENSAJE*/
	generate_encode_matrix();	
	 
	/*CIFRADO DEL MENSAJE*/
	for(int i=0;i<original_message.text.size();++i){
		for(int j=0;j<original_message.text[i].size();++j){
			encode_struct encode_character;
			encode_character.varphi = rand()%81;
			encode_character.mu = encode_function(original_message.text[i][j],0,encode_character.varphi);	
			encode_message.push_back(encode_character);
		}
	}
	
	/*IMPRESION FINAL DEL PROGRAMA*/
    	print();
	return 0;
}

/*
 * GENERA LA MATRIZ DE CIFRADO
 * PRIMERO NOS GENERA EL VALOR DE U
 * POR ULTIMO EVALUA B^{u}_{N,lambda}
 */
void generate_encode_matrix(){
	unsigned long long u = 0;
	unsigned long long ac = 0;
	for(int i=0;i<original_message.text.size();++i){
		for(int j=0;j<original_message.text[i].size();++j){
			++ac;
			u = (u + (original_message.text[i][j]*ac)%g)%original_message.length;
			ac = (ac%g);
		}
	}
	u = u%original_message.length + 5;
	for(int x=0;x<u;++x){
		generate_baker_psi();
	}
}

/**
*GENERA LAS LLAVES (CONJUNTO LAMBDA Y SIGMA) PARA LA TRANSFORMACION DE BAKER
*SE EVITAN GENERAR CONJUNTOS DE SOLO 1'S {1,1,1,...,1} O EL CONJUNTO {N}
*/
void generate_baker_keys(){
	do{
		sigma.clear();
		lambda.clear();	
		int ac = n;
		while(ac>0){
			int nx = (rand() % ac) + 1;
			if(n%nx == 0){
				lambda.push_back(nx);
				ac -= nx;
			}
		}	
		sigma.push_back(0);
		for(int x=0;x<lambda.size()-1;++x){
			sigma.push_back(sigma[x]+lambda[x]);
		}
	}while(lambda.size() == 0 || lambda[0]==n || lambda.size()==n);
}

/**
*EVALUA LA TRANSFORMACION DISCRETA DE BAKER SOBRE B_{N,LAMBDA}(X,Y)
*/
pair<int,int> baker_map(int x,int y){
	int xp,yp,index=0;
	while(!(sigma[index]<=y && y<sigma[index]+lambda[index]))index++;
	int qi = n/lambda[index];
	xp = n - sigma[index] - 1 - floor((n-x-1)/qi);
	yp = (qi)*(y-sigma[index]) + ((n-x-1)%qi);
	return make_pair(xp,yp);
}

/*
*APLICA LA TRANSFORMACION DE BAKER A LA MATRIZ
* -PRIMERO GENERA UN CONJUNTO DE LLAVES
* -APLICA B_{N,LAMBDA}(PSI)
* -ELIMINA LAS LLAVES USADAS
*/
void generate_baker_psi(){
	/*GENERADO DE LAS LLAVES PARA LA MATRIZ*/
	generate_baker_keys();
	
	/*SE GENERA UNA NUEVA MATRIZ, EN BLANCO*/
	vector<vector<char> > new_encode_matrix;
	for(int i=0;i<n;++i){
		vector<char> new_vector;
		new_encode_matrix.push_back(new_vector);
		for(int j=0;j<n;++j){
			new_encode_matrix[i].push_back(' ');
		}
	}
	
	/*SE EVALUA LA TRANSFORMACION DE BAKER Y UBICA EN LA NUEVA MATRIZ*/
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			pair<int,int> new_pos = baker_map(i,j);
			new_encode_matrix[new_pos.first][new_pos.second] = encode_matrix[i][j];
			encode_index[encode_matrix[i][j]] = make_pair(new_pos.first,new_pos.second);
		}
	}
	
	/*REMPLAZA LA ANTIGUA MATRIZ*/
	encode_matrix = new_encode_matrix;
	
	/*BORRADO DE LLAVES*/
	lambda.clear();
}

/*CIFRADO DEL CARACTER POR MEDIO DEL FRACTAL DE COLLATZ*/
char encode_function(char alpha,int varphi,int rho){
        /*VALIDACION QUE EL CARACTER SE ENCUENTRE DENTRO DE LOS SIMBOLOS ACEPTADOS*/
	if(is_valid_character[alpha]!=100){
	    puts("ERROR SE HA ENCONTRADO UN CARACTER INVALIDO");
	    throw "ERROR CARACTER INVALIDO";
	}
	/*POSICION ACTUAL DEL CARACTER A CIFRAR*/
	int x= encode_index[alpha].first;
	int y= encode_index[alpha].second;
	
	/*CALCULO DE LA NUEVA POSICION*/
	pair<int,int> nuevaPos = collatzFrac(x,y, varphi, rho);
	int newX = nuevaPos.first;
	int newY = nuevaPos.second;
	
	/*SE GENERA EL NUEVO CARACTER*/
	return encode_matrix[newX][newY];
}

/*EVALUACION DEL FRACTAL DE COLLATZ PARA LA POSICION ACUTAL*/
pair<int,int> collatzFrac (int x,int y, int cont, int iter){
	if(cont==iter){
		return make_pair(x%9,y%9);
	}
	
	if(x==3){x=10;}
	if(y==3){y=10;}
	if(x==7){x=16;}
	if(y==7){y=16;}
	if(x==8){x=12;}
	if(y==8){y=12;}

	if(x % 2 == 0 && y % 2 == 0){
		x=x/2;
		y=y/2;
	}else if(x % 2 != 0 && y % 2 == 0){
		x=(3*x)+1;
		y=y/2;
	}else if(x % 2 == 0 && y % 2 != 0){
		x=x/2;
		y=(3*y)+1;
	}else{
		x=(3*x)+1;
		y=(3*y)+1;
	}
	
	collatzFrac(x,y,cont+1,iter);
}


/**
*METODO ENCARGADO DE IMPRESION DE LA INFORMACION CIFRADA AL ARCHIVO OUTPUT.TXT
*
*/
void print(){

	/*IMPRESION DE LA MATRIZ DE CIFRADO*/
	cout<<n<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<encode_matrix[i][j];
		}
		cout<<endl;
	}
	
	/*IMPRESION DEL MENSAJE CIFRADO*/
	int ac = 0;
	for(int x=0;x<encode_message.size();++x){
		ac++;
		int i = encode_message[x].varphi/n;
		int j = encode_message[x].varphi%n;
		/*MANEJO DEL ORDEN DE IMPRESION*/
		if(ac%2==0){
			cout<<encode_matrix[i][j]<<encode_message[x].mu;
		}else{
			cout<<encode_message[x].mu<<encode_matrix[i][j];
		}
		if(ac==100){
			cout<<endl;
			ac = 0;
		}
	}
}


