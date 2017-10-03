// Simple ring(circular) buffer using templates
//
#include "ring.h"
#include <iostream>



int main() {


  ring<std::string> textstring(3); //specify the buffer memory

  // if we try to add more elements than buffer memory, we will observe overwritten entries in a cyclic way
  textstring.add("first_entry");
  textstring.add("second_entry");
  textstring.add("third_entry");
  textstring.add("fourth_entry");
  textstring.add("fifth_entry");

  for(ring<std::string>::iterator it=textstring.begin(); it!=textstring.end(); it++){
    std::cout << *it << std::endl;
  }


  return 0;
}
