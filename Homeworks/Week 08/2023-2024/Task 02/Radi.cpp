#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Guest
{
    size_t arrival;
    size_t departure;
    size_t index;
    size_t seat;

    bool operator<(const Guest &other) const
    {
        return arrival > other.arrival;
    }

    bool operator>(const Guest &other) const
    {
        return departure > other.departure;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t N, arrival, departure, T;
    cin >> N;
    priority_queue<Guest, vector<Guest>, less<Guest>> arrivals;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arrival >> departure;
        arrivals.push({arrival, departure, i, 0});
    }
    cin >> T;

    priority_queue<size_t, vector<size_t>, greater<size_t>> freeSeats;
    for (size_t i = 0; i < N; i++)
    {
        freeSeats.push(i);
    }

    priority_queue<Guest, vector<Guest>, greater<Guest>> departures;
    while (!arrivals.empty())
    {
        while (!departures.empty() && departures.top().departure <= arrivals.top().arrival)
        {
            freeSeats.push(departures.top().seat);
            departures.pop();
        }
        Guest temp = arrivals.top();
        arrivals.pop();
        temp.seat = freeSeats.top();
        freeSeats.pop();
        departures.push(temp);

        if (temp.index == T)
        {
            cout << temp.seat;
            break;
        }
    }

    return 0;
}