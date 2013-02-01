#include "MainWin.h"
#include "StatusBar.h"
#include "DrawingArea.h"

INIT_CLASS(MainWin, mainwin_construct, mainwin_destruct);

CONSTRUCTOR(mainwin_construct) {
  struct MainWin *self = _self;

  // create main window
  self->win = newwin(0, 0, 0, 0);
  self->current_x = 0;
  self->current_y = 0;

  // create a status bar
  self->statusbar = new(StatusBar);
  self->drawingarea = new(DrawingArea);
}

DESTRUCTOR(mainwin_destruct) {
  struct MainWin *self = _self;
  delete(self->statusbar);
  delwin(self->win);
}

static void mainwin_size_changed(struct MainWin *self) {
  size_t x, y;
  getmaxyx(stdscr, y, x);

  if(self->current_x != x || self->current_y != y) {
    self->current_x = x;
    self->current_y = y;

    // resize own window
    wresize(self->win, y, x);
    box(self->win, '|', '-');

    // resize status bar
    statusbar_set_length(self->statusbar, self->current_x);
    drawingarea_set_boundary(self->drawingarea, self->current_y, self->current_x, 3, 0);
  }
}

void mainwin_render(void *_self) {
  struct MainWin *self = _self;

  // resize this if necesarry
  mainwin_size_changed(self);

  // refresh main window
  wrefresh(self->win);

  statusbar_render(self->statusbar);
}
