#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct StudentData {
    string name;
    size_t grade;

    bool operator<(const StudentData& other) const{
        return this->grade > other.grade || (this->grade == other.grade && this->name < other.name);
    }
};

int main() {
    size_t N;
    cin >> N;

    StudentData students[N];
    for (size_t i = 0; i < N; i++) {
        cin >> students[i].name;
    }

    for (size_t i = 0; i < N; i++) {
        cin >> students[i].grade;
    }

    sort(students, students + N);

    for (int i = 0; i < N; ++i) {
        cout << students[i].name << " " << students[i].grade << '\n';
    }

    return 0;
}
