/*!  \brief  ProtoVector2.h: Templated 2D vector class
 ProtoVector2.h
 Protobyte Library v02
 
 Created by Ira on 8/5/13.
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

#ifndef PROTO_VECTOR2_H
#define PROTO_VECTOR2_H

#include <string.h>
#include <iostream>
#include <cmath>
#include <cassert>


namespace ijg {
    
    // forward declaration for non-member ops
    template <class T> class ProtoVector2;
    
    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // add vecs
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // sub vecs
    
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // mult by vec
    
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // div by vec
    
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, T s); // add by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator+(T s, const ProtoVector2<T>& rhs); // add by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, T s); // sub by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator-(T s, const ProtoVector2<T>& rhs); // sub by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, T s); // mult by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator*(T s, const ProtoVector2<T>& rhs); // mult by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, T s); // div by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator/(T s, const ProtoVector2<T>& rhs); // div by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& rhs); // negate vec
    
    template <typename T>
    T mag(const ProtoVector2<T>& v); // vec length
    
    template <typename T>
    T angleBetween(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // angle between vecs
    
    template <typename T>
    T dot(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // vec dot
    
    
    // class declaration
    template <class T>
    class ProtoVector2 {
        
    public:
        
        // overloaded << operator declared as friend function for access to private data
        template <typename U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoVector2<U>& vec);
        
        // fields
        T x, y;
        
        /*****************************************************/
        /*                    Constructors                   */
        /*****************************************************/
        ProtoVector2();
        ProtoVector2(T x, T y);
        explicit ProtoVector2(T xy[2]);
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        const ProtoVector2& operator+=(const ProtoVector2& v);
        const ProtoVector2& operator+=(T s);
        const ProtoVector2& operator-=(const ProtoVector2& v);
        const ProtoVector2& operator-=(T s);
        const ProtoVector2& operator*=(const ProtoVector2& v);
        const ProtoVector2& operator*=(T s);
        const ProtoVector2& operator/=(const ProtoVector2& v);
        const ProtoVector2& operator/=(T s);
        const ProtoVector2& operator-();
        const ProtoVector2& operator++();
        const ProtoVector2& operator++(int);
        const ProtoVector2& operator--();
        const ProtoVector2& operator--(int);
        
        T operator[](unsigned index);
        const T operator[](unsigned index) const;
        bool operator==(const ProtoVector2& v) const;
        bool operator!=(const ProtoVector2& v) const;
        
        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        T mag() const;
        T magSqr() const;
        void normalize();
        bool isNormalized() const;
        T angle() const;
        T angleBetween(const ProtoVector2& v) const;
        T dot(const ProtoVector2& v) const;
        const ProtoVector2& rotate(T theta);
        
        
    private:
        // nada for now
        
    };
    
    /*****************************************************/
    /*          Non-Member Function definitions          */
    /*****************************************************/
    
    // add vecs
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)+=rhs;
    }
    
    // subtract vecs
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)-=rhs;
    }
    
    // mult vecs
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(lhs)*=rhs;
    }
    
    // div vecs
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)/=rhs;
    }
    
    // add lhs by sclr
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)+=s;
    }
    
    // add rhs by sclr
    template <typename T>
    ProtoVector2<T> operator+(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)+=s;
    }
    
    // sub lhs by sclr
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)-=s;    }
    
    // sub rhs by sclr
    template <typename T>
    ProtoVector2<T> operator-(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)-=s;
    }
    
    // mult lhs by sclr
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)*=s;    }
    
    // mult rhs by sclr
    template <typename T>
    ProtoVector2<T> operator*(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)*=s;
    }
    
    // div lhs by sclr
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)/=s;
    }
    
    // div rhs by sclr
    template <typename T>
    ProtoVector2<T> operator/(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)/=s;
    }
    
    // invert signs
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(rhs)*=-1;
    }
    
    // vec magnitude
    template <typename T>
    T mag(const ProtoVector2<T>& v){
        return sqrt(v.x*v.x + v.y*v.y);
    }
    
    // angle between vecs
    template <typename T>
    T angleBetween(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return atan2(rhs.y-lhs.y, rhs.x-lhs.x);
    }
    
            
    // vec dot product
    template <typename T>
    T dot(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return lhs.x*rhs.x + lhs.y*rhs.y;
    }
    
    // outstream opp
    template <class T>
    std::ostream& operator<<(std::ostream& out, const ProtoVector2<T>& v){
        out << v.x << ", " << v.y;
        return out;
    }

        
        
        /*****************************************************/
        /*                    Constructors                   */
        /*****************************************************/
        template <class T>
        inline ProtoVector2<T>::ProtoVector2():x(0), y(0){
        }
        
        template <class T>
        inline ProtoVector2<T>::ProtoVector2(T x, T y):
        x(x), y(y){
        }
        
        template <class T>
        inline ProtoVector2<T>::ProtoVector2(T xy[2]):
        x(xy[0]), y(xy[1]){
        }
        
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator+=(const ProtoVector2<T>& v){
            x+=v.x;
            y+=v.y;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator+=(T s){
            x+=s;
            y+=s;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator-=(const ProtoVector2<T>& v){
            x-=v.x;
            y-=v.y;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator-=(T s){
            x-=s;
            y-=s;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator*=(const ProtoVector2<T>& v){
            x*=v.x;
            y*=v.y;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator*=(T s){
            x*=s;
            y*=s;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator/=(const ProtoVector2<T>& v){
            x/=v.x;
            y/=v.y;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator/=(T s){
            x/=s;
            y/=s;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator-(){
            x*=-1;
            y*=-1;
            return *this;
            
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator++(){
            x++;
            y++;
            return *this;
        }
        
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator++(int){
            ++x;
            ++y;
            return *this;
        }
        
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator--(){
            x--;
            y--;
            return *this;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::operator--(int){
            --x;
            --y;
            return *this;
        }
        
        
        template <class T>
        inline T ProtoVector2<T>::operator[](unsigned index){
            assert( index >= 0 && index <= 1 );
            return *(&x+index);
        }
        
        template <class T>
        inline const T ProtoVector2<T>::operator[](unsigned index) const{
            assert( index >= 0 && index <= 1 );
            return *(&x+index);
        }
        
        
        template <class T>
        inline bool ProtoVector2<T>::operator==(const ProtoVector2<T>& v) const{
            return (x==v.x && y==v.y);
        }
        
        template <class T>
        inline bool ProtoVector2<T>::operator!=(const ProtoVector2<T>& v) const{
            return (x!=v.x || y!=v.y);
        }
        
        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        template <class T>
        inline T ProtoVector2<T>::mag() const{
            return sqrt(x*x + y*y);
        }
        
        template <class T>
        inline T ProtoVector2<T>::magSqr() const{
            return x*x + y*y;
        }
        
        template <class T>
        inline void ProtoVector2<T>::normalize(){
            T m = mag();
            x/=m;
            y/=m;
        }
        
        template <class T>
        inline bool ProtoVector2<T>::isNormalized() const{
            return (mag() > .99 && mag() < 1.1);
        }
        
        template <class T>
        inline T ProtoVector2<T>::angle() const{
            return atan2(y,x);
        }
        
        
        template <class T>
        inline T ProtoVector2<T>::angleBetween(const ProtoVector2<T>& v) const{
            return atan2(v.y,v.x) - atan2(y,x);
        }
        
        template <class T>
        inline T ProtoVector2<T>::dot(const ProtoVector2<T>& v) const{
            return x*v.x + y*v.y;
        }
        
        template <class T>
        inline const ProtoVector2<T>& ProtoVector2<T>::rotate(T theta){
            float tempX = cos(theta)*x - sin(theta)*y;
            float tempY = sin(theta)*x + cos(theta)*y;
            return *this(ProtoVector2<T>(tempX, tempY));
        }
        
#define ProtoVector2f ProtoVector2<float>
#define ProtoVector2d ProtoVector2<double>
        
        
        }
        
#endif // PROTO_VECTOR2_H
