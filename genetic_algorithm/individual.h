//
// Created by Admin on 05.12.2018.
//

#ifndef LAB4_INDIVIDUAL_H
#define LAB4_INDIVIDUAL_H

#include <iostream>
#include <vector>
#include "knapsack_problem.h"
#include "random_generator.h"

using namespace std;

template<class T>
class individual {
private:
    vector<T> genotype;
    knapsack_problem<T> *problem;

    void generate_population();

public:
    individual();

    individual(knapsack_problem<T> *new_problem);

    individual(const individual<T> &other);

    ~individual();

    double get_fitness();

    void mutate();

    pair<individual<T> *, individual<T> *> cross(individual<T> *parent2);

    string to_string();

    // void new_mutation();

//    vector<T> get_genotype();

    individual<T>& operator++(int);

    individual<T> operator+(individual<T> &parent2);

    individual<T> operator-(individual<T> &parent2);

};


#endif //LAB4_INDIVIDUAL_H

template<class T>
individual<T>::individual() {
    genotype = vector<T>();
}

template<class T>
individual<T>::individual(knapsack_problem<T> *new_problem) {
    problem = new_problem;
    genotype = vector<T>(problem->get_items_number());
    generate_population();
}

template<class T>
void individual<T>::generate_population() {
    for (int i = 0; i < problem->get_items_number(); i++) {
        T value = random_generator::draw_value<T>(0, problem->get_max_item_amount());
        genotype[i] = value;
    }
}

template<class T>
individual<T>::individual(const individual<T> &other) {
    problem = other.problem;
    genotype = vector<T>(problem->get_items_number());
    for (int i = 0; i < problem->get_items_number(); i++) {
        genotype[i] = other.genotype[i];
    }
}


template<class T>
individual<T>::~individual() {
    genotype.clear();
}

template<class T>
double individual<T>::get_fitness() {
    return problem->get_fitness(genotype);
}

template<class T>
void individual<T>::mutate() {
    for (int i = 0; i < genotype.size(); i++) {
        genotype[i] = (T) (problem->get_max_item_amount() - (double) genotype[i]);
    }
}

//
//template<class T>
//void individual<T>::new_mutation() {
//    int cutting_point_1 = random_generator::draw_value<int>(1, genotype.size() - 1);
//    int cutting_point_2 = random_generator::draw_value<int>(1, genotype.size() - 1);
//    vector<T> mutate_field;
//
//    if (cutting_point_1 > cutting_point_2) {
//        for (int i = cutting_point_1; i < cutting_point_2; i++) {
//            mutate_field.push_back(genotype[i]);
//        }
//        for (int i = cutting_point_1; i < cutting_point_2; i++) {
//            for (int j = mutate_field.size(); j > 0; j--) {
//                genotype[i] = mutate_field[j];
//            }
//        }
//    } else {
//        for (int i = cutting_point_2; i < cutting_point_1; i++) {
//            mutate_field.push_back(genotype[i]);
//        }
//        for (int i = cutting_point_2; i < cutting_point_1; i++) {
//            for (int j = mutate_field.size(); j > 0; j--) {
//                genotype[i] = mutate_field[j];
//            }
//        }
//    }
//    mutate_field.clear_coordinator();
//}


template<class T>
pair<individual<T> *, individual<T> *> individual<T>::cross(individual *parent2) {
    individual<T> *first_child = new individual<T>(problem);
    individual<T> *second_child = new individual<T>(problem);

    int cutting_point = random_generator::draw_value<int>(1, genotype.size() - 1);

    for (int i = 0; i < cutting_point; i++) {
        first_child->genotype[i] = genotype[i];
        second_child->genotype[i] = parent2->genotype[i];
    }
    for (int i = cutting_point; i < genotype.size(); i++) {

        first_child->genotype[i] = parent2->genotype[i];
        second_child->genotype[i] = genotype[i];

    }

    return pair<individual<T> *, individual<T> *>(first_child, second_child);
}


template<class T>
string individual<T>::to_string() {
    string gen = problem->to_string_genotype(genotype);
    return gen;
}

//template<class T>
//vector<T> individual<T>::get_genotype() {
//    return genotype;
//}

template<class T>
individual<T>& individual<T>::operator++(int) {
    mutate();
    return *this;
}

template<class T>
individual<T> individual<T>::operator+(individual<T> &parent2) {
    individual<T> first_child (problem);

    int cutting_point = random_generator::draw_value<int>(1, genotype.size() - 1);

    for (int i = 0; i < cutting_point; i++) {
        first_child.genotype[i] = genotype[i];
    }
    for (int i = cutting_point; i < genotype.size(); i++) {
        first_child.genotype[i] = parent2.genotype[i];
    }
    return first_child;
}



