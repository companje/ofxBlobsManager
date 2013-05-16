/*
 *  ofxStoredBlobVO.cpp
 *
 *  Created by Peter Uithoven on 5/6/11.
 */

#include "ofxStoredBlobVO.h"

ofPoint ofxStoredBlobVO::center; //center of sphere
float ofxStoredBlobVO::tipSmoothingFactor = .9f;

ofxStoredBlobVO::ofxStoredBlobVO(ofxCvBlob& newBlob)
{
	// a quick "shallow" copy
    age = 0;
	update(newBlob);
    firstPos = centroid;

	id = -1;
	lastDetectedTime = 0;
}

void ofxStoredBlobVO::update(ofxCvBlob& newBlob)
{
	// a quick "shallow" update
	area = newBlob.area;
	length = newBlob.length;
	boundingRect = newBlob.boundingRect;
	pCentroid = centroid;

	centroid = newBlob.centroid;
	hole = newBlob.hole;
	pts = newBlob.pts;
	nPts = newBlob.nPts;

    age++;


    //NOTE: find blob point nearest to center and average through time (make sure blob clustering is disabled)
	pTip = tip;
    ofPoint *localTip = NULL;

    for (int j=0; j<newBlob.nPts; j++) {
        ofPoint &p = newBlob.pts.at(j);
        if (!localTip || p.distance(center) < localTip->distance(center)) localTip = &p;
    }

    if (localTip) {
        if (tip.x==0) {
            pTip = tip = *localTip;
        } else {
            tip.x = pTip.x * f + localTip->x * (1 - f);
            tip.y = pTip.y * f + localTip->y * (1 - f);
        }

    }
}
