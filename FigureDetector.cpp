#include "FigureDetector.h"

FigureDetector::FigureDetector()
{
    storage = cvCreateMemStorage(0);
    capture = cvCaptureFromCAM(0);
    photo = cvQueryFrame(capture);
    contours_image = cvCreateImage( cvGetSize(photo), 8, 1 );
    gray_scale_image = cvCreateImage( cvGetSize(photo), 8, 3 );

}
FigureDetector::~FigureDetector(){}
void FigureDetector :: DrawFigures(){

         takePhoto();
         cvCanny( photo, contours_image, 50, 200, 3 );
         cvThreshold(contours_image,contours_image,100,255,CV_THRESH_BINARY);
         cvCvtColor( contours_image, gray_scale_image, CV_GRAY2BGR );
         cvFindContours(contours_image,storage, &contours, sizeof(CvContour), CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
         result= cvApproxPoly(contours, sizeof(CvContour),storage,CV_POLY_APPROX_DP,cvContourPerimeter(contours)*0.02,0);
         lines = cvHoughLines2( contours_image, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50, 10 );
         drawRects();
         drawRectangles();
         drawTriangles();
         //---------------------------detectar circulos-------------------------------------------
              /*cvSmooth( gray, gray, CV_GAUSSIAN, 9, 9 ); // suaviza la imagen
              CvSeq* circles = cvHoughCircles( gray, storage, CV_HOUGH_GRADIENT, 2, gray->height/4, 200, 100 );
              int i;

                     // for( i = 0; i < circles->total; i++ )
                      {
                           float* p = (float*)cvGetSeqElem( circles, i );
                          // cvCircle( gray, cvPoint(cvRound(p[0]),cvRound(p[1])), 3, CV_RGB(0,255,0), -1, 8, 0 );
                          // cvCircle( gray, cvPoint(cvRound(p[0]),cvRound(p[1])), cvRound(p[2]), CV_RGB(255,0,0), 3, 8, 0 );
                      }*/

         //-----------------------------------------------------------------------------------------
         cvShowImage("Iconia",photo);
         //cout<<result->total<<endl;
}


void FigureDetector::takePhoto(){
    photo = cvQueryFrame(capture);
    if ( !photo || capture == NULL){
        fprintf(stderr, "Error: frame is null ...\n");
        getchar();
    }


}


int FigureDetector::getNumeroDeLados(){
    cvFindContours(contours_image,storage, &contours, sizeof(CvContour), CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    result= cvApproxPoly(contours, sizeof(CvContour),storage,CV_POLY_APPROX_DP,cvContourPerimeter(contours)*0.02,0);
    return result->total;

}
void FigureDetector::drawRects(){

    for( i = 0; i < lines->total; i++ )
            {
                 CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
                cvLine( photo, line[0], line[1], CV_RGB(255,0,0), 3, 8 );
            }
}
void FigureDetector::drawRectangles(){
    if (result->total == 4 && fabs(cvContourArea(result, CV_WHOLE_SEQ))>20)
           {
               CvPoint *pt[4];
               for(int i=0 ; i<4;i++)
               {
                   pt[i] = (CvPoint*)cvGetSeqElem(result,i);
                   //cout << "x: "<< pt[i]->x << "\ny: " << pt[i]->y << "\n" <<endl;
               }
               cvLine(photo, *pt[0], *pt[1],  CV_RGB(255,0,0), 3, 8);
               cvLine(photo, *pt[1], *pt[2], CV_RGB(255,0,0), 3, 8);
               cvLine(photo, *pt[2], *pt[3], CV_RGB(255,0,0), 3, 8);
               cvLine(photo, *pt[3], *pt[0], CV_RGB(255,0,0), 3, 8);

           }

}
void FigureDetector::drawTriangles(){
    if (result->total == 3 && fabs(cvContourArea(result, CV_WHOLE_SEQ)) > 20)
           {
               CvPoint *pt[3];
               for (int i=0 ; i<3 ;i++)
               {
                   pt[i]= (CvPoint*)cvGetSeqElem(result,i);
               }
               cvLine(photo, *pt[0], *pt[1],CV_RGB(255,0,0), 3, 8);
               cvLine(photo, *pt[1], *pt[2],CV_RGB(255,0,0), 3, 8);
               cvLine(photo, *pt[2], *pt[0],CV_RGB(255,0,0), 3, 8);
           }

}
void FigureDetector::releaseObjects(){
    cvReleaseCapture(&capture);
    cvDestroyAllWindows();
    cvReleaseImage(&photo);
    cvReleaseImage(&gray_scale_image);
    cvReleaseImage(&contours_image);
    cvClearMemStorage( storage );

}
