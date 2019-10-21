
#ifndef FaceDetector_hpp
#define FaceDetector_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
class FaceDetector
{
private:
    cv::CascadeClassifier face_cascade;
    int next_height;
    double window_scaling;
    int minClassifiers;
    int imgHeight;
    int flags;

public:
    FaceDetector(std::string face_cascade_name, int next_height_ = 40, double scale_factor = 1.1, int minConsensus = 4, int next_height_img = 40, int flag = 0);
    FaceDetector();
    ~FaceDetector(){};
    std::vector<cv::Rect> nextFrame(cv::Mat frame);
    std::vector<cv::Rect> ImgDetect(cv::Mat image);
};

#endif /* FaceDetector_hpp */
