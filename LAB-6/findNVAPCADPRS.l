%{
#include<stdio.h> 
#include<string.h>
%}
%%
[$] {return 0;}
[\t ]+ 
Mukul |
Radhe |
Rajeev |
Car	{ printf("%s	: is Noun\n", yytext); }                     

Play |
Eat |
Write |
Dance |
Sing  |
run |
do |
walk       { printf("%s	: is Verb\n", yytext); }

very |
simply |
lonely    { printf("%s	: is Adverb\n", yytext); }

to |
from |
behind |
of |
for |
between |
below     { printf("%s	: is Preposition\n", yytext); }

if |
then |
and |
but |
or       { printf("%s	: is Conjunction\n", yytext); }

their |
my |
your |
his |
her |
its      { printf("%s	: is Adjective\n", yytext); }

I |
you |
he |
she  |
we  |
they |
it      { printf("%s	: is Pronoun\n", yytext); }


[a-zA-Z]+ {
       printf("%s	: Something Else\n", yytext);
      }
.|\n        { ECHO;}

%%
int yywrap(void){}
int main()
{
     yylex();
}
