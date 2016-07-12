#ifndef COURSE_H_
#define COURSE_H_

#include<string>
using namespace std;

class Course
{
    public:
        Course(string name,int number,int value);
        void print();        
    private:
        string course_name;
        int course_number;
        int course_value;

};

#endif
