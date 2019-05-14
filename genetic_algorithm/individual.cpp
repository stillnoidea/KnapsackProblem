//
// Created by Admin on 10.01.2019.
//
#include "individual.h"

template<>
individual<int> individual<int>::operator-(individual<int> &parent2) {
    individual<int> *result = new individual<int>(problem);

    for (int i = 0; i < genotype.size(); i++) {
        int substract = this->genotype[i] - parent2.genotype[i];
        if (substract < 0) {
            result->genotype.push_back(0);
        } else { result->genotype.push_back(substract); }
    }

    return *result;
}

template<>
individual<bool> individual<bool>::operator-(individual<bool> &parent2) {
    individual<bool> *result = new individual<bool>(problem);
    for (int i = 0; i < genotype.size(); i++) {
        result->genotype.push_back(this->genotype[i] ^ parent2.genotype[i]);
    }
    return *result;
}

template<>
individual<double> individual<double>::operator-(individual<double> &parent2) {
    individual<double> *result = new individual<double>(problem);;

    for (int i = 0; i < genotype.size(); i++) {
        double substract = this->genotype[i] - parent2.genotype[i];
        if (substract < 0) {
            result->genotype.push_back(0);
        } else { result->genotype.push_back(substract); }
    }

    return *result;
}