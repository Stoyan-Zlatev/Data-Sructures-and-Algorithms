#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct Packet {
    bool isDownloaded;
    list<size_t>::iterator it;

    Packet() {
        isDownloaded = false;
    }

    Packet(bool isDownloaded, list<size_t>::iterator it) : isDownloaded(isDownloaded), it(it) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t T, N;
    cin >> T >> N;
    Packet isPacket[100001];
    list<size_t> packets;
    size_t packet;
    for (size_t i = 0; i < T; i++) {
        cin >> packet;
        if (packets.size() < N) {
            if (isPacket[packet].isDownloaded) {
                cout << "true" << endl;
                packets.erase(isPacket[packet].it);
            } else {
                cout << "false" << endl;
            }
            isPacket[packet] = Packet(true, packets.insert(packets.begin(), packet));
        } else {
            if (isPacket[packet].isDownloaded) {
                cout << "true" << endl;
                packets.erase(isPacket[packet].it);
                isPacket[packet] = Packet(true, packets.insert(packets.begin(), packet));
            } else {
                cout << "false" << endl;
                isPacket[packets.back()] = Packet();
                packets.pop_back();
                isPacket[packet] = Packet(true, packets.insert(packets.begin(), packet));
            }
        }
    }

    return 0;
}
