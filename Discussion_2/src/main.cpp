/******************************************************************************
# Author:           Hemen Babis
# Assignment:       A02 Gumball guesser (CS161A)
# Date:             April 21, 2022
# Description:      This program will guess the amount of gumball in a jar
# Input:            gumballRadius as a float, jarRadius as a float, jarHeight as a float
# Output:           gumballsEstimate as integer
# Sources:          Mr. Schaeffer
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
const double PI = M_PI;
using namespace std;

//main function
int main() {
  //variables declared for gumball guessing calculation
  float gumballRadius = 0.0;
  float jarRadius = 0.0;
  float jarHeight = 0.0;
  float jarVolume = 0.0;
  float gumballVolume = 0.0;
  int gumballsEstimate = 0;
  cout << "Welcome to my gumball guesser program!" << endl;
  //user input
  cout << "\nEnter the radius of a gumball(cm): ";
  cin >> gumballRadius;
  cout << "Enter the radius and the height of the jar(cm) separated by a space: ";
  cin >> jarRadius >> jarHeight;

  //calculations
  gumballVolume= 4.0*PI* gumballRadius* gumballRadius* gumballRadius/ 3;
  jarVolume= PI* jarRadius *jarRadius* jarHeight;
  gumballsEstimate= jarVolume*0.69/gumballVolume;
  //output to the user
  //set fixed and showpoint with 2 precision set to 2 decimal places
  cout << fixed << showpoint << setprecision(2);
  cout << "\nEstimate of gumballs in the jar: " << gumballsEstimate << endl;
 cout << "\nThank you for using my program!" << endl;

  //end program
  return 0;
}