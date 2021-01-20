#if !defined(SIMDE_ARM_NEON_LD1_LANE_H)
#define SIMDE_ARM_NEON_LD1_LANE_H
#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x2_t
simde_vld1_lane_s32(int32_t *ptr, simde_int32x2_t val, const int lane)
    SIMDE_REQUIRE_CONSTANT_RANGE(lane, 0, 1) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    SIMDE_CONSTIFY_2_NO_RESULT_(vst1_lane_f32, HEDLEY_UNREACHABLE(), lane, ptr, val);
  #else
    simde_int32x2_private val_ = simde_int32x2_to_private(val);
    val_.values[lane] = *ptr;
    return simde_int32x2_from_private(val_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vld1_lane_s32
  #define vld1_lane_s32(a, b, c) simde_vld1_lane_s32((a), (b), (c))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_LD1_LANE_H) */

