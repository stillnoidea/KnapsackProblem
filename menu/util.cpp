//
// Created by Admin on 02.01.2019.
//

#include <sstream>
#include <iostream>
#include "util.h"
#include "../consts.h"


int if_char(const std::string &input, const std::string &chars, std::string &exception, int &position) {
    for (int i = 0; i < chars.size(); i++) {
        if (input[position] == chars[i]) {
            position++;
            return i;
        }
    }
    exception_on_position(exception, position, chars);
    return -1;
}

std::string parse(const std::string &input, std::string &exception, int &position, const std::string &name_char) {
    std::string parsed;

    if (if_char(input, name_char, exception, position) == -1) return parsed;

    while (input[position] != name_char[0] && input.length() > position) {
        parsed += input[position];
        position++;
    }

    if (input.length() < position) {
        exception_on_position(exception, position, name_char);

        return parsed;
    }

    if (parsed.empty()) {
        std::ostringstream stream;
        stream << position;
        exception = MISTAKE_NO_STRING + stream.str();
        return parsed;
    }
    position++;
    return parsed;
}

std::string exception_on_position(std::string &exception, int &position, const std::string &chars) {
    std::ostringstream stream;
    stream << position;
    return exception = MISTAKE_IN_READING + stream.str() + WAITING_FOR_CHAR + chars;
}

bool is_valid_number(std::string input_string) {
    bool used_comma = false;
    for (std::string::size_type i = 0; i < input_string.size(); ++i) {
        if (i == 0 && input_string[0] != '-' && !isdigit(input_string[0])) {
            return false;
        }
        if (!used_comma && input_string[i] == '.') {
            used_comma = true;
        } else if (!isdigit(input_string[i])) {
            return false;
        }
    }
    return true;
}

double input_number(double min_value, double max_value) {
    std::string input_string;
    do {
        std::cout << GET_NUMBER << min_value << COMMA << max_value << CLOSING_BRACKET_COLON;
        getline(std::cin, input_string);
    } while (!is_valid_number(input_string) || std::atof(input_string.c_str()) > max_value ||
             std::atof(input_string.c_str()) < min_value);

    return std::atof(input_string.c_str());;
}
