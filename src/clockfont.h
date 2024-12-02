#ifndef CLOCKFONT_H
#define CLOCKFONT_H

#include <ncurses.h>

// #define ANSI_RESET "\033[0m"
// #define ANSI_BLACK "\033[30m"
// #define ANSI_RED "\033[31m"
// #define ANSI_GREEN "\033[32m"
// #define ANSI_YELLOW "\033[33m"
// #define ANSI_BLUE "\033[34m"
// #define ANSI_MAGENTA "\033[35m"
// #define ANSI_CYAN "\033[36m"
// #define ANSI_WHITE "\033[37m"

extern const char* font_hashtag[10][5];
extern const char* font_asterisk[10][5];
extern const char* font_lines[10][5];
extern const char* font_doublelines[10][5];

char* getNormalClock();
char* getTime(int margin, int f);

#endif // CLOCKFONT_H