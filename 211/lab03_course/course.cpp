#include<iostream>
#include"course.h"

Course::Course(string name, int number, int value)
{
    course_name = name;
    course_number = number;
    course_value = value;


}

void Course::print()
{
    cout << course_name << " ";
    cout << course_number << " at ";
    cout << course_value << endl;
    
}

