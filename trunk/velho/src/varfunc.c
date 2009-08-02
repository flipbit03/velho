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

// velho exit cleanup (atexit())
void cleanupandexit()
{
	printf("SDL cleanup.\n");
	SDL_Quit();
	printf("Velho exiting...\n");
}

