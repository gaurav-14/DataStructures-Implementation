#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include <node.h>

class quadviz
{
  
// point topleft,bottmright;
public:

 int winWidth,winHeight;
 
 //backgrd image
 cv::Mat backgrd; 

 //initialise window width and height
 quadviz(int,int);

 
 //draw quad given two corners
 void drawquad(point,point); 
 
 //draw backgrd to draw on
 void createbackgrd(); 

 //show the quadtree on created backgrd
 void showquad(); 
};
