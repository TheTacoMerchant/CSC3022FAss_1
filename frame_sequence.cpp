#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "header.h"

namespace BRGMAR044
{

    FrameSequence::FrameSequence(void)
    {
        mustReverse = false;
    }

    FrameSequence::~FrameSequence()
    {
        for (int i = 0; i< large_height;++i){
            delete LargeImage[i];
        }
        delete LargeImage;
    }

    void FrameSequence::setFrameSize(int height, int width)
    {
        frame_height = height;
        frame_width = width;
    }

    void FrameSequence::setCoords(int x1in, int x2in, int y1in, int y2in)
    {
        if (x1in > x2in)
        {
            x1 = x2in;
            x2 = x1in;
            y1 = y2in;
            y2 = y1in;
            if (mustReverse)
            {
                mustReverse = false;
            }
            else
            {
                mustReverse = true;
            }
        }
        else
        {
            x1 = x1in;
            x2 = x2in;
            y1 = y1in;
            y2 = y2in;
        }
        generatePathCoords();
    }

    void FrameSequence::generatePathCoords(void)
    {
        float dx, dy, x, y;
        float g;
        x = float(x1);
        y = float(y1);
        PathCoords.push_back(std::vector<float>{x, y});

        dx = x2 - x1;
        dy = y2 - y1;
        if (dy > dx)
        {
            g = dx / dy;
            for (y = y1 + 1; y <= dy; ++y)
            {
                x += g;
                PathCoords.push_back(std::vector<float>{std::round(x), y});
            }
        }
        else
        {
            g = dy / dx;
            for (x = x1 + 1; x <= dx; ++x)
            {
                y += g;
                PathCoords.push_back(std::vector<float>{x, std::round(y)});
            }
        }

        if (mustReverse)
        {
            std::reverse(PathCoords.begin(), PathCoords.end());
        }
        //TODO Delete this
        for (int i = 0; i < PathCoords.size(); ++i)
        {
            //std::cout << PathCoords[i][0] << PathCoords[i][1] << "\n";
        }
    }

    void FrameSequence::addCommand(std::string type, std::string filename)
    {
        Commands.push_back(std::vector<std::string>{type, filename});
    }

    void FrameSequence::parsePGM(std::string filename)
    {
        std::ifstream infile(filename, std::ios::binary);
        int row, col, maxval;
        std::string inputString;
        float value;

        std::getline(infile, inputString);
        std::getline(infile, inputString);
        infile >> large_width >> large_height >> std::ws;
        infile >> maxval;

        char *buffer = new char[(large_height * large_width) + 1];
        infile.read(buffer, (large_width*large_height)+1);

        LargeImage = new unsigned char*[large_height];
        for (int i = 0; i<large_height;++i){
            LargeImage[i] = new unsigned char[large_width];
            for (int j = 0; j<large_width;++j){
                LargeImage[i][j] = (unsigned char)(buffer[i*large_width + j + 1]);
            }
        }

        delete buffer;


        for (row = 0; row < 10; ++row)
        {
            for (col = 0; col < 10; ++col)
            {
                std::cout << int(LargeImage[row][col]) << " ";
            }
            std::cout << std::endl;
        }
    }

}