//
// Created by Admin on 03.01.2019.
//

#include "run_int_problem.h"
#include "../genetic_algorithm/coordinator.h"

run_int_problem::run_int_problem() {
    set_help( RUN_INT_KNAPSACK_HELP);
}

bool run_int_problem::run_command() {
    return coordinator::run_int();
}