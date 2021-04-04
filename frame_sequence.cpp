#include <vector>

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

FrameSequence::FrameSequence(void){

}

void FrameSequence::setFrameSize(int height, int width){
    frame_height = height;
    frame_width = width;
}

void setCoords(int x1, int x2, int y1, int y2){
    x1 = x1;
    y1 = y1;
    x2 = x2;
    y2 = y2;
}

}