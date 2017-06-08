#include"main.h"
#define CYCLE 80000L

unsigned long int* game(void) {
  
  int taille=10; /* car taille du serpent est égale a 10*/
  int corpsadd=0; // nombre de corps a  ajouter
  int res=0; // creer la boucle infini 
  int tmpx; // coord new tete en x
  int tmpy; // coord new tete en y
  char lastimg[255]="onyxdroite.png"; // stocke valeur initial tete
  int* tab; // stock 3 int, direction  x direction y et indice tableau pour connaitre image tete a afficher
  unsigned long int chronos=0; /* variable qui stock le temp ecouler */
  char dure[255]; // stock la duree
  unsigned long int score=0; // stock le score
  unsigned long int scoress=0; // stock le score
  char tableauscore[5]; // stock score
  
  /* On  choisis 5 en Capacité car le score max du joueur est de
     5975=((2400-10)/2)*5 donc il y aura au max 4 char et le marqueur de fin de chaine */
  int a=-1; // si a=1 victoire, si a=0, defaite
  unsigned long int scoreetwinorloose[5];
  int x=19,y=34; // valeur pour metre la tete au milieu de l'ecran
  int** coordxy;
  int** coordserpent;
  int cpt,xnewpoke,ynewpoke;
  int i,dirx,diry; //retour de test()
  int Clavier=1; // permettre le lancement du snake
  unsigned long int suivant=0;
  suivant=Microsecondes()+CYCLE; 
  int indicetableauimg=0; 
  unsigned long int duree=0;

  char** tabimg;
  scoreetwinorloose[0]=0; /* victoire ou defaite */ 
  scoreetwinorloose[1]=0; /* score */ 
  scoreetwinorloose[2]=0; /* temps */
  


  tabimg=malloc(4*sizeof(char*));  // stock les nom des fichiers images
  tabimg[0]=malloc(255*sizeof(char));
  tabimg[1]=malloc(255*sizeof(char));
  tabimg[2]=malloc(255*sizeof(char));
  tabimg[3]=malloc(255*sizeof(char));

  strcpy(tabimg[0],"img/onyxdroite.png");
  strcpy(tabimg[1],"img/onyxgauche.png");
  strcpy(tabimg[2],"img/onyxhaut.png");
  strcpy(tabimg[3],"img/onyxbas.png");


  
 
  tab=malloc(3*sizeof(int)); //stock dirx dirx et indice

  
  
  sprintf(tableauscore,"%lu",scoress);
  EcrireTexte(55,836,tableauscore,2); 
    
  coordserpent=init();
  
 
   
  
  coordxy=poke(coordserpent);
  
  /* pour que le serpent commence par aller vers la droite*/
  
  x=coordserpent[0][0]; // on affecte a x et y la position de la tete
  y=coordserpent[1][0];
  
  while(res==0) { /* Boucle infini */
    chronos=scoreetwinorloose[2];
    duree=timer(chronos);
    scoreetwinorloose[2]=duree;
        
    if(Microsecondes()>suivant) {
      {
	suivant=Microsecondes()+CYCLE;

	if(ToucheEnAttente()==1) {
	  Clavier=Touche();
	}
	else {
	  Clavier=1;
	}
	tab= mouv(x,y,Clavier,indicetableauimg); 
        
	indicetableauimg=tab[2];
       	tmpx=x;
	tmpy=y;
	
         

	dirx=tab[0];
	diry=tab[1];
        
	tmpx+=dirx; // permet de recuperer les direction pour bougerserpent
	tmpy+=diry;
         


 
	for(i=0;i<taille;i++) {
	  
	}
	
	taille=bougerserpent(corpsadd,x,y,tmpx,tmpy,taille,coordserpent,tabimg[indicetableauimg]);
	if(corpsadd>0) { // si il mange une pokeball
	  corpsadd--; // pour permettre d'eviter que le serpent grandisse a l'infini
	}
	for(i=0;i<taille;i++) {
	  
	}
         
	
	if(tmpx<0 || tmpx>=60 || tmpy<0 || tmpy>=40) {
	  /*delimite l'ecran pour faire perdre le joueur*/ 
	  
	  a=0;
	  res=1;
	}
       	cpt=test1(coordserpent,tmpx,tmpy,taille); //test si il se rentre dedans
	if(cpt==1) {
	  
	  scoreetwinorloose[0]=0;
	  res=1; 
     
	}
       	cpt=test(coordxy,tmpx,tmpy,5); //test si il mange
	if(cpt>-1) /* comme cpt renvoi un indice c'est pour connaitre quelle pokeball il faut supprimer dans le tableau */ 
	  {
	    corpsadd+=2; //pendant 2 tours un corps va se rajouter par tour
	    score=scoreetwinorloose[1];
	    scoress=scores(score);
	    scoreetwinorloose[1]=scoress;
	    
        

	    xnewpoke=(rand()%60); // nouvelle coordoné de la pokeball
	    ynewpoke=(rand()%40);
	
	     srand (time(NULL));/* pour la nouvelle pokeball */
	    while(test(coordserpent,xnewpoke,ynewpoke,taille)==1) {
	      xnewpoke=(rand()%60);
	      ynewpoke=(rand()%40);

	    }
	    
	    coordxy[0][cpt]=xnewpoke; // cpt corespont a l'ancien indice de la pokeball manger
	    coordxy[1][cpt]=ynewpoke;

	    ChargerImage("img/pok.png",coordxy[0][cpt]*20,coordxy[1][cpt]*20,0,0,20,20); 

	  }
   
	
    
	if (taille==2400){ // si il gagne
	  
	  scoreetwinorloose[0]=1;
	  res=1;
     
	}
  
	x=tmpx; // desormais l'ancenne tete prend comme coordoné la nouvelle
	y=tmpy;
	
      }
      
    }
  }
  free(tabimg[0]); // UN MALLOC = UN FREE :p
  free(tabimg[1]);
  free(tabimg[2]);
  free(tabimg[3]);
  free(tabimg);

 
  free(coordserpent[0]);
  free(coordserpent[1]);
  free(coordserpent);
  
  free(coordxy[0]);
  free(coordxy[1]);
  free(coordxy);
  

  free(tab);
  
  return  scoreetwinorloose; // retourne tableau d'int pour  afficher les score dans le menu
/* non fonctionnelle */
  
}



 
