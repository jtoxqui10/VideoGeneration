#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>
#include <cstring>
#include "global.h"
#include "frame.h"
#include "rectangle.h"

Frame frame;
int main(int argc, char * argv[]) {
	const char * cmd =
		"ffmpeg		     "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " 
		"-pixel_format rgb24 "
		"-video_size 720x480 "
		"-r 60               " 
		"-i -                " 
		"-pix_fmt yuv420p    " 
		"-vcodec mpeg4       "
		"-an                 " 
		"-q:v 5              " 
		"output.mp4          ";

#ifdef _WIN32
	FILE * pipe = _popen(cmd, "wb");
#else
	FILE * pipe = popen(cmd, "w");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << std::endl;
		return 1;
	}

	Rectangle rec1 (55, 100, 200, 0);
	rec1.setVelocity(10, 10); 

	Rectangle rec2 (40, 155, 0, 0);
	rec2.setVelocity(10, 10); 

	Rectangle rec3(30, 60, 0, 0);
	rec2.setVelocity(10, 10);

	int num_frames = duration_in_seconds * frames_per_second;
	for (int i = 0; i < num_frames; ++i) {
		double dt = i / frames_per_second;
		if (dt > 1.0 / 60.0) {
			rec1.setColor(0, 0, 255); 
			rec1.update(dt); 
			rec1.draw(); 

			rec2.setColor(0, 255, 0); 
			rec2.update(dt);
			rec2.draw();

			rec3.setColor(255, 0, 0); 
			rec3.update(dt);
			rec3.draw();


			frame.write(pipe); 
			frame.clear();
		}
	}

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
	std::cout << "num_frames: " << num_frames << std::endl;
	std::cout << "Done." << std::endl;
	return 0;
}
