#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////// project1 /////////////////////////
Mat img;
vector<vector<int>> newPoints;


// <<smin, vmin, hmax, smax, vmax;
//vector<vector<int>> myColors{ {19,151,0,71,255,255}, //white
//								{ 66,95,14,155,217,139 }, //black
//									{89, 161, 0, 112, 255, 255}	}; //green olive
//
//vector<Scalar> myColorValues{ {92, 78, 58}, //White
//	{ 30,30,30 }, //Black
//	{ 188, 228, 167 }}; //Green Olive
vector<vector<int>> myColors{ {84, 50, 2, 179, 206, 85}, //black
								{ 78,47,0,100,255,255 },
									{ 0,0,5,179,187,62 }}; //Silver

vector<Scalar> myColorValues{ {0, 0, 0}, //black
								{ 27, 91, 110 }}; //cyan


///////////////  Color Detection  //////////////////////

Point getContours(Mat imgDil) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2; 
			myPoint.y = boundRect[i].y;
						
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			
		}
	}
	return myPoint;
}


void findColor(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);


	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x,myPoint.y,1 });
		}
	}
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues)
{

	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(img, (Point(newPoints[i][0]), Point(newPoints[i][1])), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}
  

void main() {

	VideoCapture cap(0);

	while (true) {

		cap.read(img);
		findColor(img);

		imshow("Image", img);
		waitKey(1);

	}
}