//
// Created by Admin on 02.01.2019.
//

#include "c_command.h"
#include "c_menu_item.h"
#include "../consts.h"

bool c_command::run_command() {
    std::cout << DEFAULT_COMMAND;
    help = DEFAULT_COMMAND_HELP;
    return true;
}

c_command::~c_command() {

}

void c_command::print_help() {
    std::cout << help;
}

void c_command::set_help(std::string new_help) {
    help = new_help;
}

