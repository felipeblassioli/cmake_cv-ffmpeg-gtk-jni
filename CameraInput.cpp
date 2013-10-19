#include <opencv/cv.h> 
#include <opencv/highgui.h> 
#include <stdio.h>
#include <gtk-2.0/gtk/gtk.h>
#include <glib-2.0/glib.h>

#include <libavcodec/avcodec.h>

 // A Simple Camera Capture Framework 
 int main() {
   CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
   if ( !capture ) {
     fprintf( stderr, "ERROR: capture is NULL \n" );
     getchar();
     return -1;
   }
   // Create a window in which the captured images will be presented
   cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
   // Show the image captured from the camera in the window and repeat
   while ( 1 ) {
     // Get one frame
     IplImage* frame = cvQueryFrame( capture );
     if ( !frame ) {
       fprintf( stderr, "ERROR: frame is null...\n" );
       getchar();
       break;
     }
     cvShowImage( "mywindow", frame );
     // Do not release the frame!
     //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
     //remove higher bits using AND operator
     if ( (cvWaitKey(10) & 255) == 27 ) break;
   }
   // Release the capture device housekeeping
   cvReleaseCapture( &capture );
   cvDestroyWindow( "mywindow" );
   return 0;
 }