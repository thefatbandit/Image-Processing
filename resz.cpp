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
	//Compressing Image (1/2 size)
	Mat a((rows/2),(cols/2),CV_8UC3,Scalar(0,0,0));
	for (int j = 0; j < cols;j=j+2)
	{
		for (int i = 0; i < cols; i=i+2)
		{
			//a.at<Vec3b>(i/2,j/2)= (((img.at<Vec3b>(i,j)) + (img.at<Vec3b>(i+1,j)) + (img.at<Vec3b>(i,j+1)) + (img.at<Vec3b>(i+1,j+1)))/4);
			
			/*int ib= finI( (img.at<Vec3b>(i,j)[0]) , (img.at<Vec3b>(i+1,j)[0]) , (img.at<Vec3b>(i,j+1)[0]) , (img.at<Vec3b>(i+1,j+1)[0]) );
			int ig= finI( (img.at<Vec3b>(i,j)[1]) , (img.at<Vec3b>(i+1,j)[1]) , (img.at<Vec3b>(i,j+1)[1]) , (img.at<Vec3b>(i+1,j+1)[1]) );
			int ir= finI( (img.at<Vec3b>(i,j)[2]) , (img.at<Vec3b>(i+1,j)[2]) , (img.at<Vec3b>(i,j+1)[2]) , (img.at<Vec3b>(i+1,j+1)[2]) );
			a.at<Vec3b>(i,j)={ib,ig,ir};*/

			for (int k = 0; k < 3; k++)
			{
				int I= ( (img.at<Vec3b>(i,j)[k]) + (img.at<Vec3b>(i+1,j)[k]) + (img.at<Vec3b>(i,j+1)[k]) + (img.at<Vec3b>(i+1,j+1)[k]) )/4.0;
				a.at<Vec3b>(i/2,j/2)[k]=I;
			}


		}
	}

	//Enlarging Image (2 Size)
	/*Mat b(rows*2,cols*2,CV_8UC3,Scalar(0,0,0));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			b.at<Vec3b>(i,j)= ;
		}
	}*/
	//cout << typeid(img.at<Vec3b>(10,10)).name() << endl; INCOMPREHENSIBLE VALUE WAS FOUND
	namedWindow("Image",WINDOW_NORMAL);
	imshow("Image",img);
	namedWindow("Compressed Image",WINDOW_NORMAL);
	imshow("Compressed Image",a);
	waitKey(4000);
}
/*int finI(int ic1,int ic2,int ic3,int ic4)
{
	return (ic1 + ic2 + ic3 + ic4)/4;
}*/
