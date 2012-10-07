/*
 *  ofxStoredBlobVO.cpp
 *
 *  Created by Peter Uithoven on 5/6/11.
 */

#include "ofxStoredBlobVO.h"


ofxStoredBlobVO::ofxStoredBlobVO(ofxCvBlob& newBlob)
{
	// a quick "shallow" copy
	update(newBlob);


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
	pTip = tip;
	pTail = tail;

	centroid = newBlob.centroid;
	hole = newBlob.hole;
	pts = newBlob.pts;
	nPts = newBlob.nPts;

    ofPoint *tip = NULL;
    ofPoint *tail = NULL;
    ofPoint center(320,240); //center of sphere

    for (int j=0; j<newBlob.nPts; j++) {
        ofPoint &p = newBlob.pts.at(j);
        if (!tip || p.distance(center) < tip->distance(center)) tip = &p;
        if (!tail || p.distance(center) > tail->distance(center)) tail = &p;
    }

    if (tip) {
        this->tip = *tip;
        //if (pTip.x==0) pTip = *tip;
    }

    if (tail) {
        this->tail = *tail;
        //if (pTail.x==0) pTail = *tail;
    }



}
////
//ofPoint *tip = NULL;
//ofPoint *tail = NULL;
//
//for (int j=0; j<blob.nPts; j++) {
//    ofPoint &p = blob.pts.at(j);
//    if (!tip || p.distance(center) < tip->distance(center)) tip = &p;
//    if (!tail || p.distance(center) > tail->distance(center)) tail = &p;
//}
