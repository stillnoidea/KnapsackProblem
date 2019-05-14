//
// Created by Admin on 02.01.2019.
//

#include <string>

#ifndef LAB4_UTIL_H
#define LAB4_UTIL_H

#endif //LAB4_UTIL_H

int if_char(const std::string &input, const std::string &chars, std::string &exception, int &position);

std::string parse(const std::string &input, std::string &exception, int &position, const std::string &name_char);

std::string exception_on_position(std::string &exception, int &position, const std::string &chars);

double input_number(double min_value, double max_value);

bool is_valid_number(std::string input_string);