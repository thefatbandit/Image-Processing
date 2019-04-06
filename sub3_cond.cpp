#define PI 3.1415

int isValid(point p)	
{
	point a={p.x-4,p.y-9};
	for (int ang = 0; ang >-91; ang-=10)
	{
		int flag=0;
		for (int i = 0; i <10; i+=9)
		{
			for (int j = 0; j < 20; ++j)
			{
				int nx=(j-10)*sin((p.ang+ang)*PI/180)+(i-5)*cos((p.ang+ang)*PI/180) +15;
				int ny=(j-10)*cos((p.ang+ang)*PI/180)-(i-5)*sin((p.ang+ang)*PI/180) +30;
				if(a.x+nx<0||p.y+ny<0||a.x+nx>=img.rows||p.y+ny>=img.cols)
				{	
					flag=1;
					break;
				}
				if(img.at<Vec3b>(a.x+nx,p.y+ny)[0]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[1]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[2]==255)
				{
					flag=1;
					break;
				}

			}
			if (flag==1)
				break;

		}
		if(flag==1)
			continue;

		for (int j = 0; j <20; j+=19)
		{
			for (int i = 0; i <10; ++i)
			{
				int nx=(j-10)*sin((p.ang+ang)*PI/180)+(i-5)*cos((p.ang+ang)*PI/180) +15;
				int ny=(j-10)*cos((p.ang+ang)*PI/180)-(i-5)*sin((p.ang+ang)*PI/180) +30;
				if(a.x+nx<0||p.y+ny<0||a.x+nx>=img.rows||p.y+ny>=img.cols)
				{	
					flag=1;
					break;
				}
				if(img.at<Vec3b>(a.x+nx,p.y+ny)[0]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[1]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[2]==255)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;		
		}
		if(flag==0)
			return (p.ang+ang)
		

	}
	for (int ang = 0; ang <91; ang+=10)
	{
		int flag=0;
		for (int i = 0; i <10; i+=9)
		{
			for (int j = 0; j < 19; ++j)
			{
				int nx=(j-10)*sin((p.ang+ang)*PI/180)+(i-5)*cos((p.ang+ang)*PI/180) +15;
				int ny=(j-10)*cos((p.ang+ang)*PI/180)-(i-5)*sin((p.ang+ang)*PI/180) +30;
				if(a.x+nx<0||p.y+ny<0||a.x+nx>=img.rows||p.y+ny>=img.cols)
				{	
					flag=1;
					break;
				}
				if(img.at<Vec3b>(a.x+nx,p.y+ny)[0]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[1]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[2]==255)
				{
					flag=1;
					break;
				}

			}
			if (flag==1)
				break;

		}
		if(flag==1)
			continue;

		for (int j = 0; j <20; j+=19)
		{
			for (int i = 0; i < 9; ++i)
			{
				int nx=(j-10)*sin((p.ang+ang)*PI/180)+(i-5)*cos((p.ang+ang)*PI/180) +15;
				int ny=(j-10)*cos((p.ang+ang)*PI/180)-(i-5)*sin((p.ang+ang)*PI/180) +30;
				if(a.x+nx<0||p.y+ny<0||a.x+nx>=img.rows||p.y+ny>=img.cols)
				{	
					flag=1;
					break;
				}
				if(img.at<Vec3b>(a.x+nx,p.y+ny)[0]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[1]==255 && img.at<Vec3b>(a.x+nx,p.y+ny)[2]==255)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;		
		}
		if(flag==0)
			return (p.ang+ang)
	}
	return -1;
}
						/*int nx=(j-10)*sin((p.ang+ang)*PI/180)+(i-5)*cos((p.ang+ang)*PI/180) +15;
						int ny=(j-10)*cos((p.ang+ang)*PI/180)-(i-5)*sin((p.ang+ang)*PI/180) +30;
						if(nx<0||ny<0||nx>=img.rows||ny>=img.cols)
							continue;
						if(img.at<Vec3b>(nx,ny)[0]==255 && img.at<Vec3b>(nx,ny)[1]==255 && img.at<Vec3b>(nx,ny)[2]==255)
							continue;*/