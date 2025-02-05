//
// Created by timob on 31.01.2025.
//

#ifndef bardow_STATE_H
#define bardow_STATE_H

#include <stdint.h>

#ifndef bardow_DEFAULT_STATE_SIZE
#define bardow_DEFAULT_STATE_SIZE 32
#endif //bardow_DEFAULT_STATE_SIZE

/**
 * @brief Determines which uintN_t state uses. Must be one of [8, 16, 32, 64].
 */
#ifndef bardow_STATE_SIZE
#define bardow_STATE_SIZE bardow_DEFAULT_STATE_SIZE
#endif //bardow_STATE_SIZE

/**
 * @brief A bitmask representing whether up to bardow_STATE_SIZE
 * independent variables are known or not.
 *
 * Each bitmask bit indicates whether the corresponding variable is known.
 * Mapping needs to be tracked separately.
 *
 * If bardow_STATE_SIZE is not set, it defaults to bardow_DEFAULT_STATE_SIZE.
 * If bardow__DEFAULT_STATE_SIZE is not set, it defaults to 32.
 *
 */
#if bardow_STATE_SIZE == 8
typedef uint8_t state;
#elif bardow_STATE_SIZE == 16
typedef uint16_t state;
#elif bardow_STATE_SIZE == 32
typedef uint32_t state;
#elif bardow_STATE_SIZE == 64
typedef uint64_t state;
#else
#error "bardow_STATE_SIZE must be 8, 16, 32 or 64"
#endif //bardow_STATE_SIZE

#endif //bardow_STATE_H
