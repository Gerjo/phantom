Phantom
=======

Compilation and development requirements:
=======
http://www.libsdl.org/download-1.2.php (both runtime and dev kits)<br>
or<br>
A few carefully crafted apt-get / yum commands to load SDL-*.<br>

Lib SDL-draw
=======
http://sdl-draw.sourceforge.net/
 If the shared lib cannot be found by the linker, try adding a symlink from the missing so file to your to /usr/lib/ folder. Also double check file privs.

HTML5 demo canvas:
=======
https://github.com/koenbollen/phantom/blob/SDLGraphics/demo.html