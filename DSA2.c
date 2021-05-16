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
            if (pat[i] == '\0')
            {
                flag = 1;
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
    return flag;
}