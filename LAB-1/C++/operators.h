#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<string> operators(string s){

	vector<string> temp;
	string keys[]= {"+", "-", "*", "/", "%", "=", "++",
				"--", "==", "+=", "-=", "*=", 
				"/=", "!=", ">","<", ">=", "<=", "&&","||","!","<<",">>","&","^","|","%=","&=","^=","|=",",","?","?:"};
	int rows = sizeof(keys)/sizeof(keys[0]);
	for(int i=0;i<rows;i++){
		if(s.find(keys[i]) !=-1)
			temp.push_back(keys[i]); 
	
	}
	return temp;
		
}
