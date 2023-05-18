#include "enigme.h"
void initImages(image boutoun[], image winorlose[])
{

    int i;

    winorlose[0].img = IMG_Load("win.png");
    winorlose[1].img = IMG_Load("lose.png");

    winorlose[0].pos.x = 0;
    winorlose[0].pos.y = 0;
    winorlose[1].pos.x = 0;
    winorlose[1].pos.y = 0;

    for (i = 0; i < 3; i++)

        boutoun[i].img = IMG_Load("button.png");

    boutoun[0].pos.x = 200;
    boutoun[0].pos.y = 400;

    boutoun[1].pos.x = 550;
    boutoun[1].pos.y = 400;

    boutoun[2].pos.x = 900;
    boutoun[2].pos.y = 400;
}

void genererEnigme(enigme *e, char *nomfichier)

{
    

    int numerodequestion = 0;

    srand(time(0));

    e->choix_question = (rand() % (3));

    SDL_Color couleurNoire = {0, 0, 0};
    TTF_Font *police;

    police = TTF_OpenFont("font.otf", 30);

    FILE *F;

    F = fopen(nomfichier, "r");

    if (F != NULL)
    {
        
        while ((fscanf(F, "%s , %s , %s , %s  %d\n", e->question, e->r1, e->r2, e->r3, &(e->reponsejuste)) != EOF) && (numerodequestion != e->choix_question))
        {
            numerodequestion++;
        }
    }
    else
        printf("erreur lors de l'execution du fichier\n");
    fclose(F);


    printf("%s \n %d \n", e->question, e->reponsejuste);

    e->quest = TTF_RenderText_Solid(police, e->question, couleurNoire);
    e->posQuestion.x = 300;
    e->posQuestion.y = 250;

    e->reponses[0] = TTF_RenderText_Blended(police, e->r1, couleurNoire);
    e->posRepones[0].x = 250;
    e->posRepones[0].y = 450;

    e->reponses[1] = TTF_RenderText_Blended(police, e->r2, couleurNoire);

    e->posRepones[1].x = 620;
    e->posRepones[1].y = 450;

    e->reponses[2] = TTF_RenderText_Blended(police, e->r3, couleurNoire);
    e->posRepones[2].x = 980;
    e->posRepones[2].y = 450;

    load_horloge_images(e);

    // for (int i = 0; i < 10; i++) {
    // sprintf(Horloge_position, "horloge/%dhorloge.gif", i + 1);
    // e->horloge[i] = IMG_Load(Horloge_position);

    // }


    // e->horloge[0] =IMG_Load("horloge/1horloge.gif");
    // e->horloge[1] =IMG_Load("horloge/2horloge.gif");
    // e->horloge[2] =IMG_Load("horloge/3horloge.gif");
    // e->horloge[3] =IMG_Load("horloge/4horloge.gif");
    // e->horloge[4] =IMG_Load("horloge/5horloge.gif");
    // e->horloge[5] =IMG_Load("horloge/6horloge.gif");
    // e->horloge[6] =IMG_Load("horloge/7horloge.gif");
    // e->horloge[7] =IMG_Load("horloge/8horloge.gif");
    // e->horloge[8] =IMG_Load("horloge/9horloge.gif");
    // e->horloge[9] =IMG_Load("horloge/10horloge.gif");
}
void load_horloge_images(enigme *e)
{	

    char Horloge_image[50];
    for (int i = 0; i < 10; i++)
    {
        sprintf(Horloge_image, "horloge/%dhorloge.gif", i + 1);
        e->horloge[i] = IMG_Load(Horloge_image);
    }
}

void afficherEnigme(enigme *e, SDL_Surface *screen)

{


    SDL_BlitSurface(e->quest, NULL, screen, &(e->posQuestion));
    SDL_BlitSurface(e->reponses[0], NULL, screen, &(e->posRepones[0]));
    SDL_BlitSurface(e->reponses[1], NULL, screen, &(e->posRepones[1]));
    SDL_BlitSurface(e->reponses[2], NULL, screen, &(e->posRepones[2]));
}

void afficherbutton(image a, SDL_Surface *screen)

{ 

    SDL_BlitSurface(a.img, NULL, screen, &a.pos);
}

void animerEnigme(enigme *e)
{
    

    e->fin = clock();                                
    e->temps = (e->fin - e->debut) / CLOCKS_PER_SEC; 
}

