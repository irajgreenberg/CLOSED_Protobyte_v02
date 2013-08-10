/*! \File:   ProtoBlock.h
 * Simple Hexahedron class   
 * ProtoBlock.h
 * Author: 33993405
 *
 * Created on April 6, 2013, 1:19 PM
 */

#ifndef ProtoBLOCK_H
#define	ProtoBLOCK_H

#include <iostream>
#include "ProtoGeomBase.h"

namespace ijg {

    class ProtoBlock : public ProtoGeomBase {
    public:
        friend std::ostream& operator<<(std::ostream& out, const Block& block);

        /*!
         * Default Constructor */
        ProtoBlock();
        /*!
         * Constructor */
        ProtoBlock(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
                const Color4<float>& col4);
        /*!
         * Constructor */
        ProtoBlock(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
                const Color4<float>& col4, float textureScale);

        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes.
         * 
         * Generates all vertices.*/
        void calcVerts();
        
        
        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes: 
         * 
         * Generates indices to group vertices to triangle faces.*/
        void calcInds();
      

    };
}

#endif	/* ProtoBLOCK_H */

