#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
 
int Isvalid(int x,int y,int rows,int cols)
{
	if (x<0||y<0||x>=rows||y>=cols)
	{
		return 0;
	}
	return 1;
}

int fill(int x,int y,int var)
{
	Mat img=imread("samps/veg.jpg",0);
	int sum=0, val=1;
	
}


int main()
{
 	Mat img=imread("samps/veg.jpg",1);
	namedWindow("image",WINDOW_NORMAL);
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			img.at<Vec3b>(i,j)=fill(i,j)
		}
	}
}