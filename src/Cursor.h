#ifndef CURSOR_H
#define CURSOR_H
#include <libobj/libobj.h>
#include <ncurses.h>
#include "DrawingArea.h"

CLASS(Cursor);
  size_t pos_x;
  size_t pos_y;
  size_t size_x;
  size_t size_y;
  chtype color;
END_CLASS;

CONSTRUCTOR(cursor_construct);
DESTRUCTOR(cursor_construct);

size_t cursor_xpos(void *_self);
size_t cursor_ypos(void *_self);
void cursor_moveby(void *_self, int y, int x);
void cursor_moveto(void *_self, size_t y, size_t x);
void cursor_set_color(void *_self, chtype ch);
void cursor_draw(void *_self, struct DrawingArea *surface);

#endif CURSOR_H
