	#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Refer to opencv documentation
int main(int argc, char const *argv[])
{
	//Mat image creation
	Mat a(100,100,CV_8UC3,Scalar(255,0,0));
	//storing green channel pixel intensity
	int x= a.at<Vec3b>(10,10)[1];
	cout << x << endl;
	//output

	//creating a window
	namedWindow("window1",WINDOW_NORMAL);
	imshow("window1",a);
	waitKey(2000);	
	return 0;
}