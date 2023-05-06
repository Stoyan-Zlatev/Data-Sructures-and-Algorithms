#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

struct Dir {  
    std::string name;
    Dir* parent = nullptr;
    std::unordered_map<std::string, Dir*> children;
    
    ~Dir() {
        for (auto& kvp: children) {
            delete kvp.second;
        }
    }
};

void printChildren(const Dir* dir) {
    std::vector<std::string> names;
    for (auto& kvp: dir->children) {
        names.push_back(kvp.first);
    }
    std::sort(names.begin(), names.end());
    for(size_t j = 0; j < names.size(); j++){
        std::cout << names[j] << " ";    
    }
            
    std::cout << '\n';
}

void printAbsolutePath(const Dir* currentDir) {
    std::string result = "";
    while(currentDir->parent != nullptr){
        result = currentDir->name + "/" + result;
        currentDir = currentDir->parent;
    }
            
    result = "/" + result;
    std::cout << result << '\n';
}

void makeDir(Dir* currentDir) {
    std::string newDirName;
    std::cin >> newDirName;
    if(currentDir->children.find(newDirName) == currentDir->children.end()) {
        Dir* newDir = new Dir();
        newDir->name = newDirName;
        newDir->parent = currentDir;
        currentDir->children.insert({ newDir->name, newDir});
    }
    else {
        std::cout << "Directory already exists\n";
    }
}

void changeDir(Dir*& currentDir) {
    std::string dirName;
    std::cin >> dirName;
            
    if(dirName == "..") {
        if(currentDir->parent != nullptr) {
            currentDir = currentDir->parent;
        }
        else {
            std::cout << "No such directory\n";
        }
    }
    else { 
        if(currentDir->children.find(dirName) != currentDir->children.end()) {
            currentDir = currentDir->children[dirName];
        }
        else {
            std::cout << "No such directory\n";
        }
    }
}

void free(Dir* currentDir) {
    while(currentDir->parent != nullptr){
        currentDir = currentDir->parent;
    }
    
    delete currentDir;
}

int main() {
    size_t queries;
    std::cin >> queries;
    
    Dir* currentDir = new Dir();
    currentDir->name = "/";
    
    for(size_t i = 0; i < queries; i++) {
        std::string command;
        std::cin >> command;
        
        if(command == "ls") {
            printChildren(currentDir);
        }
        else if(command == "pwd") {
            printAbsolutePath(currentDir);
        }
        else if(command == "mkdir") {
            makeDir(currentDir);
        }
        else if(command == "cd") {
            changeDir(currentDir);
        }
    }
    
    free(currentDir);
    
    return 0;
}