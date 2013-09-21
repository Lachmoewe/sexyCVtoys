#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main () {
	cv::VideoCapture cam = cv::VideoCapture(0);
	cv::Mat frame;
	cv::namedWindow(" Demo ", CV_WINDOW_AUTOSIZE );
	int key = -1;
	while (1) {
		cam >> frame;
		for ( int i=0; i<frame.cols*frame.rows*3; i++) {
			frame.data[i] = frame.data[i]*2;//causes Bufferoverflow when Input > 127
		}

		imshow (" Demo ", frame );
		key = cv::waitKey (10);
		if (key ==113) break;
	}
	cam.release();
	return 0;
}
