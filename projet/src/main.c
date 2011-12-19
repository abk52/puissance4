#include <stdio.h>
#include <stdlib.h>
#include "../include/partie.h"

int main()
{ 
  int choice;
  printf("Que voulez vous faire ? \n 1- Nouvelle Partie \n 2- Cnsulter les Scores \n 3- Quitter \n");
  scanf("%d",&choice);

  switch (choice) 
    {
    case 1:
      {
	printf("Nous allons démarrer une nouvelle partie\n \n");
	game();	
	break;
      }
    case 2:
      { 
	printf (" Voici la liste de tout les gagnant de ce puissance4 : \n");
	FILE* fresult=NULL;
	fresult = fopen("scores.txt","r");
	int carac;	
	if (fresult != NULL)
	{	
	carac = fgetc(fresult);
	while (carac != EOF)
	{
	printf("%c", carac); 
	carac = fgetc(fresult);
	}
}
	break;
      }
    case 3 :
      {
	break;
      }
    default :
      {
	printf(" Veuillez entrer les chiffres 1,2 ou 3 correspondatns");
      }
    }
  return 0;
}

