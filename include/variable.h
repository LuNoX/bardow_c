//
// Created by timob on 30.01.2025.
//

#ifndef bardow_VARIABLE_H
#define bardow_VARIABLE_H

#include "units.h"

typedef struct {
    double value;
    unit unit;
} known;

inline void known_apply_unit_prefix(known* known) {
    known->value *= prefix_to_decimal(known->unit.prefix);
    known->unit.prefix = none;
}

constexpr int max_symbols_length = 16 - sizeof(dimension);

typedef struct {
    char symbol[max_symbols_length];
    dimension dimension;
} unknown;

typedef union {
    known known;
    unknown unknown;
} variable;

// TODO: assert in a test that size of known = unknown = variable = 16 bytes

#endif //bardow_VARIABLE_H
