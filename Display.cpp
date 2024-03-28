/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** test
*/

#include "Display.hpp"

Displays::Displays() : window(nullptr)
{
}

void Displays::initNcurses()
{
    if (window == nullptr) {
        initscr();
        resize_term(30, 100);
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        box(stdscr, 0, 0);
        refresh();
    }
}

std::string Displays::setUser() const
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    std::string user;

    if (!pw) {
        return "";
    }
    if (pw) {
        user = pw->pw_name;
    }
    return user;
}

std::string Displays::setHost() const
{
    std::string host;
    char hostname[200];

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        host = hostname;
    } else
        host = "";
    return host;
}

std::string Displays::setDate() const
{
    std::time_t now = std::time(nullptr);
    char dateString[sizeof("dd/mm/yyyy")];
    std::strftime(dateString, sizeof(dateString), "%d/%m/%Y", std::localtime(&now));
    return std::string(dateString);
}

std::string Displays::setTm() const
{
    std::time_t now = std::time(nullptr);
    char timeString[sizeof("HH:mm:ss")];
    std::strftime(timeString, sizeof(timeString), "%H:%M:%S", std::localtime(&now));
    return std::string(timeString);
}

void Displays::dispInformations()
{
    initNcurses();

    user = setUser();
    host = setHost();
    date = setDate();
    tim = setTm();

    attron(COLOR_PAIR(2));
    mvprintw(0, 3, "System Info");
    attroff(COLOR_PAIR(2));

    mvprintw(2, 2, "Username: ");
    attron(COLOR_PAIR(1));
    printw("%s", user.c_str());
    attroff(COLOR_PAIR(1));

    mvprintw(3, 2, "Hostname: ");
    attron(COLOR_PAIR(1));
    printw("%s", host.c_str());
    attroff(COLOR_PAIR(1));

    mvprintw(3, 87, " %s", date.c_str());
    mvprintw(4, 89, " %s", tim.c_str());

    refresh();

}

Displays::~Displays()
{
    if (window != nullptr) {
        endwin();
    }
}