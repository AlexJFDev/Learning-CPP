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
    /*int* i = new int(1);
    print(i);
    print(*i);
    i = new int(3);
    print(i);
    print(*i);
    int *j = (int*)0x1;
    print(j);
    print(*j);*/
    int* h = new int(5);
    print("h addr as hex: ", "");
    print(h);
    print("h addr as b10: ", "");
    print(long(h));
    print("h addr value: ", "");
    print(*h);

    h = new int(1);
    print("h has a new addr");
    print("h addr as b10: ", "");
    print(long(h));
    print("h addr value: ", "");
    print(*h);

    int* i = (int*)std::stol(input("enter address:"));
    print("i addr as hex: ", "");
    print(i);
    print("i addr value: ", "");
    print(*i);
}