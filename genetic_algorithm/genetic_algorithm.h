//
// Created by Admin on 05.12.2018.
//

#ifndef LAB4_GENETIC_ALGORITHM_H
#define LAB4_GENETIC_ALGORITHM_H


#include <ctime>
#include "individual.h"
#include "../consts.h"
#include "random_generator.h"

template<class T>
class genetic_algorithm {
private:
    int pop_size;
    float cross_prob;
    float mut_prob;
    int seconds;
    individual<T> *best_solution;
    vector<individual<T> *> population;
    knapsack_problem<T> *problem;

    void clear_population();

    pair<individual<T> *, individual<T> *> get_children();

    individual<T> *get_child();

    individual<T> *get_parent();

public:
    genetic_algorithm();

    genetic_algorithm(int new_pop_size, float new_cross_prob, float new_mut_prob, int new_seconds,
                      knapsack_problem<T> *new_problem);

    ~genetic_algorithm();

    pair<individual<T> *, int> get_best_solution();

    void run(knapsack_problem<T> *problem);

    void print_best_genotype();
};


#endif //LAB4_GENETIC_ALGORITHM_H

template<class T>
genetic_algorithm<T>::genetic_algorithm() {
    population = vector<individual<T> *>();
}

template<class T>
genetic_algorithm<T>::genetic_algorithm(int new_pop_size, float new_cross_prob, float new_mut_prob, int new_seconds,
                                        knapsack_problem<T> *new_problem) {
    population = vector<individual<T> *>(new_pop_size, NULL);
    pop_size = new_pop_size;
    cross_prob = new_cross_prob;
    mut_prob = new_mut_prob;
    seconds = new_seconds;
    best_solution = NULL;
    problem = new_problem;
}

template<class T>
genetic_algorithm<T>::~genetic_algorithm() {
    clear_population();
    delete best_solution;
    delete problem;
}

template<class T>
pair<individual<T> *, int> genetic_algorithm<T>::get_best_solution() {

    for (int i = 0; i < pop_size; i++) {
        int tmp = population[i]->get_fitness();

        if (best_solution == NULL || tmp > best_solution->get_fitness()) {
            delete best_solution;
            best_solution = new individual<T>(*population[i]);
        }
    }

    return pair<individual<T> *, int>(best_solution, best_solution->get_fitness());
}


template<class T>
void genetic_algorithm<T>::run(knapsack_problem<T> *problem) {

    pair<individual<T> *, int> result;

    for (int i = 0; i < pop_size; i++) {
        individual<T> *pop = new individual<T>(problem);
        population[i] = pop;
    }
    result = get_best_solution();

    time_t start_time;
    time(&start_time);

    time_t current_time;
    double time_elapsed;
    do {
        vector<individual<T> *> new_population;

        while (new_population.size() < pop_size) {
            individual<T> *child = get_child();
            new_population.push_back(child);

//            pair<individual<T> *, individual<T> *> children = get_children();
//            new_population.push_back(children.first);
//            new_population.push_back(children.second);
        }

        clear_population();
        population = new_population;

        for (int i = 0; i < pop_size; i++) {
            if (random_generator::draw_value<double>(0.0, 1.0) < mut_prob) {
                individual<T> genotype = *population[i];
                genotype++;
            }
        }

        result = get_best_solution();

        time(&current_time);
        time_elapsed = difftime(current_time, start_time);
        cout << time_elapsed << BEST_SOLUTION + result.first->to_string() + BEST_FITNESS << result.second << NEW_LINE;


    } while (time_elapsed < seconds);

    cout << BEST_SOLUTION + result.first->to_string() + BEST_FITNESS << result.second << NEW_LINE << NEW_LINE;
    print_best_genotype();

}

template<class T>
void genetic_algorithm<T>::clear_population() {
    for (int i = 0; i < population.size(); i++) {
        delete population[i];
    }
    population.clear();
}

template<class T>
void genetic_algorithm<T>::print_best_genotype() {
    cout << BEST << best_solution->to_string() << NEW_LINE;
    cout << BEST_FITNESS << best_solution->get_fitness() << NEW_LINE;
}

template<class T>
individual<T> *genetic_algorithm<T>::get_child() {

    individual<T> *first_parent = get_parent();
    individual<T> *second_parent = get_parent();

    if (random_generator::draw_value<double>(0.0, 1.0) < cross_prob) {
        individual<T> child = *first_parent - *second_parent;
        return new individual<T>(child);
    } else {
        return new individual<T>(*first_parent);
    }
}

template<class T>
pair<individual<T> *, individual<T> *> genetic_algorithm<T>::get_children() {

    individual<T> *first_parent = get_parent();
    individual<T> *second_parent = get_parent();

    if (random_generator::draw_value<double>(0, 1) < cross_prob) {
        return first_parent->cross(second_parent);
    } else {
        individual<T> *first_child = new individual<T>(*first_parent);
        individual<T> *second_child = new individual<T>(*second_parent);
        return pair<individual<T> *, individual<T> *>(first_child, second_child);
    }
}

template<class T>
individual<T> *genetic_algorithm<T>::get_parent() {
    individual<T> *first_choice = population[random_generator::draw_value<int>(0, population.size() - 1)];
    individual<T> *second_choice = population[random_generator::draw_value<int>(0, population.size() - 1)];

    individual<T> *first_parent;

    if (first_choice->get_fitness() > second_choice->get_fitness()) {
        first_parent = first_choice;
    } else first_parent = second_choice;

    return first_parent;
}