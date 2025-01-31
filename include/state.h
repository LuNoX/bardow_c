//
// Created by timob on 31.01.2025.
//

#ifndef bardow_STATE_H
#define bardow_STATE_H

#include <stdint.h>
#include "variable.h"

constexpr uint8_t temperature_is_known = 0b'0000'0001;
constexpr uint8_t pressure_is_known = 0b'0000'0010;
constexpr uint8_t volume_is_known = 0b'0000'0100;
constexpr uint8_t entropy_is_known = 0b'0000'1000;
constexpr uint8_t enthalpy_is_known = 0b'0001'0000;
constexpr uint8_t internal_energy_is_known = 0b'0010'0000;

constexpr uint8_t is_stationary_process = 0b'0100'0000;
constexpr uint8_t is_ideal_process = 0b'1000'0000;

typedef struct {
    uint8_t flags;
    //15 bytes padding TODO: use this space
    variable temperature;
    variable pressure;
    variable volume;
    variable entropy;
    variable enthalpy;
    variable internal_energy;
    // TODO: currently 7*16 bytes in size. Not ideal. Consider redesign
} state;

#endif //bardow_STATE_H
