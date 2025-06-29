#pragma once
#include <string>
#include <fstream>

class FileControl{
public:
    FileControl(std::string filepath);
    ~FileControl();
    std::string readLine();
    void writeLine(std::string s);
    bool atEOF();
private:
    std::string filepath;
    std::ifstream inFile;
    std::ofstream outFile;
    bool reading = true;
};