// Bundle API auto-generated header file. Do not edit!
// Glow Tools version: 2022-05-19 (2ee55ec50) (Glow_Release_MCUX_SDK_2.12.0)

#ifndef _GLOW_BUNDLE_BEST_INT8_H
#define _GLOW_BUNDLE_BEST_INT8_H

#include <stdint.h>

// ---------------------------------------------------------------
//                       Common definitions
// ---------------------------------------------------------------
#ifndef _GLOW_BUNDLE_COMMON_DEFS
#define _GLOW_BUNDLE_COMMON_DEFS

// Glow bundle error code for correct execution.
#define GLOW_SUCCESS 0

// Memory alignment definition with given alignment size
// for static allocation of memory.
#define GLOW_MEM_ALIGN(size)  __attribute__((aligned(size)))

// Macro function to get the absolute address of a
// placeholder using the base address of the mutable
// weight buffer and placeholder offset definition.
#define GLOW_GET_ADDR(mutableBaseAddr, placeholderOff)  (((uint8_t*)(mutableBaseAddr)) + placeholderOff)

#endif

// ---------------------------------------------------------------
//                          Bundle API
// ---------------------------------------------------------------
// Model name: "best_int8"
// Total data size: 15014016 (bytes)
// Activations allocation efficiency: 1.0000
// Placeholders:
//
//   Name: "images"
//   Type: float<1 x 256 x 256 x 3>
//   Size: 196608 (elements)
//   Size: 786432 (bytes)
//   Offset: 0 (bytes)
//
//   Name: "Identity"
//   Type: float<1 x 11 x 1344>
//   Size: 14784 (elements)
//   Size: 59136 (bytes)
//   Offset: 786432 (bytes)
//
// NOTE: Placeholders are allocated within the "mutableWeight"
// buffer and are identified using an offset relative to base.
// ---------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// Placeholder address offsets within mutable buffer (bytes).
#define BEST_INT8_images    0
#define BEST_INT8_Identity  786432

// Memory sizes (bytes).
#define BEST_INT8_CONSTANT_MEM_SIZE     12071296
#define BEST_INT8_MUTABLE_MEM_SIZE      845568
#define BEST_INT8_ACTIVATIONS_MEM_SIZE  2097152

// Memory alignment (bytes).
#define BEST_INT8_MEM_ALIGN  64

// Bundle entry point (inference function). Returns 0
// for correct execution or some error code otherwise.
int best_int8(uint8_t *constantWeight, uint8_t *mutableWeight, uint8_t *activations);

#ifdef __cplusplus
}
#endif
#endif
