// Copyright 2021 Kuznetsov Mikhail

#include <iostream>
#include <cstdlib>
#include "MyStack.h"
#include "postfix.h"

int main() {
  std::string s1("(18 + 01 + 20.21) * (12.02 - 10 - 81) / 1");
  std::string s2 = infix2postfix(s1);
  std::cout << s2 << std::endl;  //18 01 + 20.21 + 12.02 10 - 81 - * 1 /
  s1 = "1 + (1 + (1 + (1 + 1) + 1) + 1) + 1";
  s2 = infix2postfix(s1);
  std::cout << s2 << std::endl;  //1 1 1 1 1 + + 1 + + 1 + + 1 +
  return 0;
}
