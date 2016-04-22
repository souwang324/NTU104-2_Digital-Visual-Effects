//
//  ImageStitch.h
//  ImageStitching
//
//  Created by Zhi-Wei Yang on 4/22/16.
//  Copyright © 2016 Zhi-Wei Yang. All rights reserved.
//

#ifndef ImageStitch_h
#define ImageStitch_h

#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <string>

class ImageStitch
{
public:

	ImageStitch(const std::string & p);
	void StartStitching();
	cv::Mat CylindricalProjection(int ind);
	void CalculateFeatures();
	std::pair<double, double> RANSAC(int ind1, int ind2, double thres, int k = 50, int n = 1);
	cv::Mat MergeImage(cv::Mat * img1, cv::Mat * img2, std::pair<int, int> shift);

private:
public:
	static const int MAX_IMAGE_SIZE = 15;
	std::string path;
	std::string parameter = "parameter.txt";

	std::vector<double> focalLens;
	std::vector< cv::Mat > images;

	std::vector< std::vector< std::pair<double, double> > > features;
	std::vector< std::pair<int, int> > matches[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
};




#endif /* ImageStitch_h */