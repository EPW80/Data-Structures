#pragma once

#include <algorithm>

#include <cstddef>

#include <stdexcept>

#pragma once

#include <algorithm> // move(), move_backward(), copy()

#include <cstddef>   // size_t

#include <stdexcept> // range_error

// Template Class Definition
template < typename T >
  class FixedVector {
    public:
      // Constructors, destructor, and assignments
      FixedVector(std::size_t capacity = 64); // power of 2, but nothing special about 2^6
    FixedVector(const FixedVector & other); // Copy constructor
    FixedVector & operator = (const FixedVector & rhs); // Copy assignment
    ~FixedVector();

    // Queries
    T & at(std::size_t index); // Checks bounds, throws std::range_error
    T & operator[](std::size_t index); // No bounds checking

    std::size_t size();
    bool empty();

    // Iterators
    T * begin();
    T * end();

    // Mutators
    void push_back(const T & value); // Checks capacity, throws std::range_error

    std::size_t erase(std::size_t index); // Checks bounds, throws std::range_error
    T * erase(T * position); // Checks bounds, throws std::range_error

    void set(std::size_t index,
      const T & value); // Checks bounds, throws std::range_error

    std::size_t insert(std::size_t beforeIndex,
      const T & value); // Checks capacity, throws std::range_error
    T * insert(T * beforePosition,
      const T & value); // Checks capacity, throws std::range_error

    void clear();

    private: std::size_t _ = 0;
    std::size_t
    const _capacity = 0;
    T * _array = nullptr;
  };

// Implementation

// Constructor with initial capacity argument
template < typename T >
  FixedVector < T > ::FixedVector(std::size_t capacity): _size(0), _capacity(capacity), _array(new T[capacity]()) {}

template < typename T >
  std::size_t FixedVector < T > ::size() {
    return _size;
  }

template < typename T >
  bool FixedVector < T > ::empty() {
    return _size == 0;
  }

template < typename T >
  T * FixedVector < T > ::begin() {
    return _array;
  }

template < typename T >
  T * FixedVector < T > ::end() {
    return _array + _size;
  } // Note the pointer arithmetic used

template < typename T >
  void FixedVector < T > ::clear() {
    // destroy the elements held allowing resources to be released.  But maintain "this" FixedVector's capacity
    while (_size != 0)
      _array[--_size].~T(); // Direct call to destructor
  }

template < typename T >
  T & FixedVector < T > ::at(std::size_t index) {
    if (index >= _size)
      throw std::range_error("FixedVector index out of range");
    return _array[index];
  }