#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
size_t competitors[(size_t)1e5 + 2];

struct Player
{
    size_t strength;
    size_t kills;
};

stack<Player> players;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> competitors[i];
    }

    size_t maxKills = 0;
    players.push({competitors[0], 0});

    for (size_t i = 1; i < N; i++)
    {
        while (players.top().strength >= competitors[i])
        {
            size_t topKills = players.top().kills;
            players.pop();
            if (players.empty())
            {
                break;
            }
            players.top().kills = max(topKills, players.top().kills);
        }

        if (players.empty())
        {
            players.push({competitors[i], 0});
            continue;
        }

        players.top().kills += 1;
        maxKills = max(players.top().kills, maxKills);
        players.push({competitors[i], 0});
    }
    cout << maxKills;

    return 0;
}