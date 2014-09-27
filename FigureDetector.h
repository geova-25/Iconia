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
    void DibujaFiguras();
private:
    char key;
    CvMemStorage* storage = NULL;
    CvCapture* capture = NULL ;
    IplImage* src = NULL;
    CvSeq* contours = NULL;
    CvSeq* result = NULL;
    IplImage* dst = NULL;
    IplImage* gray = NULL;
    CvSeq* lines = 0;
    bool captured= false;
    int i;



};

#endif // FIGUREDETECTOR_H
