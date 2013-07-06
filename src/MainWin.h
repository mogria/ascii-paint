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
  char *filename;
END_CLASS;

CONSTRUCTOR(mainwin_construct);
DESTRUCTOR(mainwin_destruct);
void mainwin_render(void *_self);
void mainwin_onkey(void *_self, int ch);

#endif /* MAINWIN_H */
