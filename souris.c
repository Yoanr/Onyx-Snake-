/** ROCK      Yoan            *
 *  COLOMBIER Adrien          *
 *                            * 
 *  VOICI LE FICHIER SOURIS   */
#include"main.h"
int souris(void){
  int infini_menu=1,x,y;//créer les variables 
  couleur c;
  int cangogame;
  c=CouleurParNom("white");

  while(infini_menu==1)
    { //tant que infini_menu=1
      if(SourisCliquee())  { //test si un bouton de la souris a été cliqué
	x=_X;// x prend l'abscisse de la position de la souris
	y=_Y;// y prend l'ordonnée de la position de la souris

	if(x>133 && x<387 && y>32 && y<100){//conditions pour le bouton jouer
	  
	  	  cangogame=1;
	  ChoisirCouleurDessin(c);
	  DessinerRectangle(0,0,1200,800);
	  RemplirRectangle(0,0,1200,800);
	  infini_menu=0;
	}

	else if(x>500 && x<735 && y>28 && y<94){//conditions pour le bouton commandes  
	  ChargerImage("img/commandes.png",400,200,0,0,450,450);
          cangogame=0;
	  infini_menu=0;
	  
	}
		  
      }
          
 
    }
        
  return cangogame;
}
