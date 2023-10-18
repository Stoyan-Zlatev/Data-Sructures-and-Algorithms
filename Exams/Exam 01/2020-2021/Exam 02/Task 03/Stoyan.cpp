#include <bits/stdc++.h>

using namespace std;

struct Efficiency {
    double x, y;
    size_t index;

    double getEfficiency() const {
        return (x * x) / y;
    }

    bool operator<(const Efficiency &other) const {
        return getEfficiency() > other.getEfficiency() ||
               (getEfficiency() == other.getEfficiency() && this->x > other.x);
    }
};

int main() {
    size_t N;
    double first, second;
    cin >> N;

    vector<Efficiency> efficiency;
    for (size_t i = 0; i < N; ++i) {
        cin >> first >> second;
        efficiency.push_back({first, second, i + 1});
    }

    std::sort(efficiency.begin(), efficiency.end());
    for (const auto &element: efficiency) {
        cout << element.index << " ";
    }
    return 0;
}
