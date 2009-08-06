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

#include <stdio.h>
#include <stdlib.h>

#include "lo/lo.h"

#include "main.h"
#include "draw.h"
#include "structs.h"
#include "varfunc.h"

// OSC Server Handlers

/* updatescreen
no args
updates the changed rects while not in "auto update mode" */
int updatescreen_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	c_updatescreen(screen);
	return 0;
}

/* setautoupdate
argv[0]->i --> 1 = yes / ANYTHING ELSE = no */
int setautoupdate_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	c_setautoupdate(screen, argv[0]->i);
	return 0;
}

/* clrscr
argv[0]->i --> R (0-255)
argv[1]->i --> G (0-255)
argv[2]->i --> B (0-255) */
int clearscreen_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	c_clearscreen(screen, argv[0]->i, argv[1]->i, argv[2]->i);
	return 0;
}

/* drawarea
argv[0]->i --> X1
argv[1]->i --> Y1
argv[2]->i --> X2
argv[3]->i --> Y2
argv[4]->i --> R (0-255)
argv[5]->i --> G (0-255)
argv[6]->i --> B (0-255) */
int drawarea_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	c_drawarea(screen, argv[0]->i, argv[1]->i, argv[2]->i, argv[3]->i, argv[4]->i, argv[5]->i, argv[6]->i);
	return 0;
}

/* draw
argv[0]->i --> X (0-screenxres/rectx)
argv[1]->i --> Y (0-screenyres/recty)
argv[2]->i --> R (0-255)
argv[3]->i --> G (0-255)
argv[4]->i --> B (0-255) */
int draw_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	c_drawrectangle(screen, argv[0]->i, argv[1]->i, argv[2]->i, argv[3]->i, argv[4]->i);
	return 0;
}

/* chgrect
argv[0]->i --> rect X size
argv[1]->i --> rect Y size */
int chgrect_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data)
{
	rectx = clipvalue(argv[0]->i, 1, screenxres);
	recty = clipvalue(argv[1]->i, 1, screenyres);
	calcgridsize();
	return 0;
}

/* lo_server error handler */
void error_handler(int num, const char *msg, const char *path)
{
	printf("Fatal: LibLO server error %d in path %s: %s\n", num, path, msg);
	exit(1);
}

// Main OSC Server init function.
struct loservfd oscserver_init(char *port)
{
	struct loservfd output;

	output.s = lo_server_new(port, error_handler);
	output.fd = lo_server_get_socket_fd(output.s);

	if (!(output.fd > 0)) {
                printf("Fatal: Could not get OSC server's filedescriptor.\n");
                exit(1);
	}

	// add server handlers
	lo_server_add_method(output.s, "/updatescreen",	"", updatescreen_handler, NULL);
	lo_server_add_method(output.s, "/setautoupdate", "i", setautoupdate_handler, NULL);
	lo_server_add_method(output.s, "/clear", "iii", clearscreen_handler, NULL);
	lo_server_add_method(output.s, "/chgrect", "ii", chgrect_handler, NULL);
	lo_server_add_method(output.s, "/drawarea","iiiiiii", drawarea_handler, NULL);
	lo_server_add_method(output.s, "/draw", "iiiii", draw_handler, NULL);

	printf("[OSC][Init] Ok.\n");
	return output;
}
