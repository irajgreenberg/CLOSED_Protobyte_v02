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
#include "ProtoBoundsRect.h"
#include "ProtoCamera.h"
//#include "ProtoAnimator.h"
//#include "ProtoRenderer.h"

// from http://www.nuonsoft.com/blog/2012/10/21/implementing-a-thread-safe-singleton-with-c11/
// to ensure thread safety
#include <memory>
#include <mutex>

//#define NDEBUG //uncomment for production code
#include <cassert>

namespace ijg {
    
    class ProtoWorld {
        
    private:
        
        // field for singleton instance
        static std::unique_ptr<ProtoWorld> singletonWorld;
        static std::once_flag protoOnceFlag; // for thread safety
        
        // private default cstr to enforce singleton pattern
        ProtoWorld();
        
        // private copy cstr
        ProtoWorld(const ProtoWorld& world);
        
        // private operator=
        //ProtoWorld& operator=(const ProtoWorld& world);
        
        
        // Camera stuff
        static ProtoBoundsRect<float> canvasBounds; // for aspect ratio
        std::vector< std::unique_ptr<ProtoCamera> > cameras; // holds up to 4 cameras
        static unsigned char cameraCount; // 1-4
        static const unsigned char CAMERA_COUNT_MAX; // 4
        
        Vec3f worldRotSpeed;
        
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
        
       
        // need to implement this function
        
        int activeCamera;
        

        
    public:
        
        static float canvasWidth, canvasHeight;
        
        // for multiple views
        enum WorldView {
            SINGLE_VIEW,
            DOUBLE_VIEW_LANDSCAPE,
            DOUBLE_VIEW_PORTRAIT,
            QUAD_VIEW
        };
        
        float fovAngle;
        float nearClipPlane;
        float farClipPlane;
        WorldView worldView;
        
        
        friend std::ostream& operator<<(std::ostream& out, const ProtoWorld& protoWorld);
        
        // singleton pattern
        //static ProtoWorld& getInstance();
        static ProtoWorld& getInstance(float canvasWidth = 100.0, float canvasHeight = 100.0);
        
        
        /****** add/remove stuff to the ProtoWorld *******
        * using overloaded add functions
        *************************************************/
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
        
        void draw();
        
        void rotate(const Vec3f& worldRot);
        
        
        // state changes
        //        void setRenderState(ProtoRenderer::RenderModeEnum renderMode = ProtoRenderer::SURFACE, float pointSize = 3.5f);
        
        void setWorldRotSpeed(const Vec3f& worldRotSpeed);
        //void setWorldFrustum(float fovAngle=60, float nearClipPlane = 0.1f, float farClipPlane = 1000.0f);
        void setWorldView(WorldView worldView = QUAD_VIEW);
        void setCurrentCamera(int cameraID1, int cameraID2);
        void setCurrentCameras();
        void setActiveCamera(int activeCamera);
        void setDefaultProjection(float fovAngle=60, float nearClipPlane = 0.1f, float farClipPlane = 1000.0f);
        
        
    };
}

#endif // Protobyte_v02_ProtoWorld_cpp
