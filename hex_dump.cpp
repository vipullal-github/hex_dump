#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

int hex_dump(std::string fileName)
{
    std::ifstream inputStream(fileName, std::ios::binary);
    if (!inputStream.is_open())
    {
        std::cerr << "Could not open file for reading in binary mode";
        return -1;
    }
    std::cout << "Hex dump of file :" << fileName << std::endl;
    char aByte;
    int bytesPerLine = 32;
    int currentByte = 0;
    char buffer[bytesPerLine + 1] = {0};
    while (inputStream.get(aByte))
    {
        if (isprint(aByte))
        {
            buffer[currentByte] = aByte;
        }
        else
        {
            buffer[currentByte] = '.';
        }
        unsigned intValue = (unsigned char)aByte;
        // print the hex value:
        std::cout << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << intValue << ' ';

        if (++currentByte >= bytesPerLine)
        {
            buffer[currentByte] = 0;
            std::cout << buffer << std::endl;
            currentByte = 0;
        }
    }
    // print the last few bytes in the buffer...
    while (currentByte < bytesPerLine)
    {
        buffer[currentByte++] = ' ';
    }
    buffer[currentByte] = 0;
    std::cout << buffer << std::endl;

    std::cout << std::endl;
    return 0;
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cout << "Usage hex_dump filename " << std::endl;
    }
    hex_dump(std::string("a.out"));
}