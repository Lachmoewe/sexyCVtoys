#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main () {
	cv::VideoCapture cam = cv::VideoCapture(0);
	cv::Mat frame1, frame2;
	cv::namedWindow(" Demo1 ", CV_WINDOW_AUTOSIZE );
	cv::namedWindow(" Demo2 ", CV_WINDOW_AUTOSIZE );
	//cv::namedWindow(" Demo3 ", CV_WINDOW_AUTOSIZE );
	int key = -1;
	while (1) {
		cam >> frame1;
		cv::medianBlur(frame1,frame2,15);
		imshow (" Demo1 ", frame1 );
		imshow (" Demo2 ", frame2 );
		//imshow (" Demo3 ", frame );
		key = cv::waitKey (10);
		if (key ==113) break;
	}
	cam.release();
	return 0;
}
