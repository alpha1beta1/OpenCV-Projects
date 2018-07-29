#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace std;
using namespace cv;

int main(int argv, char** argc)
{
	Mat frame;

	VideoCapture vid("rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov");

	//namedWindow("WebCam", CV_WINDOW_AUTOSIZE);

	int fps = (int)vid.get(CV_CAP_PROP_FPS);

	if (!vid.isOpened())
	{
		return -1;

	}

	while (true)
	{
		vid.read(frame);
		imshow("Webcam", frame);

		if (waitKey(1000 / fps) >= 0)
			break;

	}

	return 1;

}