/*
 * This code is provided as part of "A Practical Introduction to Computer Vision with OpenCV"
 * by Kenneth Dawson-Howe © Wiley & Sons Inc. 2014.  All rights reserved.
 */
#include "Utilities.h"
#include <iostream>
#include <fstream>
using namespace std;



int main(int argc, const char** argv)
{
	char* file_location = "Media/";
	char* image_files[] = {

		"TrinityRegentHouse.jpg", //0
	
    };

	// Load images
	int number_of_images = sizeof(image_files)/sizeof(image_files[0]);
	Mat* image = new Mat[number_of_images];
	for (int file_no=0; (file_no < number_of_images); file_no++)
	{
		string filename(file_location);
		filename.append(image_files[file_no]);
		image[file_no] = imread(filename, -1);
		if (image[file_no].empty())
		{
			cout << "Could not open " << image[file_no] << endl;
			return -1;
		}
	}


	// Needed for mean shift in histogram demos
	Rect Surveillance_car_position_frame_124(251,164,64,32);
	Rect Bicycles_position_frame_180(242,26,37,60);
	Rect Person_position_frame_100(507,110,67,90);
	// Load video(s)
	char* video_files[] = { 
		"PETS2000.avi",
 };
	int number_of_videos = sizeof(video_files)/sizeof(video_files[0]);
	VideoCapture* video = new VideoCapture[number_of_videos];
	for (int video_file_no=0; (video_file_no < number_of_videos); video_file_no++)
	{
		string filename(file_location);
		filename.append(video_files[video_file_no]);
		video[video_file_no].open(filename);
		if( !video[video_file_no].isOpened() )
		{
			cout << "Cannot open video file: " << filename << endl;
			return -1;
		}
	}

	

	int line_step = 13;
	Point location( 7, 13 );
	Scalar colour( 0, 0, 255);
	Mat default_image = ComputeDefaultImage( image[0] );
	


	int choice;
	do
	{
		imshow("Welcome", default_image);
		//choice = cvWaitKey();
		cvDestroyAllWindows();
		
		string filename(file_location);
		filename.append("default.xml");
		cout << "file search " <<filename << endl;
		//filename = "C:\Users\Deirdre Meehan\Desktop\AugmentedReality\AR_Project_1\OpenCVExample\Media\default.xml";
		CameraCalibration( filename );
		
				
	} while ((choice != 'x') && (choice != 'X'));
}
