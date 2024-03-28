/*
** EPITECH PROJECT, 2024
** rush03
** File description:
** flop
*/
#include "Display.hpp"

int main()
{
    Displays disp;
    disp.initNcurses();
    disp.dispInformations();
    getch();
    endwin();
    return 0;
}
