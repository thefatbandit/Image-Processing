#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	//reading image
	Mat img= imread("samps/fruits.png",1);
	img.at<Vec3b>(25,25)[0]=10;
	// cout << x << endl;
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",img);
	waitKey(2000);
	return 0;
}