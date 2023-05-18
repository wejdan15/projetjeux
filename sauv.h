#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED
#include "perso.h"
#include<SDL/SDL_mixer.h>
#include "background.h"
struct Boutton
{
    SDL_Surface* Img[2];
    SDL_Rect Pos;
       Mix_Chunk *son;
};
typedef struct Boutton Boutton;


void sauvegarder (Personne p,background b, char * nomfichier);
int charger (Personne *p,background *b,  char * nomfichier);

#endif
