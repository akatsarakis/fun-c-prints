//
// Created by Antonis Katsarakis on 20/10/2018.
//

#include "func_prints.h"

#include <memory.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>

#define FUNC_PRINTF(st, fg, bg, f) do{ \
    va_list args;                       \
    va_start(args, format);             \
    func_printf(st, fg, bg, f, args);   \
    va_end(args);                       \
}while(0)

static inline void
append_uint8_t_to_str(char* str, uint8_t n)
{
    char uint8_to_str[5]; //stores a uint8_t to str with a ';' at the end
    snprintf(uint8_to_str, 3, "%d", n);
    strcat(str, uint8_to_str);
}

static void
style_n_color_switcher(uint8_t text_style,
                       uint8_t foreground_op, uint8_t background_op,
                       char *ret_value, uint16_t val_len)
{
    assert(val_len > 5);
    ret_value[0] = '\0';
    strcat(ret_value, "\033[");

    switch(text_style) {
        case FP_STYLE_DEFAULT:
        case FP_STYLE_BOLD:
        case FP_STYLE_DIM:
        case FP_STYLE_UNDERLINED:
        case FP_STYLE_BLINK:
        case FP_STYLE_REVERSE:
        case FP_STYLE_HIDDEN:
            append_uint8_t_to_str(ret_value, text_style);
            strcat(ret_value, ";");
            break;
        default:
            printf("There is no text style with opcode %d, is not supported\n", text_style);
            assert(0);
    }

    switch(foreground_op) {
        case FP_FOREGROUND_DEFAULT :
        case FP_FOREGROUND_BLACK :
        case FP_FOREGROUND_RED :
        case FP_FOREGROUND_GREEN :
        case FP_FOREGROUND_YELLOW :
        case FP_FOREGROUND_BLUE :
        case FP_FOREGROUND_MAGENTA :
        case FP_FOREGROUND_CYAN :
        case FP_FOREGROUND_LIGHT_GRAY :
        case FP_FOREGROUND_DARK_GRAY :
        case FP_FOREGROUND_LIGHT_RED :
        case FP_FOREGROUND_LIGHT_GREEN :
        case FP_FOREGROUND_LIGHT_YELLOW :
        case FP_FOREGROUND_LIGHT_BLUE :
        case FP_FOREGROUND_LIGHT_MAGENTA :
        case FP_FOREGROUND_LIGHT_CYAN :
        case FP_FOREGROUND_WHITE :
            append_uint8_t_to_str(ret_value, foreground_op);
            strcat(ret_value, ";");
            break;
        default:
            printf("There is no foreground with opcode %d, is not supported\n", foreground_op);
            assert(0);
    }

    switch(background_op){
        case FP_BACKGROUND_DEFAULT :
        case FP_BACKGROUND_BLACK :
        case FP_BACKGROUND_RED :
        case FP_BACKGROUND_GREEN :
        case FP_BACKGROUND_YELLOW :
        case FP_BACKGROUND_BLUE :
        case FP_BACKGROUND_MAGENTA :
        case FP_BACKGROUND_CYAN :
        case FP_BACKGROUND_LIGHT_GRAY :
        case FP_BACKGROUND_DARK_GRAY :
        case FP_BACKGROUND_LIGHT_RED :
        case FP_BACKGROUND_LIGHT_GREEN :
        case FP_BACKGROUND_LIGHT_YELLOW :
        case FP_BACKGROUND_LIGHT_BLUE :
        case FP_BACKGROUND_LIGHT_MAGENTA :
        case FP_BACKGROUND_LIGHT_CYAN :
        case FP_BACKGROUND_WHITE :
            append_uint8_t_to_str(ret_value, background_op);
            strcat(ret_value, ";");
            break;
        default: {
            printf("There is no background with opcode %d, is not supported\n", background_op);
            assert(0);
        }
    }

    strcat(ret_value, "m");
}


//static
void
func_printf(uint8_t text_style, uint8_t foreground_color, uint8_t background_color, const char *format, ...)
{
    va_list args;
    int i;

    char buf1[BUFF_LIM], buf2[BUFF_LIM];
    memset(buf1, '\0', BUFF_LIM);
    memset(buf2, '\0', BUFF_LIM);

    if(text_style == 0)
        text_style = FP_STYLE_DEFAULT;

    if(foreground_color == 0)
        foreground_color = FP_FOREGROUND_DEFAULT;

    if(background_color == 0)
        background_color = FP_BACKGROUND_DEFAULT;

    va_start(args, format);

    // Marshal the stuff to print in a buffer
    vsnprintf(buf1, BUFF_LIM, format, args);

    // Probably a bad check for buffer overflow
    for(i = BUFF_LIM - 1; i >= BUFF_LIM - 50; --i)
        assert(buf1[i] == '\0');

    // Get the create the color code
    char value[10];
    style_n_color_switcher(text_style, foreground_color, background_color, value, 10);

    // Add markers for red color and reset color
    snprintf(buf2, 1000, "%s%s\033[0m", value, buf1);

    // Probably another bad check for buffer overflow
    for(i = BUFF_LIM - 1; i >= BUFF_LIM - 50; --i)
        assert(buf2[i] == 0);

    printf("%s", buf2);
    printf("\033[0;49m"); //reset color
    va_end(args);
}

// Like printf, but red. Limited to Buff_lim characters.
void
red_printf(const char *format, ...)
{
    FUNC_PRINTF(0, FP_FOREGROUND_RED, 0, format);
}

void
cyan_printf(const char *format, ...)
{
    FUNC_PRINTF(0, FP_FOREGROUND_CYAN, 0, format);
}

void
green_printf(const char *format, ...)
{
    FUNC_PRINTF(0, FP_FOREGROUND_GREEN, 0, format);
}

void
yellow_printf(const char *format, ...)
{
    FUNC_PRINTF(0, FP_FOREGROUND_YELLOW, 0, format);
}

void
black_fg_white_bg_printf(const char *format, ...)
{
    FUNC_PRINTF(0, FP_FOREGROUND_WHITE, FP_BACKGROUND_BLACK, format);
}

void
bold_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_BOLD, 0, 0, format);
}

void underlined_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_UNDERLINED, 0, 0, format);
}

void dim_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_DIM, 0, 0, format);
}

void blink_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_BLINK, 0, 0, format);
}

void reverse_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_REVERSE, 0, 0, format);
}

void hidden_printf(const char *format, ...)
{
    FUNC_PRINTF(FP_STYLE_HIDDEN, 0, 0, format);
}
