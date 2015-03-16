#ifndef MAT2QIMAGE_H
#define MAT2QIMAGE_H

#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

inline QImage Mat2QImage(cv::Mat image)
{
//    assert(image.channels()==3);
    QImage ans;
    switch(image.channels())
    {
    case 3:
        ans = QImage(image.data, image.cols, image.rows,QImage::Format_RGB888 );
        break;
    case 1:
        ans = QImage(image.data, image.cols, image.rows, QImage::Format_Indexed8);
    }

    return ans;
}

inline cv::Mat QImage2Mat(QImage image)
{
    cv::Mat ans;
    switch(image.format())
    {
    case QImage::Format_RGB32:
    {
        /// The image is stored using a 32-bit RGB format (0xffRRGGBB).
        /// Remove the first channel
        cv::Mat tmp(image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine());
        std::vector<cv::Mat> channels(4);
        cv::split(tmp, &channels[0]);
        channels.pop_back();
        cv::merge(channels, ans);
        break;
    }

    default:
        qFatal("Format not implemented");
    }

    return ans;
}

#endif // MAT2QIMAGE_H
