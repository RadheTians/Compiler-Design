#include<iostream>
#include<vector>
#include<boost>
using namespace std;

void Left_Recursion(){
  int n;
  string x;
  std::vector<string> v,r,result;
  std::cout << " Enter the number of productions := ";
  std::cin >> n;
  std::cout << " <<==: Enter the Productions :==>> " << endl;
  for (int i=0;i<n;i++) {
    std::cin >> x;
    v.push_back(x);
  }
  for (int i=0;i<n;i++) {
    if (v[i].find("|")!= -1) {
      boost::split(r, v[i], boost::is_any_of("->"));

    }else{
      result.push_back(v[i]);
    }
  }

}

int main(){
  Left_Recursion();
  return 0;
}
