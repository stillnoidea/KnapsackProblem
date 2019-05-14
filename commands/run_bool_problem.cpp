//
// Created by Admin on 03.01.2019.
//

#include "run_bool_problem.h"
#include "../genetic_algorithm/coordinator.h"

run_bool_problem::run_bool_problem() {
    set_help( RUN_BOOL_KNAPSACK_HELP);
}

bool run_bool_problem::run_command() {
    return coordinator::run_bool();
}
