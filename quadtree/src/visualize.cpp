#include <visualize.h>


using namespace std;


quadviz::quadviz(int width,int height){

 this->winWidth = width;
 this->winHeight = height;

}


void quadviz::drawquad(point tl,point br){
 
 
 


}


//create a black image to draw tree on
void quadviz::createbackgrd(){
 
  backgrd = cv::Mat(cv::Size(this->winWidth,this->winHeight), CV_64FC1, cv::Scalar(0));

}


void quadviz::showquad(){

  string window = "quad tree";
  cv::namedWindow(window,cv::WINDOW_AUTOSIZE);
  cv::imshow(window,backgrd);
  cv::waitKey(0);

}
