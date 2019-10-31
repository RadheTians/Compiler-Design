%{ 
/* Definition section */
#include<stdio.h> 
int flag=0; 
%} 

%token id

%left '+' 

%left '-' 

%% 

ArithmeticExpression: E{ 

		printf("\nResult=%d\n", $$); 

		return 0; 

		}; 
E:E'+'E {$$=$1+$3;} 

|E'-'E {$$=$1-$3;} 

| id {$$=$1;} 

; 

%% 


void main() 
{ 
printf("\nEnter Any Arithmetic Expression :\n"); 

yyparse(); 
if(flag==0) 
printf("\nEntered arithmetic expression is Valid\n\n"); 
} 

void yyerror() 
{ 
printf("\nEntered arithmetic expression is Invalid\n\n"); 
flag=1; 
} 
