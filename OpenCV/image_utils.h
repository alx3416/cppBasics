#ifndef CPPBASICS_IMAGE_UTILS_H
#define CPPBASICS_IMAGE_UTILS_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cmath>

namespace myLib{

    cv::Mat gammaCorrectionPassByValue(cv::Mat frame_gray){
        double value = 0;
        for(int row=0; row<frame_gray.rows; row++){
            for(int col=0; col<frame_gray.cols; col++){
                value = static_cast<double>(frame_gray.at<uint8_t >(row, col));
                value = value / 255;
                value = pow(value, 0.3);
                value = value * 255;
                frame_gray.at<uint8_t >(row, col) = static_cast<uint8_t>(value);
            }
        }
        return frame_gray;
    }

    void gammaCorrectionPassByReference(cv::Mat &frame_gray){
        double value = 0;
        for(int row=0; row<frame_gray.rows; row++){
            for(int col=0; col<frame_gray.cols; col++){
                value = static_cast<double>(frame_gray.at<uint8_t >(row, col));
                value = value / 255;
                value = pow(value, 0.3);
                value = value * 255;
                frame_gray.at<uint8_t >(row, col) = static_cast<uint8_t>(value);
            }
        }
    }
} // namespace myLib

#endif //CPPBASICS_IMAGE_UTILS_H
