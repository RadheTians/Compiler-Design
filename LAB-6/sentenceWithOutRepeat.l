%{
#include<stdio.h>
#include<string.h> 
char Something[100][100];
char verb[100][100];
char adverb[100][100];
char preposition[100][100];
char conjunction[100][100];
char adjective[100][100];
char pronoun[100][100];
int s=-1,v=-1,a=-1,p=-1,c=-1,ad=-1,pr=-1;
%}

%%
[$] {return 0;}
[\t ]+;
is |
am |
are |
were |
was |
be |
being |
been |
do |
does |
did |
will |
would |
should |
can |
could |
has |
have |
had |
Play |
playing |
played |
Eat |
ate |
eaten |
eating |
Write |
writing |
wrote |
written |
dance |
dancing |
danced |
sing  |
sang |
singing |
sung |
run |
running |
ran |
walk |
walking |
walked |
go |
going |
went |
gone      { 
            int flag = 0;
            for(int i=0;i<=v;i++){
                if(strcmp(verb[i],yytext)==0){
                    flag=1;
                    break;
                }       
            }
            if(flag==0)
                strcpy(verb[++v],yytext);
         }

very |
simply |
gently |
quietly |
calmly |
angrily {
            int flag = 0;
            for(int i=0;i<=a;i++){
                if(strcmp(adverb[i],yytext)==0){
                    flag=1;
                    break;
                }       
            }
            if(flag==0) 
                strcpy(adverb[++a],yytext); 
        }

to |
from |
behind |
above |
below |
between { 
            int flag = 0;
            for(int i=0;i<=p;i++){
                if(strcmp(preposition[i],yytext)==0){
                    flag=1;
                    break;
                }       
            }
            if(flag==0)
                strcpy(preposition[++p],yytext);
        }

if |
then |
and |
but |
or  { 
        int flag = 0;
        for(int i=0;i<=c;i++){
            if(strcmp(conjunction[i],yytext)==0){
                flag=1;
                break;
            }       
        }
        if(flag==0)
            strcpy(conjunction[++c],yytext); 
    }

their |
my |
your |
his |
her |
its     { 
            int flag = 0;
            for(int i=0;i<=ad;i++){
                if(strcmp(adjective[i],yytext)==0){
                    flag=1;
                    break;
                }       
            }
            if(flag==0)
                strcpy(adjective[++ad],yytext);
        }

I |
you |
he |
she  |
we  |
they    { 
            int flag = 0;
            for(int i=0;i<=pr;i++){
                if(strcmp(pronoun[i],yytext)==0){
                    flag=1;
                    break;
                }       
            }
            if(flag==0)
                strcpy(pronoun[++pr],yytext);
        }


[a-zA-Z]+   { 
                int flag = 0;
                for(int i=0;i<=s;i++){
                    if(strcmp(Something[i],yytext)==0){
                        flag=1;
                        break;
                    }       
                }
                if(flag==0)
                    strcpy(Something[++s],yytext);
                }

.|\n        { ECHO;}

%%

int yywrap(void){} 

int main() 
{ 	
    yylex(); 
    for(int i=0;i<=s;i++)
        printf("  %s :  Something\n", Something[i]);
    for(int i=0;i<=v;i++)
        printf("  %s :  verb\n", verb[i]);
    for(int i=0;i<=a;i++)
        printf("  %s :  adverb\n", adverb[i]);
    for(int i=0;i<=p;i++)
        printf("  %s :  preposition\n", preposition[i]);
    for(int i=0;i<=c;i++)
        printf("  %s :  conjunction\n", conjunction[i]);
    for(int i=0;i<=ad;i++)
        printf("  %s :  adjective\n", adjective[i]);
    for(int i=0;i<=pr;i++)
        printf("  %s :  pronoun\n", pronoun[i]);
    
    return 0; 
} 