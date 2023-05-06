#include <iostream>
#include <set>

int main() {
    int boardLength, shipsCount, shipSize;
    std::cin >> boardLength >> shipsCount >> shipSize;
    std::set<int> shotAtIndexes;
    shotAtIndexes.insert(0);
    shotAtIndexes.insert(boardLength + 1);

    int shotsCount;
    std::cin >> shotsCount;
    int liedAtShot = -1;

    int possibleShipsAtIteration = (boardLength + 1) / (shipSize + 1);

    for (int i = 1; i <= shotsCount; i++) {
        int currentIndex;
        std::cin >> currentIndex;

        auto firstLower = shotAtIndexes.lower_bound(currentIndex);
        firstLower--;
        auto firstHigher = shotAtIndexes.upper_bound(currentIndex);
        shotAtIndexes.insert(currentIndex);

        int possibleShips = possibleShipsAtIteration;

        possibleShips -= ((*firstHigher - *firstLower) / (shipSize + 1));
        possibleShips += ((currentIndex - *firstLower) / (shipSize + 1));
        possibleShips += ((*firstHigher - currentIndex) / (shipSize + 1));

        possibleShipsAtIteration = possibleShips;

        if (possibleShips < shipsCount) {
            liedAtShot = i;
            break;
        }

    }

    std::cout << liedAtShot;

    return 0;
}