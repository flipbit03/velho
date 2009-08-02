#include "main.h"

// useful functions used throughout the whole program.

// make sure a value is in a given range
int clipvalue(int value, int lowvalue, int highvalue);

// recalculate grid size (set gridx and gridy)
void calcgridsize();

// velho exit cleanup (atexit())
void cleanupandexit();

