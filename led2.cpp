#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;




int main(int argc, char* argv[])
{

IplImage* newImg = NULL;
IplImage* grayImg = NULL;
IplImage* contourImg = NULL;
float minAreaOfInterest = 180.0;
float maxAreaOfInterest = 220.0;
//parameters for the contour detection
CvMemStorage * storage = cvCreateMemStorage(0);
CvSeq * contours = 0;
int mode = CV_RETR_EXTERNAL;
mode = CV_RETR_CCOMP; //detect both outside and inside contour
cvNamedWindow("src", 1);
cvNamedWindow("Threshhold",1);
//load original image
newImg = cvLoadImage("samps/blue.jpeg", 1);

IplImage* imgHSV = cvCreateImage(cvGetSize(newImg), 8, 3);
cvCvtColor(newImg, imgHSV, CV_BGR2HSV);

cvNamedWindow("HSV",1);
cvShowImage( "HSV", imgHSV );
IplImage* imgThreshed = cvCreateImage(cvGetSize(newImg), 8, 1);

cvInRangeS(newImg, cvScalar(20, 100, 100), cvScalar(30, 255, 255), imgThreshed);
cvShowImage( "src", newImg );

cvShowImage( "Threshhold", imgThreshed );

//make a copy of the original image to draw the detected contour
contourImg = cvCreateImage(cvGetSize(newImg), IPL_DEPTH_8U, 3);
contourImg=cvCloneImage( newImg );
cvNamedWindow("Contour",1);
//find the contour
cvFindContours(imgThreshed, storage, &contours, sizeof(CvContour), mode, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
int i = 0;
for (; contours != 0; contours = contours->h_next)
{
    i++;
    //ext_color = CV_RGB( rand()&255, rand()&255, rand()&255 ); //randomly coloring different contours      
    cvDrawContours(contourImg, contours, CV_RGB(0, 255, 0), CV_RGB(255, 0, 0), 2, 2, 8, cvPoint(0,0));
}
printf("Total Contours:%d\n", i);
cvShowImage( "Contour", contourImg );
for

cvWaitKey(0);
cvDestroyWindow( "src" ); cvDestroyWindow( "Threshhold" );
cvDestroyWindow( "HSV" );
cvDestroyWindow( "Contour" );
cvReleaseImage( &newImg ); cvReleaseImage( &imgThreshed ); 
cvReleaseImage( &imgHSV );
cvReleaseImage( &contourImg );



}
