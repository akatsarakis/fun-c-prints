//
// Created by Antonis Katsarakis on 20/10/2018.
//


/// A c library for fancy ("fun-c") printfs
#include <stdint.h>

#ifndef FANCY_PRINTS_FANCY_PRINTS_H
#define FANCY_PRINTS_FANCY_PRINTS_H

#define BUFF_LIM 1000

// Text styles
#define FP_STYLE_DEFAULT 0
#define FP_STYLE_BOLD 1
#define FP_STYLE_DIM 2
#define FP_STYLE_UNDERLINED 3
#define FP_STYLE_BLINK 4
#define FP_STYLE_REVERSE 7
#define FP_STYLE_HIDDEN 8

// Color opcodes
#define FP_FOREGROUND_DEFAULT 39
#define FP_FOREGROUND_BLACK 30
#define FP_FOREGROUND_RED 31
#define FP_FOREGROUND_GREEN 32
#define FP_FOREGROUND_YELLOW 33
#define FP_FOREGROUND_BLUE 34
#define FP_FOREGROUND_MAGENTA 35
#define FP_FOREGROUND_CYAN 36
#define FP_FOREGROUND_LIGHT_GRAY 37
#define FP_FOREGROUND_DARK_GRAY 90
#define FP_FOREGROUND_LIGHT_RED 91
#define FP_FOREGROUND_LIGHT_GREEN 92
#define FP_FOREGROUND_LIGHT_YELLOW 93
#define FP_FOREGROUND_LIGHT_BLUE 94
#define FP_FOREGROUND_LIGHT_MAGENTA 95
#define FP_FOREGROUND_LIGHT_CYAN 96
#define FP_FOREGROUND_WHITE 97

// Background color ops
#define FP_BACKGROUND_DEFAULT 49
#define FP_BACKGROUND_BLACK 40
#define FP_BACKGROUND_RED 41
#define FP_BACKGROUND_GREEN 42
#define FP_BACKGROUND_YELLOW 43
#define FP_BACKGROUND_BLUE 44
#define FP_BACKGROUND_MAGENTA 45
#define FP_BACKGROUND_CYAN 46
#define FP_BACKGROUND_LIGHT_GRAY 47
#define FP_BACKGROUND_DARK_GRAY 100
#define FP_BACKGROUND_LIGHT_RED 101
#define FP_BACKGROUND_LIGHT_GREEN 102
#define FP_BACKGROUND_LIGHT_YELLOW 103
#define FP_BACKGROUND_LIGHT_BLUE 104
#define FP_BACKGROUND_LIGHT_MAGENTA 105
#define FP_BACKGROUND_LIGHT_CYAN 106
#define FP_BACKGROUND_WHITE 107

// colorful printf like functions. Limited to BUFF LIM characters in length.
void red_printf(const char *format, ...);
void cyan_printf(const char *format, ...);
void green_printf(const char *format, ...);
void yellow_printf(const char *format, ...);


void black_fg_white_bg_printf(const char *format, ...);


void bold_printf(const char *format, ...);
void underlined_printf(const char *format, ...);
void dim_printf(const char *format, ...);
void blink_printf(const char *format, ...);
void reverse_printf(const char *format, ...);
void hidden_printf(const char *format, ...);

// if any of the (three opcodes) is set to zero the default value is used
void func_printf(uint8_t text_style, uint8_t foreground_color, uint8_t background_color, const char *format, ...);
#endif //FANCY_PRINTS_FANCY_PRINTS_H

