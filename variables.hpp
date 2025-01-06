#pragma once
#include <cstdint>
#include <cstdlib>

namespace variables {
inline std::int32_t g_num; // have external linkage (linked every translation unit) and can defy ODR (One-Def Rule)
  
static std::int32_t sg_num; // has internal linkage (only visible in current translation unit.)
  
inline static std::int32_t sg_inline_num;
  
const std::uint32_t g_RAND = std::rand();
  
inline const std::uint32_t g_INLINE_RAND = std::rand();
  
constexpr std::int32_t g_NUM = 10;

inline constexpr std::int32_t g_INLINE_NUM = 10;

void var_practice() noexcept;
  
// inline const means untouchable variable not copied. 
extern std::int32_t g_extern;
//extern static std::int32_t gs_static;
extern const std::int32_t g_CONST_EXTERN;
// extern constexpr std::int32_t g_CONSTEXPR_EXTERN = 42;
} // namespace variables
