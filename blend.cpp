#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat pik=imread("samps/pikachu.jpg",1);
	Mat mew=imread("samps/Mew.jpg",1);
	Mat fimg(pik.rows,pik.cols,CV_8UC3,Scalar(0,0,0));
	int th=0;
	namedWindow("Image",WINDOW_NORMAL);
	createTrackbar("Threshold","Image",&th,100);
	while(1)
	{
		for (int i = 0; i < pik.rows; i++)
		{
			for (int j = 0; j < pik.cols; j++)
			{
				fimg.at<Vec3b>(i,j)=(mew.at<Vec3b>(i,j)*(th/100.0)) 
				  + (pik.at<Vec3b>(i,j)*(1-th/100.0));
			}
		}
		imshow("Image",fimg);
		waitKey(1);
	}
}