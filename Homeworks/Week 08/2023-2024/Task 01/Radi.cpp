#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

#define llong long long

using namespace std;

struct Site
{
    llong X;
    llong Y;
    llong distance;

    bool operator<(const Site &other) const
    {
        return distance == other.distance ? (X == other.X ? Y > other.Y : X > other.X) : distance > other.distance;
    }
};

int main()
{
    llong X, Y, N, K;
    cin >> X >> Y >> N >> K;

    priority_queue<Site> pq;
    llong tempX, tempY;
    for (llong i = 0; i < N; i++)
    {
        cin >> tempX >> tempY;
        pq.push({tempX, tempY, (X - tempX) * (X - tempX) + (Y - tempY) * (Y - tempY)});
    }

    for (llong i = 0; i < K; i++)
    {
        Site temp = pq.top();
        pq.pop();
        cout << temp.X << " " << temp.Y << endl;
    }

    return 0;
}