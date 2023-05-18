prog:menu.o initilatisation.o background.o perso.o enigme.o sauv.o
	gcc menu.o initilatisation.o background.o perso.o enigme.o sauv.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
menu.o:menu.c
	gcc -c menu.c -g
initilatisation.o:initilatisation.c
	gcc -c initilatisation.c -g 
background.o:background.c
	gcc -c background.c -g

perso.o:perso.c
	gcc -c perso.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
sauv.o:sauv.c
	gcc -c sauv.c -g	
 
