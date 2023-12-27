#include "Test.h"
#include "student.h"
#include <vector>


bool test_addStudent() {
    vector<STUDENT> students;

    STUDENT newStudent("John Doe", 1, new double[5] {4.0, 3.5, 4.5, 3.0, 5.0});
    students.push_back(newStudent);

    return (students.size() == 1 && students[0].getName() == "John Doe" &&
        students[0].getGroupNumber() == 1 &&
        students[0].getGrades()[0] == 4.0 && students[0].getGrades()[4] == 5.0);
}
