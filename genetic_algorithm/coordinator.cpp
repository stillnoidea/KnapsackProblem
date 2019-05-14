//
// Created by Admin on 02.01.2019.
//

#include "coordinator.h"

knapsack_problem<bool> *coordinator::bool_problem = new knapsack_problem<bool>();
knapsack_problem<int> *coordinator::int_problem = new knapsack_problem<int>();
knapsack_problem<double> *coordinator::double_problem = new knapsack_problem<double>();

genetic_algorithm<bool> *coordinator::bool_ga = new genetic_algorithm<bool>();
genetic_algorithm<int> *coordinator::int_ga = new genetic_algorithm<int>();
genetic_algorithm<double> *coordinator::double_ga = new genetic_algorithm<double>();

coordinator::coordinator() {
    initialize_problems();
}

coordinator::~coordinator() {
    clear_coordinator();
}

bool coordinator::run_bool() {
    bool_ga->run(bool_problem);
    return true;
}

bool coordinator::run_int() {
    int_ga->run(int_problem);
    return true;
}

bool coordinator::run_double() {
    double_ga->run(double_problem);
    return true;
}

bool coordinator::initialize_bool_problem(int items_amount, double max_item_amount, double max_weight) {
    bool_problem = new knapsack_problem<bool>(items_amount, max_item_amount, max_weight);
    return true;
}

bool coordinator::initialize_int_problem(int items_amount, double max_item_amount, double max_weight) {
    int_problem = new knapsack_problem<int>(items_amount, max_item_amount, max_weight);
    return true;
}

bool coordinator::initialize_double_problem(int items_amount, double max_item_amount, double max_weight) {
    double_problem = new knapsack_problem<double>(items_amount, max_item_amount, max_weight);
    return true;
}


bool coordinator::set_item_in_bool_problem(int index, double weight, double value) {
    if (index >= bool_problem->get_items_number()) {
        cout << INDEX_OUT_OF_BOUNDS;
    } else {
        bool_problem->set_weight(index, weight);
        bool_problem->set_value(index, value);
    }
    return true;
}

bool coordinator::set_item_in_int_problem(int index, double weight, double value) {
    if (index >= int_problem->get_items_number()) {
        cout << INDEX_OUT_OF_BOUNDS;
    } else {
        coordinator::int_problem->set_weight(index, weight);
        coordinator::int_problem->set_value(index, value);
    }
    return true;
}

bool coordinator::set_item_in_double_problem(int index, double weight, double value) {
    if (index >= double_problem->get_items_number()) {
        cout << INDEX_OUT_OF_BOUNDS;
    } else {
        coordinator::double_problem->set_weight(index, weight);
        coordinator::double_problem->set_value(index, value);
    }
    return true;
}

void coordinator::initialize_problems() {
    //clear_coordinator();

    bool_problem = new knapsack_problem<bool>(DEFAULT_ITEMS_NUMBER, DEFAULT_MAX_ITEM_AMOUNT, DEFAULT_MAX_TOTAL_WEIGHT);
    int_problem = new knapsack_problem<int>(DEFAULT_ITEMS_NUMBER, DEFAULT_MAX_ITEM_AMOUNT, DEFAULT_MAX_TOTAL_WEIGHT);
    double_problem = new knapsack_problem<double>(DEFAULT_ITEMS_NUMBER, DEFAULT_MAX_ITEM_AMOUNT,
                                                  DEFAULT_MAX_TOTAL_WEIGHT);

    for (int i = 0; i < DEFAULT_ITEMS_NUMBER; i++) {
        bool_problem->set_value(i, random_generator::draw_value<bool>(1, DEFAULT_MAX_ITEM_VALUE));
        int_problem->set_value(i, random_generator::draw_value<int>(1, DEFAULT_MAX_ITEM_VALUE));
        double_problem->set_value(i, random_generator::draw_value<double>(1.0, DEFAULT_MAX_ITEM_VALUE_DOUBLE));

        bool_problem->set_weight(i, random_generator::draw_value<bool>(1, DEFAULT_MAX_ITEM_WEIGHT));
        int_problem->set_value(i, random_generator::draw_value<int>(1, DEFAULT_MAX_ITEM_WEIGHT));
        double_problem->set_value(i, random_generator::draw_value<double>(1.0, DEFAULT_MAX_ITEM_WEIGHT_DOUBLE));
    }

    bool_ga = new genetic_algorithm<bool>(DEFAULT_POP_SIZE, DEFAULT_CROSS_PROB, DEFAULT_MUT_PROB, DEFAULT_TIME_ITER,
                                          bool_problem);
    int_ga = new genetic_algorithm<int>(DEFAULT_POP_SIZE, DEFAULT_CROSS_PROB, DEFAULT_MUT_PROB, DEFAULT_TIME_ITER,
                                        int_problem);
    double_ga = new genetic_algorithm<double>(DEFAULT_POP_SIZE, DEFAULT_CROSS_PROB, DEFAULT_MUT_PROB, DEFAULT_TIME_ITER,
                                              double_problem);
}

bool coordinator::initialize_bool_ga(int pop_size, double cross_prob, double mutation_prob, int max_time) {
    bool_ga = new genetic_algorithm<bool>(pop_size, cross_prob, mutation_prob, max_time, bool_problem);
    return true;
}

bool coordinator::initialize_int_ga(int pop_size, double cross_prob, double mutation_prob, int max_time) {
    int_ga = new genetic_algorithm<int>(pop_size, cross_prob, mutation_prob, max_time, int_problem);
    return true;
}

bool coordinator::initialize_double_ga(int pop_size, double cross_prob, double mutation_prob, int max_time) {
    double_ga = new genetic_algorithm<double>(pop_size, cross_prob, mutation_prob, max_time, double_problem);
    return true;
}


bool coordinator::fill_bool_problem(int max_value, int max_weight) {
    for (int i = 0; i < double_problem->get_items_number(); i++) {
        double_problem->set_value(i, random_generator::draw_value<int>(1, max_value));
        double_problem->set_value(i, random_generator::draw_value<int>(1, max_weight));
    }
    return true;
}

bool coordinator::fill_int_problem(int max_value, int max_weight) {
    for (int i = 0; i < double_problem->get_items_number(); i++) {
        double_problem->set_value(i, random_generator::draw_value<int>(1, max_value));
        double_problem->set_value(i, random_generator::draw_value<int>(1, max_weight));
    }
    return true;
}

bool coordinator::fill_double_problem(double max_value, double max_weight) {
    for (int i = 0; i < double_problem->get_items_number(); i++) {
        double_problem->set_value(i, random_generator::draw_value<double>(1.0, max_value));
        double_problem->set_value(i, random_generator::draw_value<double>(1.0, max_weight));
    }
    return true;
}

void coordinator::clear_coordinator() {
    delete bool_ga;
    delete int_ga;
    delete double_ga;
}
