#include "SDL.h"

#include "main.h"

void c_drawrectangle(SDL_Surface *surface, Uint16 x, Uint16 y, Uint8 r, Uint8 g, Uint8 b)
{

	SDL_Rect drawrect;
	drawrect.x = x * rectx;
	drawrect.y = y * recty;
	drawrect.w = rectx;
	drawrect.h = recty;

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
}

void c_drawarea(SDL_Surface *surface, Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Rect drawrect;
	if((x1 <= x2) && (y1 <= y2)) {
		drawrect.x = x1 * rectx;
		drawrect.y = y1 * recty;
		drawrect.w = (abs(x2 - x1)+1) * rectx;
		drawrect.h = (abs(y2 - y1)+1) * recty;
	} else {
		drawrect.x = x2 * rectx;
		drawrect.y = y2 * recty;
		drawrect.w = (abs(x2 - x1)+1) * rectx;
		drawrect.h = (abs(y2 - y1)+1) * recty;
	}

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
}

void c_clearscreen(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
	SDL_UpdateRect(surface, 0, 0, 0, 0);
}
