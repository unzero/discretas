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
		-output.txt (ARCHIVO DE ENTRADA PARA EL PROGRAMA)
	EL ARCHVIO input.txt DEBE SER DADO POR EL USUARIO. ESTE ARCHIVO REPRESENTA LA SALIDA DEL PROGRAMA "SCF"
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

ifstream fin("output.txt");
ofstream fout("result.txt");
#define cin fin
#define cout fout

/*ESTRUCTURAS DEL PROGRAMA*/
struct encode_struct{
	char mu;
	int varphi;
};
vector<vector<char> > encode_matrix;
map<char,pair<int,int> > encode_index;
vector<encode_struct> encode_message;
int n;

/*FIRMA DE LOS METODOS*/
void print();
char decode_function(char alpha,int varphi,int rho);
pair<int,int> decoding (int x,int y, int cont, int iter);


int main(){

	/*LECTURA DE LA MATRIZ DE CIFRADO*/
	string line;
	cin>>n;
	getline(cin,line);
	for(int x=0;x<n;++x){
		vector<char> new_vector;
		getline(cin,line);
		for(int i=0;i<n;++i){
			new_vector.push_back(line[i]);
			encode_index[line[i]] = make_pair(x,i);
		}
		encode_matrix.push_back(new_vector);
	}

	/*LECTURA DEL MENSAJE*/
	while(getline(cin,line)){
		int cnt = 1;
		for(int x=0;x<line.size();x+=2,++cnt){
			encode_struct character;
			if(cnt%2==1){
				character.mu = line[x];
				pair<int,int> index = encode_index[line[x+1]];
				character.varphi = index.first*n + index.second;
			}else{
				pair<int,int> index = encode_index[line[x]];
				character.mu = line[x+1];
				character.varphi = index.first*n + index.second;
			}
			encode_message.push_back(character);
		}
	}
	if(encode_message.size()==0){
		puts("ERROR!, NO HAY MENSAJE DE ENTRADA");
		return -1;
	}
	print();

	/*DESDE ACA PUEDEN USAR EL PROGRAMA*/
	/*EL MENSAJE LO ENCUENTRAN EN LA ESTRUCTURA encode_message YA ESTA EN FORMA NATURAL
	 *POR MEDIO DE LA ESTRUCTURA encode_struct DONDE PUEDEN ACCEDER DIRECTAMENTE AL mu Y varphi.
	 */
	
	return 0;
}

void print(){

	for(int x=0;x<encode_message.size();++x){
		//cout<<encode_message[x].mu<<":"<<encode_message[x].varphi<<endl;
		cout<<decode_function(encode_message[x].mu,0,encode_message[x].varphi);
        //encode_character.mu = encode_function(original_message.text[i][j],0,encode_character.varphi);

	}
}



char decode_function(char alpha,int varphi,int rho){
	/*POSICION ACTUAL DEL CARACTER A CIFRAR*/
	int x= encode_index[alpha].first;
	int y= encode_index[alpha].second;

	/*CALCULO DE LA NUEVA POSICION*/
	pair<int,int> nuevaPos = decoding(x,y, varphi, rho);
	int newX = nuevaPos.first;
	int newY = nuevaPos.second;

	/*SE GENERA EL NUEVO CARACTER*/
	return encode_matrix[newX][newY];
}


pair<int,int> decoding (int x,int y, int cont, int iter){
	if(cont==iter){
		return make_pair(x,y);
	}
	switch (x){
		case 0:
		x = 0;
		break;
		case 1:
		x = 2;
		break;
		case 2:
		x = 4;
		break;
		case 3:
		x = 6;
		break;
		case 4:
		x = 1;
		break;
		case 5:
		x = 3;
		break;
		case 6:
		x = 8;
		break;
		case 7:
		x = 5;
		break;
		case 8:
		x = 7;
		break;
	}

		switch (y){
		case 0:
		y = 0;
		break;
		case 1:
		y = 2;
		break;
		case 2:
		y = 4;
		break;
		case 3:
		y = 6;
		break;
		case 4:
		y = 1;
		break;
		case 5:
		y = 3;
		break;
		case 6:
		y = 8;
		break;
		case 7:
		y = 5;
		break;
		case 8:
		y = 7;
		break;
	}
	
	decoding(x,y,cont+1,iter);
}
