#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "MatToQImage.h"
using namespace cv;
using namespace std;

// Define the size of QLabel
#define scale  1.3
#define QLHeight scale*240
#define QLWidth  scale*320

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoCapture cap;
    Mat capture, smooth, edge, hline, hline2, convert, erod, dil, opening, gradient;


private slots:

    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
