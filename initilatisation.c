#include "initilatisation.h"
#include "enigme.h"
//*****************************menu principale*******************************************
void affichermainbackground(component c)
{

        afficher(c.backg, c.screen);
        afficher(c.bt_j, c.screen);
        afficher(c.bt_o, c.screen);
        afficher(c.bt_q, c.screen);
        if (c.newvalue == 0)
        {
                afficher(c.bt_j_s, c.screen);
        }
        else if (c.newvalue == 1)
        {
                afficher(c.bt_o_s, c.screen);
        }
        else if (c.newvalue == 2)
        {
                afficher(c.bt_q_s, c.screen);
        }
}
void initialisationmenuprincipale(component *c, int gxm, int gym)
{

        initBackgroundprincipale(&c->backg);
        init_bt_j(&c->bt_j, gxm, gym);
        init_bt_j_s(&c->bt_j_s, gxm, gym);
        init_bt_o(&c->bt_o, gxm, gym);
        init_bt_o_s(&c->bt_o_s, gxm, gym);
        init_bt_q(&c->bt_q, gxm, gym);
        init_bt_q_s(&c->bt_q_s, gxm, gym);
}
void initBackgroundprincipale(Image *Backg)
{
        Backg->img = IMG_Load("img/MENU/1250aaa666.png");
        if (Backg->img == NULL)
        {
                printf("unable to load bitmap:%s\n", SDL_GetError());
                return;
        }
        Backg->pos1.x = 0;
        Backg->pos1.y = 0;

        Backg->pos2.x = 0;
        Backg->pos2.y = 0;
        Backg->pos2.w = 1920;
        Backg->pos2.h = 1080;
}

void init_bt_j(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_p.png"); 
        if (A->img == NULL)                                              
        {
                return;
        }
       
        A->pos1.x = 484 + gxm; 
        A->pos1.y = 281 + gym; 
        A->pos1.w = 325;       
        A->pos1.h = A->img->h; 
        
        A->pos2.x = 0;         
        A->pos2.y = 0;         
        A->pos2.w = 325;      
        A->pos2.h = A->img->h; 
}
void init_bt_j_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_p_s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = gxm + 484;
        A->pos1.y = gym + 281;
        A->pos1.w = 325;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 325;
        A->pos2.h = A->img->h;
}
void init_bt_o(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_o.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = gxm + 484;
        A->pos1.y = gym + 380;
        A->pos1.w = 325;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 325;
        A->pos2.h = A->img->h;
}
void init_bt_o_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_o_s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = gxm + 484;
        A->pos1.y = gym + 380;
        A->pos1.w = 325;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 325;
        A->pos2.h = A->img->h;
}
void init_bt_q(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_q.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = gxm + 484;
        A->pos1.y = gym + 479;
        A->pos1.w = 325;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 325;
        A->pos2.h = A->img->h;
}
void init_bt_q_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/buttonsmenu/bt_q_s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = gxm + 484;
        A->pos1.y = gym + 479;
        A->pos1.w = 325;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 325;
        A->pos2.h = A->img->h;
}
//**************************************************************************************************

//*****************************menu option*******************************************
void affichemenuroption(componentoption c2)
{
        afficher(c2.backg_op, c2.screen);
        afficher(c2.bt_v_f_n, c2.screen);
        afficher(c2.curseur_volume, c2.screen);
        if ((c2.fs == 1 && c2.newvalue != 3) || c2.newvalue == 2)
        {
                afficher(c2.bt_full_s, c2.screen);
        }
        if (c2.newvalue != 2 && c2.fs == 0 || c2.newvalue == 3)
        {
                afficher(c2.bt_normal_s, c2.screen);
        }

        if ((c2.solo == 0 && c2.newvalue != 6) || c2.newvalue == 7)
        {
                afficher(c2.bt_multi_s, c2.screen);
        }
        if ((c2.solo == 1 && c2.newvalue != 7) || c2.newvalue == 6)
        {
                afficher(c2.bt_solo_s, c2.screen);
        }
        if ((c2.controller == 0 && c2.newvalue != 5) || c2.newvalue == 4)
        {
                afficher(c2.bt_key_board_s, c2.screen);
                afficher(c2.bt_mouse_s, c2.screen);
        }
        if ((c2.newvalue == 5 && c2.newvalue != 4) || c2.controller == 1)
        {
                afficher(c2.bt_manette_s, c2.screen);
        }

        if (c2.increment == 1 || c2.newvalue == 1)
        {
                afficher(c2.btplus_s, c2.screen);
        }
        if (c2.decremente == 1 | c2.newvalue == 0)
        {
                afficher(c2.btmoin_s, c2.screen);
        }
}
void initialisationmenuoption(componentoption *c, int gxm, int gym)
{

        initBackground_op(&c->backg_op);
        init_bt_v_f_n(&c->bt_v_f_n, gxm, gym);
        init_btmoin_s(&c->btmoin_s, gxm, gym);
        init_btplus_s(&c->btplus_s, gxm, gym);
        init_bt_full_s(&c->bt_full_s, gxm, gym);
        init_bt_normal_s(&c->bt_normal_s, gxm, gym);
        init_bt_key_board_s(&c->bt_key_board_s, gxm, gym);
        init_bt_mouse_s(&c->bt_mouse_s, gxm, gym);
        init_bt_manette_s(&c->bt_manette_s, gxm, gym);
        init_bt_solo_s(&c->bt_solo_s, gxm, gym);
        init_bt_multi_s(&c->bt_multi_s, gxm, gym);
        init_curseur_volume(&c->curseur_volume, gxm, gym);
}

void initBackground_op(Image *Backg)
{
        Backg->img = IMG_Load("img/options/1250aa666.png");
        if (Backg->img == NULL)
        {
                printf("unable to load bitmap:%s\n", SDL_GetError());
                return;
        }
        Backg->pos1.x = 0;
        Backg->pos1.y = 0;

        Backg->pos2.x = 0;
        Backg->pos2.y = 0;
        Backg->pos2.w = 1920;
        Backg->pos2.h = 1080;
}

void init_bt_v_f_n(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/bt_v_f_n.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 478 + gxm;
        A->pos1.y = 200 + gym;
        A->pos1.w = 400;
        A->pos1.h = A->img->h;
        
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 400;
        A->pos2.h = A->img->h;
}

void init_btplus_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/btplus_s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 754 + gxm;
        A->pos1.y = 296 + gym;
        A->pos1.w = 9;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 9;
        A->pos2.h = A->img->h;
}


void init_btmoin_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/btmoin_s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 552 + gxm;
        A->pos1.y = 300 + gym;
        A->pos1.w = 10;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 10;
        A->pos2.h = A->img->h;
}

void init_curseur_volume(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/bt_v.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 710 + gxm;
        A->pos1.y = 258 + gym;
        A->pos1.w = 10;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = A->img->w;
        A->pos2.h = A->img->h;
}

void init_bt_full_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/bt_full-s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 493 + gxm;
        A->pos1.y = 328 + gym;
        A->pos1.w = 145;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 145;
        A->pos2.h = A->img->h;
}

void init_bt_normal_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/bt_normal-s.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 683 + gxm;
        A->pos1.y = 328 + gym;
        A->pos1.w = 145;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 145;
        A->pos2.h = A->img->h;
}

void init_bt_key_board_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/key_board.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 477 + gxm;
        A->pos1.y = 394 + gym;
        A->pos1.w = 116;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 116;
        A->pos2.h = A->img->h;
}

void init_bt_mouse_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/mouse.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 601 + gxm;
        A->pos1.y = 394 + gym;
        A->pos1.w = 116;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 116;
        A->pos2.h = A->img->h;
}

void init_bt_manette_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/manette.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 726 + gxm;
        A->pos1.y = 393 + gym;
        A->pos1.w = 116;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 116;
        A->pos2.h = A->img->h;
}

void init_bt_solo_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/solo.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 490 + gxm;
        A->pos1.y = 472 + gym;
        A->pos1.w = 163;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 163;
        A->pos2.h = A->img->h;
}

void init_bt_multi_s(Image *A, int gxm, int gym)
{
        A->img = IMG_Load("./img/background menu/settings/multi.png");
        if (A->img == NULL)
        {
                return;
        }
        A->pos1.x = 675 + gxm;
        A->pos1.y = 472 + gym;
        A->pos1.w = 162;
        A->pos1.h = A->img->h;
        //
        A->pos2.x = 0;
        A->pos2.y = 0;
        A->pos2.w = 162;
        A->pos2.h = A->img->h;
}
//*******************************************************************************************
void afficher(Image p, SDL_Surface *screen)
{
        SDL_BlitSurface(p.img, &p.pos2, screen, &p.pos1);
}
void playmusique(int options)
{
        SDL_Init(SDL_INIT_AUDIO);                          
        Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096); 
        Mix_Music *music;                                  
        if (options == 1)
        {
                music = Mix_LoadMUS("./music/menu music/OnlyMP3.net - Subway Surfers OST Extended-HOdsVMSoBg0-192k-1641238732421.mp3");
        }
        else if (options == 2)
        {
                music = Mix_LoadMUS("./music/menu music/**");
        }
        Mix_PlayMusic(music, -1); 
};
int next_button(int oldvalue, int operation, int max)
{
        if ((oldvalue > max) || (oldvalue < 0))
        {
                return 0;
        }
        if (operation)
        {
                if (oldvalue == max)
                {
                        return 0;
                }
                else
                {
                        oldvalue++;
                }
        }
        else
        {
                if (oldvalue == 0)
                {
                        return max;
                }
                else
                {
                        oldvalue--;
                }
        }
        return oldvalue;
}
void freesurfaces(component *c, componentoption *c2)
{

        liberer(c->backg);
        liberer(c->bt_j);
        liberer(c->bt_j_s);
        liberer(c->bt_o);
        liberer(c->bt_o_s);
        liberer(c->bt_q);
        liberer(c->bt_q_s);
        liberer(c2->backg_op);
        liberer(c2->bt_v_f_n);
        liberer(c2->bt_full_s);
        liberer(c2->bt_normal_s);
        liberer(c2->bt_manette_s);
        liberer(c2->bt_key_board_s);
        liberer(c2->bt_solo_s);
        liberer(c2->bt_multi_s);
        liberer(c2->btmoin_s);
        liberer(c2->btplus_s);
}
void freemusic(listmusic *mm)
{

        Mix_FreeChunk(mm->son);
        Mix_FreeMusic(mm->music);
}
void liberer(Image A)
{
        SDL_FreeSurface(A.img);
}
