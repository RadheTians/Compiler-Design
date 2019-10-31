%{ 
/* Definition section */
#include<stdio.h> 
#include<stdlib.h> 
%} 

%token E NL 

/* Rule Section */
%% 
stmt: E NL { printf("valid string\n"); 
			exit(0); } 
; 
E: E '+' E | 
   E '-' E |
   id
; 
%% 

int yyerror(char *msg) 
{ 
printf("invalid string\n"); 
exit(0); 
} 

//driver code 
main() 
{ 
printf("enter the string\n"); 
yyparse(); 
} 
