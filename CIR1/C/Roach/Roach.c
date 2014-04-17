#include "Roach.h"

int main() {
	int continuer = 1;
	int nVis = 1;
	int btndown = 0;
	int deltax;
	int deltay;
	SDL_Event event;
	Roach *roaches;
	SDL_Surface *bathmat;
	TTF_Font *police = NULL;
	SDL_Color couleur = {255, 255, 255};
	SDL_Surface *texte;

	if(SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr,"Erreur d'initialisation de la SDL : %s\n", 
				SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_Surface *floor = NULL;
	SDL_Surface *ecran = init("img/floor.bmp", &floor);

	SDL_WM_SetCaption("Roach", NULL);

	SDL_Surface *sprites = LoadSprites("img/roach.bmp");

	roaches = CreateRoaches(ecran, sprites, MAX_ROACHES);

	bathmat = LoadImage("img/bathmat.bmp", X_INIT_TAPIS, Y_INIT_TAPIS);

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 
		MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
	{
		printf("%s", Mix_GetError());
	}

	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", 
					TTF_GetError());
		exit(EXIT_FAILURE);
	}

	police = TTF_OpenFont("The_Urban_Way.ttf", 31);

	texte = TTF_RenderText_Blended(police, "alo ui cer tapis", couleur);

	while(continuer) {
		nVis = MarkHiddenRoaches(roaches, MAX_ROACHES, bathmat);

		if(nVis) {
			SDL_BlitSurface(floor, NULL, ecran, NULL);

			MoveRoaches(roaches, MAX_ROACHES, ROACH_SPEED, ecran);

			DrawRoaches(roaches, MAX_ROACHES, ecran);
		}
	
		DrawImage(bathmat, ecran);

		SDL_BlitSurface(texte, NULL, ecran, &bathmat->clip_rect);

		SDL_Flip(ecran);

		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					continuer = 0;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT
						&& PointInRect(event.button.x, 
							event.button.y,
							bathmat->clip_rect.x,
							bathmat->clip_rect.y,
							bathmat->w,bathmat->h)){

					/* Clic sur le bathmat */
						btndown = 1;
				// Ecart entre clic et coin sup gauche bathmat
						deltax = event.button.x - 
							bathmat->clip_rect.x;
						deltay = event.button.y - 
							bathmat->clip_rect.y;
					}
					break;
				case SDL_MOUSEMOTION :
					if (btndown) {
					// "Nettoyage" du bathmat (2 options )
						SDL_BlitSurface(floor,NULL, 
									ecran,NULL);
						// Mise à jour position du bathmat
						bathmat->clip_rect.x = 
								event.button.x
									- deltax;
						bathmat->clip_rect.y = 
								event.button.y 
									- deltay;
					}
					break;
				case SDL_MOUSEBUTTONUP :
					btndown = 0;
					break;
			}
		}
		SDL_Delay(DELAI_P_TOUR);
	}

	TTF_CloseFont(police);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	return EXIT_SUCCESS;
}
