
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
    int window_scaling;
    int minClassifiers;
    int imgHeight;
    int flags;

public:
    FaceDetector(std::string face_cascade_name, int next_height_);
    FaceDetector(std::string face_cascade_name, int next_height_, int scale_factor, int minConsensus, int next_height_img, int flag);
    FaceDetector();
    ~FaceDetector(){};
    std::vector<cv::Rect> nextFrame(cv::Mat frame);
    std::vector<cv::Rect> ImgDetect(cv::Mat image);
};

#endif /* FaceDetector_hpp */
