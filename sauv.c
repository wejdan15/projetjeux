#include "sauv.h"

void sauvegarder (Personne p,background b, char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d %d %d\n", p.position.x, p.position.y, b.pos_background_affiche.x ,b.pos_background_affiche.y);
	//fclose(f);
}

int charger (Personne *p,background *b,  char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	
	
		fscanf(f,"%hd %hd %hd %hd\n",&p->position.x,&p->position.y,&b->pos_background_affiche.x ,&b->pos_background_affiche.y);
	
	}
	//fclose(f);
}

