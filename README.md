# cub3D

A simple 3D raycasting engine written in C, inspired by classic games like Wolfenstein 3D. This project renders a first-person 3D view from a 2D map using the DDA (Digital Differential Analyzer) algorithm to calculate ray intersections with walls.

Features:
- 3D rendering using raycasting.
- Map parsing and player movement.
- Collision detection.
- Wall textures.
- Doors which can open and close.
- A minimap system.
- Basic user input for movement and rotation.
- Rotate the point of view with the mouse.

About the DDA Algorithm:
The DDA algorithm is used to cast rays from the player’s position into the game world to find where each ray hits a wall. It works by incrementally stepping through the grid cells of the map in the direction of the ray until it detects a collision with a wall. This allows the engine to calculate the distance to the wall and render the correct height of the wall slice on screen.

Requirements:
- GCC or any C compiler
- Unix-like OS (Linux, macOS)
- MiniLibX graphics library

How to Build:
Clone the repo and run:

`make`

This will compile the program into an executable named cub3D.

How to Use:
Run the program:

`./cub3D [map_file.cub]`

Control the player with keyboard inputs (WASD for movement, arrow keys or mouse for rotation).

