#include<iostream>
using namespace std;
int main(){

	int a=0,b=1,t,n;
	
	cout << "Enter Number of terms that you want :== " ;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cout << " " << a;
		t = a + b;
		a = b;
		b = t;
	} 
	return 0;
}
