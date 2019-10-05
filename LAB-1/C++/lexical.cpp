#include<iostream>
#include<fstream>
#include "keywords.h"
#include "operators.h"
#include "delimiter.h"
#include<vector> 

using namespace std;

int main(){

	string line;
	ifstream file;
	int l=1;
	
	file.open("fibonacci.cpp"); 	
	while(file){ 
       	
		cout << " -------------------LINE------------------ : " << l << endl << endl;
		
		getline(file,line); 
		

		cout << " ----------KEYWORDS------ " << endl;
		vector<string> g1 = keyword(line);
		for (auto i = g1.begin(); i != g1.end(); ++i) 
        		cout << *i << " ";
		cout << endl;  


		cout << " ----------OPERATORS------ " << endl;
		vector<string> g2 = operators(line);
		for (auto i = g2.begin(); i != g2.end(); ++i) 
        		cout << *i << " ";
		cout << endl;


		cout << " ----------DELIMITERS------ " << endl;
		vector<string> g3 = delimiter(line);
		for (auto i = g3.begin(); i != g3.end(); ++i) 
        		cout << *i << " ";
		cout << endl << endl; 
		l++;
  
        }
	file.close();
	return 0;
}
