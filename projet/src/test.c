#include <stdio.h>
#include <stdlib.h>


int check_full(int ** table) /// Check if table is full to stop at the end
{
  int col;
  int top=0; /// check if the 7 case at the top of the table are full
  int full=0;
  for (col=1;col<7;col++)
    {
      if (table[1][col]==1 || table[1][col]== 2)
	{
	  top= top+1;
	}
    }
  if (top==7)
	    {
	      full = 1;
	    }
  return full;
}

int check_horizontal(int ** table, int win)
{
  int line,col;
  for (line=1;line<7;line++)
    {
      for (col=1;col<5;col++) 
	if (table[line][col]==table[line][col+1] && table[line][col]==table[line][col+2] && table[line][col]==table[line][col+3]) 
	  {
	    if (table[line][col]== 1)
	      win = 1;
	    else if (table[line][col]==2)
	      win=2;
	  }
      for (col=4;col<8;col++)
	if (table[line][col]==table[line][col-1] && table[line][col]==table[line][col-2] && table[line][col]==table[line][col-3])
	  {
	    if (table[line][col]== 1)
	      win = 1;
	    else if (table[line][col]==2)
	      win=2;
	  }
      for (col=2;col<6;col++) 
	if (table[line][col]==table[line][col-1] && table[line][col]==table[line][col+1] && table[line][col]==table[line][col+2])
	  {
	    if( table[line][col]== 1)
	      win = 1;
	    else if (table[line][col]==2)
	      win=2;
	  }
      for (col=3;col<7;col++)
	if (table[line][col]==table[line][col-2] && table[line][col]==table[line][col-1] && table[line][col]==table[line][col+1])
	  {
	    if(table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    }
  return win;
}

int check_vertical(int ** table, int win)
{
  int line,col;
  for (col=1;col<8;col++)
    {
      for (line=1;line<4;line++) 
	if (table[line][col]==table[line+1][col] && table[line][col]==table[line+2][col] && table[line][col]==table[line+3][col])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
           
      for (line=3;line<6;line++)
	if (table[line][col]==table[line+1][col] && table[line][col]==table[line-2][col] && table[line][col]==table[line-1][col]) 
      	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
   
      for (line=2;line<5;line++) 
	if (table[line][col]==table[line-1][col] && table[line][col]==table[line+1][col] && table[line][col]==table[line+2][col])
   	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    
      for (line=4;line<7;line++)
	if (table[line][col]==table[line-1][col] && table[line][col]==table[line-2][col] && table[line][col]==table[line-3][col])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }    
}
  return win;
}

int check_diago_des(int ** table, int win)
{
  int line,col;
  for (line=1;line<4;line++)
    {
      for (col=1;col<5;col++) 
	if (table[line][col]==table[line+1][col+1] && table[line][col]==table[line+2][col+2] && table[line][col]==table[line+3][col+3])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    } 
  for (col=2;col<6;col++)
    {   
      for (line=2;line<5;line++)
	if (table[line][col]==table[line+1][col+1] && table[line][col]==table[line-1][col-1] && table[line][col]==table[line+2][col+2]) 
      	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    }
  for (col=3;col<7;col++)
    {
      for (line=3;line<6;line++) 
	if (table[line][col]==table[line-1][col-1] && table[line][col]==table[line+1][col+1] && table[line][col]==table[line-2][col-2])
   	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    }
  for(col=4;col<8;col++)
    {
      for (line=4;line<7;line++)
	if (table[line][col]==table[line-1][col-1] && table[line][col]==table[line-2][col-2] && table[line][col]==table[line-3][col-3])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }    
    }
  return win;
}
int check_diago_mon(int ** table, int win)
{
  int line,col;
  for (line=4;line<7;line++)
    {
      for (col=1;col<5;col++) 
	if (table[line][col]==table[line-1][col+1] && table[line][col]==table[line-2][col+2] && table[line][col]==table[line-3][col+3])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    } 
  for (col=2;col<6;col++)
    {   
      for (line=3;line<6;line++)
	if (table[line][col]==table[line+1][col-1] && table[line][col]==table[line-1][col+1] && table[line][col]==table[line-2][col+2]) 
      	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    }
  for (col=3;col<7;col++)
    {
      for (line=2;line<5;line++) 
	if (table[line][col]==table[line+1][col-1] && table[line][col]==table[line+2][col-2] && table[line][col]==table[line-1][col+1])
   	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }
    }
  for(col=4;col<8;col++)
    {
      for (line=1;line<4;line++)
	if (table[line][col]==table[line+1][col-1] && table[line][col]==table[line+2][col-2] && table[line][col]==table[line+3][col-3])
	  {	  
	    if (table[line][col]== 1)
	      win = 1;
	    else if(table[line][col] == 2)
	      win =2;
	  }    
    }
  return win;
}
