// Student ID:20511457
#include<iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
using namespace std;


int main(int argc, char** argv) {

	double x ,result;
	cout << "Enter a value for x: ";
	cin >> x;
	result = 1 + x + pow(x, 2) / (2 * 1) + pow(x, 3) / (3 * 2 * 1) + pow(x, 4) / (4 * 3 * 2 * 1);
	cout << result << endl;
	

	
}