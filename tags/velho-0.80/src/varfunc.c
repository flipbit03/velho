/*
 * Velho, a network-enabled graphic drawing application.
 * Copyright (C) 2009 Carlos Eduardo C. B. Shinagawa <cadu.coelho@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"

// show program version and copyright/gpl status
void printvelhover()
{
	printf("%s %s: a network-enabled graphic drawing application.\n",PROGNAME,PROGVERSION);
	printf("Copyright (C) 2009 Carlos Eduardo C. B. Shinagawa <cadu.coelho@gmail.com>\n");
	printf("This program is released under the GPL, see doc/LICENSE for details.\n");
}

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
	printf("\nVelho config\n");
	printf("--------------------------------\n");
	printf("Server port = %s\n",serverport);
	printf("Auto-update mode = %d\n",autoupdatemode);
	printf("Screen resolution = %dx%d\n",screenxres,screenyres);
	printf("Square size = %dx%d\n",rectx,recty);
	printf("Fullscreen = %d\n",fullscreen);
	printf("--------------------------------\n\n");
}	

