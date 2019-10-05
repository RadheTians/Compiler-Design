package radhe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Vector;

public class laxical {
	public static void main(String arg[]){
		String line;
		int l=1;
		
		try {
			BufferedReader br = new BufferedReader( new FileReader("/home/radhetians/Desktop/Compiler-Lab/LAB-1/C++/" + "/fibonacci.cpp"));
			while( (line = br.readLine()) != null){
				System.out.println("--------------------LINE------------------ : " + l);
				System.out.println();
				
				System.out.println("-----------KEYWORDS-----------");
				for(String temp : keyword(line))
					System.out.print(temp+"  ");
				System.out.println();
				
				System.out.println("-----------OPERATORS-----------");
				for(String temp : operator(line))
					System.out.print(temp+"  ");
				System.out.println();
				
				System.out.println("-----------DELIMITER-----------");
				for(String temp : delimiter(line))
					System.out.print(temp+"  ");
				System.out.println();
				
				l++;
				 
		    }
		}catch(Exception e) {
			System.out.println(e);
		}
		
		
	}
	
	public static Vector<String> keyword(String s) {
		
		Vector<String> temp = new Vector<String>();
		String keys[] = {"asm","else","new","this","auto","enum","operator","throw","bool",
				"explicit","private","true","break","export","protected","try",
				"case","extern","public","typedef","catch","false","register",
				"typeid","char","float","reinterpret_cast","typename","class",
				"for","return","union","const","friend","short","unsigned",
				"const_cast","goto","signed","using","continue","if","sizeof",
				"virtual","default","inline","static","void","delete","int",
				"static_cast","volatile","do","long","struct","wchar_t",
				"double","mutable","switch","while","dynamic_cast",
				"namespace","template","include","iostream","std","printf"};
		for(String key:keys) {
			if(s.contains(key)) {
				temp.add(key);
				
			}
			
		}
		return temp;
	}
	
	public static Vector<String> operator(String s) {
		
		Vector<String> temp = new Vector<String>();
		String keys[] = {"+", "-", "*", "/", "%", "=", "++",
							"--", "==", "+=", "-=", "*=", "/=", "!=", ">",
							"<", ">=", "<=", "&&","||","!","<<",">>","&",
							"^","|","%=","&=","^=","|=",",","?","?:"};
		for(String key:keys) {
			if(s.contains(key)) {
				temp.add(key);
				
			}
			
		}
		return temp;
	}

	public static Vector<String> delimiter(String s) {
	
		Vector<String> temp = new Vector<String>();
		String keys[]= {";",")","(","}","{","]","[","'"};
		for(String key:keys) {
			if(s.contains(key)) {
				temp.add(key);
			
			}
		
		}
		return temp;
	}


}
