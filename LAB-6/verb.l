%{ 
#include<stdio.h>
#include<string.h>  
%} 

%% 
[$] {exit(0);}
[\t[a-zA-Z]]+;

play[a-zA-Z]| 
eat[a-zA-Z]| 
dance[a-zA-Z]| 
write[a-zA-Z]| 
sing[a-zA-Z]| 
run[a-zA-Z]| 
walk[a-zA-Z] {printf("\n%s : is verb",yytext);}
[a-zA-Z]+ {printf("\n%s :isn't verb",yytext);}

.|\n {ECHO;}
%% 

int yywrap(void){} 

int main() 
{ 	
    yylex(); 
    return 0; 
} 
