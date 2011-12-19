#include <stdio.h>
#include <stdlib.h>

#include "../include/grille.h"
#include "../include/test.h"

void create_result(char* player)
{
  FILE* fresult=NULL;
 fresult = fopen("scores.txt","a");
 fprintf(fresult,"%s\n",player);
}

void name(char* j1, char* j2)
{
  printf ("\n Joueur 1 : veuillez entrer votre nom: \n");
  scanf ("%s",j1);


  printf ("\n Joueur 2 : veuillez entrer votre nom: \n");
  scanf ("%s",j2);
  printf(" \n Bienvenue %s et %s \n",j1,j2);

  printf(" J'ai le plaisir de vous annoncer que %s aura les O et %s aura les X \n\n",j1,j2);
}

void game()
{
  int round=1;
  int full=0;
  int win= 0;
  char* j1 = malloc(20*sizeof(char));
  char* j2 = malloc(20*sizeof(char));
  int **table = create_tab();
  
  name(j1,j2);
  initialize(table);

  while(full==0 && win == 0)
    {
      full=check_full(table); /// at first we check if table is full to continue
      remplissage(round,j1,j2,table); 
      display(table);
      win=check_horizontal(table,win);
      win=check_vertical(table,win);
      win=check_diago_des(table,win);
      win=check_diago_mon(table,win); 
      round++;
    }
  if (win==1)
{
    printf("\nBravo a %s tu a gagné \n",j1);
    create_result(j1);
} 
 if (win==2)
{
    printf("\nBravo a %s tu a gagné \n",j2);
    create_result(j2);
}
  if (win==0)
    printf("\nEgalité il n'y a aucun gagnant\n");

}

