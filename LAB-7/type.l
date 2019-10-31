
%{ 
#include<stdio.h> 
#include<string.h> 
#include<ctype.h>
int i;
%} 

%% 

%% 

int yywrap(void){} 

int main() 
{ 
	yylex(); 

	return 0; 
} 
