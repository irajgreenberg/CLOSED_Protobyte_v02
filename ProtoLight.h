/*!  \brief  ProtoLight.h: (add brief description)
 ProtoLight.h
 Protobyte Library v02
 
 Created by Ira on 8/26/13.
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

#ifndef Protobyte_dev_v02_ProtoLight_cpp
#define Protobyte_dev_v02_ProtoLight_cpp

#include <iostream>
#include "ProtoColor4.h"

namespace ijg {
    
    class ProtoLight {
    
    public:
        ProtoLight();
        ~ProtoLight();
        
        enum lightPosMode{
            DIRECTIONAL_INFINITE,
            POSITIONAL
        };
        
    private:
        ProtoColor4f diffuse, ambient, specular, emmissive;
        
        
    };
}

#endif // Protobyte_dev_v02_ProtoLight_cpp
