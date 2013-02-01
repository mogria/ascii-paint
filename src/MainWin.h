#ifndef MAINWIN_H
#include <libobj/libobj.h>
#include <ncurses.h>
#include "StatusBar.h"

CLASS(MainWin);
  WINDOW *win;
  void (*render)(void *_self);
  struct StatusBar *statusbar;
  struct DrawingArea *drawingarea;
  size_t current_x;
  size_t current_y;
END_CLASS;

CONSTRUCTOR(mainwin_construct);
DESTRUCTOR(mainwin_destruct);
void mainwin_render(void *_self);

#endif /* MAINWIN_H */
