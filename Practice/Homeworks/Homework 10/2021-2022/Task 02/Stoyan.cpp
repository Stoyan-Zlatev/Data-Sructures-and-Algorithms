#include <bits/stdc++.h>

using namespace std;

unordered_map<size_t, unordered_map<size_t, bool>> visited;

struct Student {
    size_t row, col;
};

bool validate(const Student &student, size_t rows, size_t cols) {
    return 0 <= student.row && student.row < rows && 0 <= student.col &&
           student.col < cols;
}

int main() {
    size_t rows, cols, T, K, row, col;
    cin >> rows >> cols >> T >> K;

    deque<Student> illStudents;
    size_t illCounter = 0;
    for (size_t i = 0; i < K; ++i) {
        cin >> row >> col;
        illStudents.push_back(Student({--row, --col}));
        visited[row][col] = true;
        ++illCounter;
    }

    for (size_t i = 0; i < T; ++i) {
        size_t illStudentsNow = illStudents.size();
        for (size_t j = 0; j < illStudentsNow; ++j) {
            Student illStudent = illStudents.front();

            for (const Student &student: {
                    Student{illStudent.row - 1, illStudent.col},
                    Student{illStudent.row + 1, illStudent.col},
                    Student{illStudent.row, illStudent.col - 1},
                    Student{illStudent.row, illStudent.col + 1}
            }) {
                if (validate(student, rows, cols) && !visited[student.row][student.col]) {
                    illStudents.push_back(student);
                    visited[student.row][student.col] = true;
                    illCounter++;
                }
            }

            illStudents.pop_front();
        }
    }

    cout << rows * cols - illCounter;
    return 0;
}
