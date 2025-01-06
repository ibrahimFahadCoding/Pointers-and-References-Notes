#include "variables.hpp"
#include <iostream>

namespace variables {
namespace {

std::int32_t g_anon;
const std::uint32_t g_CONST_ANON = std::rand();
constexpr std::int32_t g_CONSTEXPR_ANON = 32;
  
} // namespace
std::int32_t g_extern;
static std::int32_t gs_static;
const std::int32_t g_CONST_EXTERN = std::rand();
constexpr std::int32_t g_CONSTEXPR_EXTERN = 42;
  
std::uint32_t counter() noexcept {
  static std::uint32_t count = 0; // all local vars have no linkage.
  return count++;
}
  
void var_practice() noexcept {
  std::cout << "g_num = " << g_num << ", address: " << &variables::g_num << std::endl;
  std::cout << "g_NUM = " << g_NUM << ", address: " << &variables::g_NUM << std::endl;
  std::cout << "g_RAND = " << g_RAND << ", address: " << &variables::g_RAND << std::endl;
  std::cout << "sg_num = " << sg_num << ", address: " << &variables::sg_num << std::endl;


  //extern
  std::cout << "g_extern = " << g_extern << ", address: " << &variables::g_extern << std::endl;
  std::cout << "gs_static = " << gs_static << ", address: " << &variables::gs_static << std::endl;
  std::cout << "g_CONST_EXTERN = " << g_CONST_EXTERN << ", address: " << &variables::g_CONST_EXTERN << std::endl;
  std::cout << "g_CONSTEXPR_EXTERN = " << g_CONSTEXPR_EXTERN << ", address: " << &variables::g_CONSTEXPR_EXTERN << std::endl;


  std::cout << "sg_inline_num = " << sg_inline_num << ", address: " << &variables::sg_inline_num << std::endl;
  std::cout << "g_INLINE_RAND = " << g_INLINE_RAND << ", address: " << &variables::g_INLINE_RAND << std::endl;
  std::cout << "g_INLINE_NUM = " << g_INLINE_NUM << ", address: " << &variables::g_INLINE_NUM << std::endl;

  for (std::uint32_t i=0;i<10;++i) {
    std::cout << "Counter Result: " << counter() << std::endl;
  }
}
  
} // variables
