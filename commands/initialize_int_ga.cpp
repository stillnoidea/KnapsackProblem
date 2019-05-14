//
// Created by Admin on 03.01.2019.
//

#include "initialize_int_ga.h"
#include "../menu/util.h"
#include "../genetic_algorithm/coordinator.h"

initialize_int_ga::initialize_int_ga() {
    set_help(INIT_INT_GA_HELP);
}

bool initialize_int_ga::run_command() {
    std::cout << HOW_MANY_ITEMS << std::endl;
    int pop_size = input_number(0, 9999);
    std::cout << WHAT_CROSS_PROB << std::endl;
    double cross_prob = input_number(0, 9999);
    std::cout << WHAT_MUTATION_PROB << std::endl;
    double mutation_prob = input_number(0, 9999);
    std::cout << WHAT_MAX_TIME << std::endl;
    double max_time = input_number(0, 9999);
    return coordinator::initialize_int_ga( pop_size,  cross_prob,  mutation_prob,  max_time);
}
