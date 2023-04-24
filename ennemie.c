
#include "ennemie.h"




int
nb_frame1=12,
ennemie_h=250,
ennemie_w=86,
ennemie_y=100,
ennemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *tableau,Ennemie *e)
{	

for (int j=0;j<nb_frame1; j++)
	{
	tableau[j].h=ennemie_h;
	tableau[j].w=ennemie_w;
	tableau[j].x = j*ennemie_w;
	tableau[j].y = 0;
        } 



}




void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("ENNEMIE.png"); 
   
    e->pos_ennemie.x = 900;
    e->pos_ennemie.y = 400;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
   
    
    
}



void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}


void animerEnnemi(Ennemie *e)
{   if (e->frame_ennemie >=0 && e->frame_ennemie <(nb_frame1-1)) 
 e->frame_ennemie++;
    if ( e->frame_ennemie ==(nb_frame1-1)) 
       e->frame_ennemie=0;

}


void update_ennemie(Ennemie *e)
{
	
if ((e->pos_ennemie.y>=100) && (e->direction==0))
e->pos_ennemie.y-=5;
if (e->pos_ennemie.y<=100)
e->direction=1;
if ((e->pos_ennemie.y<=600) && (e->direction==1))
e->pos_ennemie.y+=5;
if (e->pos_ennemie.y>=600)
e->direction=0;
	animerEnnemi(e);
	

}
/////////////////////////////////////////////////////////////////////:
int collisionBB(SDL_Rect posp,SDL_Rect pose)
{
	

if ((posp.x + posp.w< pose. x) || (posp.x> pose.x + pose. w) ||
(posp.y + posp.h< pose. y) || (posp.y> pose. y + pose.h ))
return 0;
else 
return 1;
 
}
////////////////////////////////////////////////////////////////////////


/***************************************************************/
void afficher_perso(personnage p , SDL_Surface *screen)
{
   SDL_BlitSurface(p.perso,NULL, screen, &p.perso_pos);

}
void initialiser_perso(personnage *p)
{
    p->perso= IMG_Load("per.png");
    p->perso_pos.x = 100;
    p->perso_pos.y = 100;
    p->perso_pos.h = 281;
    p->perso_pos.w = 217;
    
    
}




