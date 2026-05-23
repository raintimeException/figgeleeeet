#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FONT_H 5
#define FONT_W 7

#define TOTAL_LETTERS 128

#define ARRSZ(x) (sizeof(x)/sizeof(*x))

#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')

#define TO_UPPER_CASE(c) (((c) >= 'a' && (c) <= 'z') ? c -= 32 : c)
#define TO_LOWER_CASE(c) (((c) >= 'A' && (c) <= 'Z') ? c += 32 : c)

typedef enum {false, true} bool;

bool _is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}


typedef struct {
    char c;
    char data[FONT_H][FONT_W];
} Font;


bool char_is_allowed(char c)
{
    assert(c >= 'A' && c <= 'Z' || _is_space(c));
    return true;
}

Font *get_font_from_font_arr_with_c(Font *font_arr, int font_arr_len, char c)
{
    assert(font_arr != NULL);
    assert(font_arr_len >= 0);
    assert(char_is_allowed(c) == true);

    for (int pos = 0; pos < font_arr_len; ++pos) {
        if (font_arr[pos].c == c)
            return &font_arr[pos];
    }
    return NULL;
}

void _null_terminate_font_data_row(Font *font, int row)
{
    assert(font != NULL);
    assert(row <= FONT_H);

    font->data[row][FONT_W-1] = 0;
    assert(font->data[row][FONT_W-1] == 0);
}

char *get_data_row_from_font(Font *font_arr, int font_arr_len, int row, char c) {
    assert(font_arr != NULL);
    assert(font_arr_len >= 0);
    assert(row <= FONT_H);
    assert(char_is_allowed(c) == true);

    Font *_font = get_font_from_font_arr_with_c(font_arr, font_arr_len, c);
    assert(_font != NULL);

    _null_terminate_font_data_row(_font, row);
    return _font->data[row];
}


Font font_arr[] = {
    {' ', {
    "      ",
    "      ",
    "      ",
    "      ",
    "      ",
}},
    {'A', {
    "  __  ",
    " /  \\ ",
    "|    |",
    "|----|",
    "|    |",
}},
    {'B', {
    ".___. ",
    "|   | ",
    "|---\\ ",
    "|    |",
    "|___/ ",
}},
    {'C', {
    ".____.",
    "|    |",
    "|     ",
    "|    .",
    "|____|",
}},
    {'D', {
    ".__.  ",
    "|   \\ ",
    "|    \\",
    "|    /",
    "|___/ ",
}},
    {'E', {
    ".____.",
    "|     ",
    "|---- ",
    "|     ",
    "|____.",
}},
    {'F', {
    ".____.",
    "|     ",
    "|---- ",
    "|     ",
    "|     ",
}},
    {'G', {
    " .__. ",
    "/    \\",
    "|   _.",
    "|    /",
    "|___/ ",
}},
    {'H', {
    ".    .",
    "|    |",
    "|____|",
    "|    |",
    "|    |",
}},
    {'I', {
    "   .  ",
    "   |  ",
    "   |  ",
    "   |  ",
    "   |  ",
}},
    {'J', {
    "   .  ",
    "   |  ",
    ".  |  ",
    "|  |  ",
    " \\/   ",
}},
    {'K', {
    ".    .",
    "|   / ",
    "|__/  ",
    "|  \\  ",
    "|   \\ ",
}},
    {'L', {
    ".     ",
    "|     ",
    "|     ",
    "|     ",
    "|____ ",
}},
    {'M', {
    ".    .",
    "|    |",
    "|\\__/|",
    "|    |",
    "|    |",
}},
    {'N', {
    ".   . ",
    "|\\  | ",
    "| \\ | ",
    "|  \\| ",
    "|   | ",
}},
    {'O', {
    " ____.",
    "/    |",
    "|    |",
    "|    |",
    "|____|",
}},
    {'P', {
    " ____ ",
    "|    |",
    "|____|",
    "|     ",
    "|     ",
}},
    {'Q', {
    " ____ ",
    "/   | ",
    "|   | ",
    "|   | ",
    "|__/\\ ",
}},
    {'R', {
    ".____.",
    "|    |",
    "|----*",
    "|\\___.",
    "|    |",
}},
    {'S', {
    ".___.",
    "|    ",
    "|___.",
    "    |",
    ".___|",
}},
    {'T', {
    ".____.",
    "  |   ",
    "  |   ",
    "  |   ",
    "  |   ",
}},
    {'U', {
    ".   . ",
    "|   | ",
    "|   | ",
    "|  /| ",
    "|_/ |_",
}},
    {'V', {
    ".    .",
    "|    |",
    "|    |",
    "|    |",
    " \\__/ ",
}},
    {'W', {
    ". . . ",
    "| | | ",
    "| | | ",
    "| | | ",
    " \\|/  ",
}},
    {'X', {
    ".   .",
    " \\|/ ",
    "  |  ",
    " /|\\ ",
    "| | |",
}},
    {'Y', {
    ".    .",
    "|    |",
    "|____|",
    "     |",
    " .__/ ",
}},
    {'Z', {
    ".___. ",
    "   /  ",
    "  /   ",
    " /    ",
    "/___. ",
}},
};


char *glyph[TOTAL_LETTERS][FONT_H];

int main(int argc, char *argv[])
{
    const char *supported_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *prog_name = *argv++;
    if (argc < 2) {
        printf("usage: ");
        printf("%s ", prog_name);
        printf("[%s]\n", supported_chars);
        return -1;
    }
    char *chars = *argv;
    int chars_count = strlen(chars);

    char *out[FONT_H];
    char *line;
    int line_len = FONT_W * chars_count * sizeof(char) + 1;

    for (int row = 0; row < FONT_H; ++row) {
        out[row] = malloc(line_len*sizeof(char) + 1);
        assert(out[row] != NULL);
        line = malloc(line_len*sizeof(char) + 1);
        assert(line != NULL);

        for (int ci = 0; ci < chars_count; ++ci) {
            char c = TO_UPPER_CASE(chars[ci]);
            char *data = get_data_row_from_font(font_arr, ARRSZ(font_arr), row, c);
            strcat(line, data);
        }
        memcpy(out[row], line, line_len - 1);
    }

    for (int i = 0; i < FONT_H; ++i) {
        printf("%s\n", out[i]);
    }
    return 0;
}

/*
 * TODO:
 * [] give the possibility choose the size of the font x2, x3
 * [] no libs, only standard... (unistd.h)
 * [] no heap allocation
 */
