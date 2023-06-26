#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Color Detection  //////////////////////

	//////////// Draw Shapes and text ////////
void main() {
	
	// Blank Image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "Farhan's Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

	imshow("Image", img);
	waitKey(0);
}


	//void main() {

	//	string path = "Resources/lambo.png";
	//	Mat img = imread(path);
	//	Mat imgHSV, mask;
	//	int hmin = 0, smin = 110, vmin = 153;
	//	int hmax = 19, smax = 240, vmax = 255;

	//	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	//	namedWindow("Trackbars", (640, 200));
	//	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	//	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	//	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	//	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	//	createTrackbar("Val Min", "Trackbars", &hmin, 255);
	//	createTrackbar("Val Max","Trackbars", &hmin, 255);

	//	while (true) {

	//		Scalar lower(hmin, smin, vmin);
	//		Scalar upper(hmax, smax, vmax);
	//		inRange(imgHSV, lower, upper, mask);

	//		imshow("Image", img);
	//		imshow("Image HSV", imgHSV);
	//		imshow("Image Mask", mask);
	//		waitKey(1);

	//	}

	//}


///////////////  Video  //////////////////////

//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//	}
//}


/////////////////  Webcam  //////////////////////

//void main() {
//
//	VideoCapture cap(0);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(1);
//	}
//}