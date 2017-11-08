#pragma once

#include "ofMain.h"


// you may have to change these paths...
// this is the path to chainer-fast-neuralstyle
#define NEURAL_STYLE_PATH "/home/elian/Documents/repos/chainer-fast-neuralstyle"

// openframeworks overwrites the path so you can't find CUDA.
// if you have the chainer script working, just change this so it matches what
// you get if you run "echo $PATH" in a terminal
#define PATH "/usr/local/cuda-8.0/bin:/home/elian/torch/install/bin:/home/elian/torch/install/bin:/home/elian/bin:/home/elian/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

// same thing for "echo $LD_LIBRARY_PATH"
#define LD_LIBRARY_PATH "/usr/local/cuda-8.0/lib64/:/home/elian/torch/install/lib:/home/elian/torch/install/lib:"

// if you have CUDA and your paths are correct, set this to 1. otherwise set to 0
#define GPU_ENABLED 1


#include "worker.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    // these are hardcoded since you can't put threads in a vector
    ThreadedObject worker1, worker2, worker3, worker4;
    
    ofVideoGrabber grab;
    
    ofImage cam_img;
    ofImage chainer_img;
    
    float last, t;
    float min_lapse;
};
