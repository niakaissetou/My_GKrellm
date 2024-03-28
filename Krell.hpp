/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** step1
*/
#ifndef KRELL_HPP
    #define KRELL_HPP
    #include <string>
    #include <iostream>
    #include "unistd.h"
    #include <pwd.h>
    #include <string>
    #include <vector>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() {}
        //virtual void update() = 0;
    protected:
    };

    class IDisplay {
    public:
        virtual ~IDisplay() {}
        virtual std::string setUser() const = 0;
        virtual std::string setHost() const = 0;
        virtual std::string setDate() const = 0;
        virtual std::string setTm() const = 0;
    };
}

#endif
