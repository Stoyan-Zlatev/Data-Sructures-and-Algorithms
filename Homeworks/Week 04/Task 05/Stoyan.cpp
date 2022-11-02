#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct Ball {
    size_t color;
    size_t index;

    Ball(size_t color, size_t index) {
        this->color = color;
        this->index = index;
    }
};

void printList(const list<Ball> &balls) {
    for (auto i = balls.begin(); i != balls.end(); ++i) {
        cout << i->color << " ";
    }
}

void checkSequence(list<Ball> &balls, list<Ball>::iterator currentIterator, size_t &target, size_t &destroyed) {
    list<Ball>::iterator left = currentIterator;
    list<Ball>::iterator right = ++currentIterator;
    list<Ball>::iterator leftBorder, rightBorder;

    vector<list<Ball>::iterator> iteratorsToDelete;
    size_t sequenceCount = 0;
    for (leftBorder = left; leftBorder->color == target; leftBorder--) {
        iteratorsToDelete.push_back(leftBorder);
    }

    for (rightBorder = right; rightBorder->color == target; rightBorder++) {
        iteratorsToDelete.push_back(rightBorder);
    }

    if (iteratorsToDelete.size() >= 3) {
        destroyed += iteratorsToDelete.size();
        for (auto iteratorToDelete : iteratorsToDelete) {
            balls.erase(iteratorToDelete);
        }

        if (balls.empty()) {
            return;
        }
        if (leftBorder->color == rightBorder->color) {
            checkSequence(balls, leftBorder, leftBorder->color, destroyed);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    list<Ball> balls;
    size_t N, ball;
    cin >> N;
    vector<list<Ball>::iterator> ballIterators;
    for (int i = 0; i < N; ++i) {
        cin >> ball;
        balls.push_back(Ball(ball, i));
        ballIterators.push_back(prev(balls.end()));
    }

    size_t Q;
    cin >> Q;
    size_t Pi, Ci;
    for (int i = 0; i < Q; ++i) {
        cin >> Ci >> Pi;
        if (balls.empty()) {
            cout << "Game Over" << endl;
        } else {
            size_t destroyed = 0;
            auto newBallIterator = balls.insert(next(ballIterators[Ci]), Ball(Pi, N + i));
            ballIterators.push_back(newBallIterator);
            checkSequence(balls, newBallIterator, Pi, destroyed);
            cout << destroyed << endl;
        }
    }

    if (!balls.empty()) {
        printList(balls);
    } else {
        cout << "-1";
    }

    return 0;
}
