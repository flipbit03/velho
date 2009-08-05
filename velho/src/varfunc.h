#include "main.h"

// make sure a value is in a given range
int clipvalue(int value, int lowvalue, int highvalue);

// recalculate grid size (set gridx and gridy)
void calcgridsize();

// toggle fullscreen
void togglefullscreen();

// set or change video mode (fullscreen etc)
void screensetvideomode(int change);

// velho exit cleanup (atexit())
void cleanupandexit();

// print configuration (global vars)
void printconfig();
