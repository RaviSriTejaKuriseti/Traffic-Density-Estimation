#include "auxcode.h"

vector<Point2f>src_img;
vector<Point2f>desti_img;
vector<Point2f>rect;
int S[6000];
int arr[10];



struct arg_struct{
    int curr;
	int totalthreads;
	int currthreadnum;
	Mat im1;
	Mat im2;
};

void* f(void *arguments){
	struct arg_struct *args = (struct arg_struct *)arguments;
	int threadnum=args->currthreadnum;
	int curr=args->curr;
	Mat img=args->im1;
	Mat emptyframe=args->im2;
	int tot=args->totalthreads;
	arr[threadnum]=0;
	for(int i=0;i<img.size().height;i++){
		if(i%tot!=threadnum)continue;
		for(int j=0;j<img.size().width;j++){
				if (abs(img.at<uchar>(i,j)-emptyframe.at<uchar>(i,j))>30) {
				    arr[threadnum]+= 1;
			}

			}

		}
		
	return NULL;

}


int main(int argc, char** argv)
{
	
	desti_img.push_back(Point2f(472, 52));
	desti_img.push_back(Point2f(472, 830));
	desti_img.push_back(Point2f(800, 830));
	desti_img.push_back(Point2f(800, 52));

	src_img.push_back(Point2f(990, 223));
	src_img.push_back(Point2f(302, 1071));
	src_img.push_back(Point2f(1545, 1070));
	src_img.push_back(Point2f(1275, 215));

	rect.push_back(Point2f(465, 32));
	rect.push_back(Point2f(805, 829));

    Mat x1=imread("requiredimage.jpg");
    Mat emptyframe = colourtransformframe(x1,src_img, desti_img, rect);
	double totalpixels=(double) emptyframe.size().height*emptyframe.size().width;
	VideoCapture cap("/mnt/c/Users/Lenovo/Desktop/trafficvideo.mp4");
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video file" << endl;
		cin.get(); 
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per seconds : " << fps << endl;

	double frames = cap.get(CAP_PROP_FRAME_COUNT);
	cout << "No of frames=" << frames << "\n";

	String window_name = "Traffic Video";	
	int param1;
	cout<<"Enter the no.of threads:";
	cin>>param1;
	if(param1<=0 || param1>4){
		cout<<"Invalid Input"<<"\n";
		return 0;
	}
	else{
		int ct1=1;
		int rc;
		
		
	auto start=high_resolution_clock::now();
	pthread_t threads[param1];
	struct arg_struct list[(int)frames];
	while (ct1<=frames)
    {
		for(int Q=0;Q<param1;Q++){
			arr[Q]=-1;
		}   
		
		Mat frame2;
		bool bSuccess = cap.read(frame2);
		if (bSuccess == false)
		{
			cout << "Found the end of the video" << endl;
			break;
		}

		Mat frame3=colourtransformframe(frame2, src_img, desti_img, rect);
		int I=0;
		while(I<param1){
			struct arg_struct args=list[ct1-1];
			args.curr = ct1;
			args.totalthreads=param1;
			args.im1 = frame3;
			args.im2 = emptyframe;
			args.currthreadnum=I;
					
			rc = pthread_create(&threads[I], NULL, &f,&list[ct1-1]);
			I+=1;
			if (rc != 0) {
				cout<<"Thread creation failed"<<"\n";
				exit(-1);
			}

		 I+=1;


		}
		
	
		int s=0;
		cout<<ct1<<"\n";
		for(int Q=0;Q<param1;Q++){
			s+=arr[Q];
		}
		S[ct1]=s;
	
	
		
		if (waitKey(10) == 27)
			{
				cout << "Esc key is pressed by user. Stoppig the video" << endl;
				break;
			}

		
			
  		ct1+=1;
		  
	}

					
		auto stop=high_resolution_clock::now(); 
		auto duration = duration_cast<microseconds>(stop - start);

		ofstream req;		
		string s = "Using " + to_string(param1)+" threads"+".txt";
		req.open(s);
		req << "Frame Number" << " " << "Queue Density" << "\n";
		double x00;
		for(int i=1;i<=frames;i++){
			x00=(S[i]+0.0)/(totalpixels); 
			req<<i<<" "<<x00<<"\n";
		}
			
		
		req << "Time taken by function: "
			<< duration.count() << " microseconds" << endl; 
		req.close();

		

	}

	

	return 0;
}
