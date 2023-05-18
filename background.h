#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

typedef struct
{
SDL_Surface *backg;
SDL_Rect pos_background_ecran;
SDL_Rect pos_background_ecran2;
SDL_Rect pos_background_affiche;
SDL_Rect pos_background_affiche2;
int direction;
int pas;
SDL_Surface  *t[2][4];
SDL_Rect pos_animer;
int num;
//Mix_Music *music;
}background;

typedef struct
{
int score;
int temps;
char playername[20];
}scoreinfo;

void initBack(background *b);
void initBacksolo(background *b);
void initBack2(background *b);
void aficherBack(background b, SDL_Surface *screen);
void aficherBack2(background b, SDL_Surface *screen);
void scrolling (background * b, int direction ,int pas);
void scrolling2 (background * b, int direction ,int pas);
void animerBack (background *b, SDL_Surface *screen);
void blitanim(background b,SDL_Surface *screen);
//void saveScore(scoreinfo  s,char *fscore);
//void bestScore(char *fscore,scoreinfo t[]);

#endif // BACKGROUND_H_INCLUDED
