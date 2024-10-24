```
workspace git:(master) docker run -it --rm -v ${PWD}:/project launchiine-builder make -j2
Application.cpp
entry.cpp
CFile.cpp
DirList.cpp
FSUtils.cpp
GameList.cpp
GameIcon.cpp
GuiIconGrid.cpp
GuiImage.cpp
GameSplashScreen.cpp
KeyboardHelper.cpp
MainWindow.cpp
Resources.cpp
In file included from /project/src/resources/Resources.cpp:2:
/project/src/resources/filelist.h:21:10: fatal error: bgMusic_ogg.h: No such file or directory
   21 | #include "bgMusic_ogg.h"
      |          ^~~~~~~~~~~~~~~
compilation terminated.
make[1]: *** [/opt/devkitpro/devkitPPC/base_rules:15: Resources.o] Error 1
make[1]: *** Waiting for unfinished jobs....
make: *** [Makefile:106: build] Error 2
```
