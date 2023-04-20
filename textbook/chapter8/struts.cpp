#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void print(string str, string end = "\n") {
    cout << str << end;
}

void print(double dub, string end = "\n"){
    cout << dub << end;
}

struct Point {
    double x, y;

    string as_string() {
        return "Point(" + to_string(this->x) + ", " + to_string(this->y) + ")";
    }

    double euclidean_distance_to(Point point) {
        double dx = point.x - this->x;
        double dy = point.y - this->y;
        return sqrt(dx*dx + dy*dy);
    }
};

struct Rectangle{
    Point upper_left_corner;
    double width, height;

    Point get_lower_right() {
        Point temp = {this->upper_left_corner.x + width, this->upper_left_corner.y - height};
        return temp;
    }

    double get_area() {
        return width * height;
    }
};

int main() {
    Point origin = {0, 0};

    Rectangle rect = {origin, 5, 5};

    print(rect.get_lower_right().as_string());
    print(rect.get_area());
}

