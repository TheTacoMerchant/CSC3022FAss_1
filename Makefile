driver: driver.cpp header.h frame_sequence.cpp
	g++ frame_sequence.cpp header.h driver.cpp -o driver

clean:
	rm -f driver