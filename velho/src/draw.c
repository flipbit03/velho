#include "SDL.h"

#include "main.h"
#include "varfunc.h"

// Internal commands
static void ci_addtoupdatelist(SDL_Rect newarea)
{
	// don't even bother adding Rects to the update list if we have
	// to redraw the whole screen.
	if (manualupdatewhole == 0) {
		updaterectcount++;
		updaterectlist = realloc(updaterectlist, updaterectcount * sizeof(SDL_Rect));
		if (updaterectlist == NULL) {
			printf("FATAL: Couldn't get memory for rect storage (autoupdatemode off)\n");
			exit(1);
		}
		*(updaterectlist + updaterectcount - 1) = newarea;
	}
}

// Commands directly tied to OSC
void c_updatescreen(SDL_Surface *surface) {
	if (autoupdatemode == 0 && (updaterectcount > 0 || manualupdatewhole == 1)) {
		// Just update the whole screen if manualupdatewhole==1
		if (manualupdatewhole == 1) {
			SDL_UpdateRect(surface, 0, 0, 0, 0);
			manualupdatewhole = 0;
		} else {
			// or update a list of SDL_Rects as usual)
			SDL_UpdateRects(surface, updaterectcount, updaterectlist);
		}
	
		updaterectcount = 0;
		free(updaterectlist);
		updaterectlist = NULL;
	}
}

void c_setautoupdate(SDL_Surface *surface, Uint8 yesno)
{
	if (yesno == 1) {
		c_updatescreen(surface);
		autoupdatemode = 1;
	} else {
		autoupdatemode = 0;
	}
}

void c_drawrectangle(SDL_Surface *surface, Uint16 x, Uint16 y, Uint8 r, Uint8 g, Uint8 b)
{

	SDL_Rect drawrect;
	drawrect.x = clipvalue(x,0,gridx-1) * rectx;
	drawrect.y = clipvalue(y,0,gridy-1) * recty;
	drawrect.w = rectx;
	drawrect.h = recty;

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format,
		clipvalue(r, 0, 255), clipvalue(g, 0, 255), clipvalue(b, 0, 255)));

	if (autoupdatemode == 1) {
		SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
	} else {
		ci_addtoupdatelist(drawrect);
	}
}

void c_drawarea(SDL_Surface *surface, Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2, Uint8 r, Uint8 g, Uint8 b)
{
	x1 = clipvalue(x1,0,gridx-1);
	y1 = clipvalue(y1,0,gridy-1);
	x2 = clipvalue(x2,0,gridx-1);
	y2 = clipvalue(y2,0,gridy-1);

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

	SDL_FillRect(surface, &drawrect, SDL_MapRGB(surface->format,
		clipvalue(r, 0, 255), clipvalue(g, 0, 255), clipvalue(b, 0, 255)));
	
	if (autoupdatemode == 1) {
		SDL_UpdateRect(surface, drawrect.x, drawrect.y, drawrect.w, drawrect.h);
	} else {
		ci_addtoupdatelist(drawrect);
	}
}

void c_clearscreen(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Rect drawrect;

	drawrect.x = 0;
	drawrect.y = 0;
	drawrect.w = surface->w;
	drawrect.h = surface->h;

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,
		clipvalue(r, 0, 255), clipvalue(g, 0, 255), clipvalue(b, 0, 255)));

	if (autoupdatemode == 1) {
		SDL_UpdateRect(surface, 0, 0, 0, 0);
	} else {
		manualupdatewhole = 1;	
		ci_addtoupdatelist(drawrect);
	}
}
