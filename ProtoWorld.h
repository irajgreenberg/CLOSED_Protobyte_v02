/*!  \brief  ProtoWorld.h: Top Level Master controller class -
 Implmented as a pointer singleton
 ProtoWorld.h
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

#ifndef Protobyte_v02_ProtoWorld_cpp
#define Protobyte_v02_ProtoWorld_cpp

#include <iostream>
#include <vector>
#include "ProtoCamera.h"
//#include "ProtoAnimator.h"
//#include "ProtoRenderer.h"

// from http://www.nuonsoft.com/blog/2012/10/21/implementing-a-thread-safe-singleton-with-c11/
// to ensure thread safety
#include <memory>
#include <mutex>

namespace ijg {
    
    class ProtoWorld {
        
    private:
        
        // field for singleton instance
        static std::unique_ptr<ProtoWorld> singletonWorld;
        static std::once_flag protoOnceFlag; // for thread saftety
        
        // private default cstr to enforce singleton pattern
        ProtoWorld();
        
        // disallow overriding copy cstr
        ProtoWorld(const ProtoWorld& world);
        
        // disallow overriding operator=
        ProtoWorld& operator=(const ProtoWorld& world);
        
        
        // Camera stuff
        std::vector< std::unique_ptr<ProtoCamera> > cameras;
        static unsigned char cameraCount;
        static const unsigned char CAMERA_COUNT_MAX;
        
        //iterator
        //std::vector<ProtoCamera&>::iterator cameraObjsIter;
        
        // set world managers : no access outside of class
        //        std::unique_ptr<ProtoAnimator>  animator; // singleton
        //        std::unique_ptr<ProtoRenderer> renderer; // singleton
        
        // controls rendering style (point cloud, wireframe or surface)
        //ProtoRenderer::RenderModeEnum renderMode;
        
        void init();
        //
        //        // collection of all ProtoGeomBase ptrs
        //        std::vector<ProtoGeomBase*> geomObjs;
        //        // iterator
        //        std::vector<ProtoGeomBase*>::iterator geomObjsIter;
        //

        
    public:
        
        friend std::ostream& operator<<(std::ostream& out, const ProtoWorld& protoWorld);
        
        // only returns a single instance
        static ProtoWorld& getInstance();
        
        // dstr
//        ~ProtoWorld();
        
        // overloaded assignment op
        //ProtoWorld& operator=(const ProtoWorld& world);
        
        /****** add/remove stuff to the ProtoWorld ******/
        // adds ProtoGeomBase/ProtoGeomComposite pointers
        //        void add(ProtoGeomBase* baseObj); // single geometric obj
        //        void add(ProtoGeomComposite* compositeObj); // composite geometric obj
        //
        
        // adds camera obs
        void add(std::unique_ptr<ProtoCamera> camera);
      
        
        
        //        // cleans up containers but NOT memory
        //        void remove(ProtoGeomBase* graphicsObj);
        //        void remove(ProtoCamera* camera);
        
        
        // run world
        void run();
        
        // stop world
        void stop();
        
        
        // state changes
        //        void setRenderState(ProtoRenderer::RenderModeEnum renderMode = ProtoRenderer::SURFACE, float pointSize = 3.5f);
        
        
    };
}

#endif // Protobyte_v02_ProtoWorld_cpp
