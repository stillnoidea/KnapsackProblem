//
// Created by Admin on 03.01.2019.
//

#include "set_item_in_bool_problem.h"
#include "../menu/util.h"
#include "../genetic_algorithm/coordinator.h"

set_item_in_bool_problem::set_item_in_bool_problem() {
    set_help(SET_ITEM_BOOL_HELP);
}

bool set_item_in_bool_problem::run_command() {

    std::cout << GET_INDEX << std::endl;
    int index = input_number(0, 9999);
    std::cout << GET_WEIGHT << std::endl;
    double weight = input_number(0, 9999);
    std::cout << GET_VALUE << std::endl;
    double value = input_number(0, 9999);
    return coordinator::set_item_in_bool_problem(index, weight, value);
}
