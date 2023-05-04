#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

template <typename T>
void print(T out, string end = "\n") {
    cout << out << end;
}

int random_int(int upper) {
    return floor(rand() % (upper + 1));
}

template <typename T>
map<T, int> generate_histogram(vector<T> input_vector) {
    int input_size = input_vector.size();
    map<T, int> histogram;
    for(int i = 0; i < input_size; i++){
        histogram[input_vector[i]]++;
    }
    return histogram;
}

int main() {
    int total_randoms = 10000;
    vector<int> randoms(total_randoms);
    srand(time(NULL));
    for (int i = 0; i < total_randoms; i++) {
        randoms[i] = random_int(10);
    }
    map<int, int> randoms_histogram = generate_histogram(randoms);
    for (auto key: randoms_histogram) {
        print(to_string(key.first) + ":" + to_string(key.second));
    }
    return 0;
}