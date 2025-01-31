//
// Created by timob on 31.01.2025.
//

#ifndef bardow_VARIABLE_RELATIONSHIPS_H
#define bardow_VARIABLE_RELATIONSHIPS_H
#include <stdint.h>
#include <stdlib.h>

// TODO: decide on a default state size
// state in this context is a bitfield where each bit represents a variable
// and 0 indicates we do not know the value and 1 that it is known
typedef uint8_t state;

typedef struct {
    state inputs;
    state output;
} variable_relationship;

inline state relate(const state state,
                    const variable_relationship relationship) {
    if ((state & relationship.inputs) != relationship.inputs)
        return state;
    return relationship.output ^ state;
}

// TODO: implement
int n_choose_k(int n, int k);

inline variable_relationship* permutations(
    const variable_relationship relationship) {
    /*
     * Returns a malloc allocated array of variable_relationships.
     */
    const state unique = relationship.output ^ relationship.inputs;
    const int number_of_permutations = n_choose_k(
        __builtin_popcount(unique), __builtin_popcount(relationship.inputs)
    );


    variable_relationship* permutations = malloc(
        number_of_permutations * sizeof(variable_relationship));

    for (state i = 0; i < number_of_permutations; i++) {
        permutations[i].inputs = 0; // TODO: calculate properly
        permutations[i].output = unique;
    }

    return permutations;
};


#endif //bardow_VARIABLE_RELATIONSHIPS_H
