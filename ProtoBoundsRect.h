/*!  \brief  ProtoBoundsRect.h: (add brief description)
 ProtoBoundsRect.h
 Protobyte Library v02
 
 Created by Ira on 8/16/13.
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

#ifndef Protobyte_dev_v02_ProtoBoundsRect_h
#define Protobyte_dev_v02_ProtoBoundsRect_h

#include <iostream>

namespace ijg {
    
    template<class T>
    class ProtoBoundsRect {
        
    public:
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const ProtoBoundsRect<U>& bounds);
        
        ProtoBoundsRect();
        ProtoBoundsRect(T x, T y, T w, T h);
        ProtoBoundsRect(T xywh[4]);
        virtual ~ProtoBoundsRect() {}
        
        T x;
        T y;
        T w;
        T h;
        
    private:
        
    };
    
    template<typename T>
    std::ostream& operator<<(std::ostream& out, const ProtoBoundsRect<T>& bounds){
        out << bounds.x << ", " << bounds.y << ", " << bounds.w << ", " << bounds.h;
        return out;
    }
    
    template<typename T>
        inline ProtoBoundsRect<T>::ProtoBoundsRect():
    x(static_cast<T>(0.0)), y(static_cast<T>(0.0)), w(static_cast<T>(1.0)), h(static_cast<T>(1.0)){
        
    }
                                            
    template<typename T>
        inline ProtoBoundsRect<T>::ProtoBoundsRect(T x, T y, T w, T h):
    x(x), y(y), w(w), h(h){
        
    }
    
    template<typename T>
        inline ProtoBoundsRect<T>::ProtoBoundsRect(T xywh[4]):
        x(xywh[0]), y(xywh[1]), w(xywh[2]), h(xywh[3]) {
    }
}

#endif // Protobyte_dev_v02_ProtoBoundsRect_h
