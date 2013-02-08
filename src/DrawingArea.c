#include <libobj/libobj.h>
#include "DrawingArea.h"

INIT_CLASS(DrawingArea, drawingarea_construct, drawingarea_destruct);

CONSTRUCTOR(drawingarea_construct) {
  struct DrawingArea *self = _self;
  self->win = newwin(0,0,0,0);
}

DESTRUCTOR(drawingarea_destruct) {
  struct DrawingArea *self = _self;
  delwin(self->win);

}

void drawingarea_render(void *_self) {
  struct DrawingArea *self = _self;
  wrefresh(self->win);
}

void drawingarea_set_boundary(void *_self, size_t height, size_t length, size_t pos_y, size_t pos_x) {
  struct DrawingArea *self = _self;
  wresize(self->win, height, length);
  mvwin(self->win, pos_y, pos_x);
}

void drawingarea_get_size(void *_self, size_t *y, size_t *x) {
  struct DrawingArea *self = _self;
  getmaxyx(self->win, *y, *x);
}

void drawingarea_onkey(void *_self) {
  struct DrawingArea *self = _self;
}
