#include <iostream>
#include <stdexcept>
#include <string>

#include "s_linked_list.h"
#include "student.h"

namespace {

void ForwardPrint(SLinkedList<Student>::Iterator iter) {
  if (iter == nullptr) {
    return;
  }
  std::cout << *iter;
  ForwardPrint(iter.next());
}

void BackwardPrint(SLinkedList<Student>::Iterator iter) {
  if (iter == nullptr) {
    return;
  }
  BackwardPrint(iter.next());
  std::cout << *iter;
}

}  // namespace

int main() {
  SLinkedList<Student> students;

  Student student;
  for (int i = 0; i < 5; ++i) {
    student.SetName("Student_" + std::to_string(i));
    student.SetSemesters(2);
    students.Prepend(student);
  }

  SLinkedList<Student> class_roster(students);
  for (int i = 1; i <= 5; ++i) {
    student.SetName("Student_" + std::to_string(i * 10));
    student.SetSemesters(2);
    class_roster.Append(student);
  }

  students = class_roster;
  std::cout << "Front and back:\n"
            << class_roster.Front() << class_roster.Back() << "\n\n";

  std::cout << "Range-based for loop traversal:\n";
  for (const auto& student_item : students) {
    std::cout << student_item;
  }
  std::cout << "\n\n";

  class_roster.InsertAfter(class_roster.Begin() + 2, Student("Bob"));

  std::cout << "Recursive forward traversal:\n";
  ForwardPrint(students.Begin());
  std::cout << "\n\n";

  std::cout << "Recursive backward traversal:\n";
  BackwardPrint(students.Begin());
  std::cout << "\n\n";

  students.Reverse();

  std::cout << "Recursive forward traversal (after reversal):\n";
  ForwardPrint(students.Begin());
  std::cout << "\n\n";

  std::cout << "Recursive backward traversal (after reversal):\n";
  BackwardPrint(students.Begin());
  std::cout << "\n\n";

  std::cout << "Pop until empty traversal:\n";
  while (!students.Empty()) {
    std::cout << students.Front();
    students.RemoveFront();
  }

  SLinkedList<unsigned int> test_scores;
  test_scores.Append(89);
  test_scores.Append(92);
  test_scores.Append(75);
  test_scores.Append(97);
  std::cout << "\nTest score average is: "
            << test_scores.Add() / test_scores.Size() << "%\n";
}
