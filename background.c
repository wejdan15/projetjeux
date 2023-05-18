#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initBacksolo(background *b)
{
b->backg=NULL;
b->backg=IMG_Load("map.png"); 

b->pos_background_ecran.x=0;
b->pos_background_ecran.y=0;

b->pos_background_affiche.x=0;
b->pos_background_affiche.y=0;

b->pos_background_affiche.h=480;
b->pos_background_affiche.w=1300;

//b->music=Mix_LoadMUS("music1.mp3");

b->t[0][0]=IMG_Load("0.png");
b->t[0][1]=IMG_Load("1.png");
b->t[0][2]=IMG_Load("2.png");
b->t[0][3]=IMG_Load("3.png");
b->t[1][0]=IMG_Load("00.png");
b->t[1][1]=IMG_Load("01.png");
b->t[1][2]=IMG_Load("02.png");
b->t[1][3]=IMG_Load("03.png");


b->pos_animer.x=0;
b->pos_animer.y=0;
b->num=0;
}



void initBack(background *b)
{
b->backg=NULL;
b->backg=IMG_Load("map.png"); 

b->pos_background_ecran.x=0;
b->pos_background_ecran.y=0;

b->pos_background_affiche.x=0;
b->pos_background_affiche.y=0;

b->pos_background_affiche.h=480;
b->pos_background_affiche.w=750;

//b->music=Mix_LoadMUS("music1.mp3");

b->t[0][0]=IMG_Load("0.png");
b->t[0][1]=IMG_Load("1.png");
b->t[0][2]=IMG_Load("2.png");
b->t[0][3]=IMG_Load("3.png");
b->t[1][0]=IMG_Load("00.png");
b->t[1][1]=IMG_Load("01.png");
b->t[1][2]=IMG_Load("02.png");
b->t[1][3]=IMG_Load("03.png");


b->pos_animer.x=0;
b->pos_animer.y=0;
b->num=0;
}
void initBack2(background *b)
{ 
b->pos_background_ecran2.x=750;
b->pos_background_ecran2.y=0;

b->pos_background_affiche2.x=0;
b->pos_background_affiche2.y=0;

b->pos_background_affiche2.h=480;
b->pos_background_affiche2.w=3437;
}

void aficherBack(background b,SDL_Surface *screen)
{
SDL_BlitSurface(b.backg,&b.pos_background_affiche,screen,&b.pos_background_ecran);
//Mix_PlayMusic(b.music,-1);
}

void aficherBack2(background b,SDL_Surface *screen)
{
SDL_BlitSurface(b.backg,&b.pos_background_affiche2,screen,&b.pos_background_ecran2);
}

 void scrolling (background * b, int direction,int pas)
   {
 if(direction==1 && b->pos_background_affiche.x<1800) 
 b->pos_background_affiche.x+=pas;
  
 if(direction==2 && b->pos_background_affiche.x>0) 
 b->pos_background_affiche.x-=pas;

 if(direction==4 && b->pos_background_affiche.y<0) 
 b->pos_background_affiche.y+=pas;
   }

 void scrolling2 (background * b, int direction,int pas)
   {
 if(direction==5 && b->pos_background_affiche2.x<2687) 
 b->pos_background_affiche2.x+=pas;
  
 if(direction==6 && b->pos_background_affiche2.x>0) 
 b->pos_background_affiche2.x-=pas;

 if(direction==8 && b->pos_background_affiche2.y<0) 
 b->pos_background_affiche2.y+=pas;
   }

// void animerBack (background *b,SDL_Surface *screen)
// {
// if (b->num==3)
// b->num=0;
// else 
// b->num++;
// }

// void blitanim(background b,SDL_Surface *screen)
// {
// SDL_BlitSurface(b.t[b.direction][b.num],NULL,screen,&b.pos_animer);
// SDL_Delay(50);
// }


void saveScore(scoreinfo s, char *fscore)
 {
     FILE *f = fopen(fscore,"a");    
     fprintf(f,"%s %d %d\n",s.playername,s.score,s.temps);
     fclose(f);
 }

// void bestScore(char *fscore,scoreinfo t[])
// {
// FILE *f;
//     int i, j;
//     scoreinfo aux;
//     int size = 0;

// f = fopen(fscore,"r");

// while (!feof(f))
// {
// fscanf(f,"%s %d %d", &t[size].playername,&t[size].score,&t[size].temps);
// size++;
// }
// fclose(f);

// for (i = 0; i < size-1; i++) 
//    {
//         for (j = i+1; j < size; j++) 
//        {
//             if (t[i].score < t[j].score || (t[i].score == t[j].score && t[i].temps > t[j].temps)) 
//            {
//                 aux = t[i];
//                 t[i] = t[j];
//                 t[j] = aux;
//             }
//         }
//     }

// printf("Meilleurs scores:\n");
//     for (i = 0;i<3;i++)
//      {
//       printf("%d: NOM: %s - SCORE: %d  - TEMPS: %d s\n", i+1, t[i].playername,t[i].score,t[i].temps);
//      }
// }
