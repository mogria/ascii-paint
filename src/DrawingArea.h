#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H
#include <libobj/libobj.h>
#include <ncurses.h>
struct DrawingArea;
#include "Cursor.h"

CLASS(DrawingArea);
  WINDOW *win;
  size_t size_x;
  size_t size_y;
  struct Cursor *cur;
END_CLASS;


CONSTRUCTOR(drawingarea_construct);
DESTRUCTOR(drawingarea_destruct);

void drawingarea_render(void *_self);
void drawingarea_set_boundary(void *_self, size_t height, size_t length, size_t pos_y, size_t pos_x);
void drawingarea_get_size(void *_self, size_t *y, size_t *x);
void drawingarea_onkey(void *_self, int ch);

void drawingarea_from_file(void *_self, const char *filename);
void drawingarea_to_file(void *_self, const char *filename);

#endif /* DAWINGAREA_H */
