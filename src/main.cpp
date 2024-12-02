#include <ncurses.h>
#include <string.h>
#include <cstdlib>
#include <locale.h>
#include "clockfont.h"

/**
 * @brief The main function of the program.
 *
 * This function initializes the ncurses library and sets up the
 * terminal. It then enters an infinite loop where it prints the
 * current time on the screen in a fancy way.
 *
 * The user can change the font of the clock by pressing 'w' or 'W'.
 * The program will quit if the user presses 'q' or 'Q'.
 *
 * The function will only work if the terminal window is at least 6
 * lines and 55 columns tall.
 */
int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
    raw();
    noecho();
    timeout(1000);

    char* clockString;

    int height, width;
    int prevHeight = 0, prevWidth = 0;

    char ch;
    int font = 0;

    while (1) {
        getmaxyx(stdscr, height, width);

        if (height < 6 || width < 55) {
            clear();
            mvprintw(0, 0, "The terminal window is too small");
            refresh();
            continue;
        }

        if (height != prevHeight || width != prevWidth) {
            clear();
            prevHeight = height;
            prevWidth = width;
        }

        clockString = getTime((width / 2) - 24, font);

        mvprintw((height / 2) - 3, 0, clockString);

        mvprintw(height - 1, 0, "Press `q` or `Q` to quit");
        mvprintw(height - 1, width - 4, "Press w to change font");

        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;

        if (ch == 'w' || ch == 'W') {
            font = (font + 1) % 4;
        }

        refresh();
    }
    clear();
    endwin();
    return 0;
}

