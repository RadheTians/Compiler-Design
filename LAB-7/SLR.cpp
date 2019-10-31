#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int char_after_dot(char*);
void insert_dot(char*);
bool is_nonterminal(char);
void swap_dot_and_char(char*); 


//Contains details of a group, along with closure and goto

class group
{
    public:             //Bad idea making all datamembers public
                        //But its the simplest way to implement groups_are_different()
    char name[10];
    char productions[100][100];
    int group_prod_count;
    char added[100];

    group()
    {
        group_prod_count = 0;
        for (int i=0; i<100; i++)
            added[i] = '0';
    }
    void set_name(char new_name[])
    {
        strcpy(name, new_name);
    }
    void add_prod(char prod[100])
    {
        strcpy(productions[group_prod_count], prod);
        group_prod_count++;
    }
    void closure(char given_prods[100][100], int given_prods_count)
    {
        //printf("\nProds are : \n");
        //for (int i=0; i<given_prods_count; i++)
        //    printf("%s", given_prods[i]);
        bool already_there;
        for (int i=0; i<group_prod_count; i++)
        {
            
            //printf("Taking %s", productions[i]);
            int next_char_loc;
            next_char_loc = char_after_dot(productions[i]);
            already_there = false;
            if (is_nonterminal(productions[i][next_char_loc]))
            {
                for (int k=0; added[k] != '0'; k++)
                {
                    if (added[k] == productions[i][next_char_loc])
                        already_there = true;
                }
                if (already_there) continue;
                for (int k=0; k<given_prods_count; k++)
                {
                    //printf("Considering %s", given_prods[k]);
                    if (productions[i][next_char_loc] == given_prods[k][0])
                    {
                        if (!strcmp(given_prods[k],productions[i])) continue;
                        add_prod(given_prods[k]);
                        group_prod_count++;
                        //printf("added : %s", given_prods[k]);
                    }
                }
                int l;
                for (l=0; added[l] != '0'; l++);
                added[l] = productions[i][next_char_loc];
                //printf("%c is new!\n", productions[i][next_char_loc]);
            }
         }
     } 
        
    void go2(char x, char gotoprods[100][100], int& num_of_prods)
    {
        int next_char_loc;
        num_of_prods = 0;
        for (int i=0; i<group_prod_count; i++)
        {
            next_char_loc = char_after_dot(productions[i]);
            if (x == productions[i][next_char_loc])
            {
                swap_dot_and_char(productions[i]);
                //printf("$$$%s", productions[i]);
                //printf("%s", productions[i]);
                strcpy(gotoprods[num_of_prods], productions[i]);
                num_of_prods++;
            }
        }
    }

    void cleanup_prods()
    {
        for (int i=0; i<group_prod_count; i++)
        {
            if (strlen(productions[i]) <= 1)
            {
                for (int j=i; j<group_prod_count-1; j++)
                {
                    strcpy(productions[j], productions[j+1]);
                }
                group_prod_count--;
            }
        }
    }
           
    void copy_prods(group a)
    {
        for (int i=0; i<a.group_prod_count; i++)
        {
            printf("Copying: %s", a.productions[i]);
            add_prod(a.productions[i]);
        }
    }

    void clear_prods()
    {
        group_prod_count = 0;
    }
    
    void display_prods()
    {
        printf ("\nProductions in %s are : \n", name);
        for (int i=0; i<group_prod_count; i++)
            printf("%s", productions[i]);
    }
};

void swap_dot_and_char(char* production)
{
    int loc;
    loc = char_after_dot(production);
    production[loc-1] = production[loc];
    production[loc] = '.';
}
    

int char_after_dot(char* production)
{
    for (int i=0; i<strlen(production); i++)
    {
        if (production[i] == '.')
            return i+1;
    }
    return -1;
}

//Takes old_prod, adds a '.' to the 3rd location, and puts it into new_prod
void insert_dot(char* old_prod)     
{
    for (int j=99; j>3; j--)
        old_prod[j] = old_prod[j-1];
    old_prod[3] = '.';
}

bool is_nonterminal(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    else
        return false;
}

void find_characters(char characters[100], char productions[100][100], int prod_count)
{
    int i, j, k;
    bool already_there;
    for (i=0; i<100; i++)
        characters[i] = ' ';
        
    for (i=0; i<prod_count; i++)
    {
        for (j=0; productions[i][j] != '\n'; j++)
        {
            already_there = false;
            if (productions[i][j] == '=' || productions[i][j] == '.') continue;
            if (productions[i][j] == '-' && productions[i][j+1] == '>')
            {
                j++;
                continue;
            }
            for (k=0; characters[k] != ' '; k++)
            {
                if (characters[k] == productions[i][j])
                {
                    already_there = true;
                    break;
                }
            }
            if (!already_there)
                characters[k] = productions[i][j];
        }
    }
    
    
             
}

bool groups_are_different( group a, group b)
{
    if (a.group_prod_count != b.group_prod_count) 
        return true;
        
    for (int i=0; i<a.group_prod_count; i++)
    {
        int flag = 0;
        for (int j=0; j<b.group_prod_count; j++)    
            if (strcmp(a.productions[i], b.productions[j]) == 0)
                flag = 1;
        if (flag == 0)
            return true;
    }
    return false;
}


int main()
{
    char productions[100][100];
    group a[100];
    int prod_count;
    cout <<"Enter the number of Productions :==  ";
    cin >>prod_count;
    for (int i=0; i<prod_count; i++)
        cin >> productions[i];

    
    
    for (int i=0; i<prod_count; i++)
        insert_dot(productions[i]);

    char gotoprods[100][100];
    int num_of_prods; 
    char characters[100];
    
    find_characters(characters, productions, prod_count);

    //not so HIGHLY EXPERIMENTAL!

    group c[100];
    c[0].add_prod(productions[0]);
    c[0].set_name("I0");
    c[0].closure(productions, prod_count);
    c[0].cleanup_prods();
    int item_count=1;    
         
    for (int i=0; i < item_count; i++)
    {        
        for (int j = 0; characters[j] != ' '; j++)
        {
            group temp;
            cout << "\nItem " << i << " Symbol " << characters[j] << '\n';
            printf("There are %d productions\n", c[i].group_prod_count);
            temp.copy_prods(c[i]);
            temp.go2(characters[j], gotoprods, num_of_prods); 
            //printf("%d", num_of_prods);//temp.display_prods();
            for (int h=0; h<num_of_prods; h++)
            {
                //printf("%s", gotoprods[h]);
                c[item_count].add_prod(gotoprods[h]);
            } 
            printf("Before closure:\n");
            c[item_count].display_prods();
            c[item_count].closure(productions, prod_count);
            c[item_count].cleanup_prods();
            for (int k=0; k<item_count; k++)
            {
                if (!groups_are_different(c[item_count], c[k]))
                {    
                    c[item_count].clear_prods();         //Clear out all productions in the new group
                    break;
                }
                if (k==item_count-1)
                {
                    if (c[item_count].group_prod_count == 0)break;
                    char name[10];
                    sprintf(name, "I%d", item_count);
                    c[item_count].set_name(name);
                    c[item_count].display_prods();
                    printf("This is I%d", item_count);
                    item_count++;
                    break;
                }
            }
            
            cout << "\n\n";
        }
    }
    cout << "Value of item_count : " << item_count << '\n';     
    for (int i=0; i<item_count; i++)
        c[i].display_prods();
            
    return 0;
}