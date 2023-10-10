#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


int main(int, char**)
{
    cv::Mat frame;
    cv::VideoCapture cap;

    int deviceID = 0; // 0 = open default camera
    int apiID = cv::CAP_ANY; // 0 = autodetect default API
    cap.open(deviceID, apiID);
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    for (;;)
    {

        cap.read(frame);

        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // std::cout << frame.at<cv::Vec3b>(0, 0) << std::endl;
        // frame.at<cv::Vec3b>(0,0)[0] = 0;
        // frame.at<cv::Vec3b>(0,0)[1] = 0;
        // frame.at<cv::Vec3b>(0,0)[2] = 255;
        imshow("Live", frame);
        if (cv::waitKey(5) >= 0)
            break;
    }
    return 0;
}