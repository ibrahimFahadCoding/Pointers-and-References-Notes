#include "references.hpp"
#include <iostream>
#include <cstdint>
#include <string>

namespace memory {

void sum(std::int32_t a, std::int32_t b, std::int32_t &sum) noexcept {sum = a + b;}

void take_the_L(const std::string &the_L) noexcept {
  std::cout << "We took " << the_L << "!" << std::endl;
  //the_L = "We took the W!";
}

void take_the_wRight(const std::string &&the_W) noexcept {
  std::cout << "We took " << the_W << "!" << std::endl;
  // the_W = "We took the W!";
}

int &dangling_reference()
{
    int n = 10;
    return n;
}

std::int32_t &valid_ref(std::int32_t &r_num) noexcept {
  ++r_num;
  return r_num;
}
  
void references() noexcept {
  //references =~ pointers 
  //references 
  //instead of storing memory address they store a "blueprint".
  int& i = dangling_reference();
  std::cout << "Dangling Reference Value: " << i << std::endl;

  int num_valid_ref = 5;
  int &r_num_valid_ref = num_valid_ref;
  valid_ref(r_num_valid_ref);
  std::cout << "Valid Reference Value: " << num_valid_ref << std::endl;
  
  std::int32_t number = 1097739826;
  std::int32_t &r_number = number;
  std::cout << "ref number: " << &number << std::endl;
  std::cout << "ref r_number: " << &r_number << std::endl;

  r_number = 1082684628;
  std::cout << "ref number: " << number << std::endl;
  std::cout << "ref r_number: " << r_number << std::endl;

  const std::int32_t r_number2 = 5;
  std::int32_t &&rvalue_ref = 961937390;
  std::cout << "rvalue_ref: " << rvalue_ref << std::endl;
  rvalue_ref = 2;
  std::cout << "rvalue_ref: " << rvalue_ref << std::endl;

  const std::int32_t &&r_value_ref2 = 1472836;
  std::cout << "r_value_ref2: " << r_value_ref2 << std::endl;

  std::int32_t s;
  sum(5,6,s);
  std::cout << "s: " << s << std::endl;

  std::string lstring = "the L";
  take_the_L(std::string(lstring));
  std::cout << "lstring: " << lstring << std::endl;

  std::string rstring = "the R";
  //take_the_wRight(rstring);
  std::cout << "rstring: " << rstring << std::endl;

  std::int32_t y = 5;
  std::int32_t &&x = std::move(5); //r-value cast 
} 

} // namespace memory
//l-values refs can only bind with l-values 
// const l-values refs can bind with both l-values and r-values 
// r-values AND const r-value refs can only bind to r-values
// l-value = "left value" -> Ex: y 

// r-value = "right value" -> Ex: 5









