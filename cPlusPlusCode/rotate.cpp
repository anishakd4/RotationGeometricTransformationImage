#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Read the input image over which rotation will be applied
    Mat inputImage, roationMatrix, result;
    inputImage = imread("../assets/putin.jpg");

    //define the center using Point2f datatype and rotation angle
    Point2f center(inputImage.cols/2, inputImage.rows/2);
    double rotatingAngle = -30;
    double scale = 1;

    //Get the matrix which defines rotation and will be used to rotate image. getRotationMatrix2D takes center(point around which rotation will be applied),
    //rotation Angle (angle by which image will be rotated), scale:(an optional scaling factor)
    roationMatrix = getRotationMatrix2D(center, rotatingAngle, scale);
    cout<<roationMatrix<<endl;

    //Rotating the input image
    warpAffine(inputImage, result, roationMatrix, Size(inputImage.cols, inputImage.rows));

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("rotated", WINDOW_NORMAL);

    //display images
    imshow("image", inputImage);
    imshow("rotated", result);

    //Press esc to exit the program
    waitKey(0);

    //close all the opened windows
    destroyAllWindows();

    return 0;
}