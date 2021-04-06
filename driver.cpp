#include "header.h"
#include "iostream"
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
    BRGMAR044::FrameSequence myFrames;

    for (int i = 0; i<argc;++i){
        if (std::string(argv[i]) == "-t"){
            myFrames.setCoords(std::atoi(argv[i+1]),std::atoi(argv[i+3]),std::atoi(argv[i+2]),std::atoi(argv[i+4]));
        }
        if (std::string(argv[i]) == "-s"){
            myFrames.setFrameSize(std::atoi(argv[i+1]),std::atoi(argv[i+2]));
        }
        if (std::string(argv[i]) == "-w"){
            myFrames.addCommand(argv[i+1], argv[i+2]);
        }
        
    }
    myFrames.parsePGM(argv[1]);

    return 0;
}