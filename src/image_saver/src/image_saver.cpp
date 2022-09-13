#include "image_saver.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_saver");
    ImageSave saveImage;

    ros::Rate loop_rate(1);

    while (saveImage.numOfPhoto < 1500)
    {
        saveImage.compression_params.push_back(cv::IMWRITE_JPEG_OPTIMIZE);
        saveImage.compression_params.push_back(100);
        cv::imwrite("~/image_save/src/imagedb", saveImage.image, saveImage.compression_params);
        saveImage.numOfPhoto = saveImage.numOfPhoto + 1;
    }
    ros::spin();
    return 0;
}