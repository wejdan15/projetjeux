#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
void main()
{
    enigme e ;
    SDL_Rect p;
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    e.debut=clock();
    SDL_Surface *screen;
    SDL_Surface *back=NULL,*b;
    SDL_Rect pos,bpos;
    int done=1,done1=1,rep=0,temps=0;
    SDL_Event event;
    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE  );
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    
    
    back= IMG_Load("background.png");
    pos.x=0;
    pos.y=0;

    p.x=680;
    p.y=320;


    image boutoun[3],winorlose[2];

    initImages(boutoun,winorlose);
    genererEnigme(&e,"enigme.txt");
    
    e.temps=0;
    while(done1)
    {
        while(done)
        {
        animerEnigme(&e);
            
            if(e.temps==9)
                done=0;

            SDL_BlitSurface(back,NULL,screen,&pos);
            SDL_BlitSurface(e.horloge[e.temps],NULL,screen,&p);
            
            afficherbutton(boutoun[0], screen);
            afficherbutton(boutoun[1], screen);
            afficherbutton(boutoun[2], screen);
            
            afficherEnigme(&e,screen);
            SDL_Flip(screen);
            SDL_PollEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT:
            {
                done=0;
            }
            break;
            
            case SDL_MOUSEMOTION:

                rep=0;

                if (event.motion.x>220 && event.motion.y>400 && event.motion.x<520 && event.motion.y<550 )
                {
                    rep=1;


                }
                if (event.motion.x>570 && event.motion.y>400 && event.motion.x<870 && event.motion.y<550)
                {
                    rep=2;

                }
                if (event.motion.x>920 && event.motion.y>400 && event.motion.x<1220 && event.motion.y<550 )
                {
                    rep=3;

                }
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (rep!=0)

                        done=0;
                }
            }
        }
        SDL_PollEvent(&event);
        switch(event.type)
            {
            case SDL_QUIT:
            {
                done1=0;
            }
            break;
           }
        if(rep==e.reponsejuste)
        {
            afficherbutton(winorlose[0], screen);
SDL_Flip(screen) ;
SDL_Delay(3000) ;
done=0; 
done1=0; 


        }
        else
        {
            afficherbutton(winorlose[1], screen);
SDL_Flip(screen) ;
SDL_Delay(3000) ;
done=0; 
done1=0;
        }
        
    }
    SDL_Quit();
}


