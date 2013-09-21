#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main () {
	cv::VideoCapture cam = cv::VideoCapture(0);
	cv::Mat frame;
	cv::namedWindow(" Demo ", CV_WINDOW_AUTOSIZE );
	int key = -1;
	while (1) {
		cam >> frame;
		cv::medianBlur(frame,frame,15);
		imshow (" Demo ", frame );
		key = cv::waitKey (10);
		if (key ==113) break;
	}
	cam.release();
	return 0;
}
