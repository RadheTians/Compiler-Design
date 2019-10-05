package radhe;

import java.util.Scanner;

/**
 * 
 * @author radhetians
 * E->TE'
 * E'->+TE'|NULL
 * T->FT'
 * T'->*FT'|NULL
 * F->(E)|a
 */


public class RecursiveDescent {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String InputString;
		while(true) {
			Scanner input = new Scanner(System.in);
			System.out.println("Enter the input String :== ");
			InputString = input.nextLine();
			new RD(InputString);
		}
	}
	
	private static class RD{
		
		private char lookahead='$';
		private String InputString="a*a+a$";
		private int len=0;
		
		RD(String InputString){
			this.InputString = InputString;
			Match();
			E();
			if(lookahead == '$') 
				System.out.println("Accept");
				
			else 
				System.out.println("Error");
		}

		void Match() {
			lookahead = InputString.charAt(len++);
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
			} else
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
			} else 
				return;
			
		}
		void F() {
			if(lookahead == '(') {
				Match();
				E();
				if(lookahead == ')') 
					Match();
			} else 
				Match();
		}
	}
}

