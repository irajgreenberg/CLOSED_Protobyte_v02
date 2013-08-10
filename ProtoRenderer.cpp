/*!  \brief  ProtoRenderer.cpp: Coordinates all rendering in ProtoUniverse
 ProtoRenderer.cpp
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

#include "ProtoRenderer.h"

using namespace ijg;

ProtoRenderer* ProtoRenderer::singletonRenderer = 0;


ProtoRenderer& ProtoRenderer::operator=(const ProtoRenderer& renderer) {
    return *this;
}

// private default cstr to enforce singleton pattern
ProtoRenderer::ProtoRenderer(){
    init();
}

void ProtoRenderer::init(){
#ifdef  __linux__
    // Call to utilize all the neato things in Linux/Win - loads extensions
    glewInit();
    
    /* screwy and not working
     if (glInfo.isExtensionSupported("GL_vertex_buffer_object")) {
     //vboSupported = vboUsed = true;
     std::cout << "Video card supports GL_vertex_buffer_object." << std::endl;
     } else {
     //vboSupported = vboUsed = false;
     std::cout << "Video card does NOT support GL_vertex_buffer_object." << std::endl;
     }*/
#endif
    glGenBuffers(1, &vboID); // Create the buffer ID
    glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)
    int vertsDataSize = sizeof (float) *interleavedPrims.size();
    glBufferData(GL_ARRAY_BUFFER, vertsDataSize, NULL, GL_STREAM_DRAW); // allocate space
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
    //glBufferData(GL_ARRAY_BUFFER, vertsDataSize, &interleavedPrims[0], GL_STATIC_DRAW); // allocate and upload
    //sharedMemPointer = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
    //std::cout << "sharedMemPointer = " << sharedMemPointer << std::endl;
    
    //indices data - use GL_ELEMENT_ARRAY_BUFFER
    glGenBuffers(1, &indexVBOID); // Generate buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID); // Bind the element array buffer
    int indsDataSize = inds.size()*3 * sizeof (GL_UNSIGNED_INT);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, NULL, GL_DYNAMIC_DRAW); // allocate
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indsDataSize, &indPrims[0]); // upload the data
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, &indPrims[0], GL_STATIC_DRAW); // allocate and upload
    
    //    if (glMapBuffer && glUnmapBuffer) {
    //        //std::cout << "glMapBuffer is supported" << std::endl;
    //    }
    
    
}

ProtoRenderer* ProtoRenderer::getInstance()
{
    
    // allocation hasn't happened yet, so do it
    if(singletonRenderer == 0)
    {
        std::cout<<"Singleton ProtoRenderer obj created"<<std::endl;
        singletonRenderer = new ProtoRenderer();
        return singletonRenderer;
    }
    // pointer to object already exists just return it
    else
    {
        std::cout<<"Pointer to existing Singleton ProtoRenderer obj returned"<<std::endl;
        return singletonRenderer;
    }
    
}

void ProtoRenderer::draw(const ProtoGeomBase& geomObj, displayMode mode, renderMode render, float pointSize) {
        switch (render) {
            case POINT_CLOUD:
                glDisable(GL_CULL_FACE);
                glDisable(GL_LIGHTING);
                glPointSize(pointSize);
                break;
                
            case WIREFRAME:
                glDisable(GL_CULL_FACE);
                glDisable(GL_LIGHTING);
                glLineWidth(1.0f);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                break;
                
            case SURFACE:
                glEnable(GL_CULL_FACE);
                glEnable(GL_LIGHTING);
                glPolygonMode(GL_FRONT, GL_FILL);
                break;
        }
        // hackity-hack - fix eventually
        static float rx = .02;
        static float ry = .03;
        static float rz = .04;
        glPushMatrix();
        //glLoadIdentity();
        
        glTranslatef(pos.x, pos.y, pos.z);
        glRotatef(rot.x, 1, 0, 0); // x-axis
        glRotatef(rot.y, 0, 1, 0); // y-axis
        glRotatef(rot.z, 0, 0, 1); // z-axis
        glScalef(size.w, size.h, size.d);
        
        
        switch (mode) {
            case IMMEDIATE:
                //glDeleteLists(displayListIndex, 1);
                for (int i = 0; i < faces.size(); ++i) {
                    faces.at(i).display();
                }
                break;
                
            case VERTEX_ARRAY:
                // ensure data not bound to VBO
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                
                // ensure Diaplsy list released
                glDeleteLists(displayListIndex, 1);
                
                glEnableClientState(GL_NORMAL_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                
                
                glNormalPointer(GL_FLOAT, 0, &normPrims[0]);
                glColorPointer(4, GL_FLOAT, 0, &colorPrims[0]);
                glVertexPointer(3, GL_FLOAT, 0, &vertPrims[0]);
                glTexCoordPointer(2, GL_FLOAT, 0, &texturePrims[0]);
                
                if (render == POINT_CLOUD) {
                    glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
                } else {
                    glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
                    
                    
                }
                
                // deactivate arrays after drawing
                glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
                glDisableClientState(GL_NORMAL_ARRAY);
                glDisableClientState(GL_COLOR_ARRAY);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                break;
                
            case VERTEX_ARRAY_INTERLEAVED:
                // ensure data not bound to VBO
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                
                // ensure Diaplsy list released
                glDeleteLists(displayListIndex, 1);
                
                glEnableClientState(GL_NORMAL_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                
                // stride is 12 : (x, y, z, nx, ny, nz, r, g, b, a, u, v)
                // // vertices, normals, color, texture
                glVertexPointer(3, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0]);
                glNormalPointer(GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 3);
                glColorPointer(4, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 6);
                glTexCoordPointer(2, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 10);
                
                if (render == POINT_CLOUD) {
                    glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
                } else {
                    glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
                }
                
                // disable stuff
                glDisableClientState(GL_NORMAL_ARRAY);
                glDisableClientState(GL_COLOR_ARRAY);
                glDisableClientState(GL_VERTEX_ARRAY);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                break;
                
            case DISPLAY_LIST:
                glCallList(displayListIndex);
                break;
                
            case VERTEX_BUFFER_OBJECT:
                //glDeleteLists(displayListIndex, 1);
                
                // make sure data is bound to buffer
                glBindBuffer(GL_ARRAY_BUFFER, vboID);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
                
                // enable and specify pointers to vertex arrays
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                
                // stride is 12 : (x, y, z, nx, ny, nz, r, g, b, a, u, v)
                // vertices, normals, color
                glVertexPointer(3, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(0));
                glNormalPointer(GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(12)); // step over 3 bytes
                glColorPointer(4, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(24)); // step over 6 bytes
                glTexCoordPointer(2, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(40)); // step over 10 bytes
                
                if (render == POINT_CLOUD) {
                    glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
                } else {
                    glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
                }
                
                glDisableClientState(GL_NORMAL_ARRAY);
                glDisableClientState(GL_COLOR_ARRAY);
                glDisableClientState(GL_VERTEX_ARRAY);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                
                // free pointers to data
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                
                break;
                
        }
        glPopMatrix();
        
        // reset fill and lighting
        glEnable(GL_LIGHTING);
        glPolygonMode(GL_FRONT, GL_FILL);
        
    }

    
}
