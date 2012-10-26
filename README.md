Phantom
=======

Compilation and development requirements:
=======
yum install freeglut  <br>
yum install freeglut-devel (If you want to compile)<br>
<br><br>If your repo does not contain libpng15:<br>
git clone git://libpng.git.sourceforge.net/gitroot/libpng/libpng && git checkout origin/libpng15<br>
./configure && make <br>
make install (as root)<br>

HTML5 demo canvas:
=======
https://github.com/koenbollen/phantom/blob/SDLGraphics/demo.html
