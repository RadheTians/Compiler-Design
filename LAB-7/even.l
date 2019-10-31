
%{ 
#include<stdio.h> 
#include<string.h> 
#include<ctype.h>
int i;
%} 

%% 
[0-9]+		{i = atoi(yytext);
		if(isdigit (yytext)){

			if(i%2==0){
				printf("Even");
			}else{
				printf("Odd");
			}

		}else{
			printf("You need to write only Int.");
		}

	} 
%% 

int yywrap(void){} 

int main() 
{ 
	yylex(); 

	return 0; 
} 
