#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "lo/lo.h"
#include "SDL.h"

#include "oscstuff.h"
#include "varfunc.h"

#define PROGNAME "Velho"
#define PROGVERSION "0.79"

// Main vars/configs
Uint8 run = 1;
Uint8 autoupdatemode = 1;
Uint8 manualupdatewhole = 0;
Uint8 updaterectcount = 0;
SDL_Rect *updaterectlist = NULL;

// LibLO vars/configs
char serverport[5] = "7700";

// SDL vars/configs
char windowtitle[60];
Uint16 screenxres = 640;
Uint16 screenyres = 480;
Uint16 screenbpp = 16;
Uint8 fullscreen = 0;
Uint16 rectx = 40;
Uint16 recty = 40;
Uint16 gridx = 0;
Uint16 gridy = 0;
SDL_Surface *screen;

int main(int argc, char *argv[])
{
	struct loservfd oscsrv;
	SDL_Event myev;
	int optchar, optnumber;

	
	// parse command line arguments
	while ((optchar = getopt(argc, argv, "hfx:y:p:")) != -1) 
		switch(optchar) {
			case 'h':
				printf("%s %s: Simple remote graphics display using SDL and OSC.\n",PROGNAME,PROGVERSION);
				printf("author: Cadu (cadu.coelho@gmail.com)\n\n");
				printf("Command line options:\n");
				printf("\t-h\tShow this help.\n");
				printf("\t-f\tStart in fullscreen mode.\n");
				printf("\t-x val\tSet X resolution to \"val\" (320..1920).\n");
				printf("\t-y val\tSet Y resolution to \"val\" (240..1280)\n");
				printf("\t-p val\tSet velho to listen on port \"val\" (100..65535)\n");
				exit(0);
				break;
			
			case 'f':
				fullscreen=1;
				break;

			case 'x':
				optnumber = atoi(optarg);
				if ((optnumber >= 320) && (optnumber <= 1920)) {
					screenxres = optnumber;
				} else {
  					printf("Fatal: Getopt Error: -x\n");
					exit(1);
				}
				break;
			case 'y':
				optnumber = atoi(optarg);
				if ((optnumber >= 240) && (optnumber <= 1280)) {
					screenyres = optnumber;
				} else {
					printf("Fatal: Getopt Error: -y\n");
					exit(1);
				}
				break;
			case 'p':
				optnumber = atoi(optarg);
				if ((optnumber  > 100) && (optnumber < 65535)) {
					snprintf(serverport, 5, "%d", optnumber);
				} else {
					printf("Fatal: Getopt Error: -p\n");
					exit(1);
				}
				break;
			case '?':
				printf("Fatal: Getopt Error: Unkown option.\n");
				exit(1);	
				break;
			default:
				/* should never happen */
				break;
		}
	
	// print the actual config.
	printconfig();
		
	// calculate first grid/res ratio/size
	calcgridsize();

	// create the OSC server
	oscsrv = oscserver_init(serverport);

	// initialize SDL
	printf("[SDL][Init] ");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		printf("Fail.\nFatal: Could not initialize SDL: %s\n",
		       SDL_GetError());
		exit(1);
	} else {
		printf("Ok.\n");
	}

	// set up cleanup function at exit() (for now SDL_Quit())
	atexit(cleanupandexit);

	// get us a screen
	screensetvideomode(0);

	// window title
	snprintf(windowtitle,sizeof(windowtitle),"%s %s",PROGNAME,PROGVERSION);
	SDL_WM_SetCaption(windowtitle, NULL);

	// hide pointer
	SDL_ShowCursor(SDL_DISABLE);

	do {
		// process OSC messages
		lo_server_recv_noblock(oscsrv.s, 0);

		// process SDL events
		while (SDL_PollEvent(&myev)) {
			switch (myev.type) {
			case SDL_KEYDOWN:
				// toggle fullscreen
				if (myev.key.keysym.sym == SDLK_f) {
					togglefullscreen();
					screensetvideomode(1);
				}	

				// quit
				if (myev.key.keysym.sym == SDLK_q)
					run = 0;
				break;

			case SDL_QUIT:
				// quit the program.
				run =0;
				break;
			}
		}
	} while (run);

	// got out of the main loop, exiting.
	exit(0);
}
