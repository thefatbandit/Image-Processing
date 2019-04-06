#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
	Mat img=imread("samps/highcontrast.PNG",0);
	int rows=img.rows;
	int cols=img.cols;
	int arr[256]={};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[img.at<uchar>(i,j)]++;
		}
	}
	//max in array
	int max=arr[0];
	for (int i = 0; i < 256; i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	//scaling
	for (int i = 0; i < 256; i++)
	{
		arr[i]=arr[i]*250.0/max;
	}
	//making histogram
	Mat hist(256,256,CV_8UC1,Scalar(255));
	for (int j = 0; j < 256; j++)
	 {
	 	for (int i = 250-arr[j]; i < 250; i++)
	 	{
	 		hist.at<uchar>(i,j)=0;
	 	}
	 } 
	 namedWindow("histogram",WINDOW_NORMAL);
	 imshow("histogram",hist);
	 waitKey(2000);
}