
/*! File:   TransformFunction.cpp
 * Author: Ira Greenberg
 *
 * Created on May 19, 2013, 2:33 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#include "TransformFunction.h"
#include <iostream>

using namespace proto;

TransformFunction::TransformFunction() {
    isVectorRange = isScalerRange = false;
    vectorRange.elem0 = Vector3(0,0,0);
    vectorRange.elem1 = Vector3(1,1,1);
}

TransformFunction::TransformFunction(unsigned char functionType, /*bool isRandom = 0, */short periodCount) :
functionType(functionType), /*isRandom(isRandom), */periodCount(periodCount) {
    isVectorRange = isScalerRange = false;
    vectorRange.elem0 = Vector3(0,0,0);
    vectorRange.elem1 = Vector3(1,1,1);
}

TransformFunction::TransformFunction(unsigned char functionType, Tuple2v3 vectorRange, /*bool isRandom = 0, */short periodCount) :
functionType(functionType), vectorRange(vectorRange), /*isRandom(isRandom), */periodCount(periodCount) {
    isVectorRange = true;
    isScalerRange = false;
}

TransformFunction::TransformFunction(unsigned char functionType, Tuple2f scalerRange, /*bool isRandom = 0, */short periodCount) :
functionType(functionType), scalerRange(scalerRange), /*isRandom(isRandom), */periodCount(periodCount) {
    isVectorRange = false;
    isScalerRange = true;
    
    vectorRange.elem0 = Vector3(scalerRange.elem0, scalerRange.elem0, scalerRange.elem0);
    vectorRange.elem1 = Vector3(scalerRange.elem1, scalerRange.elem1, scalerRange.elem1);
}

TransformFunction::TransformFunction(unsigned char functionType, float maxValue, /*bool isRandom = 0, */short periodCount) :
functionType(functionType), maxValue(maxValue), /*isRandom(isRandom), */periodCount(periodCount) {
    isVectorRange = false;
    isScalerRange = false;
    vectorRange.elem0 = Vector3(0, 0, 0);
    vectorRange.elem1 = Vector3(maxValue, maxValue, maxValue);
}