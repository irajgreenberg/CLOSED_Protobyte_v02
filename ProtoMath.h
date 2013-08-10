/*!  \brief  ProtMath.h: Protobyte Library math constants and random functions
 - all static 
 ProtoMath.h
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_MATH_H
#define	PROTO_MATH_H

#include <ctime>

namespace ijg {
    
    
    class ProtoMath {
    private:
        // disallow instantiation/assignment
        
        ProtoMath() {
        }
        
    public:
        
        // all static functions
        
        // from http://stackoverflow.com/a/686373
        
        static float random(float max = 1.0) {
            return (float) rand() / ((float) RAND_MAX / max);
        }
        
        // from http://stackoverflow.com/a/686373
        
        static float random(float min, float max) {
            return min + (float) rand() / ((float) RAND_MAX / (max - min));
            
        }
        
        // static fields
        static const double PI = 3.14159265358979;
        static const double HALF_PI = 1.5707963267949;
        static const double H_PI = 1.5707963267949; // alt name to HALF_PI
        static const double QUARTER_PI = 0.785398163397448;
        static const double Q_PI = 0.785398163397448; // alt name to QUARTER_PI
        static const double TWO_PI = 6.28318530717958;
        static const double DOUBLE_PI = 6.28318530717958; // alt name to TWO_PI
        static const double THREE_PI = 9.42477796077;
        static const double TRI_PI = 9.42477796077; // alt name to THREE_PI
    };
}

#endif	// PROTO_MATH_H

