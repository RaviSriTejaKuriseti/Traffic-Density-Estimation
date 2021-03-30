#include "ss.h"

vector<Point2f>src_img;
vector<Point2f>desti_img;
vector<Point2f>rect;



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


	VideoCapture cap("/mnt/c/Users/Lenovo/Desktop/trafficvideo.mp4");
	//Read the file from location

	Mat emptyframe = imread("requiredimage.jpg");
	Mat ef=colourtransformframe(emptyframe,src_img,desti_img,rect);


	// if not success, exit program
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video file" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per seconds : " << fps << endl;

	double frames = cap.get(CAP_PROP_FRAME_COUNT);
	cout << "No of frames=" << frames << "\n";

	String window_name = "Traffic Video";
	int param;
	cout<<"Enter parameter:";
	cin>>param;
	ofstream req;
	vector<double>vec;
	auto start=high_resolution_clock::now(); 
	incre(vec,param,ef,cap,src_img,desti_img,rect);
	auto stop=high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
	
	string s = "skipping each " + to_string(param)+" th frame" + ".txt";
	req.open(s);
	req << "Frame Number" << " " << "Queue Density" << "\n";
	for(int i=0;i<vec.size();i++){
		req << i*param+1 << " " << vec[i]<< " " << "\n";
	}
	req << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	req.close();
	return 0;
}
