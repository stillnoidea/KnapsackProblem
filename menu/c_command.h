//
// Created by Admin on 02.01.2019.
//

#ifndef LAB4_C_COMMAND_H
#define LAB4_C_COMMAND_H

#include <iostream>
#include <vector>
#include "../consts.h"

class c_command {
public:
    std::string help;

    virtual bool run_command();

    void print_help();

    void set_help(std::string new_help);

    ~c_command();

};


#endif //LAB4_C_COMMAND_H
