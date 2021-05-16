/*
Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine 
the records in file F. Assume that file F is maintained in memory by a Hash Table (HT) of m 
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the 
keys in K and addresses in L are Integers. Design and develop a Program in C that uses Hash 
function H: K →L as H(K)=K mod m (remainder method), and implement hashing 
technique to map a given key K to the address space L. Resolve the collision (if any) using 
linear probing. 
*/

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
