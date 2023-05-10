#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

template <class T>
void print(T out) {
    cout << out << "\n";
}

template <class T, class G>
void print(T out, G end) {
    cout << out << end;
}

template <class T>
string input(T out, string end = "") {
    string in;
    print(out, end);
    cin >> in;
    return in;
}

int main() {
    
}