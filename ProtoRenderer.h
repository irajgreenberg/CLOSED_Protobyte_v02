/*!  \brief  ProtoRenderer.h: Coordinates all rendering in ProtoUniverse
 ProtoRenderer.h
 Protobyte Library v02
 
 Created by Ira on 7/25/13.
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

#ifndef Protobyte_v02_ProtoRenderer_cpp
#define Protobyte_v02_ProtoRenderer_cpp

#ifdef  __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __linux
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN64
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#endif

#include <iostream>
#include "ProtoGeomBase.h"
#include "ProtoGeomComposite.h"

namespace ijg {
    
    // for offset into the VBO interleaved buffer (ugly I know!)
    #define BUFFER_OFFSET(i) ((void*)(i))

    class ProtoRenderer {
    
    private:
        // field for singleton instance
        static ProtoRenderer* singletonRenderer;
        
        // private default cstr to enforce singleton pattern
        ProtoRenderer();
        
        // disallow overriding copy cstr
        ProtoRenderer(const ProtoRenderer& renderer);
        
        void init();
        
        // Display List var
        GLuint displayListIndex;
        
        // VBO stuff
        GLuint vboID, indexVBOID;
        
        //shared memory pointer for dynamic VBO's
        float* sharedMemPointer;
        
        // Utility for GL extension support
        ProtoGLInfo glInfo;

        
    public:
        
        /**********************************
         *    Display Modes for testing   *
         *********************************/
        enum DisplayModeEnum {
            IMMEDIATE, // begin at 0
            VERTEX_ARRAY,
            VERTEX_ARRAY_INTERLEAVED,
            DISPLAY_LIST,
            VERTEX_BUFFER_OBJECT
        };
        
        enum RenderModeEnum {
            POINT_CLOUD,
            WIREFRAME, // begin at 0
            SURFACE
        };
        
        // dstr
        ~ProtoRenderer();
        
        // only returns a single instance
        static ProtoRenderer* getInstance();
        
        // overloaded assignment op
        ProtoRenderer& operator=(const ProtoRenderer& renderer);
        
        void draw(const ProtoGeomBase& geomObj);
        
        
    };
}

#endif // Protobyte_v02_ProtoRenderer_cpp
