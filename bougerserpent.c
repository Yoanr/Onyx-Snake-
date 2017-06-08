#include"main.h"
int bougerserpent(int corpsadd,int x,int y, int nx, int ny, int size,int** coordserpent, char* lastimg) {
  int taille=size;
  int i,queuex,queuey;
   
  
  
  ChargerImage("img/effacer.png",nx*20,ny*20,0,0,20,20);/*On change la nouvelle case en case blanche */
  ChargerImage(lastimg,nx*20,ny*20,0,0,20,20);/*On change la nouvelle case en tete */
  ChargerImage("img/corps.png",x*20,y*20,0,0,20,20);/*On change l'ancienne tete en corps*/
  
  if(corpsadd>0) // on ne bouge pas la queue
    {  // on change le tableau des coord du serpent en y ajoutant un corps 

      
      for(i=taille-1;i>-1;i--)
	{
	  coordserpent[0][i+1]=coordserpent[0][i];
	  coordserpent[1][i+1]=coordserpent[1][i];
	}
      taille++;
    }else{
   
    queuex=coordserpent[0][taille-1];
    queuey=coordserpent[1][taille-1];
   
    
 
    ChargerImage("img/effacer.png",queuex*20,queuey*20,0,0,20,20);
    
 
    // On change tableau des coord du serpent 
   
    
    for (i=taille-2;i>-1;i--) { /* le dernier corps est deja afficher*/
     
      coordserpent[0][i+1]=coordserpent[0][i];
      coordserpent[1][i+1]=coordserpent[1][i];
      
    }
     
  }
  coordserpent[0][0]=nx;
  coordserpent[1][0]=ny;
  
  return taille;
}





