//
// Created by Admin on 02.01.2019.
//

#ifndef LAB4_C_MENU_ITEM_H
#define LAB4_C_MENU_ITEM_H


#include <string>

class c_menu_item {
protected:
    std::string s_command;
    std::string s_name;
public:
    virtual ~c_menu_item()=0;

    virtual bool run() = 0;

    virtual std::string get_name();

    virtual std::string get_command();

    virtual void print()=0;

    virtual std::string read(const std::string& input, std::string &exception, int &position)=0;
};


#endif //LAB4_C_MENU_ITEM_H
