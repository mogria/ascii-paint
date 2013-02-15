#include "Cursor.h"

INIT_CLASS(Cursor, cursor_construct, cursor_destruct);

CONSTRUCTOR(cursor_construct) {
  struct Cursor *self = _self;
  self->pos_x = 0;
  self->pos_y = 0;
  self->color = 'x';
}

DESTRUCTOR(cursor_destruct) {

}

size_t cursor_xpos(void *_self) {
  struct Cursor *self = _self;
  return self->pos_x;
}

size_t cursor_ypos(void *_self) {
  struct Cursor *self = _self;
  return self->pos_x;
}

void cursor_moveby(void *_self, int y, int x) {
  struct Cursor *self = _self;
  self->pos_y = self->pos_y + y;
  self->pos_x = self->pos_x + x;
}

void cursor_moveto(void *_self, size_t y, size_t x) {
  struct Cursor *self = _self;
  self->pos_y = y;
  self->pos_x = x;
}

void cursor_set_color(void *_self, chtype ch) {
  struct Cursor *self = _self;
  self->color = ch;
}

void cursor_draw(void *_self, struct DrawingArea *surface) {
  struct Cursor *self = _self;
  size_t x, y;
  drawingarea_get_size(surface, &y, &x);
  self->pos_y %= y;
  self->pos_x %= x;

  mvwprintw(surface->win, self->pos_y, self->pos_x, "%c", self->color);
}
