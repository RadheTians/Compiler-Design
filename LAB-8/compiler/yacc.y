%{
/*
 * A lexer for the basic grammar to use for recognizing English sentences.
 */
#include <stdio.h>
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence: subject VERB object{ printf("Sentence is valid.\n"); return 0;}
      ;

subject:    NOUN
      |     PRONOUN
      ;

object:          NOUN

      ;
%%

extern FILE *yyin;

int main()
{
    yyin=fopen("abc.txt","r");
     while (!feof(yyin)){
         yyparse();
     }
     fclose(yyin);
     return 0;
}

yyerror(s)
char *s;
{
    fprintf(stderr, "%s\n", s);
}