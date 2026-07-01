#ifndef METACORE___CGEN___BITUTILITYS_H
#define METACORE___CGEN___BITUTILITYS_H

#include "bitUtilitys/count_bit.h"
#include "bitUtilitys/get_bit.h"
#include "bitUtilitys/reset_bit.h"
#include "bitUtilitys/set_bit.h"
#include "bitUtilitys/toggle_bit.h"
#include "bitUtilitys/cbool_8.h"
#include "bitUtilitys/xchg_bit.h"
#include "bitUtilitys/binaryFormat.h"

#define binary2string(value) _Generic((value), \
    int8_t: bit8_str(value),                      \
    int16_t: bit16_str(value),                    \
    int32_t: bit32_str(value),                    \
    int64_t: bit64_str(value),                    \
    uint8_t: ubit8_str(value),                    \
    uint16_t: ubit16_str(value),                  \
    uint32_t: ubit32_str(value),                  \
    uint64_t: ubit64_str(value))

#define print_binary(value, pnl) _Generic((value), \
    int8_t: print8bit(value, pnl),                 \
    int16_t: print16bit(value, pnl),               \
    int32_t: print32bit(value, pnl),               \
    int64_t: print64bit(value, pnl),               \
    uint8_t: print_u8bit(value, pnl),              \
    uint16_t: print_u16bit(value, pnl),            \
    uint32_t: print_u32bit(value, pnl),            \
    uint64_t: print_u64bit(value, pnl))


#define count_bit(num, ones) _Generic((num), \
    int8_t: count_8bit(num, ones),           \
    int16_t: count_16bit(num, ones),         \
    int32_t: count_32bit(num, ones),         \
    int64_t: count_64bit(num, ones),         \
    uint8_t: count_u8bit(num, ones),         \
    uint16_t: count_u16bit(num, ones),       \
    uint32_t: count_u32bit(num, ones),       \
    uint64_t: count_u64bit(num, ones))

#define get_bit(num, position) _Generic((num), \
    int8_t: get_8bit(num, position),           \
    int16_t: get_16bit(num, position),         \
    int32_t: get_32bit(num, position),         \
    int64_t: get_64bit(num, position),         \
    uint8_t: get_u8bit(num, position),         \
    uint16_t: get_u16bit(num, position),       \
    uint32_t: get_u32bit(num, position),       \
    uint64_t: get_u64bit(num, position))

#define reset_bit(num, position) _Generic((num), \
    int8_t: reset_8bit(num, position),           \
    int16_t: reset_16bit(num, position),         \
    int32_t: reset_32bit(num, position),         \
    int64_t: reset_64bit(num, position),         \
    uint8_t: reset_u8bit(num, position),         \
    uint16_t: reset_u16bit(num, position),       \
    uint32_t: reset_u32bit(num, position),       \
    uint64_t: reset_u64bit(num, position))

#define set_bit(num, position) _Generic((num), \
    int8_t: set_char_bit(num, position),       \
    int16_t: set_short_bit(num, position),     \
    int32_t: set_int_bit(num, position),       \
    int64_t: set_long_bit(num, position),      \
    uint8_t: set_u8bit(num, position),         \
    uint16_t: set_u16bit(num, position),       \
    uint32_t: set_u32bit(num, position),       \
    uint64_t: set_u64bit(num, position))

#define toggle_bit(num, position) _Generic((num), \
    uint8_t: toggle_u8bit(num, position),         \
    uint16_t: toggle_u16bit(num, position),       \
    uint32_t: toggle_u32bit(num, position),       \
    uint64_t: toggle_u64bit(num, position),       \
    int8_t: toggle_8bit(num, position),           \
    int16_t: toggle_16bit(num, position),         \
    int32_t: toggle_32bit(num, position),         \
    int64_t: toggle_64bit(num, position))


#define xchg_bit(value, pos1, pos2) _Generic((value), \
    uint8_t: xchg_u8bit(value, pos1, pos2),   \
    uint16_t: xchg_u16bit(value, pos1, pos2), \
    uint32_t: xchg_u32bit(value, pos1, pos2), \
    uint64_t: xchg_u64bit(value, pos1, pos2), \
    int8_t: xchg_8bit(value, pos1, pos2),     \
    int16_t: xchg_16bit(value, pos1, pos2),   \
    int32_t: xchg_32bit(value, pos1, pos2),   \
    int64_t: xchg_64bit(value, pos1, pos2))

#endif // METACORE___CGEN___BITUTILITYS_H