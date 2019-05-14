//
// Created by Admin on 02.01.2019.
//

#include "c_menu_item.h"

c_menu_item::~c_menu_item() {}

std::string c_menu_item::get_command() {
    return s_command;
}

std::string c_menu_item::get_name() {
    return s_name;
}
