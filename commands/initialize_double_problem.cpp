//
// Created by Admin on 03.01.2019.
//

#include "initialize_double_problem.h"
#include "../menu/util.h"
#include "../genetic_algorithm/coordinator.h"

initialize_double_problem::initialize_double_problem() {
    set_help(INIT_DOUBLE_KNAPSACK_PROBLEM_HELP);
}

bool initialize_double_problem::run_command() {
    std::cout << HOW_MANY_ITEMS << std::endl;
    int items_amount = input_number(0, 9999);
    std::cout << HOW_MANY_ITEMS_IN_KNAPSACK << std::endl;
    double max_item_amount = input_number(0, 9999);
    std::cout << WHAT_IS_MAX_WEIGHT_OF_KNAPSACK << std::endl;
    double max_weight = input_number(0, 9999);
    std::cout << DEFAULT_FILL_PROBLEM;
    int if_fill = input_number(0, 1);
    bool result = coordinator::initialize_double_problem(items_amount, max_item_amount, max_weight);
    if (if_fill) {
        std::cout << MAX_VALUE;
        double max_value = input_number(0.0, 9999.0);
        std::cout << MAX_WEIGHT;
        double max_weigh = input_number(0.0, 9999.0);
        coordinator::fill_double_problem(max_value, max_weigh);
    }
    return result;
}