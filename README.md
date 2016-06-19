# Rasterizer
Real-time graphics engine for polygonal objects. Handle OBJ files. Run under liblapin 1.7 and more.

Without textures, the OBJ file will be computed like :

![Imgur](http://i.imgur.com/Zxg517V.png)

With them :

![Imgur](http://i.imgur.com/siyxtlJ.png)

(we are actively working to find his shoe)

Compilation :

- Use <code>make</code> for basic version
- Use <code>make CC="gcc -D FDF"</code> for linking vertices to each other
- Use <code>make CC="gcc -D ZBUFF"</code> for vertices colored by the Z-buffer

Keys :

- Move the object : W/A/S/D
- Rotate the object : Arrows and PG-UP/PG-DOWN
- Zoom in/out : +/-
