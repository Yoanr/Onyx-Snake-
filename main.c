#include"main.h"
void main(void) {
  int cangogame; // pui-je rentrez dans game ? (seulement si on appuie sur jouer)
  unsigned long int* tableaufinal;
  unsigned long int scores,scorestaille,duree,a;
  char tabscore[255];
  char tabduree[255];
  char tabscorestailles[2400];

  tableaufinal=malloc(3*sizeof(unsigned long int));
 
  while(1) {
InitialiserGraphique(); //initialise le mode graphique
  CreerFenetre(0,0,1200,844); //créer une fenetre de dimension 1500*850
  ChargerImage("img/fond_du_menu.png",0,0,0,0,1200,844);//permet d'afficher une image en fond
   //permet de maintenir la fenetre ouverte
  ChoisirTitreFenetre("Snake Onyx 1.0");
  Menu();
 /*a=tableaufinal[0];
  scores=tableaufinal[1];
  scorestaille=scores/5;
  duree=tableaufinal[2];
    
    
    couleur c;
    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);

    sprintf(tabscore,"%lu",scores);
    EcrireTexte(900,60,tabscore,2);

    sprintf(tabduree,"%lu",duree);
    EcrireTexte(900,140,tabduree,2);

    sprintf(tabscorestailles,"%lu",scorestaille);
    EcrireTexte(1080,55,tabscorestailles,2);*/
    do{

      cangogame=souris();
    }
    while( cangogame!=1);
  
    
    tableaufinal=game();
    
    ChargerImage("img/fond_du_menu.png",0,0,0,0,1200,844);
    if(a==1) {
      ChargerImage("img/win.png",400,200,0,0,450,450);
    }
    else {
      ChargerImage("img/gameover.png",400,200,0,0,444,246);
    }
 

    commandes();
  }
  free(tableaufinal);
}
