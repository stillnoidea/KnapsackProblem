//
// Created by Admin on 03.01.2019.
//

#include "knapsack_problem.h"

template<>
knapsack_problem<int>::knapsack_problem(int new_items_number, double new_max_item_amount, double new_max_knapsack_weight) {
    weights = vector<double>(new_items_number, 0);
    values = vector<double>(new_items_number, 0);

    if (new_items_number > 0)items_number = new_items_number;
    else {
        cout << WRONG_ITEMS_NUMBER;
        items_number=0;
    }
    max_item_amount = new_max_item_amount;
    max_knapsack_weight = new_max_knapsack_weight;
}

template<>
knapsack_problem<double>::knapsack_problem(int new_items_number, double new_max_item_amount, double new_max_knapsack_weight) {
    weights = vector<double>(new_items_number, 0);
    values = vector<double>(new_items_number, 0);

    if (new_items_number > 0)items_number = new_items_number;
    else {
        cout << WRONG_ITEMS_NUMBER;
        items_number=0;
    }
    max_item_amount = new_max_item_amount;
    max_knapsack_weight = new_max_knapsack_weight;
}

template<>
knapsack_problem<bool>::knapsack_problem(int new_items_number, double new_max_item_amount, double new_max_knapsack_weight) {
    weights = vector<double>(new_items_number, 0);
    values = vector<double>(new_items_number, 0);

    if (new_items_number > 0)items_number = new_items_number;
    else {
        cout << WRONG_ITEMS_NUMBER;
        items_number=0;
    }
    max_item_amount = 1;
    max_knapsack_weight = new_max_knapsack_weight;

}