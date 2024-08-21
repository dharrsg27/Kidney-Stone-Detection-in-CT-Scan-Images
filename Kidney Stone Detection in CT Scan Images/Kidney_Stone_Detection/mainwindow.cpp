#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QMessageBox>
#include <QFileDialog>

using namespace cv;
using namespace std;

//K-Means Algorithm
Mat K_Means(Mat Input, int K) {
    Mat samples(Input.rows * Input.cols, Input.channels(), CV_32F);
    for (int y = 0; y < Input.rows; y++)
        for (int x = 0; x < Input.cols; x++)
            for (int z = 0; z < Input.channels(); z++)
                if (Input.channels() == 3) {
                    samples.at<float>(y + x * Input.rows, z) = Input.at<Vec3b>(y, x)[z];
                }
                else {
                    samples.at<float>(y + x * Input.rows, z) = Input.at<uchar>(y, x);
                }

    Mat labels;
    int attempts = 5;
    Mat centers;
    kmeans(samples, K, labels, TermCriteria(TermCriteria::MAX_ITER|TermCriteria::EPS, 10, 1.0), attempts, KMEANS_PP_CENTERS, centers);

    Mat new_image(Input.size(), Input.type());
    for (int y = 0; y < Input.rows; y++)
        for (int x = 0; x < Input.cols; x++)
        {
            int cluster_idx = labels.at<int>(y + x * Input.rows, 0);
            if (Input.channels()==3) {
                for (int i = 0; i < Input.channels(); i++) {
                    new_image.at<Vec3b>(y, x)[i] = centers.at<float>(cluster_idx, i);
                }
            }
            else {
                new_image.at<uchar>(y, x) = centers.at<float>(cluster_idx, 0);
            }
        }
    return new_image;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("DSP Final Project - Kidney Stone Detection"));
        ui->display1->setScaledContents(true);
        ui->display2->setScaledContents(true);
        ui->display3->setScaledContents(true);
        ui->display4->setScaledContents(true);
        ui->display5->setScaledContents(true);
        ui->display6->setScaledContents(true);
        ui->display7->setScaledContents(true);
        ui->display8->setScaledContents(true);
        ui->display1->setFixedSize( 300, 300 );
        ui->display2->setFixedSize( 300, 300 );
        ui->display3->setFixedSize( 300, 300 );
        ui->display4->setFixedSize( 300, 300 );
        ui->display5->setFixedSize( 300, 300 );
        ui->display6->setFixedSize( 300, 300 );
        ui->display7->setFixedSize( 300, 300 );
        ui->display8->setFixedSize( 300, 300 );

    // Call update every 100ms
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "dharrensandhi/",
                "JPEG (*.jpg *.jpeg);;PNG(*.png)"
                );

    Mat img_gray, medianImg, imgCanny, threshImg, imgDil, imgErod, drawing_gray;

    //Input Image
    Mat img = imread(filename.toStdString()); //use the image "kidneystone.jpg"
    cout << "Height: " << img.rows << ", Width: " << img.rows << ", Channels: " << img.channels() << endl;
    //imshow("Original Image", img);

    //Change to Grayscale
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    //Median Filter
    medianBlur(img_gray,medianImg,3);
    //imshow("Median Image", medianImg);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/medianImg.jpg", medianImg);

    //K-Means Clustering Image Segmentation
    int Clusters = 4;
    Mat Clustered_Image = K_Means(medianImg, Clusters);
    //imshow("Clustered_Image.png", Clustered_Image);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/clusteredImg.jpg", Clustered_Image);

    //Thresholding
    threshold(Clustered_Image,threshImg,135,255,THRESH_BINARY);
    //imshow("Thresholded Image", threshImg);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/ThresholdedImage.jpg", threshImg);

    //Morphological Operations (Erosion -> Dilation)
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    erode(threshImg, imgErod, kernel);
    dilate(imgErod, imgDil, kernel);
    //imshow("Eroded Image", imgErod);
    //imshow("Dilated Image", imgDil);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/ErodedImage.jpg", imgErod);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/DilatedImage.jpg", imgDil);

    //Contour Detection (Removing Large and Small Contours)
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0));
    /// Approximate contours
    vector<Rect> boundRect(contours.size());
    for (unsigned int i = 0; i < contours.size(); i++)
    {   ///identify bounding box
        boundRect[i] = boundingRect(contours[i]);
    }
    Mat drawing = Mat::zeros( imgDil.size(), CV_8UC3 );
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        drawContours( drawing, contours, (int)i, Scalar(0,255,0), -1 );
        if ((boundRect[i].area() > 1200 || boundRect[i].area() < 40 ))
        {
            rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), Scalar(0,0,0), -1 );
        }
    }

    //Overlaying Remaining Contour on the Original Image
    cvtColor(drawing, drawing_gray, cv::COLOR_BGR2GRAY);
    findContours(drawing_gray, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0));
    Mat img_copy = img.clone();
    drawContours( img_copy, contours, -1, Scalar(0,255,0), -1 );

    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/ContouredImage.jpg", drawing);
    imwrite("/Users/dharrensandhi/Documents/SGU/Sem_5/DSP/Kidney_Stone_Detection/FinalImage.jpg", img_copy);

    // Convert cv::Mat to QImage
    QImage img1 = MatToQImage( img );
    QImage img2 = MatToQImage( medianImg  );
    QImage img3 = MatToQImage( Clustered_Image );
    QImage img4 = MatToQImage( threshImg   );
    QImage img5 = MatToQImage( imgErod  );
    QImage img6 = MatToQImage( imgDil  );
    QImage img7 = MatToQImage( drawing  );
    QImage img8 = MatToQImage( img_copy  );
    // Display QImage
    ui->display1->setPixmap(QPixmap::fromImage(img1));
    ui->display4->setPixmap(QPixmap::fromImage(img4));
    ui->display2->setPixmap(QPixmap::fromImage(img2));
    ui->display3->setPixmap(QPixmap::fromImage(img3));
    ui->display5->setPixmap(QPixmap::fromImage(img5));
    ui->display6->setPixmap(QPixmap::fromImage(img6));
    ui->display7->setPixmap(QPixmap::fromImage(img7));
    ui->display8->setPixmap(QPixmap::fromImage(img8));
}
