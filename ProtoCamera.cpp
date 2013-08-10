/*!  \brief  ProtoCamera.cpp: (add brief description)
 ProtoCamera.cpp
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

#include "ProtoCamera.h"

using namespace ijg;

// inialize static counter
unsigned char ProtoCamera::static_camera_count = 0;

// default cstr
ProtoCamera::ProtoCamera() {
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane):
fovAngle(fovAngle), aspectRatio(aspectRatio), nearClipPlane(nearClipPlane), farClipPlane(farClipPlane) {
    static_camera_count++;
    uniqueID = static_camera_count;
    
    gluPerspective(fovAngle, aspectRatio, nearClipPlane, farClipPlane);
}

// dstr
ProtoCamera::~ProtoCamera() {
    
}
