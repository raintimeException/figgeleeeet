#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FONT_SZ 4
#define LETTER_WIDTH 6
#define TOTAL_LETTERS 128

// TODO: more
char A[FONT_SZ][LETTER_WIDTH] = {
    "  __  ",
    " /  \\ ",
    "|----|",
    "|    |",
};

char B[FONT_SZ][LETTER_WIDTH] = {
    ".----.",
    "|    |",
    "|----|",
    "|____|",
};

char C[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "|    |",
    "|     ",
    "|____|",
};

char *glyph[TOTAL_LETTERS][FONT_SZ];

int main(int argc, char *argv[])
{

    const char *supported_chars = "ABC";
    char *prog_name = *argv++;
    if (argc < 2) {
        printf("usage: ");
        printf("%s ", prog_name);
        printf("[%s]\n", supported_chars);
        return -1;
    }

    char *chars = *argv;
    int chars_count = strlen(chars);
    for (int c = 0; c < chars_count; ++c) {
        for (int i = 0; i < FONT_SZ; ++i) {
            char curr_char = chars[c];
            glyph[curr_char][i] = malloc(LETTER_WIDTH*sizeof(char));
            // fixme
            switch (curr_char) {
                case 'A': memcpy(glyph[curr_char][i], A[i], LETTER_WIDTH); break;
                case 'B': memcpy(glyph[curr_char][i], B[i], LETTER_WIDTH); break;
                case 'C': memcpy(glyph[curr_char][i], C[i], LETTER_WIDTH); break;
            }
        }
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
