//
// Created by Admin on 02.01.2019.
//

#include "c_menu_command.h"
#include "util.h"
#include "../consts.h"


c_menu_command::c_menu_command() {
    command = DEFAULT_C_COMMAND;
    s_name = DEFAULT_NAME;
    s_command = DEFAULT_COMMAND;
}

c_menu_command::c_menu_command(std::string name, std::string command) {
    s_name = name;
    s_command = command;
}

c_menu_command::~c_menu_command() {
    delete command;

}

bool c_menu_command::run() {
    if (command) {
        return command->run_command();
    } else {
        std::cout << BLANK_COMMAND
        return true;
    }
}

std::string c_menu_command::get_command() { return s_command; };

std::string c_menu_command::get_name() { return s_name; }

void c_menu_command::set_command(c_command *cmd) {
    command = cmd;

}

void c_menu_command::print_help() {
    command->print_help();

}

void c_menu_command::print() {
    std::cout << BEGINNING_OF_COMMAND
              << APOSTROPH + s_name + APOSTROPH + NAME_SEPARATOR + APOSTROPH + s_command + APOSTROPH + NAME_SEPARATOR +
                 APOSTROPH;
    command->print_help();
    std::cout << APOSTROPH << ENDING_OF_COMMAND;
}

std::string c_menu_command::read(const std::string &input, std::string &exception, int &position) {
    if (if_char(input, BEGINNING_OF_COMMAND, exception, position) == -1) return exception;

    s_name = parse(input, exception, position, APOSTROPH);
    if (!exception.empty()) return exception;

    if (if_char(input, NAME_SEPARATOR, exception, position) == -1) return exception;

    s_command = parse(input, exception, position, APOSTROPH);
    if (!exception.empty()) return exception;

    if (if_char(input, NAME_SEPARATOR, exception, position) == -1) return exception;

    command->set_help(parse(input, exception, position, APOSTROPH));
    if (!exception.empty()) return exception;

    if (if_char(input, ENDING_OF_COMMAND, exception, position) == -1) return exception;
    return exception;
}
