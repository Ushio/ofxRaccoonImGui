#pragma once

#include "ofMain.h"
#include <imgui.h>

// C:\Users\ushiostarfish\Documents\tools\vcpkg\buildtrees\imgui\src\v1.60-e689933ef6\examples\opengl2_example
class ofxImguiTool {
public:
	void setup() {

	}
};

class ofApp : public ofBaseApp{
public:
	void setup();
	void exit();

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

};
