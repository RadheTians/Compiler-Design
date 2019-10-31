%{
#include<stdio.h>
void yyerror(char*);
int yylex();
FILE* yyin;
%}

%token NOUN PRONOUN ADJECTIVE VERB ADVERB CONJUNCTION PREPOSITION

%%
sentence: subject VERB object{ printf("Sentence is valid.\n"); }
      ;

subject:    NOUN
      |     PRONOUN
      ;

object:          NOUN

      ;
%%
void yyerror(char *s)
{
printf("ERROR:%s",s);
}


const char* readLine(FILE *file) {

    if (file == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char *lineBuffer = (char *)malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL) {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);
    int count = 0;

    while ((ch != '\n') && (ch != EOF)) {
        if (count == maximumLineLength) {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
        count++;

        ch = getc(file);
    }

    lineBuffer[count] = '\0';
    char line[count + 1];
    strncpy(line, lineBuffer, (count + 1));
    free(lineBuffer);
    const char *constLine = line;
    return constLine;
}


int main()
{
yyin=fopen("test.txt", "r"); 
while (!feof(yyin)) {
  
    const char *line = readLine(yyin);
    printf("%s\n", line);
    yyparse();
}
fclose(yyin);
return 0;
}

