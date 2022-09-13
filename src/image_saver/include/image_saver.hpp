#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>
#include <iostream>
#include <vector>

static const std::string OPENCV_WINDOW = "Image window";

class ImageSave
{
public:
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    cv_bridge::CvImagePtr cv_ptr;

    cv::Mat image;

    int numOfPhoto;
    std::vector<int> compression_params;

    void imageCb(const sensor_msgs::CompressedImage &msg);

    ImageSave() : numOfPhoto(0)
        , it_(nh_)
    {
        image_sub_ = it_.subscribe("/usb_cam/image_raw/compressed", 1, &ImageSave::imageCb);
        cv::namedWindow(OPENCV_WINDOW);
    }

    ~ImageSave()
    {
        cv::destroyWindow(OPENCV_WINDOW);
    }

};