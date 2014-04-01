#include "SDL.h"

int main() {
	if(SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr,"Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	int continuer = 1;
	SDL_Event event;

	SDL_Surface *ecran = NULL;

	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

	SDL_WM_SetCaption("OHAI IZ WINDOW LEL", NULL); 
	SDL_FillRect(ecran, NULL, 0x00ff00);

	while(continuer) {
		SDL_WaitEvent(&event); // Attente d'un événement
		switch(event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
		}
	}	
	
	SDL_Quit();
	return EXIT_SUCCESS;
}
