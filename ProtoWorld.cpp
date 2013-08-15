/*!  \brief  ProtoWorld.cpp: Top Level Master class
 ProtoWorld.cpp
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

#include "ProtoWorld.h"

namespace ijg {
    std::ostream& operator<<(std::ostream& out, const ProtoWorld& protoWorld){
        out << "ijg::protoWorld@"<< &protoWorld;
        return out;
    }
}

using namespace ijg;

// initialize static vars
unsigned char ProtoWorld::cameraCount=0;
const unsigned char ProtoWorld::CAMERA_COUNT_MAX=4;

std::unique_ptr<ProtoWorld> ProtoWorld::singletonWorld = nullptr;
std::once_flag ProtoWorld::protoOnceFlag;

//private cstr called internally
ProtoWorld::ProtoWorld() {
    init();
}

// dstr
//ProtoWorld::~ProtoWorld() {
//
//}

//ProtoWorld& ProtoWorld::operator=(const ProtoWorld& world) {
//    return *this;
//}


ProtoWorld& ProtoWorld::getInstance() {
    
    // allocation hasn't happened yet, so do it
    if(singletonWorld == nullptr)
    {
        std::cout<<"Singleton ProtoWorld obj created"<<std::endl;
        
        std::call_once(protoOnceFlag,
                       [] {singletonWorld.reset(new ProtoWorld);
                       });
        return *singletonWorld.get();
        
    }
    // pointer to object already exists just return it
    else
    {
        std::cout<<"Pointer to existing Singleton ProtoWorld obj returned"<<std::endl;
        return *singletonWorld.get();
    }
}

void ProtoWorld::init(){
    
    // CREATE DEFAULT CAMERA
    
    
    std::unique_ptr<ProtoCamera> camera1(new ProtoCamera);
    add(std::move(camera1));
    std::unique_ptr<ProtoCamera> camera2(new ProtoCamera);
    add(std::move(camera2));
    std::unique_ptr<ProtoCamera> camera3(new ProtoCamera);
    add(std::move(camera3));
    std::unique_ptr<ProtoCamera> camera4(new ProtoCamera);
    add(std::move(camera4));
    std::unique_ptr<ProtoCamera> camera5(new ProtoCamera);
    add(std::move(camera5));
    std::unique_ptr<ProtoCamera> camera6(new ProtoCamera);
    add(std::move(camera6));
    
    
    // CREATE DEFAULT RENDERER
    // enable renderer and animator
    //    renderer = ProtoRenderer::getInstance();
    
    // CREATE DEFAULT ANIMATOR
    //    animator = ProtoAnimator::getInstance();
}

//void ProtoWorld::add(ProtoGeomBase* geomObj){
//   // geomObjs.push_back(geomObj);
//}
//
//void ProtoWorld::add(ProtoGeomComposite* geomObj){
//    // TO DO
//}
//

void ProtoWorld::add(std::unique_ptr<ProtoCamera> camera){
    if(ProtoWorld::cameraCount < ProtoWorld::CAMERA_COUNT_MAX){
        cameras.push_back(std::move(camera));
        ProtoWorld::cameraCount++;
    }
    for(int i=0; i<cameras.size(); ++i){
        //std::cout << "cameras.at("<<i<<")->getUniqueID() = " << int(cameras.at(i)->getUniqueID()) << std::endl;
    }
    std::cout << "ProtoWorld::cameraCount = "<< static_cast<int>(ProtoWorld::cameraCount) << std::endl;
}


//void ProtoWorld::remove(ProtoGeomBase* geomObj) {
//}


//void ProtoWorld::remove(ProtoCamera* camera){
//    if(cameras.size()>0){
//        for(cameraObjsIter=cameras.begin(); cameraObjsIter < cameras.end(); ++cameraObjsIter){
//            if( (*cameraObjsIter)->getUniqueID() == camera->getUniqueID()){
//                cameras.erase(cameraObjsIter);
//
//            }
//        }
//    }
//    std::cout << "cameras.size() = " << cameras.size() << std::endl;
//}


// run world
void ProtoWorld::run() {
    //    for(geomObjsIter=geomObjs.begin(); geomObjsIter < geomObjs.end(); ++geomObjsIter){
    //        if(*geomObjsIter != 0){
    //           // renderer->draw(*geomObjsIter);
    //
    //        }
    //    }
}

// stop world
void ProtoWorld::stop(){
}


// set states
//void setRenderState(ProtoRenderer::RenderModeEnum renderMode, float pointSize) {
//   // this->renderMode = renderMode;
//}




