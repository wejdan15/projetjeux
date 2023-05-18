#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <SDL/SDL.h>


/**

* @file perso.h
* @brief  the header of my character movment program
* @author jawher
* @version 0.1
* @date may 05, 2023

*/

/**
* @struct Character
* @brief struct for character
*/
typedef struct
{
    SDL_Surface* surface; /*!< Surface. */
    SDL_Rect position; /*!< Rectangle*/
} Personne;
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void movePerso(Personne *p);
void movePersosolo(Personne *p);
void animerPerso(Personne* p);
void saut (Personne* p);
#endif
