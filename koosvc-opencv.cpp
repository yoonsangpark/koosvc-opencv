#include <iostream>
#include <fstream>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;


//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/opencv-arch-01.png"
#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/1920-1080-240405.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample.avi"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/stopwatch.avi"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/stopwatch01.avi"

int main(void)
{
	Mat frame, edge;

	cout << "Built with OpenCV " << CV_VERSION << endl;

	VideoCapture cap(src_name);
	CV_Assert(cap.isOpened());

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
