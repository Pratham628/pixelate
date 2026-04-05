#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    // The two kernels — do not change these
    cv::Mat K1 = (cv::Mat_<double>(3, 3) <<
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    );

    cv::Mat K2 = (cv::Mat_<double>(3, 3) <<
         1,  0, -1,
         2,  0, -2,
         1,  0, -1
    );

    cv::Mat img = cv::imread("./assets/hogwarts.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Could not load image at ./assets/hogwarts.png\n";
        return -1;
    }

    cv::Mat img_f;
    img.convertTo(img_f, CV_64FC1);
    
    filter2D(input, output, -1, gaussian);              // Convolve with original 'full' kernel

    // Making All Windows resizable
    cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::imshow("Output", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    // Define decomposed standard 3x3 Gaussian kernel
    cv::Mat K1_v = (cv::Mat_<double>(3, 1) << 1,0,-1);
    cv::Mat K1_h = (cv::Mat_<double>(1, 3) << 1,2,1);

    cv::Mat K1_h = (cv::Mat_<double>(1, 3) << 1,2,1);
    cv::Mat K1_v = (cv::Mat_<double>(3, 1) << 1,0,-1);
    
    // Declare matrix to store intermediate image
    cv::Mat intermediate;

    // Now to actually convolve
    intermediate = convolve(input,  K1_v);         // Convolve Vertically
    output = convolve(intermediate, K1_h);        // Convolve Horizontally

    cv::namedWindow("Output by Naive Seperable Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output by Naive Seperable Convolution", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Vertical Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Vertical Convolution", intermediate);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Horizontal Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Horizontal Convolution", output);
    cv::waitKey(0); // Wait for key press before exiting


    return 0;
}
