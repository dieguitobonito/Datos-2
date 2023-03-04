#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;
    std::string major;

    // Constructor predeterminado
    Student() {}

    // Constructor
    Student(std::string name, int age, std::string major){
        this->name = name;
        this->age = age;
        this->major = major;
    }
};


#endif // STUDENT_H_
