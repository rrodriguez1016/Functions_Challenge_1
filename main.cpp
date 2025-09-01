//Rene Rodriguez 08/31/25 Lab Activity: User Defined Functions
//Challenge 1: Geometric Calculations with Function Overloading
#include<iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include<math.h>
#include<cctype>
#include <sstream>
//overloading functions
double calculateArea(const double radius){
    return radius * radius * M_PI;
}
double calculateArea(const double length, const double width){
    return length * width;
}
double calculatePerimeter(const double radius){
    return M_PI * radius * 2;
}
double calculatePerimeter(const double length, const double width){
    return (2 * length) + (2 * width);
}
//getting user input through function for repeatability
double getInput(){
    double input;
    cin >> input;
    while(input < 0 || cin.fail()){
        if (cin.fail()) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        if(input < 0){
            cout << "Enter a positive number" << endl; 
        }
        cin >> input;

    }
    cout << "You entered " << input << endl;
    return input;
}
//original prompt
void promptUser(){
    cout << "What would you like to do?" << endl;
    cout << "\t 1. Area of a Circle" << endl;
    cout << "\t 2. Perimeter of a Circle" << endl;
    cout << "\t 3. Area of a Rectangle" << endl;
    cout << "\t 4. Perimeter of a Rectangle" << endl;
    cout << "\t 5. Quit" << endl;
}

int main()
{
    //initialized variables for future calculations
    int userInput;
    double output;
    double radius;
    double length;
    double width;
    //do while loop which prompts users until user input is 5
    do {
        promptUser();
        cin >> userInput;
        //input validation
        if (cin.fail()) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }
    //takes user input and uses that for switch statement 
        switch (userInput){
            case 1:
                cout << "Enter radius:" << endl;
                radius = getInput();
                output = calculateArea(radius);
                cout << "Area = " << output << endl;
                break;
            case 2:
                cout << "Enter radius:" << endl;
                radius = getInput();
                output = calculatePerimeter(radius);
                cout << "Perimeter = " << output << endl;
                break;
            case 3:
                cout << "Enter length:" << endl;
                length = getInput();
                cout << "Enter width:" << endl;
                width = getInput();
                output = calculateArea(length, width);
                cout << "Area = " << output << endl;
                break;
            case 4:
                cout << "Enter length:" << endl;
                length = getInput();
                cout << "Enter width:" << endl;
                width = getInput();
                output = calculatePerimeter(length, width);
                cout << "Perimeter = " << output << endl;
                break;
            case 5:
                cout << "Bye Bye :(" << endl;
                break;
            default:
                cout << "Please enter valid input! :)" << endl;
        }
    } while (userInput != 5);
    return 0;
}
