#include <stdio.h>
#include <stdlib.h>

int** create_tab()
{
  int i;
  int **table= malloc(7*sizeof(int*)); /// 7 to evit segmentation problem ( 6 + 1)
  for(i=1;i<8;i++)
  {
    table[i]=malloc(8*sizeof(int));/// 8 to evit segmentation problem (7 + 1) 
    }
  return table;
}
int** initialize(int ** table) 
{
  int i,j;

  for(i=1;i<7;i++)
    {
      for(j=1;j<8;j++)
	{
	  table[i][j]=0;
	}
    }
     return table;
}


void display(int** table)
{
  int i,j;
  printf("\n");
  printf(" 1 2 3 4 5 6 7 \n");
  for (i=1;i<7;i++)
    for (j=1;j<8;j++)
	if (j== 7)
	    {  
	      if (table[i][j] == 1) 
		{
		  printf("|O|\n");
		}
	      else if(table[i][j] == 2)
		{
		  printf("|X|\n");
		}
	      else ///table[i][j] = 0 because we have ever initialized the table
		{
		  printf("| |\n"); 
		}  	    
	    }
	  else
	    {
	      if (table[i][j] == 1)
		printf("|O");
	      else if(table[i][j] == 2)
		printf("|X");
	      else if(table[i][j] == 0)
		printf("| ");
	    }
  printf("---------------");
}	  
void remplissage(int round,char* j1,char* j2,int** table)
{
  int col;
  if ((round & 1) == 1)
    {
	  printf(" \n %s  Veuillez entrer la colonne(entre 1 et 7) dans laquelle vous voulez jouer : \n",j1);
	  scanf("%d",&col);

	while (table[1][col] == 1 ||  table[1][col] == 2 ) /// we check the top of the table 
	  {
	    printf("Erreur : La colonne est pleine veuillez en choisir une autre : \n");
	    scanf("%d",&col);
	  }
      int i = 6;
      while((table[i][col] == 1 ||  table[i][col] == 2) && i>1) /// i>1 to evit segmentation problem
	i--;  
      table[i][col] = 1;
         }
  else
    {
	  printf(" \n %s  Veuillez entrer la colonne dans laquelle vous voulez jouer : \n",j2);
	  scanf("%d",&col);

	  while (table[1][col] == 1 ||  table[1][col] == 2)
	    {
	      printf("Erreur : La colonne est pleine veuillez en choisir une autre : \n");
	      scanf("%d",&col);
	    }
      int i = 6;
      while((table[i][col] == 1  ||  table[i][col] == 2) && i>1)
	  i--;
		
      table[i][col] = 2;
      printf("\n");
    }
}
