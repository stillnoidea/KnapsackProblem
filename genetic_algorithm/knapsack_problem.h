//
// Created by Admin on 05.12.2018.
//

#ifndef LAB4_KNAPSACK_PROBLEM_H
#define LAB4_KNAPSACK_PROBLEM_H

#pragma once

#include<iostream>
#include <vector>
#include <sstream>
#include "../consts.h"

using namespace std;

template<class T>
class knapsack_problem {
private:
    int items_number;
    double max_item_amount;
    double max_knapsack_weight;
    vector<double> weights;
    vector<double> values;

public:
    knapsack_problem();

    knapsack_problem(int items_number, double new_max_item_amount, double new_max_knapsack_weight);

    ~knapsack_problem();

    void set_value(int index, double value);

    void set_weight(int index, double weight);

    double get_value(int index);

    double get_weight(int index);

    double get_genotype_value(vector<T> genotype);

    double get_genotype_weight(vector<T> genotype);

    double get_max_knapsack_weight();

    double get_max_item_amount();

    int get_items_number();

    double get_fitness(vector<T> &genotype);

    string to_string_genotype(vector<T> genotype);
};


#endif //LAB4_KNAPSACK_PROBLEM_H

template<class T>
knapsack_problem<T>::knapsack_problem() {
    weights = vector<double>(0, 0);
    values = vector<double>(0, 0);
    items_number = 0;
    max_knapsack_weight = 0;
    max_item_amount = 0;
}

template<class T>
knapsack_problem<T>::~knapsack_problem() {
    weights.clear();
    values.clear();
}

template<class T>
double knapsack_problem<T>::get_genotype_value(vector<T> genotype) {
    int value = 0;
    for (int i = 0; i < genotype.size(); i++) {
        if (genotype[i] > 0) {
            value += values[i] * genotype[i];
        }
    }
    return value;
}

template<class T>
double knapsack_problem<T>::get_genotype_weight(vector<T> genotype) {
    int weight = 0;
    for (int i = 0; i < genotype.size(); i++) {
        if (genotype[i] > 0) {
            weight += weights[i] * genotype[i];
        }
    }
    return weight;
}

template<class T>
void knapsack_problem<T>::set_weight(int index, double weight) {
    weights[index] = weight;
}

template<class T>
void knapsack_problem<T>::set_value(int index, double value) {
    values[index] = value;
}

template<class T>
double knapsack_problem<T>::get_value(int index) {
    return values[index];
}

template<class T>
double knapsack_problem<T>::get_weight(int index) {
    return weights[index];
}

template<class T>
double knapsack_problem<T>::get_max_knapsack_weight() {
    return max_knapsack_weight;
}

template<class T>
int knapsack_problem<T>::get_items_number() {
    return items_number;
}

template<class T>
double knapsack_problem<T>::get_max_item_amount() {
    return max_item_amount;
}

template<class T>
double knapsack_problem<T>::get_fitness(vector<T> &genotype) {
    if (get_genotype_weight(genotype) > get_max_knapsack_weight()) {
        return 0;
    } else return get_genotype_value(genotype);
}

template<class T>
string knapsack_problem<T>::to_string_genotype(vector<T> genotype) {
    stringstream gen;
    for (int i = 0; i < get_items_number(); i++) {
        gen << genotype[i];
        if (i < get_items_number() - 1) {
            gen << " ";
        }
    }
    return gen.str();
}
