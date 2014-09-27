#ifndef FIGUREDETECTOR_H
#define FIGUREDETECTOR_H
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <string.h>
#include<stdio.h>
#include <time.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;


class FigureDetector
{
public:
    FigureDetector();
    virtual~FigureDetector();
    void DrawFigures();
    int getNumeroDeLados();
    void drawRects();
    void drawRectangles();
    void drawTriangles();
    void takePhoto();
    void releaseObjects();
private:

    CvMemStorage* storage = NULL;
    CvCapture* capture = NULL ;
    IplImage* photo = NULL;
    CvSeq* contours = NULL;
    CvSeq* result = NULL;
    IplImage* contours_image = NULL;
    IplImage* gray_scale_image = NULL;
    CvSeq* lines = 0;
    int i;
    IplImage* photo_clone=NULL;




};

#endif // FIGUREDETECTOR_H
