#include <stdio.h>
#include <Windows.h>
/*
void setConsoleTextColors(int foregroundColor, int backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, foregroundColor | (backgroundColor << 4));
}

void printRainbowMessage(const char *message)
{
    const int foregroundColors[] = {
        FOREGROUND_RED | FOREGROUND_INTENSITY,      // Red
        FOREGROUND_GREEN | FOREGROUND_INTENSITY,    // Green
        FOREGROUND_BLUE | FOREGROUND_INTENSITY,     // Blue
        FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,     // Magenta
        FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,   // Cyan
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY     // Yellow
    };
    const int backgroundColors[] = {
        BACKGROUND_RED | BACKGROUND_INTENSITY,      // Red
        BACKGROUND_GREEN | BACKGROUND_INTENSITY,    // Green
        BACKGROUND_BLUE | BACKGROUND_INTENSITY,     // Blue
        BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY,     // Magenta
        BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY,   // Cyan
        BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY     // Yellow
    };
    const int numColors = sizeof(foregroundColors) / sizeof(foregroundColors[0]);
    const int messageLength = strlen(message);

    for (int i = 0; i < messageLength; i++)
    {
        setConsoleTextColors(foregroundColors[i % numColors], backgroundColors[i % numColors]);
        putchar(message[i]);
    }

    // Reset console text colors
    setConsoleTextColors(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE, 0);
}

int main()
{
    const char *message = "Hello, Rainbow!";
    printRainbowMessage(message);

    return 0;
}
*/
#include <stdio.h>
#include "include/colors.h"
int main(){
    //LETTER_BLUE;
    //BACKGROUND_COLOR_CYAN;
    
    printf_color("#{BG:cyan}#{FG:yellow}%.2X#{FG:red}#{BG:purple} a#{BG:reset}\n",  BACKGROUND_BLUE | FOREGROUND_RED);
    //LETTER_GREEN;
    //BACKGROUND_COLOR_WHITE;
    
    printf_color("#{FG:225;%d;30}#{BG:30;%d;225}a#{BG:reset}\n", 40);
    puts("---------------------");
    LETTER_RESET;
    return 0;
}