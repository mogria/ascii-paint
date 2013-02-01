#ifndef STATUSBAR_H
#define STATUSBAR_H
#include <libobj/libobj.h>
#include <ncurses.h>

CLASS(StatusBar);
  WINDOW *win;
END_CLASS;

CONSTRUCTOR(statusbar_construct);
DESTRUCTOR(statusbar_destruct);
void statusbar_render(void *_self);
void statusbar_set_length(void *_self, size_t length);

#endif /* STATUSBAR_H */
