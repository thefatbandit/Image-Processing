#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stack>
using namespace std;
using namespace cv;

Mat a(100,100,CV_8UC1,Scalar(255));
struct node
{
	int i,j;
};

stack<node> st;

bool vis[100][100]={};

bool isValid(int i,int j)
{
	if(i<0||j<0||i>=a.rows||j>=a.cols)
	{
		return 0;
	}
	if(vis[i][j])
	{
		return 0;
	}
	return 1;
}

void dfs(int i,int j)
{
	a.at<uchar>(i,j)=0;
	vis[i][j]=1;
	imshow("win",a);
	waitKey(1);
	if(isValid(i,j+1))
	{
		dfs(i,j+1);
	}
	if(isValid(i+1,j))
	{
		dfs(i+1,j);
	}
	if(isValid(i-1,j))
	{
		dfs(i-1,j);
	}
	if(isValid(i,j-1))
	{
		dfs(i,j-1);
	}
}

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	vis[0][0]=1;
	a.at<uchar>(0,0)=0;
	dfs(0,0);
	imshow("win",a);
	waitKey(5000);
}