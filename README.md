# Rasterizer
Real-time graphics engine for polygonal objects. Handle OBJ files. Run under liblapin 1.7 and more.

Without textures, the OBJ file will be computed like :

![Imgur](http://i.imgur.com/Zxg517V.png)

With them :

![Imgur](http://i.imgur.com/siyxtlJ.png)

(we are actively working to find his shoe)

## Build

First build the liblapin library using `make lapin`.

You can now build the rasterizer:
- Use `make` for basic version
- Use `make CC="gcc -D FDF"` for linking vertices to each other
- Use `make CC="gcc -D ZBUFF"` for vertices colored by the Z-buffer

## Usage

`./rasterizer demo/dragon.ini`

- Move the object : W/A/S/D
- Rotate the object : Arrows and PG-UP/PG-DOWN
- Zoom in/out : +/-
