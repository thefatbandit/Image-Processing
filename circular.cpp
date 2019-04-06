#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
using namespace std;
using namespace cv;

int main()
{
	Mat a=imread("Binary1.png",1);
	Mat b(a.rows*2,a.cols*2,CV_8UC3,Scalar(255,255,255));

	float theta=30*3.14159/180;
	for(int i=0;i<a.rows;i++)
	{
		for(int j=0;j<a.cols;j++)
		{
			int i2=(i-a.rows/2)*cos(theta)+(j-a.cols/2)*sin(theta);
			int j2=(j-a.cols/2)*cos(theta)-(i-a.rows/2)*sin(theta);
			//if(i2<0||i2>=a.rows||j2<0||j2>=a.cols)
			//	continue;
			b.at<Vec3b>(i2+a.rows/2,j2+a.cols/2)=a.at<Vec3b>(i,j);
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",b);
	waitKey(50000);
}