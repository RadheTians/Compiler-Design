#include<iostream>
using namespace std;

/**
 *
 * @author radhetians
 * E->TE'
 * E'->+TE'|NULL
 * T->FT'
 * T'->*FT'|NULL
 * F->(E)|a
 */
class RecursiveDescent{
  private :
    string inputString;
    char lookahead;
    int length;
    int len = 0;

  public :
    RecursiveDescent(string inputString ){
      this->inputString = inputString;
      this->length = inputString.length();
      Match();
      E();
      if(lookahead == '$')
        std::cout << "Accept" << endl;
      else
        std::cout << "Error" << endl;
    }

    void Match() {
      lookahead = inputString[len++];
    }
    void E() {
      T();
		  EDS();
    }
    void EDS() {
  		if(lookahead == '+') {
  			Match();
  			T();
  			EDS();
  		}
  		else
  			return;
    }
    void T() {
      F();
		  TDS();
    }
    void TDS() {
      if(lookahead == '*') {
  			Match();
  			F();
  			TDS();
		  }
		  else
			   return;
    }
    void F() {
      if(lookahead == '(') {
        Match();
  			E();
  			if(lookahead == ')') {
  				Match();
  			}
		  }
		  else
				  Match();
    }
};

int main() {
   string inputString;
   while (true) {
   cout << "Enter the Input String ::==  ";
   cin >> inputString;
   new RecursiveDescent(inputString);
 }
   return 0;
 }
