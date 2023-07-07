#include <stdio.h>
#include <stdlib.h>
typedef struct phone_number
{
    char name[30];
    int no;
}pno;
int i,n,n1;
void create()
{
    printf("Enter the number of person:");
    scanf("%d",&n);
    pno* pn;
    pn=(pno*)malloc(n*sizeof(pno));
    FILE* fptr;
    fptr=fopen("phonenumber.txt","w");
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the name of the person:");
        scanf("%s",(pn+i)->name);
        printf("Enter the phone number:");
        scanf("%d",&(pn+i)->no);
    }
    for(i=1;i<=n;i++)
    {
        fprintf(fptr,"%s:%d\n",(pn+i)->name,(pn+i)->no);
    }
    fclose(fptr);
    free(pn);
}
void append()
{
    printf("\nEnter the number of persons to append:");
    scanf("%d",&n1);
    pno* pn;
    FILE* fptr;
    pn=(pno*)malloc(n1*sizeof(pno));
    fptr=fopen("phonenumber.txt","a");
    for(i=1;i<=n1;i++)
    {
        printf("\nEnter the name of the person:");
        scanf("%s",(pn+i)->name);
        printf("\nEnter the phone number:");
        scanf("%d",&(pn+i)->no);
    }
    for(i=1;i<=n1;i++)
    {
        fprintf(fptr,"%s:%d\n",(pn+i)->name,(pn+i)->no);
    }
    fclose(fptr);
    free(pn);
}
void display()
{
    pno p;
    FILE* fptr;
    fptr = fopen("phonenumber.txt", "r");
    fread(&p,sizeof(pno),1,fptr);
    for(int i=1;i<=n;i++)
    {
        printf("%s:%d",p.name,p.no);
        fclose(fptr);
    }
    fclose(fptr);
}
int main()
{
    int num;
    pno* pn;
    do
    {
        printf("Enter 1 to create phone number\nEnter 2 to append phone number\nEnter 3 to read phone number\nEnter 0 to exit\n");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                create();
                break;
            case 2:
                append();
                break;
            case 3:
                display();
                break;
        }
    }while(num!=0);
    return 0;
}