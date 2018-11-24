#include <stdio.h>
#include "func_prints.h"

int main() {
    printf("White!\n");
    red_printf("Red!\n");
    cyan_printf("Cyan!\n");
    green_printf("Green!\n");
    yellow_printf("Yellow!\n");
    black_fg_white_bg_printf("Black on white\n");
    // Custom
    func_printf(0, FP_FOREGROUND_YELLOW, FP_BACKGROUND_RED, "antonis j%d\n", 67);
    bold_printf("Bold\n");
    underlined_printf("Underlined\n");
    dim_printf("Dim\n");
    hidden_printf("Hidden\n");
    blink_printf("Blink\n");
    reverse_printf("Reverse\n");
    printf("White!\n");
    return 0;
}