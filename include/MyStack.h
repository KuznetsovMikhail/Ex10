// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
    int size;
    int top;
    T *data;

 public:
    explicit MyStack(int sz) :
      size(sz), top(0) {
      data = new T[size];
    }
    ~MyStack() {
      delete[] data;
    }
    MyStack(const MyStack& MS) :
      size(MS.size), top(MS.top) {
      data = new T[size];
      for (int i = 0; i < size; i++) {
          data[i] = MS.data[i];
      }
    }
    T get() const {
      if (top)
        return data[top - 1];
      return 0;
    }
    void push(T add) {
      if (top < size) {
        data[top] = add;
        top++;
      }
    }
    T pop() {
      if (top) {
        top--;
        return data[top];
      }
      return 0;
    }
    bool isFull() const {
      return top == size;
    }
    bool isEmpty() const {
      return !top;
    }
};
#endif  // INCLUDE_MYSTACK_H_

