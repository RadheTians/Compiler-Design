%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
[\t ] ;
is|am|are|were|was|be|being|been|do|does|did|will|would|should|can|could|has|have|had|go { printf("VERB\t : %s\n",yytext);return (VERB);}
I|he|she|we|they|you|this {printf("PRONOUN\t : %s\n",yytext);return (PRONOUN);}
[a-zA-Z]+ {printf("NOUN\t : %s\n",yytext);return (NOUN);}
[.|\n]	{ ECHO;}
%%
int yywrap()
{
return 1;
}