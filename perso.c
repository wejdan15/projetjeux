
/**

* @file perso.c
* @brief  the c file of my character movement program
* @author jawher
* @version 0.1
* @date may 5, 2023

*/
#include "perso.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>



/**
* @brief To initialize the character .
* @param b the character
* @param url the url of the image
* @return Nothing
*/
void initPerso(Personne *p)
{

    p->surface = IMG_Load("taswira.png");
    
    p->position.y = 450;
    p->position.w = 0;
    p->position.h = 0;

   
}

/**
* @brief To show the character 
* @param b the character
* @return Nothing
*/

void afficherPerso(Personne p, SDL_Surface * screen)
{

    SDL_BlitSurface(p.surface, NULL, screen, &p.position);
}

/**
* @brief To move the person in directions .
* @param b the chracter
* @return Nothing
*/
void movePerso(Personne *p)
{
   
    const Uint8 *keystate = SDL_GetKeyState(NULL);
    int speed = 3;
  

    if (keystate[SDLK_LSHIFT]){
      
        speed = 9;
       
    }

   
    
    if (keystate[SDLK_LEFT]) {
        if(p->position.x>0 ){
        p->position.x -= speed;}
    }
    if (keystate[SDLK_RIGHT]) {
        if(p->position.x<665)
        p->position.x += speed;
    }

}
void movePersosolo(Personne *p)
{
   
    const Uint8 *keystate = SDL_GetKeyState(NULL);
    int speed = 3;
  

    if (keystate[SDLK_LSHIFT]){
      
        speed = 9;
       
    }

   
    
    if (keystate[SDLK_LEFT]) {
        if(p->position.x>0 ){
        p->position.x -= speed;}
    }
    if (keystate[SDLK_RIGHT]) {
        if(p->position.x<1000)
        p->position.x += speed;
    }

}

/**
* @brief To animate the character .
* @param b the character
* @return Nothing
*/

void animerPerso (Personne* p)
{

    int frame = 0; 
    int animation_speed = 60; 
    int animation_counter = 0; 
    SDL_Surface *sprite_sheet = NULL; 

    
    if (!sprite_sheet) {sprite_sheet = IMG_Load("spritesheet.png");
    }

  
    int frame_width = 200;
    int frame_height = 200;
    int num_frames = 8;
    int animation_start_frame = 1;
    
 
}
/**
* @brief To make the character jump .
* @param b the character
* @return Nothing
*/

void saut (Personne* p)
{
    const Uint8 *keystate = SDL_GetKeyState(NULL);
    int gravity = 3; 
    static int jump_height = 0; 


    if (keystate[SDLK_SPACE] && jump_height == 0) {
        jump_height = 20;
    }
    
    
    p->position.y -= jump_height;
    jump_height -= gravity; 

    
    if (p->position.y >= 300) {
        p->position.y = 300;
        jump_height = 0;
    }
    
}


	

