#include <iostream>
//#include "variables.hpp"
//#include "pointers.hpp"

#include "references.hpp"

//namespace variables {
  
//inline std::int32_t g_num;
  
//} // namespace variables

// ODR can only be defied by preprocessor (can't be done by yourself.)

int main() {

  memory::pointers_practice();
  memory::references();
  
  variables::g_num = 5;
  variables::sg_num = 7;
  variables::sg_inline_num = 10;
  
  //variables::g_RAND = 25;
  variables::var_practice();
  std::cout << "g_num = " << variables::g_num << ", address: " << &variables::g_num << std::endl;
  std::cout << "g_NUM = " << variables::g_NUM << ", address: " << &variables::g_NUM << std::endl;
  std::cout << "g_RAND = " << variables::g_RAND << ", address: " << &variables::g_RAND << std::endl;
  std::cout << "sg_num = " << variables::sg_num << ", address: " << &variables::sg_num << std::endl;

  //extern
  std::cout << "[main.cpp] g_extern = " << variables::g_extern << ", address: " << &variables::g_extern << std::endl;
  
  std::cout << "[main.cpp] g_CONST_EXTERN = " << variables::g_CONST_EXTERN << ", address: " << &variables::g_CONST_EXTERN << std::endl;
  


  
  std::cout << "[main.cpp] sg_inline_num = " << variables::sg_inline_num << ", address: " << &variables::sg_inline_num << std::endl;
  std::cout << "[main.cpp] g_INLINE_RAND = " << variables::g_INLINE_RAND << ", address: " << &variables::g_INLINE_RAND << std::endl;
  std::cout << "[main.cpp] g_INLINE_NUM = " << variables::g_INLINE_NUM << ", address: " << &variables::g_INLINE_NUM << std::endl;
}
