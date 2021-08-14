#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]) {
    srand(time(0));

    int xv = 1, yv = 1;

    // basic curses setup
    WINDOW* win = initscr();
    cbreak();
    noecho();
    curs_set(false);

    // find width of text
    int h = argc;
    int w = 0;
    for (int i = 1; i < argc; i++) {
        int newwidth = strlen(argv[i]);
        if (newwidth > w) {
            w = newwidth;
        };
    };


    // get terminal size
    int tw;
    int th;
    getmaxyx(win, th, tw);
    tw -= w - 1;
    th -= h - 1;

    // set initial position
    int x = rand() % tw, y = rand() % th;

    while (1) {
        erase();
        clear();

        for (int i = 1; i < argc; i++) {
            mvprintw(y + i - 1, x, argv[i]);
        };
        refresh();

        usleep(100000);


        // get terminal size
        getmaxyx(win, th, tw);
        tw -= w;
        th -= h;

        // bounce
        if (x == 0) {
            xv = 1;
        } else if (x >= tw) {
            x = tw;
            xv = -1;
        };

        if (y == 0) {
            yv = 1;
        } else if (y >= th) {
            y = th;
            yv = -1;
        };

        // move
        x += xv; y += yv;
    };

    endwin();
};
