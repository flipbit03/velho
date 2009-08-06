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
void printvelhover();

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
