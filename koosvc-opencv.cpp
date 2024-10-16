#include <iostream>
#include <fstream>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/opencv-arch-01.png"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/1920-1080-240405.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample00.avi"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/sample.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/stopwatch.avi"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/stopwatch00.avi"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/rec_640_480_1_h265.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/rec_720_480_1_h265.mp4"
//#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/rec_1024_768_1_h265.mp4"
#define src_name "/mnt/sd2/code/hdal/samples/koosvc-opencv/rec_1920_1080_1_h265.mp4"

int main(void)
{

#if 0
	Mat img = imread(src_name, IMREAD_COLOR);

	CV_Assert(img.data);

	cout << "dims : " << img.dims << endl;
	cout << "rows : " << img.rows << endl;
	cout << "cols : " << img.cols << endl;
	cout << "size() : " << img.size() << endl;
	cout << "total() : " << img.total() << endl;
	cout << "elemSize() : " << img.elemSize() << endl;
	cout << "elemSize1() : " << img.elemSize1() << endl;
	cout << "type() : " << img.type() << endl;
	cout << "step : " << img.step << endl;
	cout << "step1() : " << img.step1() << endl;
	
	cout << "depth() : " << img.depth() << endl;
	cout << "channels() : " << img.channels() << endl;
#endif

#if 1	
	Mat frame, grey, fa, fb, fc;

	//Size frsz(1920, 1080); //FHD
	Size frsz(1280, 720); //HD
	//Size frsz(720, 480); //SD

	cout << "Built with OpenCV " << CV_VERSION << endl;

	VideoCapture cap(src_name);
	CV_Assert(cap.isOpened());

	if (!cap.isOpened()) {
		cerr << "Camera open failed" << endl;
		return -1;
	}

	double frame_rate = cap.get(CAP_PROP_FPS);
	cout << frame_rate << endl;

	
	while (true) {
		cap >> frame;

		if (frame.empty())  {
			cerr << endl << "Frame empty!" << endl;
			break;
		}
		cout << frame.cols << " * " << frame.rows << endl;
        	//Canny(frame, edge, 50, 150);

		//Setep1
		cvtColor(frame, grey, COLOR_RGB2GRAY);
		frame.release();

		//Step2
		resize(grey, fa, frsz);
		grey.release();

		//Step3
		fb = fa;
		fc = fa;

		cout << "fa : " << fa.cols << " * " << fa.rows << endl;
		cout << "fb : " << fb.cols << " * " << fb.rows << endl;
		cout << "fc : " << fc.cols << " * " << fc.rows << endl;

		//Step4
		fa.release();
		fb.release();
		fc.release();
	}

	cap.release();
#endif
	return 0;
}
