#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void main() {

    string path = "Resources/test.png";
    Mat img = imread(path); 
    Mat imgGray, imgBlur;
    Mat imgCanny,imgDil,imgEro;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(5,5), 5, 0);
    Canny(imgBlur, imgCanny, 50, 150);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5)); ///Use only odd nos like (3,3) or (5,5) or (7,7)
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgEro, kernel);
    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blurred", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDil);
    imshow("Image Erosion", imgEro);
    waitKey(0);

}


