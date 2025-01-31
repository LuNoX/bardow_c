//
// Created by timob on 30.01.2025.
//

#ifndef bardow_UNITS_H
#define bardow_UNITS_H

typedef enum {
    seconds,
    meters,
    kilograms,
    ampere,
    kelvin,
    mole,
    candela
} base_unit;

typedef enum {
    time,
    length,
    mass,
    current,
    temperature,
    amount,
    luminosity
} dimension;

inline dimension base_unit_to_dimension(const base_unit base) {
    switch (base) {
    case seconds: return time;
    case meters: return length;
    case kilograms: return mass;
    case ampere: return current;
    case kelvin: return temperature;
    case mole: return amount;
    case candela: return luminosity;
    }
}

inline base_unit dimension_to_base_unit(const dimension dim) {
    switch (dim) {
    case time: return seconds;
    case length: return meters;
    case mass: return kilograms;
    case current: return ampere;
    case temperature: return kelvin;
    case amount: return mole;
    case luminosity: return candela;
    }
}

typedef enum {
    giga, mega, kilo, hecto, deca,
    none,
    deci, centi, milli, micro, nano,
} prefix;

inline float prefix_to_decimal(const prefix p) {
    switch (p) {
    case giga: return 1e9f;
    case mega: return 1e6f;
    case kilo: return 1e3f;
    case hecto: return 1e2f;
    case deca: return 1e1f;

    case none: return 1e0f;

    case deci: return 1e-1f;
    case centi: return 1e-2f;
    case milli: return 1e-3f;
    case micro: return 1e-6f;
    case nano: return 1e-9f;
    }
}

typedef struct {
    base_unit base;
    prefix prefix;
} unit;

// TODO: derived units?

#endif //bardow_UNITS_H
