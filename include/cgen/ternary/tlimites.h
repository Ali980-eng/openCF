/**
 * @file tlimites.h
 * @author ali lafi
 * @version 1.0
 * @date 2026-05-03
 */

#include <stdint.h>

#ifndef METACORE___CGEN___TERNARY_TLIMITES_H
#define METACORE___CGEN___TERNARY_TLIMITES_H

const uint8_t tnull = 0; // ternary null
// for Balanced Ternary Logic
const int8_t ttrue = 2; // ternary true
const int8_t tunknown = 1; // ternary unknown
const int8_t tfalse = -1; // ternary false
// for Unbalanced Ternary Logic
const uint8_t utrue = 3; // unbalanced ternary true
const uint8_t uunknown = 2; // unbalanced ternary unknown
const uint8_t ufalse = 1; // unbalanced ternary false

#define MAX_VALUE_TIRT 1
#define MIN_VALUE_TIRT -1
#define MAX_VALUE_UTIRT 2
#define MIN_VALUE_UTIRT 0
#define MAX_VALUE_TYRT 364
#define MIN_VALUE_TYRT -364
#define MAX_VALUE_UTYRT 728
#define MIN_VALUE_UTYRT 0
#define MAX_VALUE_UB27 26
#define MIN_VALUE_UB27 0
#define MAX_VALUE_B27 13
#define MIN_VALUE_B27 -13

#endif // METACORE___CGEN___TERNARY_TLIMITES_H