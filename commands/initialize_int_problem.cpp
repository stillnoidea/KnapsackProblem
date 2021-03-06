//
// Created by Admin on 03.01.2019.
//

#include "initialize_int_problem.h"
#include "../genetic_algorithm/coordinator.h"
#include "../menu/util.h"

initialize_int_problem::initialize_int_problem() {
    set_help(INIT_INT_KNAPSACK_PROBLEM_HELP);
}

bool initialize_int_problem::run_command() {
    std::cout << HOW_MANY_ITEMS << std::endl;
    int items_amount = input_number(0, 9999);
    std::cout << HOW_MANY_ITEMS_IN_KNAPSACK << std::endl;
    double max_item_amount = input_number(0, 9999);
    std::cout << WHAT_IS_MAX_WEIGHT_OF_KNAPSACK << std::endl;
    double max_weight = input_number(0, 9999);
    std::cout << DEFAULT_FILL_PROBLEM;
    int if_fill = input_number(0, 1);
    bool result = coordinator::initialize_int_problem(items_amount, max_item_amount, max_weight);
    if (if_fill) {
        std::cout << MAX_VALUE;
        int max_value = input_number(0.0, 9999.0);
        std::cout << MAX_WEIGHT;
        int max_weigh = input_number(0.0, 9999.0);
        coordinator::fill_int_problem(max_value, max_weigh);
    }
    return result;
}
