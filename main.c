#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FONT_SZ 4
#define LETTER_WIDTH 6
#define TOTAL_LETTERS 128

char A[FONT_SZ][LETTER_WIDTH] = {
    "  __  ",
    " /  \\ ",
    "|----|",
    "|    |",
};

char C[FONT_SZ][LETTER_WIDTH] = {
    " ____",
    "|    |",
    "|    ",
    "|____|",
};


int main(int argc, char *argv[])
{

    (void)argc;
    (void)argv;
    char *chars = "AC";
    int chars_count = strlen(chars);
    char *glyph[TOTAL_LETTERS][FONT_SZ];

    for (int i = 0; i < FONT_SZ; ++i) {
        glyph['A'][i] = malloc(LETTER_WIDTH*sizeof(char));
        memcpy(glyph['A'][i], A[i], LETTER_WIDTH);
    }
    for (int i = 0; i < FONT_SZ; ++i) {
        glyph['C'][i] = malloc(LETTER_WIDTH*sizeof(char));
        memcpy(glyph['C'][i], C[i], LETTER_WIDTH);
    }
    char *out[FONT_SZ];

    int line_len = LETTER_WIDTH * chars_count * sizeof(char);
    int is_letter_num = 1;
    for (int i = 0; i < FONT_SZ; ++i) {
        char *line = malloc(line_len);
        int k;
        for (int j = 0; j < chars_count; ++j) {
            strcat(line, glyph[chars[j]][i]);
        }
        line[line_len] = 0;
        out[i] = malloc(line_len + 1);
        memcpy(out[i], line, line_len + 1);
    }
    for (int i = 0; i < FONT_SZ; ++i) {
        printf("%s\n", out[i]);
    }

    return 0;
}
