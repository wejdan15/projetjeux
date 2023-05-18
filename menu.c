#include "initilatisation.h"
#include "background.h"
#include "perso.h"
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include "sauv.h"

int main(int argc, char **argv)
{
  int m = 0;      
  int i = 0;      
  int change = 1; 
  int done = 0;   
  
  int whichscreen = 0; 
  
  int gxm = 0; 
  int gym = 0; 
  
  component c;
  componentoption c2;
  listmusic mm;
  
  c2.fs = 0;                                    
  c2.solo = 1;                                  
  c2.controller = 0;                           
  mm.volume = MIX_MAX_VOLUME;                   
  mm.son = Mix_LoadWAV("./music/button-6.wav"); 
  mm.optionmusique = 1;                         

  //
  SDL_Event event; 
  
  playmusique(mm.optionmusique);
  
  Uint32 t_prev2, t_prev1; 
  while (!done)
  {
    if (change)
    {
      Mix_PlayChannel(-1, mm.son, 0);

      if (c2.fs)
      {
        /*c.screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);
        c2.screen = c.screen;
        if (!c.screen)
        {
          printf("unable to set 1920x1080 video: %s\n", SDL_GetError());
          return 1;
        }
        gxm = 350;
        gym = 200;*/

        if (c2.solo == 0)
        {

        }
      }
      else
      {
        c.screen = SDL_SetVideoMode(1250, 666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
        c2.screen = c.screen;
        if (!c.screen)
        {
          printf("unable to set 1250x666 video: %s\n", SDL_GetError());
          return 1;
        }
        gxm = 0;
        gym = 0;
      }
      initialisationmenuoption(&c2, gxm, gym);
      initialisationmenuprincipale(&c, gxm, gym);

      change = 0;
    }

    if (whichscreen == 0)
    {

      if (i == 0)
      {
        i++;

        affichermainbackground(c);
      }

      SDL_PollEvent(&event); 
      switch (event.type)
      {
        
      case SDL_QUIT:
        done = 1;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {

        case SDLK_ESCAPE:
          done = 1;
          break;

        case SDLK_DOWN:
        case SDLK_UP:
          if (SDL_GetTicks() - t_prev2 > 150) 
          {
            c.newvalue = next_button(c.newvalue, event.key.keysym.sym == SDLK_DOWN, 2);
            affichermainbackground(c);
            t_prev2 = SDL_GetTicks();
          }
          break;

          break;

        case SDLK_p:
          // Mix_PlayChannel (-1,son,0);
          c.newvalue = 0;
          affichermainbackground(c);

          break;

        case SDLK_o:
          // Mix_PlayChannel (-1,son,0);
          c.newvalue = 1;
          affichermainbackground(c);

          break;

        case SDLK_q:
          // Mix_PlayChannel (-1,son,0);
          c.newvalue = 2;
          affichermainbackground(c);

          break;

        case SDLK_RETURN:
          if (c.newvalue == 0)
          {
            whichscreen = 1;
          }
          else if (c.newvalue == 1)
          {
            whichscreen = 2;
          }
          else
          {
            done = 1;
          }

          break;
        }

        break;

      case SDL_MOUSEMOTION:
        if (c.newvalue != 0 && event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 281 + gym && event.motion.y <= 370 + gym)
        {
          c.newvalue = 0;
          affichermainbackground(c);
        }
        // bt_options
        else if (c.newvalue != 1 && event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 380 + gym && event.motion.y <= 469 + gym)
        {
          c.newvalue = 1;
          affichermainbackground(c);
        }
        // bt_quit
        else if (c.newvalue != 2 && event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 479 + gym && event.motion.y <= 568 + gym)
        {
          c.newvalue = 2;
          affichermainbackground(c);
        }
        else

            if (c.newvalue != 5 && !(event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 281 + gym && event.motion.y <= 370 + gym) && !(event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 380 + gym && event.motion.y <= 469 + gym) && !(event.motion.x >= 484 + gxm && event.motion.x <= 809 + gxm && event.motion.y >= 479 + gym && event.motion.y <= 568 + gym))
        {
          c.newvalue = 5;
          affichermainbackground(c);
        }
        break;

      case SDL_MOUSEBUTTONDOWN:

        if (c.newvalue == 0)
        { /*Mix_PlayChannel (-1,son,0);*/
          whichscreen = 1;
        }
        else if (c.newvalue == 1)
        { /*Mix_PlayChannel (-1,son,0);*/
          m = 0;
          whichscreen = 2;
        }
        else
        {
          done = 1;
        }

        break;
      }
    }
else if(whichscreen==1)
{

printf("hello");
 whichscreen=solo(c.screen);
if (whichscreen ==2 ) 
//whichscreen=0 ; 
	c2.newvalue=1;
c.screen = SDL_SetVideoMode(1250,666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
mm.son = Mix_LoadWAV("./music/button-6.wav");  
//break;
//whichscreen=0;
}




    else if (whichscreen == 2)
    {

      if (m == 0)
      {
        m++;
        affichemenuroption(c2);
      }

      SDL_PollEvent(&event);
      switch (event.type)
      {
      case SDL_QUIT:
        done = 1;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_r:
          whichscreen = 0;
          i = 0;
          break;
        case SDLK_p:
          if (Mix_PausedMusic() == 1) 
          {
            Mix_ResumeMusic(); 
          }
          else
          {
            Mix_PauseMusic(); 
          }
          break;
        case SDLK_BACKSPACE:
          Mix_RewindMusic(); 
          break;
        case SDLK_ESCAPE:
          break;
        case SDLK_DOWN:
        case SDLK_UP:
          if (SDL_GetTicks() - t_prev2 > 150)
          {
            c2.newvalue = next_button(c2.newvalue, event.key.keysym.sym == SDLK_DOWN, 7);
            affichemenuroption(c2);
            t_prev2 = SDL_GetTicks();
          }
          break;

          break;
        }
        break;

      case SDL_MOUSEMOTION:
        
        if (event.motion.x >= 756 + gxm && event.motion.x <= 765 + gxm && event.motion.y >= gym + 295 && event.motion.y <= 303 + gym)
        {
          if (c2.newvalue != 1)
          {
            c2.newvalue = 1;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 552 + gxm && event.motion.x <= 562 + gxm && event.motion.y >= gym + 298 && event.motion.y <= 302 + gym)
        {
          if (c2.newvalue != 0)
          {
            c2.newvalue = 0;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 500 + gxm && event.motion.x <= 645 + gxm && event.motion.y >= gym + 321 && event.motion.y <= 371 + gym)
        {
          if (c2.newvalue != 2)
          {
            c2.newvalue = 2;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 688 + gxm && event.motion.x <= 834 + gxm && event.motion.y >= 319 + gym && event.motion.y <= 371 + gym)
        {
          if (c2.newvalue != 3)
          {
            c2.newvalue = 3;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
       
        else if (event.motion.x >= 482 + gxm && event.motion.x <= 598 + gxm && event.motion.y >= 390 + gym && event.motion.y <= 441 + gym)
        {
          if (c2.newvalue != 4)
          {
            c2.newvalue = 4;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 606 + gxm && event.motion.x <= 722 + gxm && event.motion.y >= 390 + gym && event.motion.y <= 442 + gym)
        {
          if (c2.newvalue != 4)
          {
            c2.newvalue = 4;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
      
        else if (event.motion.x >= 731 + gxm && event.motion.x <= 846 + gxm && event.motion.y >= 369 + gym && event.motion.y <= 441 + gym)
        {
          if (c2.newvalue != 5)
          {
            c2.newvalue = 5;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 495 + gxm && event.motion.x <= 657 + gxm && event.motion.y >= 468 + gym && event.motion.y <= 530 + gym)
        {
          if (c2.newvalue != 6)
          {
            c2.newvalue = 6;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        
        else if (event.motion.x >= 680 + gxm && event.motion.x <= 842 + gxm && event.motion.y >= 465 + gym && event.motion.y <= 528 + gym)
        {
          if (c2.newvalue != 7)
          {
            c2.newvalue = 7;
            affichemenuroption(c2);
            Mix_PlayChannel(-1, mm.son, 0);
          }
        }
        else 
        {
          c2.newvalue = -1;
          affichemenuroption(c2);
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
        if (c2.newvalue == 1) 
        {
          if (mm.volume < 128 && ((SDL_GetTicks() - t_prev1) > 100))
          {
            mm.volume += 20;
            Mix_VolumeMusic(mm.volume);
            if (c2.curseur_volume.pos1.x < 710 + gxm)
              c2.curseur_volume.pos1.x += 30;
            affichemenuroption(c2);
            t_prev1 = SDL_GetTicks();
          }
        }
        else if (c2.newvalue == 0) 
        {
          if (mm.volume > 0 && ((SDL_GetTicks() - t_prev1) > 100))
          {
            mm.volume -= 20; 
            Mix_VolumeMusic(mm.volume);
            if (c2.curseur_volume.pos1.x > 580 + gxm)
              c2.curseur_volume.pos1.x -= 30;
            affichemenuroption(c2);
            t_prev1 = SDL_GetTicks();
          }
        }

        else
        {
          if (c2.newvalue == 2) 
          {

            c2.fs = 1;
            change = 1;
          }
          else if (c2.newvalue == 3) 
          {

            c2.fs = 0;
            change = 1;
          }
          else if (c2.newvalue == 4) 
          {
            Mix_PlayChannel(-1, mm.son, 0);
            c2.controller = 0;
          }
          else if (c2.newvalue == 5) 
          {
            Mix_PlayChannel(-1, mm.son, 0);
            c2.controller = 1;
          }
          else if (c2.newvalue == 6) 
          {

           whichscreen=solo(c.screen);
if (whichscreen ==2 ) 
	c2.newvalue=1;
c.screen = SDL_SetVideoMode(1250,666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
mm.son = Mix_LoadWAV("./music/button-6.wav");  
//break;

          }
          else if (c2.newvalue == 7) 
          {

          
        printf("hiiieiie");
    whichscreen =  duo(c.screen);
if (whichscreen ==2 ) 
	c2.newvalue=1;
c.screen = SDL_SetVideoMode(1250,666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
mm.son = Mix_LoadWAV("./music/button-6.wav");  
          }
        }

      }
    }
    SDL_Flip(c.screen); 
  }
 
}

int duo(SDL_Surface *screen)
{
char *fscore = "score.txt";
background b;
SDL_Event e;
int direction ;
int pas=30 ;

    Personne p,p2;
p.position.x = 50;
p2.position.x = 760;
    initPerso(&p);
    initPerso(&p2);
    SDL_Event event;
    
    int speed = 3;
    int running = 1;

screen=SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
initBack(&b);
initBack2(&b);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1)
 {
  printf("%s",Mix_GetError());
 }
Mix_Music *music;
music=Mix_LoadMUS("music1.mp3");
Mix_PlayMusic(music,-1);

  int done=1;
 while(done==1)
     {
 aficherBack(b,screen);
    aficherBack2(b,screen);
    afficherPerso(p, screen);
    afficherPerso(p2, screen);
	SDL_Flip(screen);
   
 SDL_PollEvent(&e);
	movePerso(&p);
 const Uint8 *keystate = SDL_GetKeyState(NULL);
    
    if (keystate[SDLK_q]) {
        if(p2.position.x >720)
        p2.position.x -= speed;
    }
    if (keystate[SDLK_d]) {
        if(p2.position.x <1300)
        p2.position.x += speed;
    }
    {


 int gravity = 3; 
    static int jump_height = 0; 


    if (keystate[SDLK_z] && jump_height == 0) {
        jump_height = 20;
    }    
    p2.position.y -= jump_height;
    jump_height -= gravity; 

    if (p2.position.y >= 300) {
        p2.position.y = 300;
        jump_height = 0;
    }

    }
    saut(&p);
    //afficherPerso(p, screen);
   // afficherPerso(p2, screen);
	//SDL_Flip(screen);
  switch(e.type)
     {
           case SDL_QUIT :
                 done=0;
           break;


         case SDL_KEYDOWN:
           switch(e.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                      done = 0 ;
                break;
                case SDLK_RIGHT:
                     direction=1;
                     b.direction=0;
                break;
                case SDLK_LEFT:
                     direction=2;
                     b.direction=1;
                break;
                case SDLK_DOWN:
                     direction=4;
                break;
                case SDLK_d:
                     direction=5;
                    b.direction=0;
                break;
                case SDLK_q:
                     direction=6;
                    b.direction=1;
                break;
                case SDLK_s:
                     direction=8;
               break;
             } 
     // animerBack(&b,screen);
             if (p.position.x>220 ) {
      scrolling(&b,direction,pas);
  }

      if (p2.position.x>750  ) {
      scrolling2(&b,direction,pas);}
      aficherBack(b,screen);
      aficherBack2(b,screen);
     // SDL_Flip(screen);
 SDL_Delay(5);
           break;
     } 
     }  
return 2 ;

}

 int solo(SDL_Surface *screen)
{

char *fscore = "score.txt";
Boutton bo,b1;
bo.Img[0]=IMG_Load("botton1.png");
bo.Img[1]=IMG_Load("charge1.png");
bo.Pos.x=600;
bo.Pos.y=0;
b1.Img[0]=IMG_Load("botton2.png");
b1.Img[1]=IMG_Load("sauv2.png");
b1.Pos.x=600;
b1.Pos.y=200;
background b;
SDL_Event e;
int direction ;
int pas=30 ;

    Personne p,p2;
p.position.x = 50;
p2.position.x = 760;
    initPerso(&p);
    initPerso(&p2);
    SDL_Event event;
    
    int speed = 3;
    int running = 1;

screen=SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
initBacksolo(&b);
//initBack2(&b);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1)
 {
  printf("%s",Mix_GetError());
 }
Mix_Music *music;
music=Mix_LoadMUS("music1.mp3");
Mix_PlayMusic(music,-1);
 bo.son= Mix_LoadWAV("clic.wav");

  int done=1;

while(done==1)
     {
      aficherBack(b,screen);
      afficherPerso(p, screen);
 SDL_BlitSurface(bo.Img[0],NULL,screen,&bo.Pos);
SDL_BlitSurface(b1.Img[0],NULL,screen,&b1.Pos);
      SDL_Flip(screen);

 SDL_PollEvent(&e);
printf("x : %d  y: %d\n",e.motion.x ,e.motion.y);
	movePersosolo(&p);
 const Uint8 *keystate = SDL_GetKeyState(NULL);
    



 int gravity = 3; 
    static int jump_height = 0; 


    if (keystate[SDLK_z] && jump_height == 0) {
        jump_height = 20;
    }    
    p2.position.y -= jump_height;
    jump_height -= gravity; 

    if (p2.position.y >= 300) {
        p2.position.y = 300;
        jump_height = 0;
    }

    
    saut(&p);
       

  switch(e.type)
     {  SDL_PollEvent(&e);
           case SDL_QUIT :
                 done=0; 
           break;

       case SDL_MOUSEBUTTONUP:
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if (e.button.x > 600 && e.button.x < 700 && e.button.y > 0 && e.button.y < 80)
                    {
					    
			 charger(&p,&b,"test.txt");
                    }
                    else if (e.button.x > 600 && e.button.x < 700 && e.button.y > 200 && e.button.y < 280)
                    {
	          sauvegarder(p,b,"test.txt");
                   
                    }
                    
                }
                break;


            case SDL_MOUSEMOTION:
printf("test\n\n");
                if (e.motion.x > 600 && e.motion.x < 700 && e.motion.y > 0 && e.motion.y < 180)
                { 
                    printf("dfrzgsdgsdgsd");

                    Mix_PlayChannel(-1,  bo.son, 0);
                    SDL_BlitSurface(bo.Img[1],NULL,screen,&bo.Pos);
                    SDL_Flip(screen);
                }
                else if (e.motion.x > 600 && e.motion.x < 700 && e.motion.y > 200 && e.motion.y < 280)
                {
                    Mix_PlayChannel(-1,  bo.son, 0);
                   SDL_BlitSurface(b1.Img[1],NULL,screen,&b1.Pos);

                    SDL_Flip(screen);
                }
               
                break;

         case SDL_KEYDOWN:
           switch(e.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                      done = 0 ;
                break;
                case SDLK_RIGHT:
                     direction=1;
                     b.direction=0;
                break;
                case SDLK_LEFT:
                     direction=2;
                     b.direction=1;
                break;
                case SDLK_DOWN:
                     direction=4;
                break;
                case SDLK_d:
                     direction=5;
                    b.direction=0;
                break;
                case SDLK_q:
                     direction=6;
                    b.direction=1;
                break;
                case SDLK_s:
                     direction=8;
               break;
             } 
             if (p.position.x>0 ) {

      scrolling(&b,direction,pas);}
if (p.position.x==410 ) {
int d=enigm (screen); 
screen=SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

      //scrolling(&b,direction,pas);
}
 
     
      SDL_Delay(5);
           break;
        } 
     }
Mix_FreeMusic(music);

return 2;
}


int enigm (SDL_Surface *screen) 
{
    SDL_Rect p;
    TTF_Init(); 
    enigme e;
    e.debut=clock();

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

}

