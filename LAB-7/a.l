%{ 
/* Definition section */
#include "y.tab.h" 
%} 

/* Rule Section */
%% 
[aA] {return A;} 
[bB] {return B;} 
\n {return NL;} 
. {return yytext[0];} 
%% 

int yywrap() 
{ 
return 1; 
} 
