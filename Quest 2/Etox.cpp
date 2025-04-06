//Student ID: 20587063
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

double etox_5_terms(double x) {
    return 1 + x + (pow(x,2)/2) + (pow(x, 3)/6) + (pow(x,4)/24);
}

int main(int argc, const char * argv[]) {
    string user_input;
    double x;
    cout << "Enter a value for x: ";
    getline(cin, user_input);
    istringstream(user_input) >> x;
    cout << etox_5_terms(x) << endl;
    return 0;
}