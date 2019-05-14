//
// Created by Admin on 03.01.2019.
//

#include "run_double_problem.h"
#include "../genetic_algorithm/coordinator.h"

run_double_problem::run_double_problem() {
    set_help(RUN_DOUBLE_KNAPSACK_HELP);
}

bool run_double_problem::run_command() {
    return coordinator::run_double();
}
