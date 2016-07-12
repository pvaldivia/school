//calc.cpp
//Valdivia, Pedro
//pvaldivia1

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

//DECLARES OBJECT CALC FOR CLASS DSTACK
Dstack calc;

int main()
{
    char char_variable;
    double double_variable;
    double next_input;
    double left_value = 0;
    double right_value = 0;
    double result_value = 0;

// WHILE LOOP GOES THROUGH EACH CHAARACTER OF INPUT UNTIL THERE IS NO MORE INPUT TO READ
    while (cin.peek() != EOF)
    {
        //READS IN ALL WHITE SPACE INPUT
        cin >> ws;
        //CIN.PEEK() ALLOWS US TO SEE THE NEXT CHARACTER OF INPUT 
        next_input = cin.peek();
        //ISDIGIT() CHECKS TO SEE IF NEXT INPUT IS AN INTEGER FROM 0-9
        if (isdigit(next_input) || cin.peek() == '.')
        {
            cin >> double_variable;
            //CIN.GOOD() CHECKS IF INPUT FOR DOUBLE_VARIABLE IS GOOD OR BAD
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
        //CHECKS TO SEE IF NEXT INPUT IS A PUNCTUATION MARK
        else if (ispunct(next_input))
        {
            cin >> char_variable;
            //CHECKS IF OPERATIOR IS + AND STACK HAS AT LEAST TWO VALUES IN IT
            if (char_variable == '+' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value + right_value;
                calc.push(result_value);
            }
            //CHECKS IF OPERATIOR IS - AND STACK HAS AT LEAST TWO VALUES IN IT
            else if (char_variable == '-' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value - right_value;
                calc.push(result_value);
            }
            //CHECKS IF OPERATOR IS * AND STACK HAS AT LEAST TWO VALUES IN IT
            else if (char_variable == '*' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                result_value = left_value * right_value;
                calc.push(result_value);
           
            }
            //CHECKS IF OPERATOR IS / AND STACK HAS AT LEAST TWO VALUES IN IT
            else if (char_variable == '/' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                //CHECKS IF DENOMINATOR OF FRACTION IS A DECIMAL
                if (right_value == 0)
                {
                    error();
                }
                result_value = left_value / right_value;
                calc.push(result_value);
            }
            //CHECKS IF OPERATOR IS ^ AND STACK HAS AT LEAST TWO VALUES IN IT
            else if (char_variable == '^' && calc.size() >= 2)
            {
                pop_two(left_value,right_value);
                //CHECKS IF BASE IS A NEGATIVE VALUE AND EXPONENT IS A DECIMAL VALUE
                if (left_value < 0 && isdecimal(right_value))
                {
                    error();
                }
                result_value = pow(left_value,right_value);
                //CHECKS IF VALUE RETURNED BY POW() IS INFINITY
                if (isinf(pow(left_value,right_value)))
                {
                    error();
                }
                calc.push(result_value);
            }
            //CHECKS IF STACK SIZE IS LESS THAN TWO
            else if (calc.size() < 2)
            {
                error();
            }
            
        }
        //CHECKS IF NEXT INPUT IS AN ALPHABETICAL LETTER
        else if (isalpha(next_input))
        {
            error();
        }
    }
    //AFTER ALL CALCULATIONS, CHECKS IF THERE IS MORE THAN ONE VALUE IN THE STACK
    if (calc.size() >= 2)
    {
        error();
    }
    //PRINTS THE STACK
    calc.print();
    return 0; 
        
}
//POPS THE LEFT_VALUE AND RIGHT_VALUE OF THE STACK
void pop_two(double &left_value, double &right_value)
{
    calc.pop(right_value);
    calc.pop(left_value);
}
//SHOWS AN ERROR HAS OCCURED AND TERMINATES THE PROGRAM WITH AN EXIT STATUS OF 1
void error()
{
    cerr << "Error: Invalid expression.\n";
    exit(1);
}
//RETURNS TRUE IF VALUE PASSED IN IS DECIMAL AND FALSE IF IT IS NOT A DECIMAL
bool isdecimal(double value)
{
    //CONVERTS DOUBLE VALUE INTO A STRING
    string number;
    ostringstream convert;
    convert << value;
    number = convert.str();
    int number_length = number.length();
    //LOOP GOES THROUGH EACH CHARACTER IN STRING TO FIND THE PERIOD PUNCUATION
    for (int i = 0; i < number_length; i++)
    {
        if (number[i] == '.')
        {
            return true;
        }
    }

    return false;
}
