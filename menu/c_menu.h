//
// Created by Admin on 02.01.2019.
//

#ifndef LAB4_C_MENU_H
#define LAB4_C_MENU_H


#include <vector>
#include "c_menu_item.h"
#include "c_menu_command.h"
#include "util.h"

class c_menu : public c_menu_item {

private:
    static c_menu *root;
    static std::string BACK_COMMAND;
    std::vector<c_menu_item *> items;

    void print_menu();

public:
    c_menu();

    c_menu(std::string name, std::string command);

    ~c_menu();

    bool run();

    bool if_name_exist(std::string name);

    bool if_command_exist(std::string command);

    bool add_item(c_menu_item *item);

    bool delete_item(std::string name);

    std::string get_command();

    std::string get_name();

    void set_name(std::string name);

    void set_command(std::string command);

    c_menu_item *get_item(std::string name);

    bool if_help(std::string task);

    bool if_search(std::string task);

    void searching(std::string *command);

    void set_root(c_menu *new_root);

    void print();

    std::string read(const std::string &input, std::string &exception, int &position);
};


#endif //LAB4_C_MENU_H
