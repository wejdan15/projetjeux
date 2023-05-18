#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

//*********************definition des structures****************************************
// structure qui contient l ensemble des paramets pour preparer une imager a etre bliter
struct Image
{
	SDL_Rect pos1;	  // to save the x,y,w,h cordinates of an image //position of display in the screen
	SDL_Rect pos2;	  // position of the photo taken
	SDL_Surface *img; // contain the img
};
typedef struct Image Image;
// structure qui contient les composant de menu principale
struct component
{

	int newvalue;
	Image backg, bt_j, bt_j_s, bt_o, bt_o_s, bt_q_s, bt_q;
	SDL_Surface *screen;
	Mix_Chunk *son;
};
typedef struct component component;
// structure qui contient les composant de menu option
struct componentoption
{
	int fs, controller, solo, newvalue, increment, decremente;
	Image backg_op, bt_v_f_n, btmoin_s, btplus_s, bt_full_s, bt_normal_s, bt_key_board_s, bt_mouse_s, bt_manette_s, bt_solo_s, bt_multi_s, curseur_volume;
	SDL_Surface *screen;
	Mix_Chunk *son;
};
typedef struct componentoption componentoption;
// structure de music
struct listmusic
{
	int volume;
	Mix_Music *music;
	Mix_Chunk *son;
	int optionmusique;
};
typedef struct listmusic listmusic;
//***********************************************************************************


//*****************************menu principale*******************************************
// afficher menu principale
 int duo(SDL_Surface *ecran);
 int solo(SDL_Surface *ecran);
int enigm(SDL_Surface *screen) ;
void affichermainbackground(component c);
// fonction qui regroupe l appele des fonctions d'initilialisation du menu prrincipale
void initialisationmenuprincipale(component *c, int gxm, int gym);
// ensemble de fonction pour initiliser les images (cordonnes,image)
// image de background
void initBackgroundprincipale(Image *Backg);
// buttonplay
void init_bt_j(Image *A, int gxm, int gym);
// buttonplayselected
void init_bt_j_s(Image *A, int gxm, int gym);
// buttonoptions
void init_bt_o(Image *A, int gxm, int gym);
// buttonoptionsselected
void init_bt_o_s(Image *A, int gxm, int gym);
// buttonquit
void init_bt_q(Image *A, int gxm, int gym);
// buttonquitselected
void init_bt_q_s(Image *A, int gxm, int gym);
//******************************************************************************************

//*****************************menu option*******************************************
// afficher menu option
void affichemenuroption(componentoption c2);
// fonction qui regroupe l appele des fonctions d'initilialisation dumenu option
void initialisationmenuoption(componentoption *c, int gxm, int gym);
// ensemble de fonction pour initiliser les images (cordonnes,image)
void initBackground_op(Image *Backg);
// allwithoutselection
void init_bt_v_f_n(Image *A, int gxm, int gym);
// increment volume
void init_btmoin_s(Image *A, int gxm, int gym);
// decremnte volume
void init_btplus_s(Image *A, int gxm, int gym);
// curseur volume
void init_curseur_volume(Image *A, int gxm, int gym);
// full screen
void init_bt_full_s(Image *A, int gxm, int gym);
// normale screen
void init_bt_normal_s(Image *A, int gxm, int gym);
// keyboard
void init_bt_key_board_s(Image *A, int gxm, int gym);
// mouse
void init_bt_mouse_s(Image *A, int gxm, int gym);
// manette
void init_bt_manette_s(Image *A, int gxm, int gym);
// solo
void init_bt_solo_s(Image *A, int gxm, int gym);
// duo
void init_bt_multi_s(Image *A, int gxm, int gym);
//*******************************************************************************************
void afficher(Image p, SDL_Surface *screen);
// function to play the musique
void playmusique(int options);
// fonction pour determiner le nouveau bouton selectionner dans le menu option
int next_button(int oldvalue, int operation, int max);
// focntion qui regroupe all the component that goona be deleted
void freesurfaces(component *c, componentoption *c2);
// focntion qui regroupe all sounds that goona be deleted
void freemusic(listmusic *mm);
// librer les allocation
void liberer(Image A);

#endif
