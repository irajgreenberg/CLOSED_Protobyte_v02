/*!  \brief  ProtoFace3.h: 3 sided polygon class
 ProtoFace3.h
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

#ifndef PROTO_FACE3_H
#define PROTO_FACE3_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif __linux
#include <GL/gl.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <GL/gl.h>
#endif

#include <vector>
#include "ProtoVertex.h"
#include "ProtoVector3.h"
#include <cmath>
#include <iostream>

namespace ijg {

    class ProtoFace3 {
    private:
        //ProtoVector3 vecs[3];
        // ProtoVector3 v0, v1, v2;
        ProtoVertex vecs[3];
        //ProtoVertex v0, v1, v2;
        //ProtoVertex *v0_p, *v1_p, *v2_p;
        ProtoVector3 norm, centroid;

        void init();

        void calcNorm();
        void calcCentroid();


    public:
        friend std::ostream& operator<<(std::ostream& output, const ProtoFace3& face3);

        //ProtoFace3(ProtoVertex& v0, ProtoVertex& v1, ProtoVertex& v2);
        ProtoFace3(ProtoVertex* v0_p, ProtoVertex* v1_p, ProtoVertex* v2_p);
        void display();

        const ProtoVector3& getNorm() const;
        const ProtoVector3& getCentroid() const;


        //const ProtoVertex& operator[](int index);
        const ProtoVertex* operator[](int index);
        
        ProtoVertex *v0_p, *v1_p, *v2_p;

    };
}

#endif /* defined(PROTO_FACE3_H) */
