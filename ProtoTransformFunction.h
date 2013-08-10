
/*! File:   TransformFunction.h
 * Author: Ira Greenberg
 *
 * Created on May 18, 2013, 10:42 AM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef TRANSFORMFUNCTION_H
#define	TRANSFORMFUNCTION_H

#include "Tuple2.h"
#include "Vector3.h"

namespace proto {

    class TransformFunction {
    private:
        unsigned char functionType;
        float minValue, maxValue;
        Tuple2<Vector3> vectorRange;
        Tuple2f scalerRange;
       // bool isRandom;
        short periodCount;
        bool isVectorRange, isScalerRange;

    public:

        /*!
         * Default Constructor */
        TransformFunction();

        /*!
         * Constructor */
        TransformFunction(unsigned char functionType, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        TransformFunction(unsigned char functionType, Tuple2v3 vectorRange, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        TransformFunction(unsigned char functionType, Tuple2f scalerRange, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        TransformFunction(unsigned char functionType, float maxValue, /*bool isRandom = 0, */short periodCount = 1);



        /*!
         * getters/setters */

        void setPeriodCount(short periodCount);
        short getPeriodCount() const;
//        void setIsRandom(bool isRandom);
//        bool getIsRandom() const;
        void setScalerRange(Tuple2f scalerRange);
        Tuple2f getScalerRange() const;
        void setVectorRange(Tuple2v3 vectorRange);
        Tuple2v3 getVectorRange() const;
        void setMaxValue(float maxValue);
        float getMaxValue() const;
        void setMinValue(float minValue);
        float getMinValue() const;
        void setFunctionType(unsigned char functionType);
        unsigned char getFunctionType() const;

        bool getIsVectorRange();
        bool getIsScalerRange();

        //  Specifies Cross-section transform functions
        static const unsigned char LINEAR = 0x00;
        static const unsigned char LINEAR_INVERSE = 0x01;
        static const unsigned char SINUSOIDAL = 0x10;
        static const unsigned char SINUSOIDAL_INVERSE = 0x11;
        //static const unsigned char SINUSOIDAL_TRANSFORM_RANDOM = 0x11;

    };

    inline void TransformFunction::setPeriodCount(short periodCount) {
        this->periodCount = periodCount;
    }

    inline short TransformFunction::getPeriodCount() const {
        return periodCount;
    }

//    inline void TransformFunction::setIsRandom(bool isRandom) {
//        this->isRandom = isRandom;
//    }
//
//    inline bool TransformFunction::getIsRandom() const {
//        return isRandom;
//    }

    inline void TransformFunction::setScalerRange(Tuple2<float> scalerRange) {
        this->scalerRange = scalerRange;
    }

    inline Tuple2f TransformFunction::getScalerRange() const {
        return scalerRange;
    }

    inline void TransformFunction::setVectorRange(Tuple2<Vector3> vectorRange) {
        this->vectorRange = vectorRange;
    }

    inline Tuple2v3 TransformFunction::getVectorRange() const {
        return vectorRange;
    }

    inline void TransformFunction::setMaxValue(float maxValue) {
        this->maxValue = maxValue;
    }

    inline float TransformFunction::getMaxValue() const {
        return maxValue;
    }

    inline void TransformFunction::setMinValue(float minValue) {
        this->minValue = minValue;
    }

    inline float TransformFunction::getMinValue() const {
        return minValue;
    }

    inline void TransformFunction::setFunctionType(unsigned char functionType) {
        this->functionType = functionType;
    }

    inline unsigned char TransformFunction::getFunctionType() const {
        return functionType;
    }

    inline bool TransformFunction::getIsVectorRange() {
        return isVectorRange;
    }

    inline bool TransformFunction::getIsScalerRange() {
        return isScalerRange;
    }



}
#endif	/* TRANSFORMFUNCTION_H */

