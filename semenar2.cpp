//
// Created by misha on 25/06/2020.
//

#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int age = 0;
};

void PrintStudent(const Student& student) {
    std::cout << student.name << " " << student.age <<std::endl;
}

void IncrementAge(Student* student) {
    ++student->age;
}

bool ByNameAndAge(const Student& left, const Student& right) {
    if (left.name != right.name)
        return left.name < right.name;
    return left.age < right.age;
}


void SortStudents(std::vector<Student>* students) {
    std::sort(students->begin(), students->end(), ByNameAndAge);
}

std::vector<Student> ReadStudents() {
    std::vector<Student> data;
    std::string name;
    int age;
    while (std::cin >> name >> age) {
        data.push_back({name, age});
    }
    return data;
}



int main() {
    /*Student student;
    student.name = "Petya";
    student.age = 20; */

    Student student{"Petya", 20};
    Student another_student;
    IncrementAge(&student);
   // PrintStudent(student);
    //PrintStudent(another_student);

    auto students = ReadStudents();
    SortStudents(&students);
    for (const auto& student : students) {
        std::cout << student.name << " " << student.age << std::endl;
    }
return 0;
}