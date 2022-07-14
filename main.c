#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
/*************************LES PROTOTYPES *****************************************

char lirecaractere();
void lirechaine(int *ptr);
int comparaison(char** chaine1,char** chaine2);

****************************CODE OF THE GAME*****************************************
int main()
{  int nombresecret;
char motsecret[10]="MARRON";

   char motactuel[strlen(motsecret)];
   char car;


   /*
   FILE* fichier_de_mots=NULL;
   fichier_de_mots=fopen("fichier1.txt","r");*

   int i;

   for(i=0;i<strlen(motsecret);i++) {motactuel[i]='*';}
   do {
    printf("donner votre carctere\n");
    car=lirecaractere();
    car=toupper(car);

    int j;
    for(j=0;j<strlen(motsecret);j++) {if(car==motsecret[j]){
        motactuel[j]=car;
    }
    }
    /*lirechaine(motactuel); printf("\n");*
    printf("resultat actuel-->%s",motactuel);




   }while ((strcmp(motsecret,motactuel))!=0);




}
****************************LA DECLARTION DES FONCTIONS******************************
char lirecaractere() {
    char caractere=0;
    caractere=getchar();
    caractere=toupper(caractere);
    while (getchar() != '\n');
        return caractere;

}
//void lirechaine(int *ptr) {int k; while(*ptr[k]!="\n"){printf("%c",*ptr[k]);}}
//int comparaison(char** chaine1,chaine**2) {int l1,l2,i;
//l1=strlen(chaine1);l2=strlen(chaine2);
//for(i=0;i<l1;i++){if}

*/
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
int gagne(int lettreTrouvee[]);
char lireCaractere();




int main(int argc, char* argv[])
{
char lettre = 0;
char motSecret[] = "MARRON"; 
int lettreTrouvee[6] = {0}; 
int coupsRestants = 10; 
int i = 0; 

printf("Bienvenue dans le Pendu !\n\n");

while (coupsRestants > 0 && !gagne(lettreTrouvee))
{
    printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
    printf("\nQuel est le mot secret ? ");
    
    for (i = 0 ; i < 6 ; i++)
    {
        if (lettreTrouvee[i]) 
        printf("%c", motSecret[i]);
        else
        printf("*"); 
}

   printf("\nProposez une lettre : ");
   lettre = lireCaractere();
   
   if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
   {
       coupsRestants--; 
   }
}
 if (gagne(lettreTrouvee))
printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
else
printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
return 0;



}
/***************la fonction gagne******/
int gagne(int lettreTrouvee[])
{
int i = 0;
int joueurGagne = 1;
for (i = 0 ; i < 6 ; i++)
{
if (lettreTrouvee[i] == 0)
joueurGagne = 0;
}
return joueurGagne;
}
/******************la fonction recherche de lettre**********/
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
int i = 0;
int bonneLettre = 0;

for (i = 0 ; motSecret[i] != '\0' ; i++)
{
if (lettre == motSecret[i]) 
{
bonneLettre = 1;
lettreTrouvee[i] = 1; 
}
}
return bonneLettre;
}

char lireCaractere()
{
char caractere = 0;
caractere = getchar(); 
caractere = toupper(caractere); 
while (getchar() != '\n') ;
return caractere; 
}





