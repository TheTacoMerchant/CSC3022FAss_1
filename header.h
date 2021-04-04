#include <vector>
#ifndef _H
#define _H
namespace BRGMAR044{
class FrameSequence{
    private:
        int frame_height, frame_width, x1, x2, y1, y2;
        std::vector<unsigned char **> ImageSequence;
    public:
        FrameSequence(void);
        void setFrameSize(int height, int width);
        void setCoords(int x1, int x2, int y1, int y2);

};
}
#endif