#include <ncurses.h>
#include <libobj/libobj.h>
#include "MainWin.h"

void initncurses() {
  initscr();
  noecho();
  cbreak();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}

int main() {
  initncurses();

  printf("MainWin: %p\n", MainWin);

  struct MainWin *win = new(MainWin);

  int ch;

  while((ch = getch()) != 'a') {
    mainwin_render(win);
    refresh();
  }

  delete(win);
  return 0;
}
