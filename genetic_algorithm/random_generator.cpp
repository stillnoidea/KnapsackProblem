//
// Created by Admin on 11.12.2018.
//

#include "random_generator.h"

std::mt19937 random_generator::generator = std::mt19937(std::random_device()());

int random_generator::draw_int(int min, int max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

double random_generator::draw_double(double min, double max) {
    double canonical_value = std::generate_canonical<double, 10>(generator);
    return min + (max - min) * canonical_value;
}

template<>
int random_generator::draw_value<int>() {
    return random_generator::draw_int(0, 100);
}

template<>
bool random_generator::draw_value<bool>() {
    return (bool) random_generator::draw_int(0,1);
}

template<>
double random_generator::draw_value<double>() {
    return random_generator::draw_double(0, 100);
}

template<>
int random_generator::draw_value<int>(double min, double max) {
    return random_generator::draw_int(min, max);
}

template<>
bool random_generator::draw_value<bool>(double min, double max) {
    return (bool) random_generator::draw_int(0,1);
}

template<>
double random_generator::draw_value<double>(double min, double max) {
    return random_generator::draw_double(min, max);
}
