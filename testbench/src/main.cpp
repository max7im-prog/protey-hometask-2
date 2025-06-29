#include <iostream>
#include <filesystem>

#include "fileControl.hpp"

int main(int argc, char const *argv[])
{
    bool running = true;

    const std::string baseName = "tempFile";
    const std::string dirName = "temp";
    std::string filepath;

    // Open directory
    std::filesystem::create_directory(dirName);
    for (int i = 0, foundPath = 0; foundPath != 1; i++)
    {
        filepath = dirName + "/" + baseName + std::to_string(i) + ".txt";
        if (!std::filesystem::exists(filepath))
        {
            foundPath = 1;
        }
    }

    FileControl fc(filepath);

    // Input
    running = true;
    while (running)
    {
        std::string input;
        std::cout << "Next line(type q to exit): ";
        std::getline(std::cin, input);
        if (input != "q")
        {
            fc.writeLine(input);
        }
        else
        {
            running = false;
        }
    }

    // Output
    running = true;
    while (running)
    {
        std::string output;
        try
        {
            output = fc.readLine();
            std::cout << output << std::endl;
        }
        catch (std::runtime_error e)
        {
            running = false;
        }
    }

    return 0;
}
