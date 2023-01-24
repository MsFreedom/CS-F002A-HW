#include <iostream>

using namespace std;

int main() {

    string first, last; //user name 

    int a, b, c, max, min;

    cout << "What is your First name? ";
    cin >> first;
    cout << "What is your Last name? ";
    cin >> last;
    cout << "Hallo " << first << " " << last << endl;

    cout << first << " " << "What is your first number? ";
    cin >> a;
    cout << first << " " << "What is your second number? ";
    cin >> b;
    cout << first << " " << "What is your third number? ";
    cin >> c;
    //cout << a << " " << b << " " << c << endl;

    max = a; //initial hypothesis: a = max
    if (b > a)
        max = b; //we revised our hypothesis, now b is max
    if (c > b)
        max = c;

    // at this point, max is the largest of a, b, cout

    min = a;
    if (b < a)
        min = b;
    if (c < b)
        min = c;

    cout << "Your max is " << max << ", your min is: " << min << endl;

    return 0;
}
