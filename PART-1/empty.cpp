#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;


vector<Point2f>src_img;
vector<Point2f>desti_img;
vector<Point2f>rect;

int ct1 = 0;
int ct2 = 0;

void MouseCall(int event, int x, int y, int flags, void* userdata) {
	if (event == 1) {
		ct1 += 1;
		if (ct1 <= 4) {
			src_img.push_back(Point2f(x, y));

		}
		else {
			destroyWindow("Original Image");
			return;

		}

	}
	else if (event == 2) {
		destroyWindow("Original Image");
	}
	else {
		return;
	}

}

void createRectangle(int event, int x, int y, int flags, void* userdata) {
	if (event == 1) {
		ct2 += 1;
		if (ct2 <= 2) {
			rect.push_back(Point2f(x, y));

		}
		else {
			destroyWindow("Projected Image");
			return;

		}

	}
	else if (event == 2) {
		destroyWindow("Projected Image");
	}
	else {
		return;
	}

}

void exitProgram(int event, int x, int y, int flags, void* userdata) {
	if (event == 1 || event == 2) {
		destroyWindow("Cropped Image");
	}
	else {
		return;
	}

}


int main(int argc, char** argv)
{
	// Read the image file 
	Mat image = imread("C:\\Users\\Lenovo\\Desktop\\MY FOLDERS\\EDU\\SEM4\\COP290\\ASSIGNMENTS\\Assignment-1\\PART-1\\traffic.jpg", 0);
	//Use the location of imagefile and  0 for grayscale reading.
	if (image.empty()) {
		cout << "Image Not Found!!!" << endl;
		waitKey(0); // Wait for any keystroke in the window 
		cin.get(); //wait for any key press 
		return -1;
	}
	// Show our image inside a window. 

	desti_img.push_back(Point2f(472, 52));  //Mapping suggested for homographic transformation
	desti_img.push_back(Point2f(472, 830));
	desti_img.push_back(Point2f(800, 830));
	desti_img.push_back(Point2f(800, 52));



	namedWindow("Original Image", WINDOW_AUTOSIZE); //Autosize to fit the screen.
	setMouseCallback("Original Image", MouseCall, NULL);
	imshow("Original Image", image);
	Mat outputimage;
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow("Original Image");
	Mat homo = findHomography(src_img, desti_img);
	warpPerspective(image, outputimage, homo, image.size());
	//For this we first select top left then bottom left followed by bottom right and top right.

	namedWindow("Projected Image", WINDOW_AUTOSIZE);
	setMouseCallback("Projected Image", createRectangle, NULL);
	imshow("Projected Image", outputimage);
	bool result = false;
	try
	{
		result = imwrite("projectedimage.jpg", outputimage);
	}
	catch (const cv::Exception& ex)
	{
		fprintf(stderr, "Exception converting image to JPG format: %s\n", ex.what());
	}
	if (result)
		printf("Saved projectedimage.jpg file.\n");
	else
		printf("ERROR: Couldn't save projectedimage.jpg file.\n");
	waitKey(0);
	destroyWindow("Projected Image");

	//For this we first select top left then bottom right.


	Mat croppedimage;
	Rect crop_region(rect[0].x, rect[0].y, abs(rect[1].x - rect[0].x), abs(rect[0].y - rect[1].y));
	croppedimage = outputimage(crop_region);
	namedWindow("Cropped Image", WINDOW_AUTOSIZE);
	setMouseCallback("Cropped Image", exitProgram, NULL);
	imshow("Cropped Image", croppedimage);
	result = false;
	try
	{
		result = imwrite("croppedimage.jpg", croppedimage);
	}
	catch (const cv::Exception& ex)
	{
		fprintf(stderr, "Exception converting image to JPG format: %s\n", ex.what());
	}
	if (result)
		printf("Saved croppedimage.jpg file.\n");
	else
		printf("ERROR: Couldn't save croppedimage.jpg file.\n");

	waitKey(0);
	destroyWindow("Cropped Image");
	
	return 0;
}
