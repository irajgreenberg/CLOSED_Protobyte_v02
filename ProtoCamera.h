/*!  \brief  ProtoCamera.h: (add brief description)
 ProtoCamera.h
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

#ifndef Protobyte_v02_ProtoCamera_cpp
#define Protobyte_v02_ProtoCamera_cpp

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <stdio.h>

//#ifdef  __APPLE__
//#include <GLUT/glut.h>
//#elif __linux
//#include <GL/glew.h>
//#include <GL/glut.h>
//#elif defined(_WIN32) || defined(_WIN64)
//#include <windows.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#endif

namespace ijg {
    
    class ProtoCamera {
    
    public:
        ProtoCamera();
        
        ProtoCamera(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane);
        
        // include in case of derived ProtoCamera class
        virtual ~ProtoCamera(); 
        
        // accessors/mutators
        unsigned char getUniqueID() const;

        
    private:
        float fovAngle;
        float aspectRatio;
        float nearClipPlane, farClipPlane;
        
        
        static unsigned char static_camera_count;
        
        // ProtoUniverse manages multiple camers through their unique_id
        unsigned char uniqueID;
        
                
    };
    
    inline unsigned char ProtoCamera::getUniqueID() const{
        return uniqueID;
    }
}


#endif // Protobyte_v02_ProtoCamera_cpp
