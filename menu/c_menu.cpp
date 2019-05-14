//
// Created by Admin on 02.01.2019.
//

#include <iostream>
#include <limits>
#include "c_menu.h"
#include "c_menu_command.h"
#include "../consts.h"
#include "util.h"
#include <sstream>

std::string c_menu::BACK_COMMAND = "back";
c_menu *c_menu::root;

c_menu::c_menu() {
    s_name = DEFAULT_NAME;
    s_command = DEFAULT_COMMAND;
}

c_menu::c_menu(std::string name, std::string command) {
    s_name = name;
    s_command = command;
}

c_menu::~c_menu() {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
    items.clear();
}

void c_menu::print_menu() {

    std::cout << NEW_LINE;
    std::cout << s_name + " (" + s_command + ")" + NEW_LINE;
    for (int i = 0; i < items.size(); i++) {
        std::cout << items[i]->get_name() + " (" + items[i]->get_command() + ")" + NEW_LINE;
    }
}

bool c_menu::run() {
    std::string task;
    bool executed;
    bool help;
    bool search;
    do {
        print_menu();

        getline(std::cin, task);
        if (task != "exit") {

            help = if_help(task);
            search = if_search(task);

            executed = false;
            for (int j = 0; j < items.size(); j++) {
                if (executed) continue;
                if (task == items[j]->get_command()) {
                    executed = true;
                    if (!items[j]->run()) return false;
                }
            }
            if (!executed && task != BACK_COMMAND && !help && !search) {
                std::cout << WRONG_COMMAND;
                std::cout << NEW_LINE;
            }
        }

    } while (task != BACK_COMMAND && task != "exit");

    std::cout << ENDING_RUN_FROM;
    std::cout << get_name() + NEW_LINE;
    return !(task == "exit");
}

bool c_menu::if_name_exist(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_name() == name) {
            std::cout << EXISTING_NAME;
            return true;
        }
    }
    return false;
}

bool c_menu::if_command_exist(std::string command) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_command() == command) {
            std::cout << EXISTING_COMMAND;
            return true;
        }
    }
    return false;
}

void c_menu::set_root(c_menu *new_root) {
    root = new_root;
}

bool c_menu::add_item(c_menu_item *item) {
    if (if_name_exist(item->get_name())) return false;
    if (if_command_exist(item->get_command())) return false;
    else {
        items.push_back(item);
        return true;
    }

}

bool c_menu::delete_item(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_name() == name) {
            c_menu_item *temp = items[i];
            items.erase(items.begin() + i);
            delete temp;
            return true;
        }
    }
    return false;
}

std::string c_menu::get_command() { return s_command; }

std::string c_menu::get_name() { return s_name; }

void c_menu::set_name(std::string name) {
    s_name = name;
}

void c_menu::set_command(std::string command) {
    s_command = command;
}

c_menu_item *c_menu::get_item(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_name() == name) {
            return items[i];
        }

    }
    return 0;
}

bool c_menu::if_help(std::string task) {
    if (task.substr(0, 6) == HELP && task.substr(task.size() - 1, 1) == SEARCH_HELP_CLOSING ){
        for (int i = 0; i < items.size(); i++) {
            if (task.substr(6, task.size() - 7) == items[i]->get_command()) {
                c_menu_command *temp;
                temp = dynamic_cast<c_menu_command *>(items[i]);
                temp->print_help();
                return true;
            }
        }
        std::cout << NO_COMMAND;
        return true;
    } else return false;
}

bool c_menu::if_search(std::string task) {
    if (task.substr(0, 8) == SEARCH  && task.substr(task.size() - 1, 1) ==  SEARCH_HELP_CLOSING) {
        std::string command;
        c_menu *temp;
        command = task.substr(8, task.size() - 9);
        for (int i = 0; i < root->items.size(); i++) {
            temp = dynamic_cast<c_menu *>( root->items[i]);
            if (temp != 0) { temp->searching(&command); }

        }
        return true;
    } else return false;
}

void c_menu::searching(std::string *command) {
    std::string path;
    c_menu *temp;
    path += s_name + ARROW;
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->get_command() == *command) {
            std::cout << root->s_name + ARROW + path + items[i]->get_command() + NEW_LINE;
        } else {
            temp = dynamic_cast<c_menu *>(items[i]);
            if (temp != 0) { temp->searching(command); }
        }
    }
}

void c_menu::print() {
    std::cout << BEGINNING_OF_MENU
              << APOSTROPH + s_name + APOSTROPH + NAME_SEPARATOR + APOSTROPH + s_command + APOSTROPH +
                 CHILDREN_SEPARATOR;
    for (int i = 0; i < items.size(); i++) {
        items[i]->print();
        if (i < items.size() - 1) std::cout << CHILD_SEPARATOR;
    }
    std::cout << ENDING_OF_MENU;
}

std::string c_menu::read(const std::string &input, std::string &exception, int &position) {
    int opction;
    if (!exception.empty()) return exception;

    if (if_char(input, BEGINNING_OF_MENU, exception, position) == -1) {
        return exception;
    }

    s_name = parse(input, exception, position, APOSTROPH);
    if (!exception.empty()) {
        return exception;
    }

    if (if_char(input, NAME_SEPARATOR, exception, position) == -1) {
        return exception;
    }

    s_command = parse(input, exception, position, APOSTROPH);
    if (!exception.empty()) {
        return exception;
    }

    if (if_char(input, CHILDREN_SEPARATOR, exception, position) == -1) {
        return exception;
    }

    int status;
    do {
        if (!exception.empty()) return exception;
        opction = if_char(input, BEGINNING_OF_MENU_OR_COMMAND_OR_ENDING_MENU, exception, position);

        if (opction == -1) return exception;
        if (opction == 0) {
            c_menu *child = new c_menu();
            add_item(child);
            child->read(input, exception, --position);
        }

        if (opction == 1) {
            c_menu_command *child = new c_menu_command();
            add_item(child);
            child->read(input, exception, --position);

            if (if_char(input, NAME_SEPARATOR, exception, position) == -1) {
                return exception;
            }
            if (child->get_command() != parse(input, exception, position, APOSTROPH)) {
                std::ostringstream stream;
                stream << position;
                exception = COMMAND_NOT_MATCHED_FOR_COMMAND + stream.str();
            }
            if (!exception.empty()) {
                return exception;
            }

        }
        if (!exception.empty()) {
            return exception;
        }

        status = if_char(input, CHILD_SEPARATOR_OR_ENDING_MENU, exception, position);
        if (status == -1 && position < input.length() - 1) {
            return exception;
        } else {
            exception.clear();
        }

        if (opction == 2 && status == 0) {

            if (s_command != parse(input, exception, position, APOSTROPH)) {
                std::ostringstream stream;
                stream << position;
                exception = COMMAND_NOT_MATCHED + stream.str();

            }
            if (!exception.empty()) {
                return exception;
            }
        }

    } while (opction != 2 && status == 0);

    return exception;
}
