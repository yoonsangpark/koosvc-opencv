#include <iostream>
#include <fstream>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;

int main(void)
{
	cout << "Built with OpenCV " << CV_VERSION << endl;

	VideoCapture cap("sample.mp4");

	return 0;
}
