#ifndef MATTOQIMAGE_H
#define MATTOQIMAGE_H

// Qt header files
#include <QtGui>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

QImage MatToQImage(const Mat&);

#endif // MATTOQIMAGE_H
