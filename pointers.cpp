#include "pointers.hpp"
#include <cstdint>
#include <iostream>
#include <string>

namespace memory {

constexpr std::int32_t g_NUM = 7;

const std::int32_t *ptr_2_static_data() noexcept { return &g_NUM; }

void print_ptr_val(std::int32_t *p_num) noexcept {
  std::cout << "pointer val: " << *p_num << std::endl;
}

std::int32_t *valid_ptr(std::int32_t *p_num) noexcept {
  ++*p_num;
  return p_num;
}

void sum_func(std::int32_t a, std::int32_t b, std::int32_t *p_sum) noexcept {
  *p_sum = a+b;
}

std::int32_t *invalid_ptr() noexcept {
  std::int32_t x = -3;
  std::cout << "x = " << x << ", &x = " << &x << std::endl;  
  return &x;
}
//dangling pointer 

  
void pointers_practice() noexcept {

  // & = reference (address) operator
  // * = dereference
  std::uint32_t x = 5;
  std::uint32_t *p_x = &x;
  std::cout << "p_x: " << p_x << std::endl;
  std::cout << "p_x Address: " << &p_x << std::endl;
  std::cout << "*p_x: " << *p_x << std::endl;
  *p_x = 27;
  std::cout << "x: " << x << std::endl;

  std::uint32_t *p = nullptr;
  std::cout << "p: " << p << std::endl;
  // (this is undefined behavior) std::cout << "*p: " << *p << std::endl;

  if (p_x == nullptr) {std::cout << "This is a nullptr" << std::endl;}
    
  else {std::cout << "*p_x: " << *p_x << std::endl;}

  if (!p_x) {std::cout << "This is a nullptr" << std::endl;}

  else {std::cout << "*p_x: " << *p_x << std::endl;}

  std::int32_t sum;
  sum_func(3,9, &sum);
  std::cout << "Sum: " << sum << std::endl;
  

  std::int32_t a = 5;
  const std::int32_t *p_const_data = &a; //pointer->const data (can change addr, not data being pointed to.)
  a = 7;
  std::cout << "*p_const_data: " << *p_const_data << std::endl;

  std::int32_t* p_a2 = &a;
  std::cout << "*p_a2: " << *p_a2 << std::endl;

  std::int32_t b = 5;
  std::int32_t c = -5;
  //std::int32_t* p_b = &b, p_c = &c; // muy mal
  std::int32_t *p_bd = &b, *p_ce = &c; // muy bien

  constexpr std::int32_t d = 7;
  //std::int32_t *p_d = &d; muy mal, data is const. 
  const std::int32_t *p_d = &d;


  std::int32_t *const p_const_ptr = &a;
  *p_const_ptr = 129;

  std::cout << "*p_const_ptr: " << *p_const_ptr << std::endl;

  const std::int32_t *const p_const_d = &d;
  
  // *p_x = dereference p_x = x

  std::int32_t num = 4;
  std::int32_t *p_num = &num;
  print_ptr_val(p_num);
  valid_ptr(valid_ptr(valid_ptr(p_num)));
  print_ptr_val(p_num);

  std::int32_t *p2 = invalid_ptr();
  std::cout << "*p2 = " << *p2 << ", p2 = " << p2 << "\n" << std::endl;

  (*p_num)++;
  print_ptr_val(p_num);
  std::int32_t hmmm = 4;
  ++++hmmm;
  (++hmmm)++;
  std::cout << hmmm << std::endl;

  std::string bob = "bob";
  std::string *p_bob = &bob;
  std::cout << "Length of Bob: " << bob.length() << std::endl;
  std::cout << "Length of *p_bob: " << p_bob->length() << std::endl;

}

} // namespace memory
  
