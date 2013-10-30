
/*!  \brief  ProtoVerletSurface.h: Verlet surface implementation
 Protobyte Library v02
 
 Created by Ira on 6/5/13.
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

#include "ProtoVerletSurface.h"


using namespace ijg;


ProtoVerletSurface::ProtoVerletSurface(){
    
}

ProtoVerletSurface::ProtoVerletSurface(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3<float>& size, const ProtoColor4<float>& col4, int rowCount, int columnCount, float tension):
ProtoGeom3(pos, rot, size, col4), rowCount(rowCount), columnCount(columnCount), tension(tension)
{
    centroidIndex = (rowCount-2)/2*(columnCount) + columnCount/2;
    pulseTheta = 0;
    init(); // calls calcVertices/calcIndices/calcFaces/etc
}

// calculate verlet geoemetry
void ProtoVerletSurface::calcVerts(){
    
    // verlet sheet
    //ind = (rows-2)/2*(cols) + cols/2;
    std::cout << " size = " << size << std::endl;
    float cellW = 1.0/columnCount;
    float cellH = 1.0/rowCount;
    for(int i=0; i<rowCount; ++i){
        for(int j=0; j<columnCount; ++j){
            float x = -.5 + cellW*j;
            float y = .5 - cellH*i;
            balls.push_back(std::shared_ptr<ProtoVerletBall>(new ProtoVerletBall(Vec3f(x, y, 0))));
            verts.push_back( ProtoVertex3(Vec3f(x, y, 0),
                                          ProtoColor4f(col4.getR(), col4.getG(), col4.getB(), col4.getA()), ProtoTuple2f(x*.5, y*.5)));
        }
    }
    
    for(int i=0, k=0, l=0, m=0, n=0; i<rowCount-1; ++i){
        for(int j=0; j<columnCount-1; ++j){
            k = i*columnCount+j;
            l = (i+1)*columnCount+j;
            m = (i+1)*columnCount+j+1;
            n = i*columnCount+j+1;
            // corners
            // TL
            if (i==0 && j==0){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(1, 0))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(0, 1))));
                // TR
            } else  if (i==0 && j==columnCount-2){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(0, 1))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
                // BR
            }  else  if (i==rowCount-2 && j==columnCount-2){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, 0))));
                //BL
            } else  if (i==rowCount-2 && j==0){
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(1, 0))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(0, 1))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
            } else {
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(l), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(l), balls.at(m), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(m), balls.at(n), tension, Tup2f(.5, .5))));
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(n), balls.at(k), tension, Tup2f(.5, .5))));
                // diag
                sticks.push_back(std::unique_ptr<ProtoVerletStick>(new ProtoVerletStick(balls.at(k), balls.at(m), tension, Tup2f(.5, .5))));
                
            }
            
        }
    }
    
}


void ProtoVerletSurface::calcInds(){
    for(int i=0, k=0, l=0, m=0, n=0; i<rowCount-1; ++i){
        for(int j=0; j<columnCount-1; ++j){
            k = i*columnCount+j;
            l = (i+1)*columnCount+j;
            m = (i+1)*columnCount+j+1;
            n = i*columnCount+j+1;
            inds.push_back(ProtoTuple3i(k, l, m));
            inds.push_back(ProtoTuple3i(k, m, n));
        }
    }
    
    
}

void ProtoVerletSurface::nudge(int index){
    balls.at(index)->pos.z += 1.5;
}

// animate VBO data based on Verlet Integration
// TO DO: move this to FPU with Vertex Shader


// interleavedPrims stride = 12;
void ProtoVerletSurface::flow() {
    
    // Activate Verlet/constraints
    for (int i = 0; i < sticks.size(); ++i) {
        sticks.at(i)->constrainLen();
    }
    
    // Animate VBO data
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    for (int i = 0; i < inds.size(); ++i) {
        
        // verts
        interleavedPrims.at(inds.at(i).elem0 * 12) = balls.at(inds.at(i).elem0)->pos.x;
        interleavedPrims.at(inds.at(i).elem0 * 12 + 1) = balls.at(inds.at(i).elem0)->pos.y;
        interleavedPrims.at(inds.at(i).elem0 * 12 + 2) = balls.at(inds.at(i).elem0)->pos.z;
        
        interleavedPrims.at(inds.at(i).elem1 * 12) = balls.at(inds.at(i).elem1)->pos.x;
        interleavedPrims.at(inds.at(i).elem1 * 12 + 1) = balls.at(inds.at(i).elem1)->pos.y;
        interleavedPrims.at(inds.at(i).elem1 * 12 + 2) = balls.at(inds.at(i).elem1)->pos.z;
        
        interleavedPrims.at(inds.at(i).elem2 * 12) = balls.at(inds.at(i).elem2)->pos.x;
        interleavedPrims.at(inds.at(i).elem2 * 12 + 1) = balls.at(inds.at(i).elem2)->pos.y;
        interleavedPrims.at(inds.at(i).elem2 * 12 + 2) = balls.at(inds.at(i).elem2)->pos.z;
        
        //vnorms
        //        nz = cos(t) * interleavedPrims.at(i + 5) - sin(t) * interleavedPrims.at(i + 3);
        //        nx = sin(t) * interleavedPrims.at(i + 5) + cos(t) * interleavedPrims.at(i + 3);
        //        interleavedPrims.at(i + 5) = nz;
        //        interleavedPrims.at(i + 3) = nx;
        
    }
    int vertsDataSize = sizeof (float) *interleavedPrims.size();
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    balls.at(centroidIndex)->pos += Vec3f(cos(-pulseTheta)*ProtoMath::random(.001, .004), sin(pulseTheta)*ProtoMath::random(.001, .004), sin(pulseTheta)*ProtoMath::random(.003, .01));
    pulseTheta += ProtoMath::random(3, 12)*ProtoMath::PI/180.0;
}
