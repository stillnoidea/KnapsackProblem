//
// Created by Admin on 11.12.2018.
//

#ifndef LAB4_RANDOM_GENERATOR_H
#define LAB4_RANDOM_GENERATOR_H

#include <random>

using namespace std;

class random_generator {
private:
    static std::mt19937 generator;
public:
    template <class T>
    static T draw_value();

    template <class T>
    static T draw_value(double min, double max);

//    template <class T>
//    static T draw_value(double min, double max);

    static int draw_int(int min, int max);

    static double draw_double(double min, double max);
};

#endif //LAB4_RANDOM_GENERATOR_H