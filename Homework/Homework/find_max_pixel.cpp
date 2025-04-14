#include <iostream>
#include<opencv2/opencv.hpp>

int main() {
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	

	double minVal, maxVal;
	cv::minMaxLoc(img, &minVal, &maxVal);

	std::cout << static_cast<int>(maxVal) << std::endl;

	cv::imshow("lenna window ", img);
	cv::waitKey(0);

	return 0;
}