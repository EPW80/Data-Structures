#pragma once#include <array>

#include <cstddef>

#include "Stack.h"

// Stack is an adapter that provides a consistent LIFO interface over an underlying container.  Here, that underlying container is
// defaulted to a singly linked list.  Other choices include a double linked list, vector, and so on.
//    Underlying container must support the following functions:
//    o) void    push( const T & element)
//    o) T       pop()
//    o) T &     top()
//    o) bool    empty()
//    o) size_t  size()
//
//
// Note:  C++20 "Concepts" will enable better enforcement of these constraints, but for now ...

template < typename T, class UnderlyingContainer = SLinkedList < T >>
  class Stack {
    public: void push(const T & element);
    T pop();
    T & top(); // peek() in zyBook
    bool empty(); // isEmpty() in zyBook
    std::size_t size(); // getLength() in zyBook

    private: UnderlyingContainer collection;
  };