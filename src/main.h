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

#include "SDL.h"

#include "configs.h"

// Main vars
extern Uint8 run;
extern Uint8 autoupdatemode;
extern Uint8 manualupdatewhole;
extern Uint8 updaterectcount;
extern SDL_Rect *updaterectlist;
  
// LibLO vars/configs
extern char serverport[5];

// SDL vars/configs
extern Uint16 screenxres;
extern Uint16 screenyres;
extern Uint16 screenbpp;
extern Uint8 fullscreen;
extern Uint16 rectx;
extern Uint16 recty;
extern Uint16 gridx;
extern Uint16 gridy;
extern SDL_Surface *screen;

