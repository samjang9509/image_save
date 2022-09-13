#include "image_saver.hpp"
    void ImageSave::imageCb(const sensor_msgs::CompressedImage &msg)
    {
        try
        {
            image = cv::imdecode(cv::Mat(msg.data), 1);
        }
        catch (cv_bridge::Exception &e)
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }

        cv::waitKey(30);
    }





    
