#include <stdio.h>
#define size 20

int HT[size];
int hash(int key);
void linear_probe(int ht, int key);
int main()
{
    FILE *fp;
    int i, n, key, hk;
    char fname[10];
    printf("\n Enter the filename: ");
    scanf("%s", fname);
    fp = fopen(fname, "a");
    for (i = 0; i < size; i++)
        HT[i] = -1;
        printf("\nHow many keys?: "); // emp
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("\nEnter the Key: ");  // enter emp name
            // fscanf(stdin,"%s",emp->name)
            fscanf(stdin,"%d",&key);
            fprintf(fp,"%d\n",key);
        }
        fclose(fp);
        fp = fopen(fname,"r");
        while(fscanf(fp,"%d",&key)>0)
        {
            hk=hash(key);
            if(HT[hk]==-1)
                HT[hk]=key;
            else
            {
                printf("\nCollision detected for key %d\n",key);
                printf("\nResolving Detection...\n");
                linear_probe(hk,key);
            }
        }
        printf("\nHash Table\n");
        printf("\nAddress\tKey\n");
        for(i=0;i<size;i++)
        {
            if(HT[i]!=-1)
            printf("%d\t%d\n",i,HT[i]);
        }
        return 0;
}

int hash(int key)
{
    return key%size;
}

void linear_probe(int hk, int key)
{
    int i , flag =0;
    for(i=hk+1; i<size ; i++)
    {
        if(HT[i]==-1)
        {
            HT[i]=key;
            flag = 1;
            break;
        }
    }
    for(i=0; i<hk && flag ==0; i++)
    {
        if(HT[i]==-1)
        {
            HT[i]=key;
            flag =1;
            break;
        }
    }
    if(!flag)
    printf("\nHash Table Full!\n");
}
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];
    char id[10];
    int m1, m2, m3,total;
} STU;

int main()
{
    int n, i, j,temp;
    STU class[5];
    printf("\nEnter no. of students in class: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Name and ID\n");
        scanf("%s%s", class[i].name, class[i].id);
        printf("\nEnter marks1 marks2 and marks3\n");
        scanf("%d%d%d", &class[i].m1, &class[i].m2, &class[i].m3);
        class[i].total = class[i].m1 + class[i].m2 + class[i].m3;
    }
    for(i=0;i<n-1;i++){
        for(j=1;j<n;j++){
            if(class[j].total < class[i].total){
                temp = class[i].total;
                class[i].total = class[j].total;
                class[j].total = temp;
            }
        }
    }
    printf("\nStudent with highest marks is\n");
    printf("%s\t%s with total %d", class[i].name, class[i].id,class[i].total);
    
}

*/