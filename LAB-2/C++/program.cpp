#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;


void recursion(char *input)
{
int i=0,j=0,flag=0;
char *l,*r,*temp,productions[25][50];
 l = strtok(input,"->");
    r = strtok(NULL,"->");
    temp = strtok(r,"|");
    while(temp)  {
        if(temp[0] == l[0])  {
            flag = 1;
            sprintf(productions[i++],"%s'->%s%s'\0",l,temp+1,l);
        }
        else
            sprintf(productions[i++],"%s->%s%s'\0",l,temp,l);
        temp = strtok(NULL,"|");
    }
    sprintf(productions[i++],"%s->ε\0",l);
    if(flag == 0)
        cout << "The given productions don't have Left Recursion";
    else
        for(j=0;j<i;j++)  {
            cout << productions[j];
        }
}
int main()  {
	char input[100][100];
	int i=0,j=0,flag=0,n;
	cout << "Enter the number of productions:";
	cin >> n;
    	cout << "Enter the productions: ";
	for(int i=0;i<n;i++)
    		cin >> input[i];
    
	for(i=0;i<n;i++)
		recursion(input[i]);
	return 0;

}


