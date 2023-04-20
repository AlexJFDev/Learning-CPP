#include <iostream>
#include <math.h>
using namespace std;

void print_twice(char phil) {
    cout << phil << phil << endl;
}

int main() {
    print_twice('a');
    //print_twice("a"); // cannot convert string to character
    print_twice(97); // the int get cast into a character ('a')
    //print_twice('😲'); it doesn't like 😲
    return 0;
}