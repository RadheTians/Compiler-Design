%{
#include<stdio.h>
void yyerror(char*);
int yylex(void);
FILE* yyin;
%}

%token NOUN PRONOUN VERB 

%%
sentence: subject VERB object	{ printf("Sentence is valid\n");return 0;}
		| ;
subject: NOUN|PRONOUN;
object: NOUN;
%%
void yyerror(char *s)
{
    printf("Invalid Sentence!!\n");
}

int main()
{	
    int i,count=0;
	char c;
	yyin=fopen("abc.txt","r");
	for (c = getc(yyin); c != EOF; c = getc(yyin)) 
		if (c == '\n')
			count = count + 1;
	fclose(yyin);
	yyin=fopen("abc.txt","r");
	for(i=0;i<count;i++){
		yyparse();
	}
	return 0;
}