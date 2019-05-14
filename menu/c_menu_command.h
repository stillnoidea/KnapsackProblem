//
// Created by Admin on 02.01.2019.
//

#ifndef LAB4_C_MENU_COMMAND_H
#define LAB4_C_MENU_COMMAND_H


#include <string>
#include "c_menu_item.h"
#include "c_command.h"

class c_menu_command : public c_menu_item {

private:
    c_command *command;

public:
    c_menu_command();

    c_menu_command(std::string name, std::string command);

    ~c_menu_command();

    bool run();

    std::string get_command();

    std::string get_name();

    void set_command(c_command *command);

    void print_help();

    void print();

    std::string read(const std::string &input, std::string &exception, int &position);

};


#endif //LAB4_C_MENU_COMMAND_H
