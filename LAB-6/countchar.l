%{ 
#include<stdio.h>
#include<string.h>  
int ch=0;
%} 

%% 
[$] {exit(0);}
. {ch++;}	 
"\n" {printf("%d\n", ch); ch = 0;} 
%% 

int yywrap(void){} 

int main() 
{ 
	
    yylex(); 
    return 0; 
} 
