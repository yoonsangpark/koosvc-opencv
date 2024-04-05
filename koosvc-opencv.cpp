#include <iostream>
#include <fstream>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;


//#define mp4_filename "/mnt/sd2/code/hdal/samples/koosvc-opencv/1920-1080-240405.mp4"
//#define mp4_filename "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample.avi"
//#define mp4_filename "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample.mp4"
#define mp4_filename "/mnt/sd2/code/hdal/samples/koosvc-opencv/stopwatch.avi"

int main(void)
{
	Mat frame, edge;

	cout << "Built with OpenCV " << CV_VERSION << endl;

	VideoCapture cap(mp4_filename);

	if (!cap.isOpened()) {
		cerr << "Camera open failed" << endl;
		return -1;
	}

	
	while (true) {
		cap >> frame;

		if (frame.empty()) {
			cerr << "Frame empty!" << endl;
			break;
		}

        	Canny(frame, edge, 50, 150);

	}

	cap.release();

	return 0;
}
