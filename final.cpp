#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main () {
	cv::VideoCapture cam = cv::VideoCapture(0);
	cv::Mat frame, frameBW, frameBWbright;
	cv::namedWindow(" Original ", CV_WINDOW_AUTOSIZE );
	cv::namedWindow(" Schwarzweiss ", CV_WINDOW_AUTOSIZE );
	cv::namedWindow(" Schwarzweiss-Hell ", CV_WINDOW_AUTOSIZE );
	int key = -1;
	while (1) {
		cam >> frame; //Kameradaten in frame schreiben
		imshow (" Original ", frame ); //Originalbild anzeigen
		//Graustufenbild Generieren
		int avg;
		for ( int i=0; i<frame.cols*frame.rows*3; i=i+3) {
			avg=(frame.data[i+0]+frame.data[i+0]+frame.data[i+0])/3;
			//if (avg>127) {avg=255;} else {avg=0;} //weglassen bei graustufen
			frame.data[i+0] = avg;
			frame.data[i+1] = avg;
			frame.data[i+2] = avg;
		}
		imshow (" Schwarzweiss ", frame );
		//Graustufenbild verstärken mit Faktor 2
		for (int i=0; i<frame.cols*frame.rows*3; i++) {
			if (frame.data[i]*2>255) { //Überlauf?
				frame.data[i]=255;
			} else {
				frame.data[i] = frame.data[i]*2;
			}
		}
		imshow (" Schwarzweiss-Hell ", frame );
		key = cv::waitKey (10); //Auf Taste warten
		if (key ==113) break;
	}
	cam.release();
	return 0;
}
