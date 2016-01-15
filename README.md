This is a Qt Application simulating Conway's Game of Life.

LOADING A WORLD:
A properly formatted world file consists of a list of pairs of coordinates, each on its own line. Each pair of coordinates should be written as "[x coordinate][space][y coordinate]", i.e. a pair of integers (negative or positive) separated by a single space.	World files should be saves in a directory named "res" within the working directory. The dimensions of the grid display can be controlled with the World Size slider.

ANIMATION:
The world can be ticked forward one generation at a time with the Tick button or animated continuously with the Animate button. The speed of animation can be controlled with the Animation Speed slider. Animation can be paused with the Pause button.

SETTING THE ORIGIN:
By default, the origin of the display (located at the top-left) is the point (0, 0). The user can chnage the origin with the Set Origin button in order to view different areas of the world.