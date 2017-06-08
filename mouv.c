#include"main.h"
#define CYCLE 1L
#include<string.h>

int* mouv(int x,int y,int Clavier,int indicetabimg) {
  
  int dirx=0,diry=0;
  /* stockera la direction en x et y, et nom de l'image que dois afficher le serpent */

  int* tab;

  tab=malloc(3*sizeof(int));
  
  
        
 
  if(Clavier==1) {
	  
   
    if(indicetabimg==0)
      { 
        
	Clavier=XK_Right;
      }
 if(indicetabimg==1)
      { 

	Clavier=XK_Left;
      }
    if(indicetabimg==2)
      { 

	Clavier=XK_Up;
      }
    if(indicetabimg==3)
      { 

	Clavier=XK_Down;
      }
  }
  

  
  
  
  if(Clavier==XK_Right && indicetabimg!=1)
    { 
       
      dirx=1;
      diry=0;
      tab[2]=0;
	 
    } 
		         
  if(Clavier==XK_Up && indicetabimg!=3)
    {
     
      dirx=0;
      diry=-1;
      tab[2]=2;
		  	  
    }
		         
  if(Clavier==XK_Down  && indicetabimg!=2)
    {
	  
		
      
      dirx=0;
      diry=1;
      tab[2]=3; 
		  
		  
    }
  if(Clavier==XK_Left  && indicetabimg!=0)
    {
           
		
      dirx=-1;
      diry=0;
      tab[2]=1;	 

    }

  tab[0]=dirx;
  tab[1]=diry;

  return tab;

}


