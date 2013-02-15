#include <libobj/libobj.h>
#include "DrawingArea.h"

INIT_CLASS(DrawingArea, drawingarea_construct, drawingarea_destruct);

CONSTRUCTOR(drawingarea_construct) {
  struct DrawingArea *self = _self;
  self->win = newwin(0,0,0,0);
  self->cur = new(Cursor);
}

DESTRUCTOR(drawingarea_destruct) {
  struct DrawingArea *self = _self;
  delwin(self->win);
  delete(self->cur);
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

void drawingarea_onkey(void *_self, int ch) {
  struct DrawingArea *self = _self;
  int x = 0, y = 0;

  if(ch == KEY_UP || ch == KEY_DOWN || ch == KEY_RIGHT || ch == KEY_LEFT) {
    switch(ch) {
      case KEY_UP:
        y = -1;
        break;
      case KEY_DOWN:
        y = 1;
        break;
      case KEY_LEFT:
        x = -1;
        break;
      case KEY_RIGHT:
        x = 1;
        break;
      default:
        break;
    }
    cursor_moveby(self->cur, y, x);
  } else if(ch == ' ') {
    cursor_draw(self->cur, self);
  }

}
