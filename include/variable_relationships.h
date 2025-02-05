//
// Created by timob on 31.01.2025.
//

#ifndef bardow_VARIABLE_RELATIONSHIPS_H
#define bardow_VARIABLE_RELATIONSHIPS_H
#include "state.h"

typedef struct {
    state inputs;
    state output;
} variable_relationship;

inline state relate(const state* state,
                    const variable_relationship* relationship) {
    if ((*state & relationship->inputs) != relationship->inputs)
        return *state;
    return relationship->output ^ *state;
}

// TODO: function to automatically generate permutations of relationships


#endif //bardow_VARIABLE_RELATIONSHIPS_H
