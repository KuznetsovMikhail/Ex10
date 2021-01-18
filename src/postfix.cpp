// Copyright 2021 Kuznetsov Mikhail

#include "postfix.h"

std::string infix2postfix (std::string inf) {
  inf.push_back(' ');
  MyStack <char> operatorStack(400);
  std::string post;
  char prev = 0;
  std::string ifNum = "1234567890.";
  for (auto symb:inf) {
    if (ifNum.find(prev) != std::string::npos &&
        ifNum.find(symb) == std::string::npos) {
      post.push_back(' ');
    }
    if (symb == '(' ) {
      operatorStack.push(symb);
    } else if (symb == ')' ) {
      while (!(operatorStack.isEmpty()) &&
             operatorStack.get() != '(') {
        post.push_back(operatorStack.pop());
        post.push_back(' ');
      }
      if (operatorStack.get() == '(') {
        operatorStack.pop();
      }
    } else if (ifNum.find(symb) != std::string::npos) {
      post.push_back(symb);
    } else if (symb == '/' || symb == '*') {
      while (!(operatorStack.isEmpty()) &&
              operatorStack.get() != '(' &&
              operatorStack.get() != '+' &&
              operatorStack.get() != '-') {
        post.push_back(operatorStack.pop());
        post.push_back(' ');
      }
      operatorStack.push(symb);
    } else if (symb == '+' || symb == '-') {
      while (!(operatorStack.isEmpty()) &&
             operatorStack.get() != '(') {
        post.push_back(operatorStack.pop());
        post.push_back(' ');
      }
        operatorStack.push(symb);
    }
    prev = symb;
  }
  while (!(operatorStack.isEmpty())){
    post.push_back(operatorStack.pop());
    post.push_back(' ');
  }
  post.pop_back();
  return post;
}

