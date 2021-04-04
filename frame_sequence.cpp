#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

namespace BRGMAR044
{
    class FrameSequence
    {
    private:
        int frame_height, frame_width, x1, x2, y1, y2;
        std::vector<unsigned char **> ImageSequence;
        std::vector<std::vector<float>> PathCoords;
        void generatePathCoords(void);
        bool mustReverse;

    public:
        FrameSequence(void);
        void setFrameSize(int height, int width);
        void setCoords(int x1, int x2, int y1, int y2);
    };

    FrameSequence::FrameSequence(void)
    {
        mustReverse = false;
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
        std::cout<<x<<y;
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

        for (int i = 0; i < PathCoords.size(); ++i)
        {
            std::cout << PathCoords[i][0] << PathCoords[i][1] << "\n";
        }
    }

}