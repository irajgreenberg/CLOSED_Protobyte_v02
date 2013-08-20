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
#include "ProtoMath.h"
#include "ProtoBoundsRect.h"
#include "ProtoVector3.h"
#include <string>

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
        // cstrs
        ProtoCamera();
        ProtoCamera(const Vec3f& pos, const Vec3f& rot);
        ProtoCamera(const Vec3f& pos, const Vec3f& rot, float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane);
        ProtoCamera(const Vec3f& pos, const Vec3f& rot, float frustumVals[4]);
        ProtoCamera(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane);
        ProtoCamera(float frustumVals[4]);
        
        // include in case of derived ProtoCamera class
        virtual ~ProtoCamera();
        
        // accessors/mutators
        unsigned char getUniqueID() const;
        
        void setName(std::string name);
        std::string getName() const;
        
        void project();
        
        void setProjection(float fovAngle, float aspectRatio, float nearClipPlane = .1f, float farClipPlane = 1000.0f);
        void setPosition(const Vec3f& pos);
        void setRotation(const Vec3f& rot);
        void setViewPort(float x, float y, float w, float h);
        
    private:
        Vec3f pos, rot;
        float fovAngle;
        float aspectRatio;
        float nearClipPlane, farClipPlane;
        std::string name;
        ProtoBoundsRect<float> viewPort;
        
        
        static unsigned char static_camera_count;
        
        // ProtoWorld manages multiple cameras through their unique_id
        unsigned char uniqueID;
        
        };
        
        inline void ProtoCamera::setPosition(const Vec3f& pos) {
            this->pos = pos;
        }
        
        inline void ProtoCamera::setRotation(const Vec3f& rot){
            this->rot = rot;
        }
        
        inline unsigned char ProtoCamera::getUniqueID() const{
            return uniqueID;
        }
        
        inline void ProtoCamera::setName(std::string name){
            this->name = name;
            
        }
        
        inline std::string ProtoCamera::getName() const {
            return name;
        }
        
    }
    
    
#endif // Protobyte_v02_ProtoCamera_cpp
