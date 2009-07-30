"Velho"

Author:
	[Cadu]
	 email: <cadu.coelho@gmail.com> 
	 irc  : cadu@freenode (#dataflow/#nethack-offtopic)

- Disclaimer:

	This program is incomplete/crappy, expect bugs, funny mishaps...
	overall it's working fine but be warned i cannot be held responsible if it fries 
	your computer, makes your life miserable, burns your house down, etc.

- What is Velho?

	Velho is basically a server that waits for messages and
	draws stuff/clears the screen as requested.

	Velho receives messages thru UDP, using OSC as the communication
	protocol, thus, any app that can talk osc can talk to Velho (Puredata,
	Processing, oscsend, ...).

	Velho uses SDL for screen drawing/event handling and LibLO for OSC.

	Velho divides the screen into a grid made of adjustable size rectangles,
	from 1x1 (ie: one pixel drawing) to as big as the whole screen.

- Compiling Velho:

	Velho compiles on Linux and Windows (with MINGW).

	On Linux:
		Install SDL and development headers (-dev package in most distros).

		Install LibLO and development headers (-dev package in most distros).

		"make" should give you a "velho" binary.

		If it fails adjust the makefile to help it find headers and stuff, no ./configure here T__T

		If you distro's precompiled liblo is too old (< 0.23) consider downloading it directly from the homepage
		and compiling it from the source.

	On Windows:
		A Makefile is provided for MINGW, but i must warn you that Windows compilation is tricky and
		requires lots of steps/fiddling... T__T

		Install MINGW and MSYS.

		Install or Compile SDL in your MINGW system.
			- There's a precompiled SDL dll/header package for MINGW available on the SDL website.
			- or build it from source *pain*.

		Install Pthreads-Win32.
			- There's a precompiled dll/header package on their website. LibLO needs this.
			- Install it in your MinGW root as usual, libraries in /lib, headers in /include.
			- Warning: rename one suitable pthreadG***.dll and .a to pthread.dll and pthread.a or LibLO won't link.

		Compile and install LibLO in your MINGW root.
			- if you installed pthreads-win32 and renamed the dlls properly, this will work just like linux "configure/make/make install"

		Compile Velho with given makefile.
			"make -f Makefile.mingw" inside MSYS should do the trick. or NOT...
			Some paths (liblo) had to be hardcoded in the makefile (no pkg-config) so be prepared to ADJUST stuff.

- Launching Velho:

	"velho" without cmdline arguments will launch Velho with these settings:
		640x480 screen
		40x40 grid size (640/40 480/40 --> fullscreen 16x12 grid)
 		listening on port 7700

	command line arguments:
		-h	help screen
		-f	Start in fullscreen mode
		-x val	Set X resolution to "val" (320..1920)
		-y val	Set Y resolution to "val" (240..1280)
		-p val	Set velho to listen on port "val" (100..65535)

- Velho keybinds:

	When Velho is running you can use these commands on Velho's side:
	
	Key	Action

	f	Toggles between Windowed and Fullscreen modes.
		*WARNING: if Velho's screen resolution isn't supported in fullscreen the app will quit*

	q	Quits Velho.

- Talking to Velho:

	Velho accepts these commands through the OSC server:

	i = 32bit integer (OSC Type)

	OSC Path	OSC Arg Types	Parameters	Comment
	/draw		iiiii		X Y R G B	Draws a point on the X-Y position on the current grid, using color R-G-B
	/chgrect	ii		X Y		Changes the size of each rectangle drawn to X-Y
	/clear		iii		R G B		Clears the whole screen to color R-G-B

