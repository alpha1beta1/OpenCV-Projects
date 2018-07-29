#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;


void takeDFT(Mat& source, Mat& destination)
{
	Mat originalComplex[2] = { source, Mat::zeros(source.size(), CV_32F) };

	Mat dftReady;

	merge(originalComplex, 2, dftReady);

	Mat dftOfOriginal;

	dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);

	destination = dftOfOriginal;

}


void recenterDFT(Mat& source)
{
	int centerX = source.cols / 2;
	int centerY = source.rows / 2;

	Mat q1(source, Rect(0, 0, centerX, centerY));
	Mat q2(source, Rect(centerX, 0, centerX, centerY));
	Mat q3(source, Rect(0, centerY, centerX, centerY));
	Mat q4(source, Rect(centerX, centerY, centerX, centerY));

	Mat swapMap;

	q1.copyTo(swapMap);
	q4.copyTo(q1);
	swapMap.copyTo(q4);

	q2.copyTo(swapMap);
	q3.copyTo(q2);
	swapMap.copyTo(q3);

}

void showDFT(Mat& source)
{
	Mat splitArray[2] = { Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F) };

	split(source, splitArray);

	Mat dftMagnitude;

	magnitude(splitArray[0], splitArray[1], dftMagnitude);

	dftMagnitude += Scalar::all(1);

	log(dftMagnitude, dftMagnitude);

	normalize(dftMagnitude, dftMagnitude, 0, 1, CV_MINMAX);

	recenterDFT(dftMagnitude);


}

void invertDFT(Mat& source, Mat& destination)
{
	Mat inverse;

	dft(source, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);

	destination = inverse;

}


void createGaussian(const Size& size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude = 1.0f)
{
	Mat temp = Mat(size, CV_32F);

	for (int r=0;r<size.height;r++)
	{
		for (int c=0;c<size.width;c++)
		{
			float x = ((c - uX)*((float)c - uX)) / (2.0f*sigmaX*sigmaX);
			float y = ((r - uY)*((float)r - uY)) / (2.0f*sigmaY*sigmaY);
			float value = amplitude * exp(-(x + y));
			temp.at<float>(r, c) = value;

		}
	}

	normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX);
	output = temp;
}

int main(int argv, char** argc)
{
	Mat output;
	createGaussian(Size(256, 256), output, 256 / 2, 256 / 2, 10, 10);
	imshow("Gaussian", output);
	waitKey();

}