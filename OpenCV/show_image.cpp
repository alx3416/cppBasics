#include "image_utils.h"


int main(int, char**)
{
    cv::Mat frame, frame_gray;
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
        cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
        myLib::gammaCorrectionPassByReference(frame_gray);

        // std::cout << frame.at<cv::Vec3b>(0, 0) << std::endl;
        // frame.at<cv::Vec3b>(0,0)[0] = 0;
        // frame.at<cv::Vec3b>(0,0)[1] = 0;
        // frame.at<cv::Vec3b>(0,0)[2] = 255;

        imshow("Live", frame);
        imshow("Live - gray", frame_gray);
        if (cv::waitKey(5) >= 0)
            break;
    }
    return 0;
}