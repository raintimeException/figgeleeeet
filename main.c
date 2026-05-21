#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FONT_SZ 5
#define LETTER_WIDTH 6
#define TOTAL_LETTERS 128

char A[FONT_SZ][LETTER_WIDTH] = {
    "  __  ",
    " /  \\ ",
    "|    |",
    "|----|",
    "|    |",
};

char B[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "|    |",
    "|----|",
    "|    |",
    "|____|",
};

char C[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "|    |",
    "|     ",
    "|    |",
    "|____|",
};

char D[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "|    \\",
    "|    |",
    "|    |",
    "\\____|",
};

char E[FONT_SZ][LETTER_WIDTH] = {
    " _____",
    "|     ",
    "|-----",
    "|     ",
    "|_____",
};

char F[FONT_SZ][LETTER_WIDTH] = {
    " _____",
    "|     ",
    "|-----",
    "|     ",
    "|     ",
};

char G[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "/    \\",
    "|   _ ",
    "|    |",
    "|___/ ",
};

char H[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|    |",
    "|    |",
    "|----|",
    "|    |",
};

char I[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "   |  ",
    "   |  ",
    "   |  ",
    "   |  ",
};

char J[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "   |  ",
    "   |  ",
    "   /  ",
    "\\_/   ",
};

char K[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|   / ",
    "|__/  ",
    "|  \\  ",
    "|   \\ ",
};

char L[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|     ",
    "|     ",
    "|     ",
    "\\_____",
};

char M[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|\\  | ",
    "| \\/| ",
    "|   | ",
    "|   | ",
};

char N[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|\\  | ",
    "| \\ | ",
    "|  \\| ",
    "|   | ",
};

char O[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "/    |",
    "|    |",
    "|    |",
    "|____|",
};

char P[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "|    |",
    "|____|",
    "|     ",
    "|     ",
};

char Q[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "/   | ",
    "|   | ",
    "|   | ",
    "|__/\\ ",
};

char R[FONT_SZ][LETTER_WIDTH] = {
    " ____ ",
    "/    |",
    "|    |",
    "|___/ ",
    "|   | ",
};

char S[FONT_SZ][LETTER_WIDTH] = {
    " ____",
    "|    ",
    "|____",
    "    |",
    "____|",
};

char T[FONT_SZ][LETTER_WIDTH] = {
    "_____ ",
    "  |   ",
    "  |   ",
    "  |   ",
    "  |   ",
};

char U[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|   | ",
    "|   | ",
    "|  /| ",
    "|_/ |_",
};

char V[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|    |",
    "|    |",
    "|    |",
    "|___/ ",
};

char W[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "| |  |",
    "| |  |",
    "| |  |",
    "|_|__|",
};

char X[FONT_SZ][LETTER_WIDTH] = {
    " ___",
    "| | |",
    "  |  ",
    "  |  ",
    "|_|_|",
};

char Y[FONT_SZ][LETTER_WIDTH] = {
    "      ",
    "|    |",
    "|____|",
    "     |",
    "  __/ ",
};

char Z[FONT_SZ][LETTER_WIDTH] = {
    "____  ",
    "   /  ",
    "  /   ",
    " /    ",
    "/____",
};



char *glyph[TOTAL_LETTERS][FONT_SZ];

int main(int argc, char *argv[])
{
    const char *supported_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *prog_name = *argv++;
    if (argc < 2) {
usage:
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
            // FIXME
            switch (curr_char) {
                case 'A': memcpy(glyph[curr_char][i], A[i], LETTER_WIDTH); break;
                case 'B': memcpy(glyph[curr_char][i], B[i], LETTER_WIDTH); break;
                case 'C': memcpy(glyph[curr_char][i], C[i], LETTER_WIDTH); break;
                case 'D': memcpy(glyph[curr_char][i], D[i], LETTER_WIDTH); break;
                case 'E': memcpy(glyph[curr_char][i], E[i], LETTER_WIDTH); break;
                case 'F': memcpy(glyph[curr_char][i], F[i], LETTER_WIDTH); break;
                case 'G': memcpy(glyph[curr_char][i], G[i], LETTER_WIDTH); break;
                case 'H': memcpy(glyph[curr_char][i], H[i], LETTER_WIDTH); break;
                case 'I': memcpy(glyph[curr_char][i], I[i], LETTER_WIDTH); break;
                case 'J': memcpy(glyph[curr_char][i], J[i], LETTER_WIDTH); break;
                case 'K': memcpy(glyph[curr_char][i], K[i], LETTER_WIDTH); break;
                case 'L': memcpy(glyph[curr_char][i], L[i], LETTER_WIDTH); break;
                case 'M': memcpy(glyph[curr_char][i], M[i], LETTER_WIDTH); break;
                case 'N': memcpy(glyph[curr_char][i], N[i], LETTER_WIDTH); break;
                case 'O': memcpy(glyph[curr_char][i], O[i], LETTER_WIDTH); break;
                case 'P': memcpy(glyph[curr_char][i], P[i], LETTER_WIDTH); break;
                case 'Q': memcpy(glyph[curr_char][i], Q[i], LETTER_WIDTH); break;
                case 'R': memcpy(glyph[curr_char][i], R[i], LETTER_WIDTH); break;
                case 'S': memcpy(glyph[curr_char][i], S[i], LETTER_WIDTH); break;
                case 'T': memcpy(glyph[curr_char][i], T[i], LETTER_WIDTH); break;
                case 'U': memcpy(glyph[curr_char][i], U[i], LETTER_WIDTH); break;
                case 'V': memcpy(glyph[curr_char][i], V[i], LETTER_WIDTH); break;
                case 'W': memcpy(glyph[curr_char][i], W[i], LETTER_WIDTH); break;
                case 'X': memcpy(glyph[curr_char][i], X[i], LETTER_WIDTH); break;
                case 'Y': memcpy(glyph[curr_char][i], Y[i], LETTER_WIDTH); break;
                case 'Z': memcpy(glyph[curr_char][i], Z[i], LETTER_WIDTH); break;
                default:
                    goto usage;
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

/*
 * TODO:
 * no libs, only standard...
 * no malloc, no freee...
 *
 */
