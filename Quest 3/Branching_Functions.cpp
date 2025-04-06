// Student ID: 20587063
#include <iostream>

double mean_of_3(int n1, int n2, int n3) {
    double avg = (n1+n2+n3)/3.0;
    return avg; 
}
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
    int greatest = n1; 
    int nums[5] = {n1,n2,n3,n4,n5};
    for(int i = 0; i < 5; i++){
        if(nums[i] > greatest){
            greatest = nums[i];
        }
    } 
    return greatest;
}
int min_of_5(int n1, int n2, int n3, int n4, int n5) {
    int smallest = n1; 
    int nums[5] = {n1,n2,n3,n4,n5};
    for(int i = 0; i < 5; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
        }
    } 
    return smallest;
}
// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid triangles. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {
    int side = a; 
    int nums[3] = {a, b ,c};
    for(int i = 0; i < 3; i++){
        if(nums[i] > side){
            side = nums[i];
        }
    } 
    int sum_of_two = a + b + c - side;
    return sum_of_two >= side;
}
// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {
    return (A+B+C == 180 || A+B+C == 0);
}
// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
    bool leap; 
    if(yyyy % 4 == 0){
        if(yyyy % 100 == 0){
            if(yyyy % 400 == 0){
                leap = true;
            } else { 
                leap = false; 
            }
        } else { 
            leap = true;
        }
    } else {
        leap = false;
    }
    return leap;
}