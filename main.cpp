#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
//#include "genetic_algorithm/genetic_algorithm.h"
#include "genetic_algorithm/random_generator.h"
#include "genetic_algorithm/coordinator.h"
#include "menu/c_menu.h"
#include "commands/initialize_int_problem.h"
#include "commands/run_int_problem.h"
#include "commands/run_double_problem.h"
#include "commands/run_bool_problem.h"
#include "commands/initialize_double_problem.h"
#include "commands/initialize_bool_problem.h"
#include "commands/set_item_in_int_problem.h"
#include "commands/set_item_in_bool_problem.h"
#include "commands/set_item_in_double_problem.h"


int main() {

//    int amount = 10;
//    double max_item_amount = 20;
//    int max_knapsack_weight = 5000;
//
//    knapsack_problem<double> *problem = new knapsack_problem<double>(amount, max_item_amount, max_knapsack_weight);
//
//    for (int i = 0; i < amount; i++) {
//        problem->set_value(i, random_generator::draw_value<double>(1, 20));
//    }
//
//    for (int i = 0; i < amount; i++) {
//        problem->set_weight(i, random_generator::draw_value<double>(1, 100));
//    }
//
//    genetic_algorithm<double>* alg = new genetic_algorithm<double>(
//            100,     //pop size
//            0.5,    //cross_prob
//            0.01,   //mutation_prob
//            2,     //time
//            problem
//        );
//    alg->run(problem);
//
//
//    delete problem;

    coordinator::initialize_problems();

    c_menu *menu = new c_menu();
    c_menu *initialize_menu = new c_menu(INITIALIZE_MENU, INIT);
    c_menu *run_menu = new c_menu(RUN_MENU, RUN);
    c_menu *managing_menu = new c_menu(MANAGING_MENU, MANAGE);

    menu->add_item(initialize_menu);
    menu->add_item(run_menu);
    menu->add_item(managing_menu);

    c_menu_command *initialize_int = new c_menu_command(INITIALIZE_INT_PROBLEM, INIT_INT);
    initialize_int->set_command(new initialize_int_problem());
    c_menu_command *initialize_double = new c_menu_command(INITIALIZE_DOUBLE_PROBLEM, INIT_DOUBLE);
    initialize_double->set_command(new initialize_double_problem());
    c_menu_command *initialize_bool = new c_menu_command(INITIALIZE_BOOL_PROBLEM, INIT_BOOL);
    initialize_bool->set_command(new initialize_bool_problem());


    c_menu_command *run_int = new c_menu_command(RUN_INT_PROBLEM, RUN_INT);
    run_int->set_command(new run_int_problem());
    c_menu_command *run_double = new c_menu_command(RUN_DOUBLE_PROBLEM, RUN_DOUBLE);
    run_double->set_command(new run_double_problem());
    c_menu_command *run_bool = new c_menu_command(RUN_BOOL_PROBLEM, RUN_BOOL);
    run_bool->set_command(new run_bool_problem());

    c_menu_command *manage_int = new c_menu_command(MANAGE_INT_PROBLEM, MANAGE_INT);
    manage_int->set_command(new set_item_in_int_problem());
    c_menu_command *manage_double = new c_menu_command(MANAGE_DOUBLE_PROBLEM, MANAGE_DOUBLE);
    manage_double->set_command(new set_item_in_double_problem());
    c_menu_command *manage_bool = new c_menu_command(MANAGE_BOOL_PROBLEM, MANAGE_BOOL);
    manage_bool->set_command(new set_item_in_bool_problem());

    run_menu->add_item(run_int);
    run_menu->add_item(run_double);
    run_menu->add_item(run_bool);
    initialize_menu->add_item(initialize_int);
    initialize_menu->add_item(initialize_bool);
    initialize_menu->add_item(initialize_double);
    managing_menu->add_item(manage_int);
    managing_menu->add_item(manage_double);
    managing_menu->add_item(manage_bool);

    menu->set_root(menu);
    menu->run();
    delete menu;
    coordinator::clear_coordinator();
}