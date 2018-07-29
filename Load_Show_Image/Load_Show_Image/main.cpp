#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argv, char** argc)
{
	Mat testColor = imread("girl.jpg", CV_LOAD_IMAGE_COLOR);

	Mat testGray = imread("girl.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	imshow("color", testColor);
	imshow("gray", testGray);

	imwrite("outputGray.jpg", testGray);

	waitKey();
}