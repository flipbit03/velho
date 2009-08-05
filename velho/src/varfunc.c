#include "main.h"

// make sure a value is in a given range
int clipvalue(int value, int lowvalue, int highvalue)
{
	if (value < lowvalue)
		value = lowvalue;
	if (value > highvalue)
		value = highvalue;
	return value;
}

// recalculate grid size (set gridx and gridy)
void calcgridsize()
{
	gridx = (screenxres / rectx);
	gridy = (screenyres / recty);
}

// toggle fullscreen
void togglefullscreen()
{
fullscreen = (fullscreen + 1) % 2;
}

// set or change video mode (fullscreen etc)
void screensetvideomode(int change)
{
if (fullscreen == 0) {
	// free the screen surface if we are changing the mode (fullscreen toggle/etc)
	if (change == 1)
		SDL_FreeSurface(screen);

	printf("[SDL][VideoMode] Windowed %dx%d@%dbpp...", screenxres, screenyres, screenbpp);

	if ((screen = SDL_SetVideoMode(screenxres, screenyres, screenbpp, SDL_SWSURFACE)) == NULL) {
		printf("Fail.\nFatal: Could not initialize SDL video mode : %s\n",SDL_GetError());
		exit(1);
	} else 
		printf("Ok.\n");
} else {
	// free the screen surface if we are changing the mode (fullscreen toggle/etc)
	if (change == 1)
		SDL_FreeSurface(screen);

	printf("[SDL][VideoMode] Fullscreen %dx%d@%dbpp...", screenxres, screenyres, screenbpp);

	if ((screen = SDL_SetVideoMode(screenxres, screenyres, screenbpp, SDL_SWSURFACE | SDL_FULLSCREEN)) == NULL) {
		printf("Fail.\nFatal: Could not initialize SDL video mode : %s\n",SDL_GetError());
		exit(1);
	} else
		printf("Ok.\n");
}

}	

// velho exit cleanup (atexit())
void cleanupandexit()
{
	printf("[SDL][Quit]\n");
	SDL_Quit();
	printf("Velho exiting...\n");
}

// print configuration (global vars)
void printconfig()
{
	printf("Velho config\n");
	printf("--------------------------------\n");
	printf("Server port = %s\n",serverport);
	printf("Auto-update mode = %d\n",autoupdatemode);
	printf("Screen resolution = %dx%d\n",screenxres,screenyres);
	printf("Square size = %dx%d\n",rectx,recty);
	printf("Fullscreen = %d\n",fullscreen);
	printf("--------------------------------\n");
}	

