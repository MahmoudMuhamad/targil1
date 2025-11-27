#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Open the default camera (0 = default device)
    VideoCapture cap;
    cap.open(0, CAP_DSHOW); // Using DirectShow backend

    if (!cap.isOpened()) {
        cout << "No video stream detected" << endl;
        cout << "Press Enter to exit...";
        cin.get();
        return -1;
    }

    cout << "Camera opened successfully! Press ESC to exit." << endl;

    Mat frame;                      // Matrix to store each captured frame
    const string windowName = "Video Player";

    // Create the display window once
    namedWindow(windowName, WINDOW_AUTOSIZE);

    while (true) {
        // Read a frame from the camera
        if (!cap.read(frame) || frame.empty()) {
            cout << "Invalid frame detected" << endl;
            break;
        }

        // Show the frame in the window
        imshow(windowName, frame);

        // Wait 25ms and check if ESC key (27) is pressed
        int key = waitKey(25);
        if (key == 27) { // ESC pressed
            break;
        }
    }

    // Release camera and destroy window
    cap.release();
    destroyWindow(windowName);
    cout << "Video capture ended." << endl;

    return 0;
}
