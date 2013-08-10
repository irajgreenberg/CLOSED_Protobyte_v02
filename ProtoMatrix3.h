/*!  \brief  ProtoMatrix3.h: 3D Matrix implementation
 ProtoMatrix3.h
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


#ifndef PROTO_MATRIX3_H
#define	PROTO_MATRIX3_H

#include "ProtoVector3.h"


namespace ijg {

    template <class T>
    class ProtoMatrix3 {
    public:
        ProtoMatrix3();
        ProtoMatrix3(float mat3[9]);
        void rotate(float theta, const ProtoVector3& axis, ProtoVector3& v);
        ProtoVector3 getRotate(float theta, const ProtoVector3& axis, const ProtoVector3& vec);
        void transpose();
        void determinent();
        void mult(const ProtoMatrix3& m);
        ProtoVector3 mult(const ProtoVector3& vec);
        void add();
        void identity();

    private:
        float mat3[9];

    };
}

#endif	// PROTO_MATRIX3_H 

