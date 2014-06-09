#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

ifstream fin("alpha.txt");
ofstream fout("input.txt");
#define cin fin
#define cout fout

int main(){
	string line;
	while(getline(cin,line));
	next_permutation(line.begin(),line.end());
	cout<<line;
	return 0;
}
