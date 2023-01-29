#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void newfile()
{
    FILE *fp;
    char name[10];
    int i=0;
    char count[100];
    strcpy(count,"");
    printf("\n\n\t\t\t\t New File ");
    printf("\n__________________________________________________________");
    printf("\n\n Enter the name of the file to create\t:");
    scanf("%s",name);
    fp=fopen(name,"w");
    printf("\n Enter the contents of the file and terminated with # \n\n");
    while(i<100)
    {
        scanf("%c",&count[i]);
        if(count[i]!='#')
        {
            fputc(count[i],fp);
        }
        else
        {
            fclose(fp);
            break;
        }
        i++;
    }
}
void openfile()
{
    FILE *fp;
    char name[10];
    char c;
    printf("\n\n\t\t\t\t Open File ");
    printf("\n___________________________________________________");
    printf("\n\n Enter the name of the file\t:");
    scanf("%s",name);
    printf("\n------------------------------------------------------\n\n");
    fp=fopen(name,"r");
    while((c=fgetc(fp))!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
    printf("\n\n------------------------------------------------");
}
void editfile()
{
    FILE *fp;
    int i,j,k,m;
    char name[10];
    char count[100];
    char c;
    char c2[50],c3[50];
    int len;
    i=0;
    printf("\n\n Enter the name of the file\t:");
    scanf("%s",name);
    printf("--------------------------------------------------------\n\n");
    fp=fopen(name,"r");
    strcpy(count,"");
    while((c=fgetc(fp))!=EOF)
    {
        count[i]=c;
        i++;
    }
    fclose(fp);
    count[i]='\0';
    printf("%s",count);
    len=i;
    printf("\n\n------------------------------------------------------\n");
    printf("\n\n\t\t\t\tEDITING SECTION \n");
    printf("\n========================================================\n");
    j=0;
    fp=fopen(name,"w");
    for(i=0;i<len;i++)
    {
        if(count[i]=='\n'&&i!=0)
        {
            c2[j]='\0';
            j=0;
            printf("%s",c2);
            printf("\n Do you want to EDIT [Y(1)/N(0)]\t\t:");
            scanf("%d",&k);
            if(k==1)
            {
                printf("\nEnter the modification terminated by #\n");
                m=0;
                strcpy(c3,"");
                while(m<30)
                {
                    scanf("%c",&c3[m]);
                    if(c3[m]=='#')
                    {
                        c3[m]='\0';
                        break;
                    }
                    else if(c3[m]!='\n')
                    {
                        m++;
                    }
                }
                fputs(c3,fp);
                fputc('\n',fp);
            }
            else
            {
                fputs(c2,fp);
                fputc('\n',fp);
            }
        }
        else
        {
            c2[j]=count[i];
            j++;
        }
    }
    fclose(fp);
}
void main()
{
int choice,op;
A:
    printf("\n\t\t\t\tEDITOR ");
    printf("\n__________________________________________________________");
    printf("\n 1.New File\t\t2.Open File\t\t3.Edit File\t4.Exit EDITOR");
   printf("\n__________________________________________________________");
    printf("\n\n Enter your choice\t:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        newfile();
        break;
    case 2:
        openfile();
        break;
    case 3:
        editfile();
        break;
    case 4:
        exit(0);
        break;
    }
    goto A;
}