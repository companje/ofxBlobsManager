/*
 *  ofxStoredBlobVO.h
 *
 *  Created by Peter Uithoven on 5/6/11.
 */

#ifndef _ofxStoredBlobVO
#define _ofxStoredBlobVO

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofxStoredBlobVO : public ofxCvBlob {
public:
	int id;
	int lastDetectedTime; // the time when it was last detected
	int iniDetectedTime; // the time when it was first detected
	int dis; //used to sort on distance and to find the closest blob to merge with
    ofPoint pCentroid;
    ofPoint firstPos;
    int age;
    deque<ofPoint> tipHistory;

    ofPoint tip;
    ofPoint pTip;

    static ofPoint center;
    static float tipSmoothingFactor;
    static int tipHistorySize;

	ofxStoredBlobVO(ofxCvBlob& newBlob);
	void update(ofxCvBlob& newBlob);
};

#endif
