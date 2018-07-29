#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argv, char** argc)
{
	Mat original = imread("sheep.jpg", CV_LOAD_IMAGE_COLOR);

	Mat splitChannels[3];

	split(original, splitChannels);

	imshow("B", splitChannels[0]);
	imshow("G", splitChannels[1]);
	imshow("R", splitChannels[2]);
	

	splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);

	Mat output;

	merge(splitChannels, 3, output);
	imshow("Merged", output);
	waitKey();
}