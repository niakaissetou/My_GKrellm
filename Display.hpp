/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** test
*/

#ifndef MODULES_HPP_
    #define MODULES_HPP_
    #include "Krell.hpp"
    #include "ncurses.h"
    #include <ctime>

class Displays : public Krell::IDisplay {
    public:
        Displays();

        void initNcurses();
        void dispInformations();

        std::string setUser() const override;
        std::string setHost() const override;
        std::string setDate() const override;
        std::string setTm() const override;
        //void update() override;
        ~Displays() override;

    protected:
        std::string user;
        std::string host;
        std::string date;
        std::string tim;
        WINDOW *window;
    private:
};

#endif