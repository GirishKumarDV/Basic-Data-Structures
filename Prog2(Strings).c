/*
Design, Develop and Implement a Program in C for the following operations on Strings. 
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP) 
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in 
STR with REP if PAT exists in STR. Report suitable messages in case PAT does not 
exist in STR 
Support the program with functions for each of the above operations. Don't use Built-in 
functions. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100], pat[100], rep[100], ans[200];
int findMatch(char str[100], char pat[100], char rep[100], char ans[200]);

void main()
{
    int flag = 0;
    printf("\nEnter String\n");
    gets(str);
    printf("\nEnter pattern to search in string\n");
    gets(pat);
    printf("\nEnter replacement string\n");
    gets(rep);
    flag = findMatch(str, pat, rep, ans);
    if (flag)
    {
        printf("\nPattern found!\n");
        printf("The string after replacement is:\n%s", ans);
    }
    else
    {
        printf("\nPattern not found!");
    }
}
/*
use of:
var 'c' = Main string Traversal
var 'm' = Main string Comparison with Patter String
var 'i' = Pattern String Traversal/Manipulation
var 'j' = Answer String Traversal/Manipulation
var 'k' = Replacement String Traversal/Manipulation
*/
int findMatch(char str[100], char pat[100], char rep[100], char ans[200])
{
    int i, j, c, m, flag, k;                  
    i = j = c = m =flag= 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')                           //Indicates Pattern is Found in entered String
            {
                flag = 1;                                 //Raise Flag to indicate Pattern found
                for (k = 0; rep[k] != '\0'; k++, j++)     
                    ans[j] = rep[k];
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
    return flag;                            //Return 1 if String found, 0 if Not found 
}
