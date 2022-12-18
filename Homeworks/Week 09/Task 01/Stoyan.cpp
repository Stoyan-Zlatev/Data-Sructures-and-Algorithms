#include <bits/stdc++.h>

using namespace std;

const string MKDIR = "mkdir";
const string CD = "cd";
const string LS = "ls";
const string PWD = "pwd";
unordered_map<string, pair<string, set<string>>> directories;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string currentDirectory = "/";
    directories.insert({currentDirectory, {"", {}}});
    size_t N;
    cin >> N;

    string command, directoryName;
    for (size_t i = 0; i < N; ++i) {
        cin >> command;
        directoryName = "";
        if (command == MKDIR) {
            cin >> directoryName;
            if (std::find(directories[currentDirectory].second.begin(), directories[currentDirectory].second.end(),
                          directoryName) == directories[currentDirectory].second.end()) {
                directories.insert({currentDirectory + directoryName + "/", {currentDirectory, {}}});
                directories[currentDirectory].second.insert(directoryName);
            } else {
                cout << "Directory already exists\n";
            }
        } else if (command == CD) {
            cin >> directoryName;
            if (directoryName == "..") {
                if (currentDirectory != "/") {
                    currentDirectory = directories[currentDirectory].first;
                } else {
                    cout << "No such directory\n";
                }
            } else if (
                    std::find(directories[currentDirectory].second.begin(), directories[currentDirectory].second.end(),
                              directoryName) != directories[currentDirectory].second.end()) {
                currentDirectory += directoryName;
                currentDirectory += "/";
            } else {
                cout << "No such directory\n";
            }

        } else if (command == LS) {
            for (const string &directory: directories[currentDirectory].second) {
                cout << directory << " ";
            }
            cout << '\n';
        } else if (command == PWD) {
            cout << currentDirectory << "\n";
        }
    }

    return 0;
}
