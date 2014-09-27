#include "FigureDetector.h"

FigureDetector::FigureDetector()


{
    storage = cvCreateMemStorage(0);
    capture = cvCaptureFromCAM(0);
    src = cvQueryFrame(capture);
    dst = cvCreateImage( cvGetSize(src), 8, 1 );
    gray = cvCreateImage( cvGetSize(src), 8, 3 );

}
FigureDetector::~FigureDetector(){}

void FigureDetector :: DibujaFiguras(){
    while(captured == false){

         src = cvQueryFrame(capture);

         if ( !src ){

             fprintf(stderr, "Error: frame is null ...\n");
             getchar();
             break;
         }
         cvCanny( src, dst, 50, 200, 3 );
          cvThreshold(dst,dst,100,255,CV_THRESH_BINARY);
         cvCvtColor( dst, gray, CV_GRAY2BGR );

         cvFindContours(dst,storage, &contours, sizeof(CvContour), CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
         result= cvApproxPoly(contours, sizeof(CvContour),storage,CV_POLY_APPROX_DP,cvContourPerimeter(contours)*0.02,0);

         lines = cvHoughLines2( dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50, 10 );

        // cout<<result->total <<endl;
         //cout<<"num de lineas  "<<lines->total <<endl;

    //--/------------------------------dibuja las lienas------------------------------------------------
         for( i = 0; i < lines->total; i++ )
                 {
                     CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
                     //cvLine( color_dst, line[0], line[1], CV_RGB(255,0,0), 3, 8 );
                 }

    //--------------------------------------Dibujar cuadros--------------------------------------------
         if (result->total == 4 && fabs(cvContourArea(result, CV_WHOLE_SEQ))>20)
                {
                    CvPoint *pt[4];
                    for(int i=0 ; i<4;i++)
                    {
                        pt[i] = (CvPoint*)cvGetSeqElem(result,i);
                        //cout << "x: "<< pt[i]->x << "\ny: " << pt[i]->y << "\n" <<endl;
                    }
                    cvLine(src, *pt[0], *pt[1],  CV_RGB(255,0,0), 3, 8);
                    cvLine(src, *pt[1], *pt[2], CV_RGB(255,0,0), 3, 8);
                    cvLine(src, *pt[2], *pt[3], CV_RGB(255,0,0), 3, 8);
                    cvLine(src, *pt[3], *pt[0], CV_RGB(255,0,0), 3, 8);

                }
    //---------------------------Dibujar triangulos.----------------------------------------
         if (result->total == 3 && fabs(cvContourArea(result, CV_WHOLE_SEQ)) > 20)
                {
                    CvPoint *pt[3];
                    for (int i=0 ; i<3 ;i++)
                    {
                        pt[i]= (CvPoint*)cvGetSeqElem(result,i);
                    }
                    cvLine(src, *pt[0], *pt[1],CV_RGB(255,0,0), 3, 8);
                    cvLine(src, *pt[1], *pt[2],CV_RGB(255,0,0), 3, 8);
                    cvLine(src, *pt[2], *pt[0],CV_RGB(255,0,0), 3, 8);

                }

        // cout<<src->nChannels<<endl;
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


         cvShowImage("cdst",src);

         key = cvWaitKey(10); //Capture Keyboard stroke

         if (char(key) == 27){ break; //If you hit ESC key loop will break.
         }

     }

        cvReleaseCapture(&capture);
        cvDestroyAllWindows();
        cvReleaseImage(&src);
        cvReleaseImage(&gray);
        cvReleaseImage(&dst);

        cvClearMemStorage( storage );

        waitKey();

}
