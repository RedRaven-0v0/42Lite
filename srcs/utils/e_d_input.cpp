#include "game.hpp"

static struct termios originalTermios;
static bool inputDisabled = false;

void disableInput(void)
{
    if (inputDisabled)
        return;
    tcgetattr(STDIN_FILENO, &originalTermios);
    struct termios t = originalTermios;
    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 0;
    t.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    tcflush(STDIN_FILENO, TCIFLUSH);
    inputDisabled = true;
}

void enableInput(void)
{
    if (!inputDisabled)
        return;
    tcflush(STDIN_FILENO, TCIFLUSH);
    tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    inputDisabled = false;
}
