#include "StatusBar.h"

INIT_CLASS(StatusBar, statusbar_construct, statusbar_destruct);

CONSTRUCTOR(statusbar_construct) {
 struct StatusBar *self = _self;
 self->win = newwin(3,0,0,0);
}

DESTRUCTOR(statusbar_destruct) {
 struct StatusBar *self = _self;
 delwin(self->win);
}

void statusbar_set_length(void *_self, size_t length) {
  struct StatusBar *self = _self;
  wresize(self->win, 3, length);
  box(self->win, '|', '-');
}

void statusbar_render(void *_self) {
 struct StatusBar *self = _self;
 wrefresh(self->win);
}
