#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H
#include <libobj/libobj.h>
#include <ncurses.h>

CLASS(DrawingArea);
  WINDOW *win;
END_CLASS;

CONSTRUCTOR(drawingarea_construct);
DESTRUCTOR(drawingarea_destruct);

void drawingarea_render(void *_self);
void drawingarea_set_boundary(void *_self, size_t height, size_t length, size_t pos_y, size_t pos_x);
void drawingarea_onkey(void *_self);

#endif /* DAWINGAREA_H */
