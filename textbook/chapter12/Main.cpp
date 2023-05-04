#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print(T out, string end = "\n") {
    cout << out << end;
}

int main() {
    print("test");
    print(1);
}