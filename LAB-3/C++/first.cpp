#include<iostream>
#include<vector>
//#include <boost/algorithm/string.hpp>
#include <set>
using namespace std;

vector<string> operators(string s, std::vector<string> v){

	vector<string> temp;
	for(int i=0;i<v.size();i++){
		if(v[i].find(s) !=-1)
			temp.push_back(v[i].substr(v[i].find(s)+2));

	}
	return temp;

}




void First(){
  int n,flag=0;
  string x;
  std::vector<string> v,T,r;
  set <string> NT;
  std::cout << " Enter the number of productions := ";
  std::cin >> n;
  std::cout << " <<==: Enter the Productions :==>> " << endl;
  for (int i=0;i<n;i++) {
    std::cin >> x;
    v.push_back(x);
  }




  for (int i=0;i<n;i++) {
      NT.insert(v[i].substr(0, v[i].find("->")));
      //T.push_back(v[i].substr(v[i].find("->")+2));

  }
  for (auto it = NT.begin(); it != NT.end(); it++){
    std::vector<string> result;
    result = operators(*it,v);
    std::cout << *it << " == : ";
    for (auto its = result.begin(); its != result.end(); its++){
      x = *its;
      for(int i=0;i<x.size();i++){
        if(isupper(x[i])){
          flag = 1;
          std::vector<string> results;
          results = operators(x[i]+"\0",v);
          for (auto itss = results.begin(); itss != results.end(); itss++){
            //string xs = *itss;
            cout << " " << *itss;
          }
        }
        if(flag == 0)
        cout << " " << x;
      }
    }
    cout <<endl;
  }







}

int main(){
  First();
  return 0;
}
