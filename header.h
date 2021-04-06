#include <vector>
#include <string>

#ifndef _H
#define _H
namespace BRGMAR044{
class FrameSequence
    {
    private:
        int frame_height, frame_width, x1, x2, y1, y2, large_height, large_width;
        std::vector<unsigned char **> ImageSequence;
        unsigned char **LargeImage;
        std::vector<std::vector<float>> PathCoords;
        std::vector<std::vector<std::string>> Commands;
        void generatePathCoords(void);
        bool mustReverse;

    public:
        FrameSequence(void);
        ~FrameSequence();
        void setFrameSize(int height, int width);
        void setCoords(int x1, int x2, int y1, int y2);
        void addCommand(std::string type, std::string filename);
        void parsePGM(std::string filename);
        void extractFrames();
        void executeCommands();
        void exportFrames(std::string filename);
    };
}
#endif