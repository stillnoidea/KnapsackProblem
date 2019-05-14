//
// Created by Admin on 03.01.2019.
//

#ifndef LAB4_RUN_BOOL_PROBLEM_H
#define LAB4_RUN_BOOL_PROBLEM_H


#include "../menu/c_command.h"

class run_bool_problem: public c_command {
public:
    run_bool_problem();

    bool run_command() override;

};


#endif //LAB4_RUN_BOOL_PROBLEM_H
