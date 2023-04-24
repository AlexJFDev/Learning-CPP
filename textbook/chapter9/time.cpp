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

struct Time {
    int partial_hours, partial_minutes;
    double partial_seconds, total_seconds;
    Time(int hours, int minutes, double seconds) {
        partial_hours = hours;
        partial_minutes = minutes;
        partial_seconds = seconds;
        set_total_seconds();
        set_partial_time();
    }

    public:
        void increment_seconds(int increment) {
            total_seconds += increment;
            set_partial_time();
        }

        string as_string() {
            return "Time(hours:" + to_string(partial_hours) + ", minutes:" + to_string(partial_minutes) + ", seconds:" + to_string(partial_seconds) + ")";
        }
    
    private: 
        void set_total_seconds() {
            total_seconds = partial_hours * 3600 + partial_minutes * 60 + partial_seconds;
        }

        void set_partial_time() {
            partial_hours = (total_seconds - (int)total_seconds % 3600)/3600;
            partial_minutes = ((int)total_seconds % 3600 - (int)total_seconds % 60)/60;
            partial_seconds = (int)total_seconds % 60;
        }
};

int main() {
    Time time1 = Time(1, 1, 61); // becomes 1, 2, 1
    time1.increment_seconds(90); // +90 sec to become 1, 3, 31
    print(time1.as_string());
}