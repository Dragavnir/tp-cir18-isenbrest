#include "SDL.h"

int main() {
	if(SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr,"Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	int continuer = 1;
	SDL_Event event;
	SDL_Surface *ecran = NULL;
	SDL_Surface *fleur;
	SDL_Rect rect_fleur;
	char img_name[30];

	srand(time(NULL));

	ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);

	SDL_WM_SetCaption("OHAI IZ WINDOW LEL", NULL); 
	SDL_FillRect(ecran, NULL, 0x006600);

	SDL_Flip(ecran);

	while(continuer) {
		SDL_WaitEvent(&event); // Attente d'un événement
		switch(event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				sprintf(img_name, "fleurs/fleur%da.bmp", rand()%8+1);
				fleur = SDL_LoadBMP(img_name);
				if(fleur == NULL) {
					fprintf(stderr, "Impossible de charger le fichier : %s\n", SDL_GetError());
				}

				SDL_SetAlpha(fleur, SDL_SRCALPHA, 0);
				fleur->format->Amask = 0xFF000000;
				fleur->format->Ashift = 24;

				rect_fleur.y = event.button.y - fleur->h+10;
				rect_fleur.x = event.button.x - ((fleur->w)/2);

				SDL_BlitSurface(fleur, NULL, ecran, &rect_fleur);
				SDL_Flip(ecran);
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_ESCAPE) {
					continuer = 0;
				}
				break;
		}
	}	
	
	SDL_Quit();
	return EXIT_SUCCESS;
}
