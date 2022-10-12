#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class TimeStamp {
private:
    size_t id;
    size_t year;
    size_t month;
    size_t day;
    size_t seconds;
    size_t minutes;
    size_t hours;
public:
    TimeStamp() = default;

    void initialize(const size_t id, const string &time,const string& date) {
        this->id = id;
        hours = stoi(time.substr( 0, 2));
        minutes = stoi(time.substr(3,2));
        seconds = stoi(time.substr(6, 2));
        day = stoi(date.substr( 0,2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));
    }

    bool operator<(const TimeStamp &other) const {
        bool isLess = this->year < other.year;
        if (this->year == other.year) {
            isLess = this->month < other.month;
            if (this->month == other.month) {
                isLess =this->day < other.day;
                if (this->day == other.day) {
                    isLess = this->hours < other.hours;
                    if (this->hours == other.hours) {
                        isLess = this->minutes < other.minutes;
                        if (this->minutes == other.minutes) {
                            isLess = this->seconds < other.seconds;
                        }
                    }
                }
            }
        }
        return isLess;
    }

    size_t getIndex() const {
        return id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t N;
    cin >> N;

    TimeStamp timeStamps[N];
    string time, date;
    for (int i = 0; i < N; ++i) {
        cin >> time;
        cin >> date;
        timeStamps[i].initialize(i + 1, time, date);
    }

    //!!!!!!!
    stable_sort(timeStamps, timeStamps + N);

    for (int i = 0; i < N; ++i) {
        cout << timeStamps[i].getIndex() << "\n";
    }
    return 0;
}
