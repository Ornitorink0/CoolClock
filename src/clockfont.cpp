#include <ncurses.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "clockfont.h"

#define CLOCK_BUFFER_SIZE 80

char* CLOCK_FONT[10][5];

/**
 * @brief (USED ONLY FOR DEBUG) Returns the current time in 24 hour format.
 *
 * The time is returned as a string in the format "HH:MM:SS".
 *
 * @return a pointer to a static string containing the current time.
 */
char* getNormalClock() {
    time_t now = time(0);
    struct tm *tstruct = localtime(&now);
    static char buffer[CLOCK_BUFFER_SIZE];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", tstruct);

    return buffer;
}

/**
 * @brief Returns the current time as a string in the given font.
 *
 * The current time is converted to a string in the given font and
 * returned as a pointer to a static string.
 *
 * The string is returned in the format "HH:MM:SS" where each digit
 * is represented by the corresponding character in the chosen font.
 *
 * The margin parameter is used to set the left margin of the string.
 *
 * The font parameter is used to select the font from the following:
 *   0:  font_hashtag
 *   1:  font_asterisk
 *   2:  font_lines
 *   3:  font_doublelines
 *
 * @param margin the left margin of the string
 * @param f the font to use
 *
 * @return a pointer to a static string containing the current time
 *         in the given font.
 */
char* getTime(int margin, int f) {
    time_t now = time(0);
    struct tm *tstruct = localtime(&now);
    int h = tstruct->tm_hour;
    int m = tstruct->tm_min;
    int s = tstruct->tm_sec;
    static char buffer[CLOCK_BUFFER_SIZE];
    int offset = 0;

    switch (f)
    {
        case 0:  memcpy(CLOCK_FONT, font_hashtag,       sizeof(font_hashtag));      break;
        case 1:  memcpy(CLOCK_FONT, font_asterisk,      sizeof(font_asterisk));     break;
        case 2:  memcpy(CLOCK_FONT, font_lines,         sizeof(font_lines));        break;
        case 3:  memcpy(CLOCK_FONT, font_doublelines,   sizeof(font_doublelines));  break;
        default: memcpy(CLOCK_FONT, font_hashtag,       sizeof(font_hashtag));      break;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < margin; j++) {
            buffer[offset++] = ' ';
        }

        offset += sprintf(buffer + offset, "%s%s  %s%s  %s%s\n",
                          CLOCK_FONT[h / 10][i], CLOCK_FONT[h % 10][i],
                          CLOCK_FONT[m / 10][i], CLOCK_FONT[m % 10][i],
                          CLOCK_FONT[s / 10][i], CLOCK_FONT[s % 10][i]);
    }

    return buffer;
}

