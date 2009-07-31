#include <stdio.h>
#include <stdlib.h>

#include "lo/lo.h"

#include "main.h"
#include "draw.h"
#include "structs.h"

int clearscreen_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data);
int draw_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data);
int chgrect_handler(const char *path, const char *types, lo_arg ** argv, int argc, void *data, void *user_data);

void error_handler(int num, const char *msg, const char *path);

struct loservfd oscserver_init(char *port);


