#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "ennemie.h"

int main()
{
    int hauteur_fenetre = 765,a=1,an=1,done=1,
        largeur_fenetre = 1360;
	

   

	SDL_Init(SDL_INIT_VIDEO);
///////////////////////////////////////////////
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
	SDL_WM_SetCaption("Mariem", NULL); 
//////////////////////////////////////////////
 	SDL_Surface *background ;
	SDL_Surface *sorry ;
	SDL_Rect pos_sorry ; 
	SDL_Rect background_pos;
	background = IMG_Load("BG.jpg");
	background_pos.x = 0;
	background_pos.y = 0;
	sorry=IMG_Load("youlost.png");
	pos_sorry.x=300;
	pos_sorry.y=300;


	
	personnage p;
	
	Ennemie en;
	 

	initialiser_perso (&p) ;
	
	initEnnemi (&en) ;
 

	

	SDL_Event event;
        while (done==1)
	{ 	 
		
	SDL_PollEvent(&event);

           
                        switch (event.type) 
                        {

                        case SDL_QUIT: 
                                done = 0;
                                break;


                        case SDL_KEYDOWN:                     
                                switch (event.key.keysym.sym) 
                                {                           
                                case SDLK_RIGHT: 
                               
                                      p.perso_pos.x += 10;
                                        break;
                                case SDLK_LEFT: 
                                        p.perso_pos.x -= 10;                                                                     
                                        break;
                                case SDLK_UP: 
                                        p.perso_pos.y -= 10;
                                        break;
                                case SDLK_DOWN: 
                                      p.perso_pos.y += 10;
                                        break;
                                }
                        } 


	
	
	update_ennemie (&en);
 
	
	SDL_BlitSurface(background,NULL,screen,&background_pos);
	
   	
   	if (collisionBB(p.perso_pos,en.pos_ennemie)==1) 
		an=0;
   	
   	if (an==1) { afficher_perso(p ,screen); 	
			afficherEnnemi (en ,screen);}
   	else{
    	 
   	SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);
 	 
   	}

	SDL_Delay(10);
	SDL_Flip(screen);

	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(sorry);
	SDL_Quit();

    return 0;
}

