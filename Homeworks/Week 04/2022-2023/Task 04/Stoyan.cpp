#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int containsPacket[1000001];

    size_t T, N, packet;
    std::cin >> T >> N;
    std::list<size_t> packets;
    size_t size = 0;
    for (size_t i = 0; i < T; i++) {
        std::cin >> packet;
        if (!containsPacket[packet]) {
            std::cout << "false" << "\n";
            if (size < N) {
                containsPacket[packet] = 1;
                packets.push_front(packet);
                size++;
            } else {
                while (size >= N) {
                    if (containsPacket[packets.back()] == 1) {
                        containsPacket[packets.back()]--;
                        packets.pop_back();
                        size--;
                        break;
                    }
                    containsPacket[packets.back()]--;
                    packets.pop_back();
                }
                containsPacket[packet] = 1;
                packets.push_front(packet);
                size++;
            }

        } else {
            containsPacket[packet]++;
            std::cout << "true" << "\n";
            packets.push_front(packet);
        }

    }

    return 0;
}
