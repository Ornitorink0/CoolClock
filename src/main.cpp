#include <ncurses.h>
#include <string.h>
#include <cstdlib>
#include <locale.h>
#include "clockfont.h"

/**
 * @brief Shows a simple user menu when `h` is pressed.
 *
 * This function prints a menu with options that can be chosen by the user.
 */
void showInstructions(int height, int width) {
    clear();

    attron(COLOR_PAIR(1));
    mvprintw(height / 2 - 2, width / 2 - 15, "Instructions:");
    mvprintw(height / 2 - 1, width / 2 - 15, "├ Press `q` or `Q` to quit");
    mvprintw(height / 2, width / 2 - 15, "├ Press `w` or `W` to change font");
    mvprintw(height / 2 + 1, width / 2 - 15, "├ Press `c` to change color scheme");
    mvprintw(height / 2 + 2, width / 2 - 15, "└ Press `h` to hide this menu");
    attroff(COLOR_PAIR(1));

    refresh();
}

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
    curs_set(0);
    timeout(1000);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_BLUE, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }

    char* clockString;

    int height, width;
    int prevHeight = 0, prevWidth = 0;

    char ch;
    int font = 0;
    int colorScheme = 0;
    bool showMenuFlag = false;

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

        attron(COLOR_PAIR(colorScheme));
        
        if (!showMenuFlag) {
            mvprintw((height / 2) - 3, 0, clockString);
            mvprintw(height - 1, 0, "Press `h` to show instructions");
        }
        
        attroff(COLOR_PAIR(colorScheme));

        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;

        if (ch == 'w' || ch == 'W') {
            font = (font + 1) % 4;
        }

        if (ch == 'c' || ch == 'C') {
            colorScheme = (colorScheme % 7) + 1;
        }

        if (ch == 'h' || ch == 'H') {
            showMenuFlag = !showMenuFlag;
            if (showMenuFlag) showInstructions(height, width);
            else clear();
        }

        refresh();
    }
    clear();
    endwin();
    return 0;
}
