#pragma once

#include <iostream>
#include <string>

class Student {
 public:
  Student();
  Student(const std::string& name, unsigned int num_of_semesters = 1);

  void UpdateNSemesters();
  void SetName(const std::string& name);
  void SetSemesters(unsigned int semesters);

  friend std::ostream& operator<<(std::ostream& os, const Student& student);
  friend std::istream& operator>>(std::istream& is, Student& student);
  friend bool operator==(const Student& lhs, const Student& rhs);
  friend bool operator<(const Student& lhs, const Student& rhs);
  friend bool operator!=(const Student& lhs, const Student& rhs);
  friend bool operator<=(const Student& lhs, const Student& rhs);
  friend bool operator>(const Student& lhs, const Student& rhs);
  friend bool operator>=(const Student& lhs, const Student& rhs);

 private:
  std::string name_;
  unsigned int num_of_semesters_ = 0;
};
