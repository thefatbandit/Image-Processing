#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Arnesh Kumar Issar
int main(int argc, char const *argv[])
{
	Mat img= imread("/home/arnesh/IP/samps/joker.jpg",1);
	int cols=img.cols;
	int rows=img.rows;
	int b=0;
	namedWindow("Image",WINDOW_NORMAL);
	createTrackbar("Brightness","Image",&b,255);
	Mat a (rows,cols,CV_8UC3,Scalar(0,0,0));
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			int ib= img.at<Vec3b>(i,j)[0];
			int ig= img.at<Vec3b>(i,j)[1];
			int ir= img.at<Vec3b>(i,j)[2];
			if (a.at<Vec3b>(i,j)[0]==255)
				{
					a.at<Vec3b>(i,j)=[255,ig+b,ir+b];		
				}	
			if (a.at<Vec3b>(i,j)[1]==255)
				{
					
				}	
			if (a.at<Vec3b>(i,j)[0]==255)
				{
					
				}	
			else:			
						}
	}
}