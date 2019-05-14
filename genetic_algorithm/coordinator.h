//
// Created by Admin on 02.01.2019.
//

#ifndef LAB4_COORDINATOR_H
#define LAB4_COORDINATOR_H


#include "knapsack_problem.h"
#include "genetic_algorithm.h"

class coordinator {
public:
    coordinator();

    ~coordinator();

    static void initialize_problems();

    static bool run_bool();

    static bool run_int();

    static bool run_double();

    static bool initialize_bool_problem(int items_amount, double max_item_amount, double max_weight);

    static bool initialize_int_problem(int items_amount, double max_item_amount, double max_weight);

    static bool initialize_double_problem(int items_amount, double max_item_amount, double max_weight);

    static bool set_item_in_bool_problem(int index, double weight, double value);

    static bool set_item_in_int_problem(int index, double weight, double value);

    static bool set_item_in_double_problem(int index, double weight, double value);

    static bool initialize_bool_ga(int pop_size, double cross_prob, double mutation_prob, int max_time);

    static bool initialize_int_ga(int pop_size, double cross_prob, double mutation_prob, int max_time);

    static bool initialize_double_ga(int pop_size, double cross_prob, double mutation_prob, int max_time);

    static bool fill_bool_problem(int max_value, int max_weight);

    static bool fill_int_problem(int max_value, int max_weight);

    static bool fill_double_problem(double max_value, double max_weight);

    static void clear_coordinator();

private:
    static knapsack_problem<bool> *bool_problem;
    static knapsack_problem<int> *int_problem;
    static knapsack_problem<double> *double_problem;

    static genetic_algorithm<bool> *bool_ga;
    static genetic_algorithm<int> *int_ga;
    static genetic_algorithm<double> *double_ga;
};


#endif //LAB4_COORDINATOR_H
