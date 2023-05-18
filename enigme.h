#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct
{



           SDL_Surface *reponses[3], *quest,*horloge[10];

           SDL_Rect posQuestion;
           SDL_Rect posRepones[3];

 			int choix_question;
       int reponsejuste,temps;
           char question[200];  
           char r1[30];
           char r2[30];
           char r3[30];  
    time_t debut,fin;
}enigme;

typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}image;

void initImages(image boutoun[],image repp[]);
void afficherbutton(image a, SDL_Surface *screen);
 
//load image that needs enigme
void load_horloge_images(enigme *e);

void genererEnigme(enigme *e,char *nomfichier);
void afficherEnigme(enigme *e,SDL_Surface *screen);
void animerEnigme (enigme *e);
#endif




