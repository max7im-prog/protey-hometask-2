#include "fileControl.hpp"
#include <filesystem>

FileControl::FileControl(std::string filepath)
{
    if (!std::filesystem::exists(filepath))
    {
        std::ofstream createFile(filepath);
        if (!createFile)
        {
            throw std::filesystem::filesystem_error("Failed to create file", filepath, std::make_error_code(std::errc::io_error));
        }
    }
    this->filepath = filepath;

    this->inFile.open(this->filepath);
    if (!this->inFile)
    {
        throw std::filesystem::filesystem_error("Failed to open file", filepath, std::make_error_code(std::errc::io_error));
    }
    this->reading = true;
}

FileControl::~FileControl()
{
    if (this->inFile.is_open())
        this->inFile.close();
    if (this->outFile.is_open())
        this->outFile.close();
}

std::string FileControl::readLine()
{
    if (!this->reading)
    {
        this->reading = true;
        if (this->outFile.is_open())
            this->outFile.close();
        this->inFile.open(this->filepath);
    }

    std::string line;
    if (std::getline(this->inFile, line))
    {
        return line;
    }
    else
    {
        if (this->atEOF())
        {
            throw std::runtime_error("Reached end of file");
        }
        else
        {
            throw std::runtime_error("Failed to read line");
        }
    }
}

void FileControl::writeLine(std::string s)
{
    if (this->reading)
    {
        this->reading = false;
        if (this->inFile.is_open())
            this->inFile.close();
        this->outFile.open(this->filepath, std::ios::app);
    }
    this->outFile << s << std::endl;
}

bool FileControl::atEOF()
{
    if (this->reading)
    {
        return this->inFile.eof();
    }
    else
    {
        return this->outFile.eof();
    }
}
