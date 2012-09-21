Phantom
=======

Compilation and development requirements:
=======
http://www.libsdl.org/download-1.2.php (both runtime and dev kits)<br>
or<br>
A few carefully crafted apt-get / yum commands to load SDL-*.<br>

Freeglut install guide:
=======
http://freeglut.sourceforge.net/ version 2.8.0<br><br>

The MakeFile searches for the includes&libs in the /opt/freeglut-2.8.0/ folder so untar them there (unless you fancy setting your own include path). <br>
./configure && make && make install; should do the trick. For a headless-box you'll probably need to apt-get libxi-dev.


HTML5 demo canvas:
=======
https://github.com/koenbollen/phantom/blob/SDLGraphics/demo.html
