#include "auxcode.h"

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

	//namedWindow(window_name, WINDOW_NORMAL); //create a window
	ofstream req;
	req.open("data.txt");
	int count = 0;
	int ct1 = -1;

	Mat frame1 = emptyframe;
	while (ct1<frames)
    {   ct1++;
		Mat frame2;
		bool bSuccess = cap.read(frame2);
        if(ct1%3==0){
		count += 1;
		Mat d;


		if (count > 1) {
			
			double x1=queuedensity(frame2,emptyframe, src_img, desti_img, rect);
			double x2=dynamicdensity(frame2, frame1,src_img, desti_img, rect);
			req << count << " " << x1 << " " << x2<< " " << "\n";
			cout<< 3*count << " " << x1 << " " << x2<< " " << "\n";


			if (bSuccess == false)
			{
				cout << "Found the end of the video" << endl;
				break;
			}

		//Breaking the while loop at the end of the video


		}
		else {
			double x1=queuedensity(frame2,emptyframe, src_img, desti_img, rect);
			req << count << " " << x1<< " " << 0.0000 << " " << "\n";
			cout<< "Frame Number"<< " " <<"Queue Density"<< " " <<"Dynamic Density"<< "\n";

			cout<< 3<< " " << x1 << " " <<0.000<< " " << "\n";

		}
		frame1 = frame2;
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}



        }
	}

	req.close();
	return 0;
}
