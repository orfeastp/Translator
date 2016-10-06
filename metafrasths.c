#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Lekshko
{
    char ellinika[242];
    char agglika[242];
};

char *EisagwghLekshs(struct Lekshko *dhmiourgia,int megethos,char lexi1[],char lexi2[])
{
    int i;

    dhmiourgia = (struct Lekshko *) realloc(dhmiourgia,megethos*sizeof(struct Lekshko ));

    for (i=0;i<megethos;i++)
    {
        if ((strstr(dhmiourgia[i].ellinika,lexi1)!=NULL && strlen(dhmiourgia[i].ellinika)==strlen(lexi1)) || (strstr(dhmiourgia[i].agglika,lexi2)!=NULL && strlen(dhmiourgia[i].agglika)==strlen(lexi2)))
        {
            return 0;
        }
    }
    strcpy(dhmiourgia[i-1].ellinika,lexi1);
    strcpy(dhmiourgia[i-1].agglika,lexi2);
    return dhmiourgia;
}

char *TropopoihshLekshs(struct Lekshko *dhmiourgia, int megethos,char lexi1[])
{
    int i;
    char lexi2[20];

    for (i=0;i<megethos;i++)
    {
        if ((strstr(dhmiourgia[i].ellinika,lexi1)!=NULL && strlen(dhmiourgia[i].ellinika)==strlen(lexi1)) || (strstr(dhmiourgia[i].agglika,lexi1)!=NULL && strlen(dhmiourgia[i].agglika)==strlen(lexi1)))
        {
            printf("\nGrapste thn leksh sta ellhnika kai epeita sta agglika:\n");
            scanf("%s %s",lexi1,lexi2);
            strcpy(dhmiourgia[i].ellinika,lexi1);
            strcpy(dhmiourgia[i].agglika,lexi2);
            return dhmiourgia;
        }
    }
    return 0;
}

char *DiagrafhLekshs(struct Lekshko *dhmiourgia,int megethos,char lexi1[])
{
    int i,j;

    for (i=0;i<=megethos;i++)
    {
        if ((strstr(dhmiourgia[i].ellinika,lexi1)!=NULL && strlen(dhmiourgia[i].ellinika)==strlen(lexi1)) || (strstr(dhmiourgia[i].agglika,lexi1)!=NULL && strlen(dhmiourgia[i].agglika)==strlen(lexi1)))
        {
            for(j=i;j<megethos;j++)
            {
                strcpy(dhmiourgia[j].ellinika,dhmiourgia[j+1].ellinika);
                strcpy(dhmiourgia[j].agglika,dhmiourgia[j+1].agglika);
            }
            dhmiourgia = (struct Lekshko*) realloc(dhmiourgia,megethos*sizeof(struct Lekshko));
            return dhmiourgia;
        }
    }
    return 0;
}

char *MetafrashLekshs(struct Lekshko *dhmiourgia,int megethos,char lexi1[])
{
    int i;

    for (i=0;i<megethos;i++)
    {
        if(strstr(dhmiourgia[i].ellinika,lexi1)!=NULL && strlen(dhmiourgia[i].ellinika)==strlen(lexi1))
        {
            return dhmiourgia[i].agglika;
        }
        else
        {
            if(strstr(dhmiourgia[i].agglika,lexi1)!=NULL && strlen(dhmiourgia[i].agglika)==strlen(lexi1))
            {
                return dhmiourgia[i].ellinika;
            }
        }
    }
    return 0;
}

char *MetafrashProtashs(struct Lekshko *dhmiourgia, int megethos,const char protash[])
{
   const char s[2]=" ";
   char *lexi,*p,metafrash[80]=" ";
   int i;

   p=(char *) malloc(sizeof(char)*5);
   lexi=(char *) malloc(sizeof(char)*5);

   lexi = strtok(protash, s);

   while( lexi != NULL )
   {
      p=MetafrashLekshs(dhmiourgia,megethos,lexi);
      if(p!=NULL)
      {
        strcat(metafrash,p);
      }
      lexi = strtok(NULL,s);
      return metafrash;
   }
   return 0;
}

void Eksodos(struct Lekshko *dhmiourgia,int megethos)
{
    int i;
    char apanthsh;
    FILE *lekshko;

    do
    {
      fflush(stdin);
      printf("\nOi allages poy kanate thelete na apothikeytoyn? Apanthste me y/n\n");
      apanthsh=getch();
      if (apanthsh=='N' || apanthsh=='n')
      {
        printf("\nOi allages den apothikeuthkan sto leksiko\n");
      }
      else
      {
        if(apanthsh=='Y' || apanthsh=='y')
        {
            if ((lekshko = fopen("lekshko.txt","w"))!=NULL)
            {
                for (i=0;i<megethos;i++)
                {
                    fprintf(lekshko,"%s ",dhmiourgia[i].ellinika);
                    fprintf(lekshko,"%s\n",dhmiourgia[i].agglika);
                }
                fclose(lekshko);
                printf("\nApothikeythkan oi allages\n");
            }
            else
                printf("\nTo arxeio dn mporese na anoiksei\n");
        }
      }
    }
    while(apanthsh!='N' && apanthsh!='n' && apanthsh!='Y' && apanthsh!='y');
}

int main()
{
    FILE *lekshko;
    int i,megethos=0;
    struct Lekshko *dhmiourgia;
    char k,xar,lexi1[20],lexi2[20];
    const char protash[80];

    if ((lekshko=fopen("lekshko.txt","r"))!=NULL)
    {
        while(!feof(lekshko))
        {
            xar = fgetc(lekshko);
            if(xar == '\n')
            {
                megethos++;
            }
        }
        fclose(lekshko);
    }
    else
    {
        printf("To lekshko den mporese na anoiksei\n");
    }
    printf("megethos: %d\n",megethos);

    dhmiourgia=(struct Lekshko *) malloc(megethos*sizeof(struct Lekshko));

    if ((lekshko=fopen("lekshko.txt","r"))!=NULL)
    {
            printf("Lekshko:\n");
            for (i=0;i<megethos;i++)
            {
                fscanf(lekshko,"%s",dhmiourgia[i].ellinika);
                fscanf(lekshko,"%s",dhmiourgia[i].agglika);
                printf("%d: %s %s\n",i+1, dhmiourgia[i].ellinika, dhmiourgia[i].agglika);
            }
            fclose(lekshko);
            do
            {
                printf("\n\n1.Eisagwgh Neas Lekshs\n2.Tropoihsh Lekshs\n3.Diagrafi Lekshs\n4.Metafrash Lekshs\n5.Metafrash Protashs\n6.Eksodos\n\nH epilogh sou: ");
                k=getch();
                printf ("\n");
                if (k=='1')
                {
                    megethos++;
                    printf("\nGrapste thn leksh pou thelete na eisagete sta ellinika kai sta agglika: \n");
                    fflush(stdin);
                    scanf("%s %s",lexi1,lexi2);
                    if(EisagwghLekshs(dhmiourgia,megethos,lexi1,lexi2)==0)
                    {
                        printf("\nH leksh yparxei sto lekshko\n");
                    }
                    else
                    {
                        printf("\nNeo lekshko:\n\n");
                        for (i=0;i<megethos;i++)
                        {
                            printf("%d: %s %s\n",i+1, dhmiourgia[i].ellinika, dhmiourgia[i].agglika);
                        }
                    }
                }
                else
                {
                    if(k=='2')
                    {
                        printf("\nGrapste thn leksh pou thelete na tropoihsete sta ellinika h sta agglika: \n");
                        fflush(stdin);
                        scanf("%s",lexi1);
                        if(TropopoihshLekshs(dhmiourgia,megethos,lexi1)==0)
                        {
                            printf("\nDen brethhke h leksh poy thelate na tropopoihsete\n");
                        }
                        else
                        {
                           printf("\nNeo lekshko:\n\n");
                           for (i=0;i<megethos;i++)
                           {
                               printf("%d: %s %s\n",i+1, dhmiourgia[i].ellinika, dhmiourgia[i].agglika);
                           }
                        }
                    }
                    else
                    {
                        if(k=='3')
                        {
                            if (megethos==0)
                            {
                                printf("\nExeis diagrapsei oles tis lekshs tou lekshkou\n");
                            }
                            else
                            {
                                printf("\nGrapste thn leksh pou thelete na diagrapsete sta ellinika h sta agglika: \n");
                                fflush(stdin);
                                scanf("%s",lexi1);
                                megethos--;
                                if(DiagrafhLekshs(dhmiourgia,megethos,lexi1)==0)
                                {
                                        printf("\nDen brethhke h leksh pou thelate na diagrapsete\n");
                                }
                                else
                                {
                                    printf("\nNeo lekshko:\n\n");
                                    for (i=0;i<megethos;i++)
                                    {
                                        printf("%d: %s %s\n",i+1, dhmiourgia[i].ellinika, dhmiourgia[i].agglika);
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(k=='4')
                            {
                                printf("\nGrapste thn leksh pou thelete na metafrasete sta ellinika h sta agglika: \n");
                                fflush(stdin);
                                scanf("%s",lexi1);
                                if(MetafrashLekshs(dhmiourgia,megethos,lexi1)==0)
                                {
                                    printf("\nDen brethhke h leksh pou thelate na metafrasete\n");
                                }
                                else
                                {
                                    printf("\n%s shmainei %s",lexi1,MetafrashLekshs(dhmiourgia,megethos,lexi1));
                                }
                            }
                            else
                            {
                                if(k=='5')
                                {
                                    printf("\nGrapste thn protash pou thelete na metafrasete sta ellinika h sta agglika: \n");
                                    fflush(stdin);
                                    scanf("%s",protash);
                                    if(MetafrashProtashs(dhmiourgia,megethos,protash)==0)
                                    {
                                        printf("\nDen brethhke h protash pou thelate na metafrasete\n");
                                    }
                                    else
                                    {
                                        printf("\n%s shmainei %s",protash,MetafrashProtashs(dhmiourgia,megethos,protash));
                                    }
                                }
                                else
                                {
                                    if(k=='6')
                                    {
                                       printf("megethos: %d\n",megethos);
                                       Eksodos(dhmiourgia,megethos);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            while (k!='6');
    }
    else
    {
        printf("To lekshko den mporese na anoiksei\n");
    }
    return 0;
}
