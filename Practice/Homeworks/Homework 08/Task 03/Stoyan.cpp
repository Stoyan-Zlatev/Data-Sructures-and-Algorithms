#include <bits/stdc++.h>

using namespace std;

struct Exam {
    size_t time, codeLines;

    bool operator<(const Exam &other) const {
        return this->codeLines > other.codeLines || (this->codeLines == other.codeLines && this->time < other.time);
    }

    bool operator>(const Exam &other) const {
        return this->time < other.time || (this->time == other.time && this->codeLines < other.codeLines);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N;
    cin >> N;
    vector<Exam> exams(N);
    for (size_t i = 0; i < N; i++) {
        cin >> exams[i].time >> exams[i].codeLines;
    }

    sort(exams.begin(), exams.end(), greater<Exam>());
    priority_queue<Exam, vector<Exam>, less<Exam>> queueExams;
    queueExams.push(exams[0]);
    size_t totalTime = 0;
    size_t currentTime = exams[0].time;
    size_t index = 1;
    for (size_t i = 0; i < N; i++) {
        while (index < N && exams[index].time <= currentTime) {
            queueExams.push(exams[index++]);
        }
        
        if (queueExams.empty()) {
            currentTime = exams[index].time;
            while (index < N && exams[index].time <= currentTime) {
                queueExams.push(exams[index++]);
            }
        } 
           
        totalTime += currentTime - queueExams.top().time + queueExams.top().codeLines;
        currentTime += queueExams.top().codeLines;
        queueExams.pop();
    }

    cout << totalTime / N;
    return 0;
}
