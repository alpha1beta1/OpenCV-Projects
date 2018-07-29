#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	Mat file1 = imread("sheep.jpg", CV_LOAD_IMAGE_UNCHANGED);
	Mat file2 = imread("sheep.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	namedWindow("Color", CV_WINDOW_FREERATIO);
	namedWindow("Fixed", CV_WINDOW_AUTOSIZE);

	imshow("Color", file1);
	imshow("Fixed", file2);
	
	//resizeWindow("Color", file1.cols/2, file1.rows/2);
	//resizeWindow("Fixed", file2.cols/2, file1.rows/2);

	moveWindow("Color", 1600, 800);
	moveWindow("Fixed", 1600 + file1.cols + 5, 800);



	waitKey();
}