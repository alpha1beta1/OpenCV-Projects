#include "opencv2/opencv.hpp"
#include "stdint.h"

using namespace cv;
using namespace std;

int main(int argv, char** argc)
{
	Mat original = imread("sheep.jpg", CV_LOAD_IMAGE_COLOR);
	Mat modified = imread("sheep.jpg", CV_LOAD_IMAGE_COLOR);

	namedWindow("Original", CV_WINDOW_FREERATIO);
	namedWindow("Modified", CV_WINDOW_FREERATIO);

	for (int r = 0; r < modified.rows; r++)
	{
		for (int c = 0; c < modified.cols; c++)
		{
			modified.at<cv::Vec3b>(r, c)[0] *= 0.0f;
		}
	}


	imshow("Original", original);
	imshow("Modified", modified);
	waitKey();
	
}