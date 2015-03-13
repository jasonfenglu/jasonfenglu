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
    cv::Mat tmp(image.height(), image.width(), CV_8UC3, (uchar*)image.bits(), image.bytesPerLine());
    cv::Mat result;
    cv::cvtColor(tmp, result, CV_BGR2RGB);
    return result;
}

#endif // MAT2QIMAGE_H
