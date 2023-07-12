#include <iostream>
#include <string>

#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<std::string, double> studentGrades, gradeBook;
    studentGrades.insert("Ricardo", 2.5);
    studentGrades.insert("Ellen", 3.5);
    studentGrades.insert("Chen", 2.5);
    studentGrades.insert("Kevin", 3.25);
    studentGrades.insert("Kumar", 3.05);

    gradeBook = studentGrades; // test assignment operator, copy constructor, and destructor

    std::string myKey = "Ellen"; // find grade of one student
    auto value = studentGrades.search(myKey);

    std::cout << "Grade of " << myKey << " is " << value << '\n';

    studentGrades.printInorder(); // print the entire BST

    if (gradeBook.getHeight() != 3)
        std::cerr << "Tree height does not match expected\n";

    gradeBook.remove("Ellen");
    if (gradeBook.getHeight() != 2)
        std::cerr << "Tree height does not match expected\n";
};

template class BinarySearchTree<unsigned, float>;
