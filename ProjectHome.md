## What is Velho? ##

  * Velho is basically a server that waits for messages and
> draws stuff/clears the screen as requested.

  * Velho receives messages thru UDP, using OSC as the communication
> protocol, thus, any app that can talk osc can talk to Velho
> (Puredata, Processing, liblo's oscsend, ...).

  * Velho uses SDL for screen drawing/event handling and LibLO
> for OSC.

  * Velho aims for simplicity, that means no opengl/3d/fancy graphics
> here, it's all 2D and simple blit ops so you can run it in
> just about any machine.

  * Velho divides the screen into a grid made of adjustable size
> rectangles, from 1x1 (one pixel drawing) to as big as the whole screen.