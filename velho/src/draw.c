#include "SDL.h"

void c_drawrectangle(SDL_Surface *surface, Uint16 x, Uint16 y, Uint16 rectx, Uint16 recty, Uint8 r, Uint8 g, Uint8 b)
{

	SDL_Rect drawrect;
	drawrect.x = x * rectx;
	drawrect.y = y * recty;
	drawrect.w = rectx;
	drawrect.h = recty;

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
}

/*TODO --> cleargridarea
void c_cleargridarea(SDL_Surface *surface, Uint16 x1, Uint16 y1,, Uint16 rectx, Uint16 recty, Uint8 r, Uint8 g, Uint8 b)
{

	SDL_Rect drawrect;
	drawrect.x = x * rectx;
	drawrect.y = 0;
	drawrect.w = rectx;
	drawrect.h = recty * (scr;

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
} */

void c_clearscreen(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, 0, 0, 0, 0);
}
