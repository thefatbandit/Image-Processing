#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	Mat img=imread("samps/testim.png",1);
	int rows=img.rows;
	int cols=img.cols;
	Mat a(rows,cols*2+5,CV_8UC3,Scalar(0,0,0));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			a.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j =0; j < cols; j++)
		{
			a.at<Vec3b>(i,(cols*2+5)-j-1)=img.at<Vec3b>(i,j);
		}
	}
	namedWindow("image",WINDOW_NORMAL);
	imshow("image",a);
	waitKey(2000);
}