// Student ID:20511457
#include <iostream>

using namespace std;

// This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {
    return static_cast<double>(n1 + n2 + n3) / 3.0;
}

// This function returns the maximum of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
    int max_val = n1;
    if (n2 > max_val) max_val = n2;
    if (n3 > max_val) max_val = n3;
    if (n4 > max_val) max_val = n4;
    if (n5 > max_val) max_val = n5;
    return max_val;
}

// This function returns the minimum of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {
    int min_val = n1;
    if (n2 < min_val) min_val = n2;
    if (n3 < min_val) min_val = n3;
    if (n4 < min_val) min_val = n4;
    if (n5 < min_val) min_val = n5;
    return min_val;
}

// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid triangles. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {
    if ((a + b >= c) && (b + c >= a) && (a + c >= b)) {
        return true;
    }
    return false;
}

// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {
    if ((A + B + C == 180) && (A >= 0) && (B >= 0) && (C >= 0)) {
        return true;
    }
    return false;
}

// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
    if (yyyy % 4 == 0) {
        if (yyyy % 100 == 0) {
            if (yyyy % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

