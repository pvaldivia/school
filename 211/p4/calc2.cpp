#include<iostream>
#include<cctype>
#include<math.h>
#include"dstack.h"
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;
void error();
void pop_two(double&,double&);
bool isdecimal(double);

Dstack calc;

int main()
{
    char char_variable;
    double double_variable;
    double next_input;
    double left_value = 0;
    double right_value = 0;
    double result_value = 0;


    while (cin.peek() != EOF)
    {
        cin >> ws;
        next_input = cin.peek();
        
        if (isdigit(next_input) || cin.peek() == '.')
        {
            cin >> double_variable;
            if (cin.good())
            {
                calc.push(double_variable);
                if (cin.peek() == '.')
                {
                    error();
                }
            }
            else
            {
                error();
            }
        }
        else if (ispunct(next_input))
        {
            cin >> char_variable;
            if (char_variable == '+' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value + right_value;
                calc.push(result_value);
            }
            else if (char_variable == '-' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value - right_value;
                calc.push(result_value);
            }
            
            else if (char_variable == '*' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value * right_value;
                calc.push(result_value);
            }
            else if (char_variable == '/' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                if (right_value == 0)
                {
                    error();
                }
                result_value = left_value / right_value;
                calc.push(result_value);
            }
            else if (char_variable == '^' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                if (left_value < 0 && isdecimal(right_value))
                {
                    error();
                }
                result_value = pow(left_value,right_value);
                calc.push(result_value);
            }
            else if (calc.size() < 2)
            {
                error();
            }
            
        }
        else if (isalpha(next_input))
        {
            
            if (next_input == 's' && calc.size() > 0)
            {
                cin >> char_variable;
                int sine_index = 0;
                int sqrt_index = 0;
                char sine[] = "sin";
                char sqroot[] = "sqrt";
                for (int i = 1; i < 4; i++)
                {
                    if (sine_index < 2 && cin.peek() == sine[i])
                    {
                        cin >> char_variable;
                        sine_index++;
                    }
                    else if (cin.peek() == sqroot[i])
                    {
                        cin >> char_variable;
                        sqrt_index++;
                    }
                }

                if (sine_index == 2)
                {
                    calc.pop(right_value);
                    right_value = right_value*(M_PI/180);
                    result_value = sin(right_value);
                    calc.push(result_value);
                }
                if (sqrt_index == 3)
                {
                    calc.pop(right_value);
                    if (right_value < 0)
                    {
                        error();
                    }
                    result_value = sqrt(right_value);
                    calc.push(result_value);
               }
            }
            else if (next_input == 'c' && calc.size() > 0)
            {
                cin >> char_variable;
                int cos_index = 0;
                char cosine[] = "cos";
                for (int i = 1; i < 3; i++)
                {
                    if (cin.peek() == cosine[i])
                    {
                        cin >> char_variable;
                        cos_index++;
                    }
                }
                if (cos_index == 2)
                {
                    calc.pop(right_value);
                    right_value = right_value*(M_PI/180);
                    result_value = cos(right_value);
                    calc.push(result_value);
                }
            }
            else if (next_input == 'a' && calc.size() > 0)
            {   cin >> char_variable;
                int ave_index = 0;    
                char average[] = "ave";
                for (int i = 1; i < 3; i++)
                {
                    if (cin.peek() == average[i])
                    {
                        cin >> char_variable;
                        ave_index++;
                    }
                }
                if (ave_index == 2)
                {
                    int stack_current_size = calc.size();
                    int stack_size = calc.size();
                    double value;
                    double total_value;
                    double  average;
                    
                    while (stack_current_size > 0)
                    {
                        calc.pop(value);
                        total_value = total_value + value;
                        stack_current_size--;
                    }
                    average = total_value/stack_size;
                    calc.push(average);
                }
                
            }
            else
            {
                error();
            }
        }
    }

    if (calc.size() >= 2)
    {
        error();
    }

    calc.print();
    return 0; 
        
}
void pop_two(double &left_value, double &right_value)
{
    calc.pop(right_value);
    calc.pop(left_value);
}

void error()
{
    cerr << "Error: Invalid expression.\n";
    exit(1);
}

bool isdecimal(double value)
{
    string number;
    ostringstream convert;
    convert << value;
    number = convert.str();
    for (int i = 0; i < number.length(); i++)
    {
        if (!isdigit(number[i]))
        {
            return true;
        }
    }

    return false;
}
