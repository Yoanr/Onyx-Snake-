#include"main.h"

int** init(void) {
 
  int i,x,y;
  int** coordserpent=malloc(2*sizeof(int*));
 /*x et y pour les 2 lignes et les 2400 cases possible*/
  coordserpent[0]=malloc(2400*sizeof(int));
  coordserpent[1]=malloc(2400*sizeof(int));
  

  /* init le début du corps, 1 tête 9 corps */
  for(i=9;i>0;i--) {
    coordserpent[0][i]=34-i; //Permet de placer le serpent au centre de l'ecran au démarrage
    coordserpent[1][i]=19;
    
    ChargerImage("img/corps.png",coordserpent[0][i]*20,coordserpent[1][i]*20,0,0,20,20);
    
  }
  coordserpent[0][0]=34;
  coordserpent[1][0]=19;
ChargerImage("img/onyxdroite.png",coordserpent[0][0]*20,coordserpent[1][0]*20,0,0,20,20);


  for(i=10;i<(40*60);i++) /*Boucle permettant de remplir le tableau de -1,
			    j'ai choisie -1 car aucune coordoné ne peux correspondre a -1*/  
    {
      
      coordserpent[0][i]=-1;
      coordserpent[1][i]=-1;
      
    }

  x=coordserpent[0][0]; // on affecte a x et y la position de la tete
  y=coordserpent[1][0];
  
  return coordserpent;
} 
