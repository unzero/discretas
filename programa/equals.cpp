#include<iostream>
#include<fstream>
#include<map>
#include<cmath>
#include<vector>
#include<cmath>
using namespace std;

ifstream fin("res.txt");
ofstream fout("resul.txt");
#define cin fin
#define cout fout

vector< vector< vector<char> > > matrix;

bool equals(vector<vector<char> > a, vector<vector<char> > b){
	for(int x=0;x<a.size();++x){
		for(int y=0;y<a[x].size();++y){
			if(a[x][y] != b[x][y] ) return false;
		}
	}
	return true;
}

int main(){
	ifstream confg("confg.txt");
	int n;
	confg>>n;
	string line;
	while(getline(cin,line)){
		vector<vector<char> > new_matrix;
		for(int x=0;x<n;++x){
			vector<char> new_vector;
			for(int y=0;y<n;++y){
				new_vector.push_back(line[y]);
			}
			new_matrix.push_back(new_vector);
			if(x!=n-1) getline(cin,line);
		}
		matrix.push_back(new_matrix);
	}
	
	map<vector<vector<char> >,int> times;
	for(int z=0;z<matrix.size();++z){
		times[matrix[z]]++;
	}
	cout<<"Se generaron: "<<times.size()<<endl;
	int z = 0;
	for(map<vector<vector<char> >,int>::iterator it = times.begin();it!=times.end();++it){
		cout<<"LA MATRIZ:"<<z++<<" SE REPITE: "<<it->second<<endl;
	}
	for(int z=0;z<matrix.size();++z){
		for(int x=0;x<matrix[z].size();++x){
			for(int y=0;y<matrix[z][x].size();++y){
				cout<<matrix[z][x][y]<<" ";
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	return 0;
}
